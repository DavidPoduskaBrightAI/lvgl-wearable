#pragma once
#include "lvgl.h"
#include "Colors.hpp"

class CameraModeSwitch{
public:
    enum CameraMode{VIDEO, PHOTO};
    static const CameraMode cameraMode = CameraMode::PHOTO;
    CameraMode ActiveCameraMode = CameraMode::PHOTO;
    static const uint32_t SWITCH_WIDTH = 262;
    static const uint32_t SWITCH_HEIGHT = 52;
    static const uint32_t KNOB_WIDTH = 142;
    static const uint32_t KNOB_HEIGHT = 52;
    lv_obj_t *object;
    lv_obj_t *knob;
    lv_obj_t *photoLabel;

    CameraModeSwitch(lv_obj_t *parent);
};