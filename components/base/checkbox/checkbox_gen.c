/**
 * @file checkbox_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "checkbox_gen.h"
#include "../../../lvpower.h"

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

/***********************
 *  STATIC VARIABLES
 **********************/

/***********************
 *  STATIC PROTOTYPES
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * checkbox_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_main_checked;
    static lv_style_t style_indicator_off;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);
        lv_style_init(&style_main_checked);
        lv_style_init(&style_indicator_off);

        lv_style_set_width(&style_main, 20);
        lv_style_set_height(&style_main, 20);
        lv_style_set_bg_color(&style_main, CONST_BASELIB_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_main, (255 * 24 / 100));
        lv_style_set_border_color(&style_main, CONST_BASELIB_ACCENT_GLOBAL);
        lv_style_set_border_width(&style_main, 2);
        lv_style_set_radius(&style_main, CONST_BASELIB_RADIUS_GLOBAL);
        lv_style_set_pad_all(&style_main, 0);
        lv_style_set_bg_color(&style_main_checked, CONST_BASELIB_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_main_checked, (255 * 100 / 100));
        lv_style_set_bg_opa(&style_indicator_off, 0);
        lv_style_set_border_width(&style_indicator_off, 0);
        lv_style_set_pad_all(&style_indicator_off, 0);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_checkbox_0 = lv_checkbox_create(parent);
        lv_obj_set_name_static(lv_checkbox_0, "checkbox_#");

        lv_obj_remove_style_all(lv_checkbox_0);
        lv_obj_add_style(lv_checkbox_0, &style_main, 0);
        lv_obj_add_style(lv_checkbox_0, &style_main_checked, LV_STATE_CHECKED);
        lv_obj_add_style(lv_checkbox_0, &style_indicator_off, LV_PART_INDICATOR);

        the_root = lv_checkbox_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

