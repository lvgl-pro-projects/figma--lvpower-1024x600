/**
 * @file chip_header_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "chip_header_gen.h"
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

lv_obj_t * chip_header_create(lv_obj_t * parent, lv_style_t * tone, const char * chip_text)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * card_0 = card_create(parent);
        lv_obj_set_name_static(card_0, "chip_header_#");
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_left(card_0, 8, 0);
        lv_obj_set_style_pad_right(card_0, 12, 0);
        lv_obj_set_style_pad_ver(card_0, 4, 0);
        lv_obj_set_style_pad_column(card_0, 8, 0);
        lv_obj_set_width(card_0, LV_SIZE_CONTENT);
        lv_obj_set_height(card_0, LV_SIZE_CONTENT);
        lv_obj_set_style_bg_color(card_0, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_border_color(card_0, CONST_BORDER_GLOBAL, 0);
        lv_obj_set_style_border_width(card_0, 1, 0);
        lv_obj_set_style_radius(card_0, CONST_RADIUS_PILL_GLOBAL, 0);

        lv_obj_t * card_1 = card_create(card_0);
        lv_obj_set_width(card_1, 7);
        lv_obj_set_height(card_1, 7);
        lv_obj_set_style_radius(card_1, 32767, 0);
        lv_obj_add_style(card_1, tone, 0);

        lv_obj_t * label_0 = label_create(card_0);
        lv_label_set_translation_tag(label_0, chip_text);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);
        lv_obj_add_style(label_0, &style_chip_global, 0);

        the_root = card_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

