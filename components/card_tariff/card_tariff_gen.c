/**
 * @file card_tariff_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "card_tariff_gen.h"
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

lv_obj_t * card_tariff_create(lv_obj_t * parent, const void * icon, const char * tier, const char * price, const char * detail, const char * unit)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * card_0 = card_create(parent);
        lv_obj_set_name_static(card_0, "card_tariff_#");
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(card_0, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        lv_obj_set_style_pad_hor(card_0, 16, 0);
        lv_obj_set_style_pad_ver(card_0, 12, 0);
        lv_obj_set_style_pad_row(card_0, 0, 0);
        lv_obj_set_width(card_0, 190);
        lv_obj_set_height(card_0, 134);
        lv_obj_set_style_bg_color(card_0, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_radius(card_0, CONST_RADIUS_LG_GLOBAL, 0);
        lv_obj_set_style_shadow_width(card_0, 24, 0);
        lv_obj_set_style_shadow_offset_y(card_0, 8, 0);
        lv_obj_set_style_shadow_spread(card_0, -6, 0);
        lv_obj_set_style_shadow_color(card_0, lv_color_hex(0x141C22), 0);
        lv_obj_set_style_shadow_opa(card_0, 26, 0);

        lv_obj_t * row_0 = row_create(card_0, 0, 0, 0, 0, 8, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_0, lv_pct(100));
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * image_0 = image_create(row_0);
        lv_obj_set_width(image_0, 16);
        lv_obj_set_height(image_0, 16);
        lv_image_set_src(image_0, icon);

        lv_obj_t * label_0 = label_create(row_0);
        lv_label_set_translation_tag(label_0, tier);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);
        lv_obj_add_style(label_0, &style_body_strong_global, 0);

        lv_obj_t * row_1 = row_create(card_0, 0, 0, 0, 0, 4, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_1, lv_pct(100));
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * label_1 = label_create(row_1);
        lv_obj_set_height(label_1, 41);
        lv_label_set_text(label_1, price);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_PRIMARY_GLOBAL, 0);
        lv_obj_add_style(label_1, &style_stat_lg_global, 0);

        lv_obj_t * row_2 = row_create(row_1, 0, 0, 0, 6, 1, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_2, LV_SIZE_CONTENT);
        lv_obj_set_height(row_2, LV_SIZE_CONTENT);
        lv_obj_t * label_2 = label_create(row_2);
        lv_obj_set_height(label_2, 18);
        lv_label_set_text(label_2, "/");
        lv_obj_set_style_text_color(label_2, CONST_ACCENT_GLOBAL, 0);
        lv_obj_add_style(label_2, &style_body_global, 0);

        lv_obj_t * label_3 = label_create(row_2);
        lv_obj_set_height(label_3, 18);
        lv_label_set_text(label_3, unit);
        lv_obj_set_style_text_color(label_3, CONST_ACCENT_GLOBAL, 0);
        lv_obj_add_style(label_3, &style_body_global, 0);

        lv_obj_t * label_4 = label_create(card_0);
        lv_obj_set_height(label_4, 14);
        lv_label_set_translation_tag(label_4, detail);
        lv_obj_set_style_text_color(label_4, CONST_TEXT_SECONDARY_GLOBAL, 0);
        lv_obj_add_style(label_4, &style_caption_global, 0);

        the_root = card_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

