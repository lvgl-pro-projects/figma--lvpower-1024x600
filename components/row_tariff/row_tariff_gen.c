/**
 * @file row_tariff_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "row_tariff_gen.h"
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

lv_obj_t * row_tariff_create(lv_obj_t * parent, const void * icon, const char * tier, const char * detail, const char * price, const char * unit, bool pressed, bool checked)
{
    LV_TRACE_OBJ_CREATE("begin");

    static lv_style_t style_pressed;
    static lv_style_t style_checked;
    static lv_style_t style_desc_0_checked;

    static bool style_inited = false;

    if (!style_inited) {
        /*Init all styles*/
        lv_style_init(&style_pressed);
        lv_style_init(&style_checked);
        lv_style_init(&style_desc_0_checked);

        lv_style_set_bg_color(&style_pressed, CONST_DIVIDER_GLOBAL);
        lv_style_set_bg_opa(&style_pressed, 255);
        lv_style_set_bg_color(&style_checked, CONST_TINT_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_checked, 255);
        lv_style_set_border_color(&style_checked, CONST_ACCENT_GLOBAL);
        lv_style_set_border_width(&style_checked, 2);
        lv_style_set_border_opa(&style_checked, 255);
        lv_style_set_bg_color(&style_desc_0_checked, CONST_ACCENT_GLOBAL);
        lv_style_set_bg_opa(&style_desc_0_checked, 255);
        lv_style_set_border_width(&style_desc_0_checked, 2);
        lv_style_set_border_opa(&style_desc_0_checked, 0);

        style_inited = true;
    }


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * card_0 = card_create(parent);
        lv_obj_set_name_static(card_0, "row_tariff_#");
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_hor(card_0, 16, 0);
        lv_obj_set_style_pad_ver(card_0, 12, 0);
        lv_obj_set_style_pad_column(card_0, 12, 0);
        lv_obj_set_width(card_0, 440);
        lv_obj_set_height(card_0, 64);
        lv_obj_set_style_bg_color(card_0, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_radius(card_0, CONST_RADIUS_MD_GLOBAL, 0);
        lv_obj_set_style_shadow_width(card_0, 24, 0);
        lv_obj_set_style_shadow_offset_y(card_0, 8, 0);
        lv_obj_set_style_shadow_spread(card_0, -6, 0);
        lv_obj_set_style_shadow_color(card_0, lv_color_hex(0x141C22), 0);
        lv_obj_set_style_shadow_opa(card_0, 26, 0);
        lv_obj_set_style_border_width(card_0, 2, 0);
        lv_obj_set_style_border_opa(card_0, 0, 0);
        lv_obj_set_flag(card_0, LV_OBJ_FLAG_CHECKABLE, true);
        lv_obj_set_radio_button(card_0, true);
        lv_obj_set_flag(card_0, LV_OBJ_FLAG_STATE_TRICKLE, true);
        lv_obj_set_state(card_0, LV_STATE_PRESSED, pressed);
        lv_obj_set_state(card_0, LV_STATE_CHECKED, checked);

        lv_obj_add_style(card_0, &style_pressed, LV_STATE_PRESSED);
        lv_obj_add_style(card_0, &style_checked, LV_STATE_CHECKED);
        lv_obj_t * image_0 = image_create(card_0);
        lv_obj_set_width(image_0, 20);
        lv_obj_set_height(image_0, 20);
        lv_image_set_src(image_0, icon);

        lv_obj_t * column_0 = column_create(card_0, 0, 0, 0, 0, 2, 1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_0, 0);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_set_flag(column_0, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(column_0, LV_OBJ_FLAG_EVENT_BUBBLE, true);
        lv_obj_t * label_0 = label_create(column_0);
        lv_obj_set_height(label_0, 18);
        lv_label_set_translation_tag(label_0, tier);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);
        lv_obj_add_style(label_0, &style_body_strong_global, 0);

        lv_obj_t * label_1 = label_create(column_0);
        lv_obj_set_height(label_1, 14);
        lv_label_set_translation_tag(label_1, detail);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);
        lv_obj_add_style(label_1, &style_caption_global, 0);

        lv_obj_t * row_0 = row_create(card_0, 0, 0, 0, 0, 2, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_0, LV_SIZE_CONTENT);
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_set_flag(row_0, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(row_0, LV_OBJ_FLAG_EVENT_BUBBLE, true);
        lv_obj_t * label_2 = label_create(row_0);
        lv_obj_set_height(label_2, 31);
        lv_label_set_text(label_2, price);
        lv_obj_set_style_text_color(label_2, CONST_TEXT_PRIMARY_GLOBAL, 0);
        lv_obj_add_style(label_2, &style_stat_md_global, 0);

        lv_obj_t * row_1 = row_create(row_0, 0, 0, 0, 4, 1, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_1, LV_SIZE_CONTENT);
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_set_flag(row_1, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(row_1, LV_OBJ_FLAG_EVENT_BUBBLE, true);
        lv_obj_t * label_3 = label_create(row_1);
        lv_obj_set_height(label_3, 18);
        lv_label_set_text(label_3, "/");
        lv_obj_set_style_text_color(label_3, CONST_ACCENT_GLOBAL, 0);
        lv_obj_add_style(label_3, &style_body_global, 0);

        lv_obj_t * label_4 = label_create(row_1);
        lv_obj_set_height(label_4, 18);
        lv_label_set_text(label_4, unit);
        lv_obj_set_style_text_color(label_4, CONST_ACCENT_GLOBAL, 0);
        lv_obj_add_style(label_4, &style_body_global, 0);

        lv_obj_t * container_0 = container_create(card_0);
        lv_obj_set_width(container_0, 18);
        lv_obj_set_height(container_0, 18);
        lv_obj_set_style_border_color(container_0, CONST_BORDER_GLOBAL, 0);
        lv_obj_set_style_border_width(container_0, 2, 0);
        lv_obj_set_style_radius(container_0, 32767, 0);
        lv_obj_set_style_clip_corner(container_0, true, 0);
        lv_obj_set_flag(container_0, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(container_0, LV_OBJ_FLAG_EVENT_BUBBLE, true);
        lv_obj_set_state(container_0, LV_STATE_CHECKED, checked);
        lv_obj_add_style(container_0, &style_desc_0_checked, LV_STATE_CHECKED);

        the_root = card_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

