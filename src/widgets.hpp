#pragma once
#include "core/lv_obj.h"
#include "misc/lv_area.h"
#include "widgets/textarea/lv_textarea.h"
#ifndef LOAD_ARC_HPP
#define LOAD_ARC_HPP
#include "lvgl.h"
#include "hex_codes.hpp"

static constexpr int32_t ARC_WIDTH = 35;

static constexpr int32_t RPM_ARC_SIZE = 542;
static constexpr int32_t RPM_ARC_ROTATION = 200;
static constexpr int32_t RPM_ARC_ANGLE = 140;
static constexpr int32_t RPM_MIN = 0;
static constexpr int32_t RPM_MAX = 7000;

static constexpr int32_t SPEEDO_ARC_SIZE = 672;
static constexpr int32_t SPEEDO_ARC_ROTATION = 190;
static constexpr int32_t SPEEDO_ANGLE = 160;
static constexpr int32_t SPEED_MIN = 0;
static constexpr int32_t SPEED_MAX = 130;

static constexpr int32_t FUEL_ARC_SIZE = 672;
static constexpr int32_t FUEL_ARC_ROTATION = 10;
static constexpr int32_t FUEL_ANGLE = 45;
static constexpr int32_t FUEL_MIN = 0;
static constexpr int32_t FUEL_MAX = 100;

static constexpr int32_t TEMP_ARC_SIZE = 672;
static constexpr int32_t TEMP_ARC_ROTATION = 125;
static constexpr int32_t TEMP_ANGLE = 45;
static constexpr int32_t TEMP_MIN = 0;
static constexpr int32_t TEMP_MAX = 100;

static void rpm_arc_event_cb(lv_event_t *event);
static void speedo_arc_event_cb(lv_event_t *event);
static void fuel_arc_event_cb(lv_event_t *event);
static void temp_arc_event_cb(lv_event_t *event);

static void debug_arc_anim(lv_obj_t *src, int32_t min, int32_t max);

extern "C" {
static void set_angle(void *obj, int32_t v);
}

