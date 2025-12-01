#include "WearableUI.hpp"
#include <chrono>
#if LV_USE_SDL
#include <SDL2/SDL.h>
#endif

void main(void){
    WearableUI ui;
    your_driver_init();

    lv_init();
#if LV_USE_SDL
    lv_tick_set_cb(SDL_GetTicks);
#endif

    display = lv_display_create(DISPLAY_WIDTH, DISPLAY_HEIGHT);
    // Allows display to be transparent for video to play underneath
    lv_display_set_color_format(display, LV_COLOR_FORMAT_ARGB8888);

    // LVGL will render to this 1/10 screen sized buffer
    static uint8_t buffer[(DISPLAY_WIDTH * DISPLAY_HEIGHT / 10) * BYTES_PER_PIXEL];
    lv_display_set_buffers(display, buffer, nullptr, sizeof(buffer), LV_DISPLAY_RENDER_MODE_PARTIAL);

    /* This callback will display the rendered image */
    lv_display_set_flush_cb(display, my_flush_cb);

    /* Create widgets */
    lv_obj_t *label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "Hello LVGL!");

    /* Make LVGL periodically execute its tasks */
    while(true){
        /* Provide updates to currently-displayed Widgets here. */
        lv_timer_handler();
        my_sleep(5);  /*Wait 5 milliseconds before processing LVGL timer again*/
    }
}

WearableUI::WearableUI(){
    #if LV_USE_SDL == 0
    startTime = getMillis();
    #endif
}

/**
 * @brief Return the elapsed milliseconds since startup.
 * @return The number of milliseconds since startup
 * @note Used for LVGL timing functions and maybe cross-platform but requires some research
 */
uint32_t WearableUI::getMillisSinceStartup(void){
    
    // Get the current time from the system clock and convert the current time to time since epoch
    std::chrono::duration duration = std::chrono::system_clock::now().time_since_epoch();

    // Convert duration to milliseconds
    int64_t milliseconds = std::chrono::duration_cast<std::chrono::milliseconds>(duration).count();
    // Cast to uint32_t losing half our range, I hope our they update the callback signature before 2038
    return static_cast<uint32_t>(milliseconds);
}

/* Copy rendered image to screen.
 * This needs to be implemented by the user. */
void WearableUI::my_flush_cb(lv_display_t * disp, const lv_area_t * area, uint8_t * px_buf){
    /* Show the rendered image on the display */
    my_display_update(area, px_buf);

    /* Indicate that the buffer is available.
     * If DMA were used, call in the DMA complete interrupt. */
    lv_display_flush_ready();
}

void WearableUI::setBackgroundTransparency(lv_obj_t *object, lv_opa_t opacity){
    lv_obj_set_style_bg_opa(lv_screen_active(), opacity, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(lv_layer_bottom(), opacity, LV_PART_MAIN);
}