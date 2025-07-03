#pragma once
#ifndef LOAD_ARC_HPP
#define LOAD_ARC_HPP
#include "lvgl.h"
#include "hexCodes.hpp"
#include "gaugeMath.hpp"

using lv_arc_label = struct {
    lv_obj_t *arc;
    lv_obj_t *label;
    const char *prefix;
};

static void setArcData(void *obj, int32_t value);
static void debugArcAnim(lv_arc_label *data, int32_t min, int32_t max);

inline auto RpmArc() -> void {
    static lv_arc_label arc_data;

    arc_data.arc = lv_arc_create(lv_screen_active());
    arc_data.label = lv_label_create(lv_screen_active());
    arc_data.prefix = "RPM: ";

    // Label alignment
    lv_obj_align(arc_data.label, LV_ALIGN_BOTTOM_RIGHT, 0, RPM_LABEL_OFFSET);

    // Object alignment and size adjustment
    lv_obj_center(arc_data.arc);
    lv_obj_set_size(arc_data.arc, RPM_ARC_SIZE, RPM_ARC_SIZE);
    lv_arc_set_rotation(arc_data.arc, RPM_ARC_ROTATION);
    lv_arc_set_bg_angles(arc_data.arc, 0, RPM_ARC_ANGLE);
    lv_arc_set_value(arc_data.arc, 0);

    // Object style changes
    lv_obj_set_style_arc_width(arc_data.arc, ARC_WIDTH, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_data.arc, lv_color_hex(LAZER_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(arc_data.arc, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc_data.arc, false, LV_PART_INDICATOR);
    lv_obj_remove_style(arc_data.arc, nullptr, LV_PART_KNOB);

    // Make it unclickable and give it an animation for testing
    lv_obj_clear_flag(arc_data.arc, LV_OBJ_FLAG_CLICKABLE);
    debugArcAnim(&arc_data, RPM_MIN, RPM_MAX);

    // Set arc range (min/max values)
    lv_arc_set_range(arc_data.arc, RPM_MIN, RPM_MAX);

    // Use these when actually changing values manually.
    // lv_obj_add_event_cb(arc_data.arc, rpmArcEventCB, LV_EVENT_VALUE_CHANGED, arc_data.label);
    // lv_obj_send_event(arc_data.arc, LV_EVENT_VALUE_CHANGED, nullptr);
}

inline auto SpeedArc() -> void {
    static lv_arc_label arc_data;
    arc_data.arc = lv_arc_create(lv_screen_active());
    arc_data.label = lv_label_create(lv_screen_active());
    arc_data.prefix = "SPEED: ";

    // Label alignment
    lv_obj_align(arc_data.label, LV_ALIGN_BOTTOM_RIGHT, 0, SPEEDO_LABEL_OFFSET);

    // Object alignment and size adjustment
    lv_obj_center(arc_data.arc);
    lv_obj_set_size(arc_data.arc, SPEEDO_ARC_SIZE, SPEEDO_ARC_SIZE);
    lv_arc_set_rotation(arc_data.arc, SPEEDO_ARC_ROTATION);
    lv_arc_set_bg_angles(arc_data.arc, 0, SPEEDO_ANGLE);
    lv_arc_set_value(arc_data.arc, 0);

    // Object style changes
    lv_obj_set_style_arc_width(arc_data.arc, ARC_WIDTH, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_data.arc, lv_color_hex(LAZER_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(arc_data.arc, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc_data.arc, false, LV_PART_INDICATOR);
    lv_obj_remove_style(arc_data.arc, nullptr, LV_PART_KNOB);

    // Make it unclickable and give it an animation for testinglv_anim_t a;
    lv_obj_clear_flag(arc_data.arc, LV_OBJ_FLAG_CLICKABLE);
    debugArcAnim(&arc_data, SPEED_MIN, SPEED_MAX);

    // Set arc range (min/max values)
    lv_arc_set_range(arc_data.arc, SPEED_MIN, SPEED_MAX);

    // Use these when actually changing values manually.
    // lv_obj_add_event_cb(arc_data.arc, speedoArcEventCB, LV_EVENT_VALUE_CHANGED, arc_data.label);
    // lv_obj_send_event(arc_data.arc, LV_EVENT_VALUE_CHANGED, nullptr);
}
inline auto FuelArc() -> void {
    static lv_arc_label arc_data;
    arc_data.arc = lv_arc_create(lv_screen_active());
    arc_data.label = lv_label_create(lv_screen_active());
    arc_data.prefix = "FUEL: ";

    // Label alignment
    lv_obj_align(arc_data.label, LV_ALIGN_BOTTOM_RIGHT, 0, FUEL_LABEL_OFFSET);

    // Object alignment and size adjustment
    lv_obj_center(arc_data.arc);
    lv_obj_set_size(arc_data.arc, FUEL_ARC_SIZE, FUEL_ARC_SIZE);
    lv_arc_set_rotation(arc_data.arc, FUEL_ARC_ROTATION);
    lv_arc_set_bg_angles(arc_data.arc, 360, FUEL_ANGLE);
    lv_arc_set_value(arc_data.arc, 0);

    // Object style changes
    lv_obj_set_style_arc_width(arc_data.arc, ARC_WIDTH, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_data.arc, lv_color_hex(LAZER_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(arc_data.arc, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc_data.arc, false, LV_PART_INDICATOR);
    lv_obj_remove_style(arc_data.arc, nullptr, LV_PART_KNOB);

    // Make it unclickable and give it an animation for testinglv_anim_t a;
    lv_obj_clear_flag(arc_data.arc, LV_OBJ_FLAG_CLICKABLE);
    debugArcAnim(&arc_data, FUEL_MIN, FUEL_MAX);

    // Set arc range (min/max values)
    lv_arc_set_range(arc_data.arc, FUEL_MIN, FUEL_MAX);

    // Use these when actually changing values manually.
    // lv_obj_add_event_cb(arc_data.arc, speedoArcEventCB, LV_EVENT_VALUE_CHANGED, arc_data.label);
    // lv_obj_send_event(arc_data.arc, LV_EVENT_VALUE_CHANGED, nullptr);
}
inline auto TempArc() -> void {
    static lv_arc_label arc_data;
    arc_data.arc = lv_arc_create(lv_screen_active());
    arc_data.label = lv_label_create(lv_screen_active());
    arc_data.prefix = "TEMP: ";

    // Label Alignment
    lv_obj_align(arc_data.label, LV_ALIGN_BOTTOM_RIGHT, 0, TEMP_LABEL_OFFSET);

    // Arc alignment and size adjustment
    lv_obj_center(arc_data.arc);
    lv_obj_set_size(arc_data.arc, TEMP_ARC_SIZE, TEMP_ARC_SIZE);
    lv_arc_set_rotation(arc_data.arc, TEMP_ARC_ROTATION);
    lv_arc_set_bg_angles(arc_data.arc, 0, TEMP_ANGLE);
    lv_arc_set_value(arc_data.arc, 0);

    // Object style changes
    lv_obj_set_style_arc_width(arc_data.arc, ARC_WIDTH, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_data.arc, lv_color_hex(LAZER_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(arc_data.arc, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc_data.arc, false, LV_PART_INDICATOR);
    lv_obj_remove_style(arc_data.arc, nullptr, LV_PART_KNOB);

    // Make it unclickable and give it an animation for testinglv_anim_t a;
    lv_obj_clear_flag(arc_data.arc, LV_OBJ_FLAG_CLICKABLE);
    debugArcAnim(&arc_data, TEMP_MIN, TEMP_MAX);

    // Set arc range (min/max values)
    lv_arc_set_range(arc_data.arc, TEMP_MIN, TEMP_MAX);

    // Use these when actually changing values manually.
    // lv_obj_add_event_cb(arc_data.arc, speedoArcEventCB, LV_EVENT_VALUE_CHANGED, arc_data.label);
    // lv_obj_send_event(arc_data.arc, LV_EVENT_VALUE_CHANGED, nullptr);
}

static void setArcData(void *obj, int32_t value) {
    auto *data = static_cast<lv_arc_label *>(obj);
    lv_arc_set_value(data->arc, value);

    lv_label_set_text_fmt(data->label, "%s%d ", data->prefix, lv_arc_get_value(data->arc));
}

static void debugArcAnim(lv_arc_label *arc_data, int32_t min, int32_t max) {
    static constexpr int32_t ANIM_DUR = 1000;
    static constexpr int32_t ANIM_DELAY = 200;
    lv_anim_t anim;
    lv_anim_init(&anim);
    lv_anim_set_var(&anim, arc_data);
    lv_anim_set_exec_cb(&anim, setArcData);
    lv_anim_set_duration(&anim, ANIM_DUR);
    lv_anim_set_repeat_count(&anim, LV_ANIM_REPEAT_INFINITE);
    lv_anim_set_playback_duration(&anim, ANIM_DUR);
    lv_anim_set_repeat_delay(&anim, ANIM_DELAY);
    lv_anim_set_values(&anim, min, max);
    lv_anim_start(&anim);
}

#endif