inline auto RPM_arc() -> void {
    lv_obj_t *arc_src = lv_arc_create(lv_screen_active());
    lv_obj_t *arc_label = lv_label_create(lv_screen_active());

    // Object alignment and size adjustment
    lv_obj_center(arc_src);
    lv_obj_set_size(arc_src, RPM_ARC_SIZE, RPM_ARC_SIZE);
    lv_arc_set_rotation(arc_src, RPM_ARC_ROTATION);
    lv_arc_set_bg_angles(arc_src, 0, RPM_ARC_ANGLE);
    lv_arc_set_value(arc_src, 0);

    // Object style changes
    lv_obj_set_style_arc_width(arc_src, ARC_WIDTH, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_src, lv_color_hex(LAZER_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(arc_src, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc_src, false, LV_PART_INDICATOR);
    lv_obj_remove_style(arc_src, nullptr, LV_PART_KNOB);

    // Make it unclickable and give it an animation for testing
    lv_obj_clear_flag(arc_src, LV_OBJ_FLAG_CLICKABLE);
    debug_arc_anim(arc_src, RPM_MIN, RPM_MAX);

    // Set arc range (min/max values)
    lv_arc_set_range(arc_src, RPM_MIN, RPM_MAX);

    lv_obj_add_event_cb(arc_src, rpm_arc_event_cb, LV_EVENT_VALUE_CHANGED, arc_label);
    lv_obj_send_event(arc_src, LV_EVENT_VALUE_CHANGED, nullptr);
}

inline auto SPEED_arc() -> void {
    lv_obj_t *arc_src = lv_arc_create(lv_screen_active());
    lv_obj_t *arc_label = lv_label_create(lv_screen_active());

    // Object alignment and size adjustment
    lv_obj_center(arc_src);
    lv_obj_set_size(arc_src, SPEEDO_ARC_SIZE, SPEEDO_ARC_SIZE);
    lv_arc_set_rotation(arc_src, SPEEDO_ARC_ROTATION);
    lv_arc_set_bg_angles(arc_src, 0, SPEEDO_ANGLE);
    lv_arc_set_value(arc_src, 0);

    // Object style changes
    lv_obj_set_style_arc_width(arc_src, ARC_WIDTH, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_src, lv_color_hex(LAZER_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(arc_src, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc_src, false, LV_PART_INDICATOR);
    lv_obj_remove_style(arc_src, nullptr, LV_PART_KNOB);

    // Make it unclickable and give it an animation for testinglv_anim_t a;
    lv_obj_clear_flag(arc_src, LV_OBJ_FLAG_CLICKABLE);
    debug_arc_anim(arc_src, SPEED_MIN, SPEED_MAX);

    // Set arc range (min/max values)
    lv_arc_set_range(arc_src, SPEED_MIN, SPEED_MAX);

    lv_obj_add_event_cb(arc_src, speedo_arc_event_cb, LV_EVENT_VALUE_CHANGED, arc_label);
    lv_obj_send_event(arc_src, LV_EVENT_VALUE_CHANGED, nullptr);
}
inline auto FUEL_arc() -> void {
    lv_obj_t *arc_src = lv_arc_create(lv_screen_active());
    lv_obj_t *arc_label = lv_label_create(lv_screen_active());

    // Object alignment and size adjustment
    lv_obj_center(arc_src);
    lv_obj_set_size(arc_src, FUEL_ARC_SIZE, FUEL_ARC_SIZE);
    lv_arc_set_rotation(arc_src, FUEL_ARC_ROTATION);
    lv_arc_set_bg_angles(arc_src, 0, FUEL_ANGLE);
    lv_arc_set_value(arc_src, 0);

    // Object style changes
    lv_obj_set_style_arc_width(arc_src, ARC_WIDTH, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_src, lv_color_hex(LAZER_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(arc_src, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc_src, false, LV_PART_INDICATOR);
    lv_obj_remove_style(arc_src, nullptr, LV_PART_KNOB);

    // Make it unclickable and give it an animation for testinglv_anim_t a;
    lv_obj_clear_flag(arc_src, LV_OBJ_FLAG_CLICKABLE);
    debug_arc_anim(arc_src, FUEL_MIN, FUEL_MAX);

    // Set arc range (min/max values)
    lv_arc_set_range(arc_src, FUEL_MIN, FUEL_MAX);

    lv_obj_add_event_cb(arc_src, speedo_arc_event_cb, LV_EVENT_VALUE_CHANGED, arc_label);
    lv_obj_send_event(arc_src, LV_EVENT_VALUE_CHANGED, nullptr);
}
inline auto TEMP_arc() -> void {
    lv_obj_t *arc_src = lv_arc_create(lv_screen_active());
    lv_obj_t *arc_label = lv_label_create(lv_screen_active());

    // Object alignment and size adjustment
    lv_obj_center(arc_src);
    lv_obj_set_size(arc_src, TEMP_ARC_SIZE, TEMP_ARC_SIZE);
    lv_arc_set_rotation(arc_src, TEMP_ARC_ROTATION);
    lv_arc_set_bg_angles(arc_src, 0, TEMP_ANGLE);
    lv_arc_set_value(arc_src, 0);

    // Object style changes
    lv_obj_set_style_arc_width(arc_src, ARC_WIDTH, LV_PART_INDICATOR);
    lv_obj_set_style_arc_color(arc_src, lv_color_hex(LAZER_BLUE), LV_PART_INDICATOR);
    lv_obj_set_style_arc_opa(arc_src, LV_OPA_TRANSP, LV_PART_MAIN);
    lv_obj_set_style_arc_rounded(arc_src, false, LV_PART_INDICATOR);
    lv_obj_remove_style(arc_src, nullptr, LV_PART_KNOB);

    // Make it unclickable and give it an animation for testinglv_anim_t a;
    lv_obj_clear_flag(arc_src, LV_OBJ_FLAG_CLICKABLE);
    debug_arc_anim(arc_src, TEMP_MIN, TEMP_MAX);

    // Set arc range (min/max values)
    lv_arc_set_range(arc_src, TEMP_MIN, TEMP_MAX);

    lv_obj_add_event_cb(arc_src, speedo_arc_event_cb, LV_EVENT_VALUE_CHANGED, arc_label);
    lv_obj_send_event(arc_src, LV_EVENT_VALUE_CHANGED, nullptr);
}

extern "C" {

static void set_angle(void *obj, int32_t v) {
    lv_arc_set_value((lv_obj_t *)obj, v);
}
}

static void debug_arc_anim(lv_obj_t *src, int32_t min, int32_t max) {
    static constexpr int32_t ANIM_DUR = 2000;
    static constexpr int32_t ANIM_DELAY = 200;
    lv_anim_t anim;
    lv_anim_init(&anim);
    lv_anim_set_var(&anim, src);
    lv_anim_set_exec_cb(&anim, set_angle);
    lv_anim_set_duration(&anim, ANIM_DUR);
    lv_anim_set_repeat_count(&anim, LV_ANIM_REPEAT_INFINITE); /*Just for the demo*/
    lv_anim_set_repeat_delay(&anim, ANIM_DELAY);
    lv_anim_set_values(&anim, min, max);
    lv_anim_start(&anim);
}

static void rpm_arc_event_cb(lv_event_t *event) {
    auto *arc_src = (lv_obj_t *)lv_event_get_target(event);
    auto *label = (lv_obj_t *)lv_event_get_user_data(event);

    lv_label_set_text_fmt(label, "%d", lv_arc_get_value(arc_src));
}

static void speedo_arc_event_cb(lv_event_t *event) {
    auto *arc_src = (lv_obj_t *)lv_event_get_target(event);
    auto *label = (lv_obj_t *)lv_event_get_user_data(event);

    lv_label_set_text_fmt(label, "%d", lv_arc_get_value(arc_src));
}

static void fuel_arc_event_cb(lv_event_t *event) {
    auto *arc_src = (lv_obj_t *)lv_event_get_target(event);
    auto *label = (lv_obj_t *)lv_event_get_user_data(event);

    lv_label_set_text_fmt(label, "%d", lv_arc_get_value(arc_src));
}

static void temp_arc_event_cb(lv_event_t *event) {
    auto *arc_src = (lv_obj_t *)lv_event_get_target(event);
    auto *label = (lv_obj_t *)lv_event_get_user_data(event);

    lv_label_set_text_fmt(label, "%d", lv_arc_get_value(arc_src));
}

#endif
