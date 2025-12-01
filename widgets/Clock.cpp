#include "Clock.hpp"
#include <ctime>
#include <string>

lv_timer_t *Clock::clockTimer = nullptr;
std::vector<Clock *> Clock::clocks;

Clock::Clock(lv_obj_t *parent, lv_font_t *font){
	clockLabel = lv_label_create(parent);
	lv_obj_set_style_text_font(clockLabel, font, LV_PART_MAIN);

	if(clockTimer == nullptr) clockTimer = lv_timer_create(clockTimerCallback, CLOCK_UPDATE_INTERVAL_MS, &clocks); 
	clocks.push_back(this);
}

void Clock::clockTimerCallback(lv_timer_t *timer){   
	Clock *clock = static_cast<Clock *>(lv_timer_get_user_data(timer)); 
	time_t timestamp = time(&timestamp);
	struct tm datetime = *localtime(&timestamp);
	for(Clock *clock : Clock::clocks){
		clock->setTime(datetime.tm_hour, datetime.tm_min);
	}
}

void Clock::setTime(int newHours, int newMinutes){
	if(newHours == hours && newMinutes == minutes) return;
	hours = newHours;
	minutes = newMinutes;
	std::string timeString;
	// Reserve space ahead of time for a bit of extra performance
	timeString.reserve(5);
	// We don't use leading zeros but still want spacing for single digit hours
	if(hours < 10) timeString += " ";
	timeString += std::to_string(hours) + ":";
	// We do use a leading zero for minutes
	if(minutes < 10) timeString += "0";
	timeString += std::to_string(minutes);
	lv_label_set_text(clockLabel, timeString.c_str());
}
