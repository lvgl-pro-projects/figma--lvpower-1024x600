/**
 * @file card_bay_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "card_bay_gen.h"
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

lv_obj_t * card_bay_create(lv_obj_t * parent, const char * bay_name, const char * value_card_bay, const char * unit, const char * meta, lv_subject_t * value_card_bay_2, lv_subject_t * bar, const char * chip_text, lv_style_t * tone, lv_style_t * tone_dot, lv_style_t * tone_label, lv_style_t * bartone)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * card_0 = card_create(parent);
        lv_obj_set_name_static(card_0, "card_bay_#");
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(card_0, LV_FLEX_ALIGN_SPACE_BETWEEN, 0);
        lv_obj_set_style_pad_hor(card_0, 16, 0);
        lv_obj_set_style_pad_ver(card_0, 12, 0);
        lv_obj_set_style_pad_row(card_0, 0, 0);
        lv_obj_set_width(card_0, 230);
        lv_obj_set_height(card_0, 148);
        lv_obj_set_style_bg_color(card_0, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_border_color(card_0, CONST_BORDER_GLOBAL, 0);
        lv_obj_set_style_border_width(card_0, 1, 0);
        lv_obj_set_style_radius(card_0, CONST_RADIUS_MD_GLOBAL, 0);
        lv_obj_set_style_shadow_width(card_0, 18, 0);
        lv_obj_set_style_shadow_offset_y(card_0, 6, 0);
        lv_obj_set_style_shadow_spread(card_0, -6, 0);
        lv_obj_set_style_shadow_color(card_0, lv_color_hex(0x141C22), 0);
        lv_obj_set_style_shadow_opa(card_0, 20, 0);

        lv_obj_t * row_0 = row_create(card_0, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_0, lv_pct(100));
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(row_0);
        lv_label_set_text(label_0, bay_name);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);
        lv_obj_add_style(label_0, &style_font_subtitle_global, 0);

        chip_card_create(row_0, tone, tone_dot, tone_label, chip_text);

        lv_obj_t * column_0 = column_create(card_0, 0, 0, 0, 0, 8, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_0, lv_pct(100));
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_t * row_1 = row_create(column_0, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_1, lv_pct(100));
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * row_2 = row_create(row_1, 0, 0, 0, 0, 2, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_2, LV_SIZE_CONTENT);
        lv_obj_set_height(row_2, LV_SIZE_CONTENT);
        lv_obj_t * label_1 = label_create(row_2);
        lv_obj_set_height(label_1, 24);
        lv_label_bind_text(label_1, value_card_bay_2, "%d");
        lv_obj_set_style_text_color(label_1, CONST_TEXT_PRIMARY_GLOBAL, 0);
        lv_obj_add_style(label_1, &style_stat_xs_global, 0);

        lv_obj_t * label_2 = label_create(row_2);
        lv_obj_set_height(label_2, 14);
        lv_label_set_text(label_2, unit);
        lv_obj_set_style_text_color(label_2, CONST_TEXT_SECONDARY_GLOBAL, 0);
        lv_obj_add_style(label_2, &style_caption_global, 0);

        lv_obj_t * label_3 = label_create(row_1);
        lv_obj_set_height(label_3, 14);
        lv_label_set_text(label_3, meta);
        lv_obj_set_style_text_color(label_3, CONST_TEXT_TERTIARY_GLOBAL, 0);
        lv_obj_add_style(label_3, &style_caption_global, 0);

        lv_obj_t * bar_b_0 = bar_b_create(column_0, 59, bartone);
        lv_obj_set_width(bar_b_0, lv_pct(100));
        lv_bar_bind_value(bar_b_0, bar);

        the_root = card_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

