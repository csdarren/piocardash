#pragma once
#include <iostream>
#include "core/lv_obj.h"
#include "display/lv_display.h"
#include "misc/lv_area.h"
#include "widgets/button/lv_button.h"
#include "widgets/label/lv_label.h"
#ifndef WIDGETS_HPP
#define WIDGETS_HPP

// auto lv_dashboard() -> void {
//     lv_obj_t dash = lv_obj_create(parent)
//         lv_obj_t = lv_obj_create()
// }

static constexpr uint32_t LAZER_BLUE = 0x1D75AB;
static constexpr uint32_t WHITE = 0xffffff;

static void btn_event(lv_event_t *event) {
    lv_event_code_t code = lv_event_get_code(event);
    lv_obj_t *btn = lv_event_get_target_obj(event);
    if (code == LV_EVENT_CLICKED) {
        static uint8_t count = 0;
        count++;

        lv_obj_t *label = lv_obj_get_child(btn, 0);
        lv_label_set_text_fmt(label, "Button: %d", count);
    }
}

inline void lv_start() {
    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(LAZER_BLUE), LV_PART_MAIN);

    lv_obj_t *label = lv_label_create(lv_screen_active());
    lv_label_set_text(label, "Blue!");
    lv_obj_set_style_text_color(label, lv_color_hex(WHITE), LV_PART_MAIN);
    lv_obj_align(label, LV_ALIGN_CENTER, 0, 0);
}

inline void lv_start2() {
    lv_obj_t *btn = lv_button_create(lv_screen_active());
    lv_obj_set_pos(btn, 10, 10);
    lv_obj_set_size(btn, 100, 50);
    lv_obj_add_event_cb(btn, btn_event, LV_EVENT_ALL, nullptr);

    lv_obj_t *label = lv_label_create(btn);
    lv_label_set_text(label, "Btn");
    lv_obj_center(label);
    int32_t width = lv_obj_get_width(lv_screen_active());
    int32_t height = lv_obj_get_height(lv_screen_active());
    lv_obj_t *size_label = lv_label_create(lv_screen_active());
    char buf[64];
    snprintf(buf, sizeof(buf), "width: %d height: %d", width, height);
    lv_label_set_text(size_label, buf);
    lv_obj_set_style_text_color(size_label, lv_color_hex(WHITE), LV_PART_MAIN);
    lv_obj_align(size_label, LV_ALIGN_LEFT_MID, 0, 0);
}

#endif
