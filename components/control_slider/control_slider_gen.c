/**
 * @file control_slider_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "control_slider_gen.h"
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

lv_obj_t * control_slider_create(lv_obj_t * parent, int32_t value)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_base;
    static lv_style_t style_indicator;
    static lv_style_t style_knob;
    static lv_style_t style_slider_knob_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_base);
        lv_style_init(&style_indicator);
        lv_style_init(&style_knob);
        lv_style_init(&style_slider_knob_pressed);

        lv_style_set_bg_color(&style_base, CONST_TRACK_GLOBAL);
        lv_style_set_radius(&style_base, 32767);
        lv_style_set_bg_color(&style_indicator, CONST_ACCENT_GLOBAL);
        lv_style_set_radius(&style_indicator, 32767);
        lv_style_set_transform_width(&style_knob, 10);
        lv_style_set_transform_height(&style_knob, 10);
        lv_style_set_bg_color(&style_knob, CONST_SURFACE_CARD_GLOBAL);
        lv_style_set_border_color(&style_knob, CONST_BORDER_GLOBAL);
        lv_style_set_border_width(&style_knob, 2);
        lv_style_set_radius(&style_knob, 32767);
        lv_style_set_border_color(&style_slider_knob_pressed, CONST_ACCENT_GLOBAL);
        lv_style_set_border_width(&style_slider_knob_pressed, 3);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * slider_0 = slider_create(parent);
        lv_obj_set_name_static(slider_0, "control_slider_#");
        lv_obj_set_width(slider_0, 404);
        lv_obj_set_height(slider_0, 8);
        lv_slider_set_value(slider_0, value, false);

        lv_obj_add_style(slider_0, &style_base, 0);
        lv_obj_add_style(slider_0, &style_indicator, LV_PART_INDICATOR);
        lv_obj_add_style(slider_0, &style_knob, LV_PART_KNOB);
        lv_obj_add_style(slider_0, &style_slider_knob_pressed, LV_PART_KNOB | LV_STATE_PRESSED);

        the_root = slider_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

