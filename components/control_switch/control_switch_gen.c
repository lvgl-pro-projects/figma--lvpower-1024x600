/**
 * @file control_switch_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "control_switch_gen.h"
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

lv_obj_t * control_switch_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_indicator;
    static lv_style_t style_knob;
    static lv_style_t style_switch_indicator_checked;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_base);
        lv_style_init(&style_indicator);
        lv_style_init(&style_knob);
        lv_style_init(&style_switch_indicator_checked);

        lv_style_set_bg_color(&style_base, CONST_CONTROL_OFF_GLOBAL);
        lv_style_set_bg_opa(&style_base, (255 * 100 / 100));
        lv_style_set_radius(&style_base, 32767);
        lv_style_set_radius(&style_indicator, 32767);
        lv_style_set_bg_color(&style_knob, CONST_ON_ACCENT_GLOBAL);
        lv_style_set_radius(&style_knob, 32767);
        lv_style_set_bg_color(&style_switch_indicator_checked, CONST_ACCENT_GLOBAL);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * switch_0 = switch_create(parent);
        lv_obj_set_name_static(switch_0, "control_switch_#");
        lv_obj_set_width(switch_0, 52);
        lv_obj_set_height(switch_0, 30);

        lv_obj_add_style(switch_0, &style_base, 0);
        lv_obj_add_style(switch_0, &style_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(switch_0, &style_knob, LV_PART_KNOB);
        lv_obj_add_style(switch_0, &style_switch_indicator_checked, LV_PART_INDICATOR | LV_STATE_CHECKED);

        the_root = switch_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

