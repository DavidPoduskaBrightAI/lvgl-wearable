#include "CameraScreen.hpp"
const lv_color_t CameraScreen::HEADER_FOOTER_BG_COLOR = Colors::GREYS_PANEL_BG;

CameraScreen::CameraScreen(){
    screen = lv_obj_create(nullptr);

    header = createHeaderFooter(LV_ALIGN_TOP_MID);
    footer = createHeaderFooter(LV_ALIGN_BOTTOM_MID);

    flashButton = lv_image_create(header);
    lv_image_set_src(flashButton, "A:images/icon-auto-flash.svg");
    lv_obj_align(flashButton, LV_ALIGN_LEFT_MID, BUTTON_X_PADDING, 0);

    exitButton = lv_obj_create(header);
    lv_image_set_src(flashButton, "A:images/icon-x.svg");
    lv_obj_align(exitButton, LV_ALIGN_RIGHT_MID, -BUTTON_X_PADDING, 0);
    lv_obj_add_event_cb(exitButton, exitCallback, LV_EVENT_PRESSED, nullptr);
    
    photoLibraryButton = lv_obj_create(footer);
    lv_obj_set_size(photoLibraryButton, 52, 52);
    lv_obj_align(photoLibraryButton, LV_ALIGN_LEFT_MID, BUTTON_X_PADDING, 0);
    lv_obj_set_style_radius(photoLibraryButton, LV_RADIUS_CIRCLE, LV_PART_MAIN);

    flipButton = lv_obj_create(footer);
    lv_image_set_src(flashButton, "A:images/icon-camera-reverse.svg");
    lv_obj_align(exitButton, LV_ALIGN_RIGHT_MID, -BUTTON_X_PADDING, 0);
}

lv_obj_t *CameraScreen::createHeaderFooter(lv_align_t alignment){
    lv_obj_t *headerFooter = lv_obj_create(screen);
    lv_obj_set_size(headerFooter, lv_obj_get_width(screen), HEADER_FOOTER_HEIGHT);
    lv_obj_set_align(headerFooter, alignment);
    lv_obj_remove_style_all(headerFooter);
    lv_obj_set_style_bg_color(headerFooter, Colors::GREYS_PANEL_BG, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(headerFooter, LV_OPA_100, LV_PART_MAIN);
    return headerFooter;
}

void CameraScreen::exitCallback(lv_event_t *event){
    lv_screen_load(mainScreen);
}

void CameraScreen::flipCameraCallback(lv_event_t *event){
    void *communicationThingy = event->user_data;
    // TODO: Implement camera flip functionality
}
