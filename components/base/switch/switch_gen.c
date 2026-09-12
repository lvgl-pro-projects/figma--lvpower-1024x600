/**
 * @file switch_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "switch_gen.h"
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

lv_obj_t * switch_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_indicator_checked;
    static lv_style_t style_knob;
    static lv_style_t style_knob_checked;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);
        lv_style_init(&style_indicator_checked);
        lv_style_init(&style_knob);
        lv_style_init(&style_knob_checked);

        lv_style_set_bg_color(&style_main, CONST_BASELIB_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_main, (255 * 24 / 100));
        lv_style_set_radius(&style_main, 32767);
        lv_style_set_anim_duration(&style_main, 120);
        lv_style_set_bg_color(&style_indicator_checked, CONST_BASELIB_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_indicator_checked, (255 * 100 / 100));
        lv_style_set_bg_color(&style_knob, CONST_BASELIB_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_knob, (255 * 100 / 100));
        lv_style_set_radius(&style_knob, 32767);
        lv_style_set_pad_all(&style_knob, -5);
        lv_style_set_bg_color(&style_knob_checked, CONST_BASELIB_ACCENT_TEXT_GLOBAL);
        lv_style_set_bg_opa(&style_knob_checked, (255 * 100 / 100));

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_switch_0 = lv_switch_create(parent);
        lv_obj_set_name_static(lv_switch_0, "switch_#");

        lv_obj_remove_style_all(lv_switch_0);
        lv_obj_add_style(lv_switch_0, &style_main, 0);
        lv_obj_add_style(lv_switch_0, &style_knob, LV_PART_KNOB);
        lv_obj_add_style(lv_switch_0, &style_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);
        lv_obj_add_style(lv_switch_0, &style_knob_checked, LV_PART_KNOB | LV_STATE_CHECKED);

        the_root = lv_switch_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

