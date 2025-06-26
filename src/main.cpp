/**
 ******************************************************************************
 * @file    main.c
 * @author  Ac6
 * @version V1.0
 * @date    01-December-2013
 * @brief   Default main function.
 ******************************************************************************
 */

#include "lv_init.h"

#include "app_hal.h"
#include "widgets.hpp"

auto main() -> int {
    // This must come first
    lv_init();

    // Must be before hal_loop, and any widgets displayed
    hal_setup();

    // Place widgets here
    // lv_demo_widgets();

    lv_start();
    lv_start2();

    // Must be last
    hal_loop();
}
