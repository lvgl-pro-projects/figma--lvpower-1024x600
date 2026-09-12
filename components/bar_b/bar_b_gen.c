/**
 * @file bar_b_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "bar_b_gen.h"
#include "../../lvpower.h"

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

lv_obj_t * bar_b_create(lv_obj_t * parent, int32_t value, lv_style_t * bartone)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_base);
        lv_style_init(&style_indicator);

        lv_style_set_bg_color(&style_base, CONST_TRACK_GLOBAL);
        lv_style_set_radius(&style_base, 32767);
        lv_style_set_bg_color(&style_indicator, CONST_ACCENT_GLOBAL);
        lv_style_set_radius(&style_indicator, 32767);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * bar_0 = bar_create(parent);
        lv_obj_set_name_static(bar_0, "bar_b_#");
        lv_obj_set_width(bar_0, 158);
        lv_obj_set_height(bar_0, 8);
        lv_bar_set_value(bar_0, value, false);

        lv_obj_add_style(bar_0, &style_base, 0);
        lv_obj_add_style(bar_0, &style_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(bar_0, bartone, LV_PART_INDICATOR);

        the_root = bar_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

