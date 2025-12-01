#pragma once
#include "lvgl.h"
#include <vector>
class Clock{
public:
    static const uint32_t CLOCK_UPDATE_INTERVAL_MS = 100;
    static lv_timer_t *clockTimer;
    static std::vector<Clock *> clocks;
    lv_obj_t *clockLabel;
    Clock(lv_obj_t *parent, lv_font_t *font);
    static void clockTimerCallback(lv_timer_t *timer);
    void setTime(int newHours, int newMinutes);
private:
    uint8_t hours = 0;
    uint8_t minutes = 0;
};