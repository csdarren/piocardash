#pragma once
#ifndef LOAD_C_IMG_HPP
#define LOAD_C_IMG_HPP

#include "lvgl.h"
#include "hex_codes.hpp"

LV_IMG_DECLARE(minifg);
LV_IMG_DECLARE(minibg);
LV_IMG_DECLARE(warning);

inline auto load_images() -> void {
    lv_obj_t *warning_icon = lv_img_create(lv_screen_active());
    lv_img_set_src(warning_icon, &warning);
    lv_obj_set_pos(warning_icon, 400, 200);
    lv_img_set_zoom(warning_icon, 32);

    // Load both background and foreground for cluster
    lv_obj_t *minifg_src = lv_img_create(lv_screen_active());
    lv_obj_t *minibg_src = lv_img_create(lv_screen_active());

    lv_img_set_src(minifg_src, &minifg);
    lv_img_set_src(minibg_src, &minifg);

    lv_obj_center(minifg_src);
    lv_obj_center(minibg_src);

    lv_img_set_zoom(minifg_src, LV_ZOOM_NONE);
    lv_img_set_zoom(minibg_src, LV_ZOOM_NONE);
}

#endif
