#pragma once
#ifndef LOAD_C_IMG_HPP
#define LOAD_C_IMG_HPP

#include "lvgl.h"
#include "hex_codes.hpp"

LV_IMG_DECLARE(warning);
LV_IMG_DECLARE(MiniDash_v1);

inline auto load_images() -> void {
    lv_obj_t *minidash_src = lv_img_create(lv_screen_active());

    lv_img_set_src(minidash_src, &MiniDash_v1);

    lv_obj_center(minidash_src);

    lv_img_set_zoom(minidash_src, LV_ZOOM_NONE);
}

#endif
