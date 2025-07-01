/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "lvgl.h"

#include "app_hal.h"
#include "load_c_img.hpp"
#include "widgets.hpp"

auto main() -> int {
    // This must come first
    lv_init();

    // Must be before hal_loop, and any widgets displayed
    hal_setup();

    // Place widgets here
    // lv_demo_widgets();

    lv_obj_set_style_bg_color(lv_screen_active(), lv_color_hex(0x000000), LV_PART_MAIN);
    load_images();
    load_arc_meter();

    // Must be last
    hal_loop();
}
