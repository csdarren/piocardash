#pragma once
#ifndef LOAD_C_IMG_HPP
#define LOAD_C_IMG_HPP

#include "lvgl.h"
#include "hex_codes.hpp"

LV_IMG_DECLARE(MINI_logo)
LV_IMG_DECLARE(warning);

inline auto load_images() -> void {
    lv_obj_t *warning_icon = lv_img_create(lv_screen_active());
    lv_img_set_src(warning_icon, &warning);
    lv_obj_set_pos(warning_icon, 400, 200);
    lv_img_set_zoom(warning_icon, 32);

    lv_obj_t *mini_src = lv_img_create(lv_screen_active());
    lv_img_set_src(mini_src, &MINI_logo);
    lv_obj_set_style_img_recolor(mini_src, lv_color_hex(LAZER_BLUE), LV_PART_MAIN);
    lv_obj_set_style_img_recolor_opa(mini_src, LV_OPA_COVER, LV_PART_MAIN);
    lv_obj_center(mini_src);
    lv_img_set_zoom(mini_src, LV_ZOOM_NONE);
}

#endif
