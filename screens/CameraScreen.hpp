#pragma once
#include <Globals.hpp>
#include <utilities/Colors.hpp>
class CameraScreen{
public:
    enum FlashMode{FLASH_OFF, FLASH_ON, FLASH_AUTO};
    FlashMode activeFlashMode = FLASH_OFF; // TODO: Load from persistant storage later
    static const uint32_t VIEWFINDER_HEIGHT = 640;
    static const uint32_t HEADER_FOOTER_HEIGHT = (DISPLAY_HEIGHT - VIEWFINDER_HEIGHT) / 2;
    static const uint32_t BUTTON_X_PADDING = 16;
    static const lv_color_t HEADER_FOOTER_BG_COLOR; // Colors::GREYS_PANEL_BG
    

    lv_obj_t *screen;
    lv_obj_t *header;
    lv_obj_t *footer;
    lv_obj_t *photoLibraryButton;
    lv_obj_t *flashButton;
    lv_obj_t *exitButton;
    lv_obj_t *flipButton;

    CameraScreen();
    /**
     * @brief Changes the flash mode and updates the flash button icon
     * @param newMode The new flash mode to set
     * @note Should only be updated from the backend, the UI does not cycle modes itself
     */
    void changeFlashMode(FlashMode newMode);

private:
    /**
     * @brief Creates a header or footer object
     * @param alignment The alignment of the header/footer (top or bottom middle)   
     * @return The created header/footer object
     * @note Headers and footers have the same style but different alignments
     */
    lv_obj_t *createHeaderFooter(lv_align_t alignment);
    /**
     * @brief Callback for when the exit button is pressed
     * @param event The LVGL event object, not used
     * @note Returns to the main screen when the exit button is pressed
     */
    static void exitCallback(lv_event_t *event);
    /**
     * @brief Callback for when the flip camera button is pressed
     * @param event The LVGL event object, contains user_data that can be a cast to communicate with backend
     * @note Informs the backend the flip camera button was pressed
     */
    static void flipCameraCallback(lv_event_t *event);
    /**
     * @brief Callback for when the flash button is pressed
     * @param event The LVGL event object, contains user_data that can be a cast to communicate with backend 
     * @note Informs the backend the flash mode change button was pressed
     */
    static void changeFlashModeCallback(lv_event_t *event);
};