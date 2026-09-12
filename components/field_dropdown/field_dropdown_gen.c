/**
 * @file field_dropdown_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "field_dropdown_gen.h"
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

lv_obj_t * field_dropdown_create(lv_obj_t * parent, const char * options, int32_t selected)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_main;
    static lv_style_t style_list;
    static lv_style_t style_list_selected;
    static lv_style_t style_dropdown_checked;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_main);
        lv_style_init(&style_list);
        lv_style_init(&style_list_selected);
        lv_style_init(&style_dropdown_checked);

        lv_style_set_bg_color(&style_main, CONST_SURFACE_CARD_GLOBAL);
        lv_style_set_bg_opa(&style_main, (255 * 100 / 100));
        lv_style_set_border_color(&style_main, CONST_BORDER_GLOBAL);
        lv_style_set_border_width(&style_main, 1);
        lv_style_set_radius(&style_main, 10);
        lv_style_set_text_color(&style_main, CONST_TEXT_PRIMARY_GLOBAL);
        lv_style_set_text_font(&style_main, font_gabarito_regular_15);
        lv_style_set_pad_hor(&style_main, 12);
        lv_style_set_pad_ver(&style_main, 0);
        lv_style_set_bg_color(&style_list, CONST_SURFACE_CARD_GLOBAL);
        lv_style_set_bg_opa(&style_list, (255 * 100 / 100));
        lv_style_set_border_color(&style_list, CONST_BORDER_GLOBAL);
        lv_style_set_border_width(&style_list, 1);
        lv_style_set_radius(&style_list, 10);
        lv_style_set_pad_all(&style_list, 8);
        lv_style_set_text_line_space(&style_list, 18);
        lv_style_set_translate_y(&style_list, 8);
        lv_style_set_text_color(&style_list, CONST_TEXT_PRIMARY_GLOBAL);
        lv_style_set_text_font(&style_list, font_gabarito_regular_15);
        lv_style_set_bg_color(&style_list_selected, CONST_TINT_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_list_selected, (255 * 100 / 100));
        lv_style_set_text_color(&style_list_selected, CONST_ACCENT_GLOBAL);
        lv_style_set_border_color(&style_dropdown_checked, CONST_ACCENT_GLOBAL);
        lv_style_set_border_width(&style_dropdown_checked, 2);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * dropdown_0 = dropdown_create(parent);
        lv_obj_set_name_static(dropdown_0, "field_dropdown_#");
        lv_obj_set_width(dropdown_0, 312);
        lv_obj_set_height(dropdown_0, 44);
        lv_dropdown_set_symbol(dropdown_0, image_vec_263_263);
        lv_dropdown_set_options(dropdown_0, options);
        lv_dropdown_set_selected(dropdown_0, selected);

        lv_obj_add_style(dropdown_0, &style_main, 0);
        lv_obj_add_style(dropdown_0, &style_dropdown_checked, LV_STATE_CHECKED);
        lv_obj_t * lv_dropdown_list_0 = lv_dropdown_get_list(dropdown_0);
        lv_obj_add_style(lv_dropdown_list_0, &style_list, 0);
        lv_obj_add_style(lv_dropdown_list_0, &style_list_selected, LV_PART_SELECTED | LV_STATE_CHECKED);

        the_root = dropdown_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

