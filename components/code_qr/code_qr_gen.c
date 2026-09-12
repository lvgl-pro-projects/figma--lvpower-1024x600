/**
 * @file code_qr_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "code_qr_gen.h"
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

lv_obj_t * code_qr_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * card_0 = card_create(parent);
        lv_obj_set_name_static(card_0, "code_qr_#");
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_main_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(card_0, 8, 0);
        lv_obj_set_style_pad_column(card_0, 0, 0);
        lv_obj_set_width(card_0, LV_SIZE_CONTENT);
        lv_obj_set_height(card_0, LV_SIZE_CONTENT);
        lv_obj_set_style_bg_color(card_0, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_border_color(card_0, CONST_BORDER_GLOBAL, 0);
        lv_obj_set_style_border_width(card_0, 1, 0);
        lv_obj_set_style_radius(card_0, CONST_RADIUS_MD_GLOBAL, 0);

        lv_obj_t * image_0 = image_create(card_0);
        lv_obj_set_width(image_0, 64);
        lv_obj_set_height(image_0, 64);
        lv_image_set_src(image_0, image_qr_receipt_64x64);
        lv_obj_set_style_radius(image_0, CONST_RADIUS_SM_GLOBAL, 0);

        the_root = card_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

