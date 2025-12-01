#include "Utilities.hpp"
#include <cmath>
static uint32_t Utilities::degreesToLvglAngle(const float degrees){
    // In case input is outside the normal range, use fmod to wrap it within 0-360
    // To convert to LVGL angle format, divide by 360 to get the fraction of a full rotation, then multiply by 3600
    return static_cast<uint32_t>((fmod(degrees, 360.0f) / 360.0f) * 3600.0f);
}

/// @brief Convert an angle in the LVGL angle format of 0.1 degree increments (0-3600) to normal degrees
/// @param degrees Input angle in the LVGL angle format as a uint32_t
/// @return Converted angle in the range of 0-360 degrees mapped from 0-3600 
static float Utilities::lvglAngleToDegrees(const uint32_t lvglAngle){
    // Convert LVGL angle format (0-3600) back to degrees (0-360)
    return (static_cast<float>(lvglAngle) / 3600.0f) * 360.0f;
}