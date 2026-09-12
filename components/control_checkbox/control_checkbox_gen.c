/**
 * @file control_checkbox_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "control_checkbox_gen.h"
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

lv_obj_t * control_checkbox_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_box;
    static lv_style_t style_checkbox_checked;
    static lv_style_t style_glyph;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_box);
        lv_style_init(&style_checkbox_checked);
        lv_style_init(&style_glyph);

        lv_style_set_border_color(&style_box, CONST_BORDER_GLOBAL);
        lv_style_set_border_width(&style_box, 2);
        lv_style_set_radius(&style_box, 10);
        lv_style_set_width(&style_box, 24);
        lv_style_set_height(&style_box, 24);
        lv_style_set_bg_color(&style_box, CONST_SURFACE_CARD_GLOBAL);
        lv_style_set_bg_opa(&style_box, (255 * 100 / 100));
        lv_style_set_bg_color(&style_checkbox_checked, CONST_ACCENT_GLOBAL);
        lv_style_set_border_width(&style_checkbox_checked, 1);
        lv_style_set_bg_image_src(&style_glyph, image_vec_263_32);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * checkbox_0 = checkbox_create(parent);
        lv_obj_set_name_static(checkbox_0, "control_checkbox_#");
        lv_checkbox_set_text(checkbox_0, "");

        lv_obj_add_style(checkbox_0, &style_box, 0);
        lv_obj_add_style(checkbox_0, &style_checkbox_checked, LV_STATE_CHECKED);
        lv_obj_add_style(checkbox_0, &style_glyph, LV_STATE_CHECKED);

        the_root = checkbox_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

