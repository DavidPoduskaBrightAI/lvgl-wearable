#pragma once
#include "lvgl.h"
#include <cstdint>
class AiChatScreen{
public:
    enum MuteState{MUTED, UNMUTED};
    enum PlayState{PLAYING, PAUSED};
    static const uint32_t HEADER_HEIGHT = 69;
    static const uint32_t HEADER_PADDING_Y = 21;
    
    static const uint32_t RESPONSE_FRAME_WIDTH = 432;
    static const uint32_t RESPONSE_FRAME_HEIGHT = 360;
    static const uint32_t RESPONSE_FRAME_X = 24;
    static const uint32_t RESPONSE_FRAME_Y = 128;
    static const uint32_t RESPONSE_BUTTON_HEIGHT = 170;
    static const uint32_t RESPONSE_BUTTON_PADDING_X = 32;
    static const uint32_t RESPONSE_ICON_BACKGROUND_SIZE = 96;

    static const uint32_t BOTTOM_BUTTON_WIDTH = 204;
    static const uint32_t BOTTOM_BUTTON_HEIGHT = 170;
    static const uint32_t BOTTOM_BUTTON_PADDING = 24;
    static const uint32_t BOTTOM_BUTTON_RADIUS = 40;

    MuteState currentMuteState = MuteState::UNMUTED;
    PlayState currentPlayState = PlayState::PLAYING;
    AiChatScreen();

    void sendMuteUnmuteMessage();
    void sendPlayPauseMessage();

    void setMuteState(MuteState newState);
    void setPlayState(PlayState newState);

    /**
     * @brief Callback for when the positive response button is pressed
     * @param event LVGL event data, eventually will contain a reference to the backend communication code
     */
    static void positiveResponseCallback(lv_event_t *event);
    /**
     * @brief Callback for when the negative response button is pressed
     * @param event LVGL event data, eventually will contain a reference to the backend communication code
     */
    static void negativeResponseCallback(lv_event_t *event);
    /**
     * @brief Callback for when the mute/unmute button is pressed
     * @param event LVGL event data, eventually will contain a reference to the backend communication code
     */
    static void muteUnmuteCallback(lv_event_t *event);
    /**
     * @brief Callback for when the play/pause button is pressed
     * @param event LVGL event data, eventually will contain a reference to the backend communication code
     */
    static void playPauseCallback(lv_event_t *event);
private:    
    lv_obj_t *screen;
    lv_obj_t *header;
    lv_obj_t *responseButtonsFrame;
    lv_obj_t *responsePositiveButton;
    lv_obj_t *responseNegativeButton;
    lv_obj_t *muteUnmuteButton;
    lv_obj_t *unmuteImage;
    lv_obj_t *muteImage;
    lv_obj_t *playPauseButton;
    lv_obj_t *playImage;
    lv_obj_t *pauseImage;

    /**
     * @brief Create a response button, there is a positive and negative version that the user presses for feedback for the AI
     * @param isPositive True for the positive response button, false for the negative version
     * @return Pointer to the created lv_obj_t
     */
    lv_obj_t *createResponseButton(bool isPositive);

    void createBottomButton(bool isPlayPause);
};