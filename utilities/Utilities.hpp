#include <cstdint>
namespace Utilities{
    /// @brief Convert degrees to the LVGL angle format of 0.1 degree increments (0-3600)
    /// @param degrees Input angle in degrees as a float
    /// @return Converted angle in the range of 0-3600 mapped from 0-360 degrees
    static uint32_t degreesToLvglAngle(const float degrees);

    /// @brief Convert an angle in the LVGL angle format of 0.1 degree increments (0-3600) to normal degrees
    /// @param degrees Input angle in the LVGL angle format as a uint32_t
    /// @return Converted angle in the range of 0-360 degrees mapped from 0-3600 
    static float lvglAngleToDegrees(const uint32_t lvglAngle);
}