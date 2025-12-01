#include "AiChatScreen.hpp"
#include "Globals.hpp"
#include "utilities/Colors.hpp"
#include "utilities/Utilities.hpp"
AiChatScreen::AiChatScreen(){
    // Create the main screen object
    screen = lv_obj_create(nullptr);
    lv_obj_set_size(screen, DISPLAY_WIDTH, DISPLAY_HEIGHT);
    lv_obj_set_style_bg_color(screen, Colors::BACKGROUNDS_PRIMARY, LV_PART_MAIN);

    // Create header
    header = lv_obj_create(screen);
    lv_obj_set_size(header, DISPLAY_WIDTH, HEADER_HEIGHT);
    lv_obj_set_style_opa(header, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_align(header, LV_ALIGN_TOP_MID, 0, HEADER_PADDING_Y);

    // Create response buttons frame
    responseButtonsFrame = lv_obj_create(screen);
    lv_obj_set_size(responseButtonsFrame, RESPONSE_FRAME_WIDTH, RESPONSE_FRAME_HEIGHT);
    lv_obj_set_style_opa(responseButtonsFrame, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_pos(responseButtonsFrame, RESPONSE_FRAME_X, RESPONSE_FRAME_Y);

    // Create positive response button
    responsePositiveButton = createResponseButton(true);

    // Create negative response button
    responseNegativeButton = createResponseButton(false);

    // Create mute/unmute button
    muteUnmuteButton = lv_button_create(screen);
    lv_obj_set_size(muteUnmuteButton, BOTTOM_BUTTON_WIDTH, BOTTOM_BUTTON_HEIGHT);
    lv_obj_align(muteUnmuteButton, LV_ALIGN_BOTTOM_LEFT, BOTTOM_BUTTON_PADDING, -BOTTOM_BUTTON_PADDING);
    lv_obj_add_event_cb(muteUnmuteButton, muteUnmuteCallback, LV_EVENT_PRESSED, this);

    unmuteImage = lv_image_create(muteUnmuteButton);
    lv_image_set_src(unmuteImage, "A:images/mic.svg");
    lv_obj_center(unmuteImage);

    muteImage = lv_image_create(muteUnmuteButton);
    lv_image_set_src(muteImage, "A:images/mic-off.svg");
    lv_obj_center(muteImage);
    lv_obj_add_flag(muteImage, LV_OBJ_FLAG_HIDDEN);

    // Create play/pause button
    playPauseButton = lv_button_create(screen);
    lv_obj_set_size(playPauseButton, BOTTOM_BUTTON_WIDTH, BOTTOM_BUTTON_HEIGHT);
    lv_obj_align(muteUnmuteButton, LV_ALIGN_BOTTOM_RIGHT, -BOTTOM_BUTTON_PADDING, -BOTTOM_BUTTON_PADDING);
    lv_obj_add_event_cb(playPauseButton, playPauseCallback, LV_EVENT_PRESSED, this);

    playImage = lv_image_create(playPauseButton);
    lv_image_set_src(playImage, "A:images/play.svg");  
    lv_obj_center(playImage);   

    pauseImage = lv_image_create(muteUnmuteButton);
    lv_image_set_src(pauseImage, "A:images/pause.svg");
    lv_obj_center(pauseImage);
    lv_obj_add_flag(pauseImage, LV_OBJ_FLAG_HIDDEN);
}

void AiChatScreen::sendMuteUnmuteMessage(){
    if(currentMuteState == MuteState::MUTED){
        // communicationThingy->sendMuteMessage();
    }else{
        // communicationThingy->sendUnmuteMessage(); 
    }
}

void AiChatScreen::sendPlayPauseMessage(){
    if(currentPlayState == PlayState::PAUSED){
        // communicationThingy->sendPlayMessage();
    }else{
        // communicationThingy->sendPauseMessage(); 
    }
}

void AiChatScreen::setMuteState(MuteState newState){

}

void AiChatScreen::setPlayState(PlayState newState)
{
}

lv_obj_t *AiChatScreen::createResponseButton(bool isPositive){
    // Create response button
    lv_obj_t *button = lv_button_create(responseButtonsFrame);
    lv_obj_set_size(button, LV_SIZE_CONTENT, RESPONSE_BUTTON_HEIGHT);
    lv_obj_remove_style_all(button);
    lv_obj_set_style_opa(button, LV_OPA_100, LV_PART_MAIN);

    lv_obj_t *label = lv_label_create(button);
    lv_obj_align(label, LV_ALIGN_LEFT_MID, RESPONSE_BUTTON_PADDING_X, 0);

    lv_obj_t *iconBackground = lv_obj_create(responsePositiveButton);
    lv_obj_remove_style_all(iconBackground);
    lv_obj_set_style_bg_color(iconBackground, lv_color_black(), LV_PART_MAIN);
    lv_obj_set_style_bg_opa(button, Colors::percentageToOpa(12), LV_PART_MAIN);
    lv_obj_set_size(iconBackground, RESPONSE_ICON_BACKGROUND_SIZE, RESPONSE_ICON_BACKGROUND_SIZE);
    lv_obj_align(iconBackground, LV_ALIGN_RIGHT_MID, -RESPONSE_BUTTON_PADDING_X, 0);

    lv_obj_t *icon = lv_image_create(iconBackground);
    lv_image_set_src(icon, "A:images/icon-thumbs-up.svg");
    lv_obj_center(icon);

    if(isPositive){        
        lv_obj_add_event_cb(button, positiveResponseCallback, LV_EVENT_PRESSED, nullptr);
        lv_obj_set_align(button, LV_ALIGN_TOP_MID);
        lv_obj_set_style_bg_color(button, Colors::WEARABLE_GREEN, LV_PART_MAIN);
        lv_label_set_text(label, "That Worked");
        responsePositiveButton = button;
    }else{
        lv_obj_add_event_cb(button, negativeResponseCallback, LV_EVENT_PRESSED, nullptr);
        lv_obj_set_align(button, LV_ALIGN_BOTTOM_MID);
        lv_obj_set_style_bg_color(button, Colors::WEARABLE_RED, LV_PART_MAIN);
        lv_label_set_text(label, "Didn't Work");
        // The thumbs dow nicon is simply the thumbs up rotated 180 degrees so we don't need a separate image
        lv_image_set_rotation(icon, Utilities::degreesToLvglAngle(180));
        responseNegativeButton = button;
    }
}

void AiChatScreen::createBottomButton(bool isMuteUnmute){
    // Create mute/unmute button
    lv_obj_t *button = lv_button_create(screen);
    lv_obj_set_size(button, BOTTOM_BUTTON_WIDTH, BOTTOM_BUTTON_HEIGHT);
    lv_obj_remove_style_all(button);
    lv_obj_set_style_opa(button, LV_OPA_100, LV_PART_MAIN);
    lv_obj_set_style_bg_color(button, Colors::WEARABLE_BLUE, LV_PART_MAIN);
    lv_obj_set_style_radius(button, BOTTOM_BUTTON_RADIUS, LV_PART_MAIN);

    lv_obj_t *defaultImage = lv_image_create(button);
    lv_obj_center(defaultImage);

    lv_obj_t *altImage = lv_image_create(button);
    lv_obj_center(altImage);
    lv_obj_add_flag(altImage, LV_OBJ_FLAG_HIDDEN);

    if(isMuteUnmute){  
        lv_obj_align(button, LV_ALIGN_BOTTOM_LEFT, BOTTOM_BUTTON_PADDING, -BOTTOM_BUTTON_PADDING);
        lv_obj_add_event_cb(button, muteUnmuteCallback, LV_EVENT_PRESSED, this);
        lv_image_set_src(defaultImage, "A:images/mic.svg");
        lv_image_set_src(altImage, "A:images/mic-off.svg");
        playPauseButton = button;
        playImage = defaultImage;   
        pauseImage = altImage;
    }else{           
        // Adjust alignment for play/pause button
        lv_obj_align(button, LV_ALIGN_BOTTOM_RIGHT, -BOTTOM_BUTTON_PADDING, -BOTTOM_BUTTON_PADDING);
        lv_obj_add_event_cb(button, playPauseCallback, LV_EVENT_PRESSED, this);
        lv_image_set_src(defaultImage, "A:images/play.svg");
        lv_image_set_src(altImage, "A:images/pause.svg");
        muteUnmuteButton = button;
        unmuteImage = defaultImage;
        muteImage = altImage;
    }
}

void AiChatScreen::positiveResponseCallback(lv_event_t *event){
    // CommunicationThingy *communicationThingy = <static_cast>(lv_event_get_user_data(event));
    // Inform backend of flash mode change
    // communicationThingy->sendPositiveResponse;
}

void AiChatScreen::negativeResponseCallback(lv_event_t *event){
    // CommunicationThingy *communicationThingy = <static_cast>(lv_event_get_user_data(event));
    // Inform backend of flash mode change
    // communicationThingy->sendNegativeResponse;
}

void AiChatScreen::muteUnmuteCallback(lv_event_t *event){
    AiChatScreen *screen = static_cast<AiChatScreen *>(lv_event_get_user_data(event));
}

void AiChatScreen::playPauseCallback(lv_event_t *event){
}
