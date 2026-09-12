/**
 * @file button_icon_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "button_icon_gen.h"
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

lv_obj_t * button_icon_create(lv_obj_t * parent, const void * icon, bool pressed)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_pressed;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_pressed);

        lv_style_set_bg_color(&style_pressed, CONST_BORDER_GLOBAL);
        lv_style_set_bg_opa(&style_pressed, 255);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * button_0 = button_create(parent);
        lv_obj_set_name_static(button_0, "button_icon_#");
        lv_obj_set_flex_flow(button_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(button_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(button_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(button_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(button_0, 0, 0);
        lv_obj_set_style_pad_column(button_0, 0, 0);
        lv_obj_set_width(button_0, 44);
        lv_obj_set_height(button_0, 44);
        lv_obj_set_style_bg_color(button_0, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_border_color(button_0, CONST_BORDER_GLOBAL, 0);
        lv_obj_set_style_border_width(button_0, 1, 0);
        lv_obj_set_style_radius(button_0, CONST_RADIUS_PILL_GLOBAL, 0);
        lv_obj_set_style_clip_corner(button_0, true, 0);
        lv_obj_set_state(button_0, LV_STATE_PRESSED, pressed);

        lv_obj_add_style(button_0, &style_pressed, LV_STATE_PRESSED);
        lv_obj_t * image_0 = image_create(button_0);
        lv_obj_set_width(image_0, 22);
        lv_obj_set_height(image_0, 22);
        lv_image_set_src(image_0, icon);

        the_root = button_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

