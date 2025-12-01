#pragma once
#include "lvgl.h"
#include <cstdint>
static const size_t BYTES_PER_PIXEL = LV_COLOR_FORMAT_GET_SIZE(LV_COLOR_FORMAT_ARGB8888);
static const uint32_t DISPLAY_WIDTH = 480;
static const uint32_t DISPLAY_HEIGHT = 800;