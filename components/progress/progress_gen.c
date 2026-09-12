/**
 * @file progress_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "progress_gen.h"
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

lv_obj_t * progress_create(lv_obj_t * parent, lv_subject_t * value)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_indicator;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_base);
        lv_style_init(&style_indicator);

        lv_style_set_bg_color(&style_base, CONST_ON_ACCENT_GLOBAL);
        lv_style_set_bg_color(&style_indicator, CONST_ACCENT_BRIGHT_GLOBAL);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * bar_0 = bar_create(parent);
        lv_obj_set_name_static(bar_0, "progress_#");
        lv_obj_set_width(bar_0, 403);
        lv_obj_set_height(bar_0, 38);
        lv_bar_bind_value(bar_0, value);

        lv_obj_add_style(bar_0, &style_base, 0);
        lv_obj_add_style(bar_0, &style_indicator, LV_PART_INDICATOR);

        the_root = bar_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

