#include "CameraModeSwitch.hpp"
CameraModeSwitch::CameraModeSwitch(lv_obj_t *parent){
    // Create main switch object
    object = lv_switch_create(parent);
    lv_obj_set_size(object, SWITCH_WIDTH, SWITCH_HEIGHT);
    lv_obj_set_style_bg_color(object, Colors::GREYS_FIELD_STROKE, LV_PART_MAIN);
    // Set opacity of main background to 30%
    lv_obj_set_style_bg_opa(object, Colors::percentageToOpa(30), LV_PART_MAIN);
    lv_obj_set_style_radius(object, SWITCH_HEIGHT / 2, LV_PART_MAIN);
    // Create the knob
    knob = lv_obj_create(object);
    lv_obj_set_size(knob, KNOB_WIDTH, KNOB_HEIGHT);
    lv_obj_set_style_bg_color(knob, Colors::GREYS_FIELD_STROKE, LV_PART_MAIN);
    lv_obj_set_style_bg_opa(knob, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_set_style_radius(knob, KNOB_HEIGHT / 2, LV_PART_MAIN);
    photoLabel = lv_label_create(knob);

}