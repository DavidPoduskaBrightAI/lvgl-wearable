#include "lvgl.h"
namespace Colors{
    static const lv_color_t GREYS_FIELD_STROKE = lv_color_hex(0x5A596F);
    static const lv_color_t GREYS_PANEL_BG = lv_color_hex(0x28242C);

    static const lv_color_t LABELS_PRIMARY = lv_color_white();
    static const lv_color_t LABELS_SECONDARY = lv_color_hex(0xEBEBF5);

    static const lv_color_t STATEFUL_BLUE_3 = lv_color_hex(0x77D3FF);

    static const lv_color_t BACKGROUNDS_PRIMARY = lv_color_white();

    static const lv_color_t WEARABLE_RED = lv_color_hex(0xD9000B);
    static const lv_color_t WEARABLE_GREEN = lv_color_hex(0x008D57);
    static const lv_color_t WEARABLE_BLUE = lv_color_hex(0x008FD3);

    lv_opa_t percentageToOpa(uint32_t percentage){
        if(percentage >= 100) return LV_OPA_100;
        return static_cast<lv_opa_t>((percentage / 100.f) * 255.0f);
    }
}
