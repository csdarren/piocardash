#pragma once
#ifndef LOAD_ARC_HPP
#define LOAD_ARC_HPP
#include "lvgl.h"
#include "hex_codes.hpp"

static constexpr int SIZE_W = 350;
static constexpr int SIZE_H = 370;
static constexpr int ROTATION = 135;
static constexpr int TOTAL_ANGLE = 270;

static void value_changed_event_cb(lv_event_t *event);

inline auto load_arc_meter() -> void {
    lv_obj_t *arc_label = lv_label_create(lv_screen_active());

    lv_obj_t *arc_src = lv_arc_create(lv_screen_active());
    lv_obj_set_size(arc_src, SIZE_W, SIZE_H);
    lv_arc_set_rotation(arc_src, ROTATION);
    lv_obj_set_style_arc_color(arc_src, lv_color_hex(LAZER_BLUE), LV_PART_INDICATOR);
    lv_arc_set_bg_angles(arc_src, 0, TOTAL_ANGLE);
    lv_arc_set_value(arc_src, 0);
    lv_obj_center(arc_src);
    lv_obj_add_event_cb(arc_src, value_changed_event_cb, LV_EVENT_VALUE_CHANGED, arc_label);

    lv_obj_send_event(arc_src, LV_EVENT_VALUE_CHANGED, nullptr);
}

static void value_changed_event_cb(lv_event_t *event) {
    auto *arc_src = (lv_obj_t *)lv_event_get_target(event);
    auto *label = (lv_obj_t *)lv_event_get_user_data(event);

    lv_label_set_text_fmt(label, "%d", lv_arc_get_value(arc_src));
    lv_arc_rotate_obj_to_angle(arc_src, label, 25);
}

#endif
