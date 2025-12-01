#pragma once
#include "Globals.hpp"

class WearableUI{
public:
    WearableUI();

    /* Return the elapsed milliseconds since startup.
    * It needs to be implemented by the user */
    uint32_t getMillisSinceStartup(void);

    /* Copy rendered image to screen.
    * This needs to be implemented by the user. */
    void my_flush_cb(lv_display_t *display, const lv_area_t *area, uint8_t *pixelBuffer);

    void setBackgroundTransparency(lv_obj_t *object, lv_opa_t opacity);
private:
    static uint32_t startTime;
}

lv_display_t *display;

void main(void);

