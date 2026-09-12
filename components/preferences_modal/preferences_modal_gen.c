/**
 * @file preferences_modal_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "preferences_modal_gen.h"
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

lv_obj_t * preferences_modal_create(lv_obj_t * parent, bool close_button_checked, bool control_slider_checked, bool control_switch_on, bool control_checkbox_checked, bool button_primary_disabled)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * card_0 = card_create(parent);
        lv_obj_set_name_static(card_0, "preferences_modal_#");
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_hor(card_0, 24, 0);
        lv_obj_set_style_pad_ver(card_0, 22, 0);
        lv_obj_set_style_pad_row(card_0, 18, 0);
        lv_obj_set_width(card_0, 452);
        lv_obj_set_height(card_0, LV_SIZE_CONTENT);
        lv_obj_set_style_bg_color(card_0, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_radius(card_0, CONST_RADIUS_XL_GLOBAL, 0);
        lv_obj_set_style_shadow_width(card_0, 50, 0);
        lv_obj_set_style_shadow_offset_y(card_0, 20, 0);
        lv_obj_set_style_shadow_spread(card_0, -12, 0);
        lv_obj_set_style_shadow_color(card_0, lv_color_hex(0x05070A), 0);
        lv_obj_set_style_shadow_opa(card_0, 102, 0);

        lv_obj_t * row_0 = row_create(card_0, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_0, lv_pct(100));
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * column_0 = column_create(row_0, 0, 0, 0, 0, 2, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_0, LV_SIZE_CONTENT);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(column_0);
        lv_obj_set_height(label_0, 26);
        lv_label_set_translation_tag(label_0, "charging_preferences");
        lv_obj_set_style_text_color(label_0, lv_color_hex(0x14181B), 0);
        lv_obj_add_style(label_0, &style_font_title_global, 0);

        lv_obj_t * label_1 = label_create(column_0);
        lv_obj_set_height(label_1, 16);
        lv_label_set_translation_tag(label_1, "session_name");
        lv_obj_set_style_text_color(label_1, lv_color_hex(0x8B9197), 0);
        lv_obj_add_style(label_1, &style_font_meta_global, 0);

        lv_obj_t * button_icon_0 = button_icon_create(row_0, image_icon_close_30435, false);
        lv_obj_set_width(button_icon_0, 36);
        lv_obj_set_height(button_icon_0, 36);
        lv_obj_set_state(button_icon_0, LV_STATE_CHECKED, close_button_checked);
        lv_obj_add_subject_set_int_event(button_icon_0, &subject_preferences_modal_state, LV_EVENT_CLICKED, 0);

        lv_obj_t * column_1 = column_create(card_0, 0, 0, 0, 0, 12, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_1, lv_pct(100));
        lv_obj_set_height(column_1, LV_SIZE_CONTENT);
        lv_obj_t * row_1 = row_create(column_1, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START);
        lv_obj_set_width(row_1, lv_pct(100));
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * label_2 = label_create(row_1);
        lv_obj_set_height(label_2, 22);
        lv_label_set_translation_tag(label_2, "charge_limit");
        lv_obj_set_style_text_color(label_2, lv_color_hex(0x14181B), 0);
        lv_obj_add_style(label_2, &style_font_subtitle_global, 0);

        lv_obj_t * row_2 = row_create(row_1, 0, 0, 0, 0, 1, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_2, LV_SIZE_CONTENT);
        lv_obj_set_height(row_2, LV_SIZE_CONTENT);
        lv_obj_t * label_3 = label_create(row_2);
        lv_obj_set_height(label_3, 24);
        lv_label_bind_text(label_3, &subject_chg_limit, "%d");
        lv_obj_set_style_text_color(label_3, lv_color_hex(0x14181B), 0);
        lv_obj_add_style(label_3, &style_stat_xs_global, 0);

        lv_obj_t * label_4 = label_create(row_2);
        lv_obj_set_height(label_4, 16);
        lv_label_set_text(label_4, "%");
        lv_obj_set_style_text_color(label_4, lv_color_hex(0x8B9197), 0);
        lv_obj_add_style(label_4, &style_chip_global, 0);

        lv_obj_t * label_5 = label_create(column_1);
        lv_obj_set_height(label_5, 16);
        lv_label_set_translation_tag(label_5, "stop_level");
        lv_obj_set_style_text_color(label_5, lv_color_hex(0x8B9197), 0);
        lv_obj_add_style(label_5, &style_font_meta_global, 0);

        lv_obj_t * control_slider_0 = control_slider_create(column_1, 55);
        lv_obj_set_width(control_slider_0, lv_pct(100));
        lv_obj_set_state(control_slider_0, LV_STATE_CHECKED, control_slider_checked);
        lv_slider_set_min_value(control_slider_0, 50);
        lv_slider_set_max_value(control_slider_0, 100);
        lv_slider_bind_value(control_slider_0, &subject_chg_limit);

        lv_obj_t * row_3 = row_create(column_1, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START);
        lv_obj_set_width(row_3, lv_pct(100));
        lv_obj_set_height(row_3, LV_SIZE_CONTENT);
        lv_obj_t * label_6 = label_create(row_3);
        lv_obj_set_height(label_6, 14);
        lv_label_set_text(label_6, "50%");
        lv_obj_set_style_text_color(label_6, lv_color_hex(0xAEB4B9), 0);
        lv_obj_add_style(label_6, &style_caption_global, 0);

        lv_obj_t * label_7 = label_create(row_3);
        lv_obj_set_height(label_7, 14);
        lv_label_set_text(label_7, "100%");
        lv_obj_set_style_text_color(label_7, lv_color_hex(0xAEB4B9), 0);
        lv_obj_add_style(label_7, &style_caption_global, 0);

        lv_obj_t * column_2 = column_create(card_0, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_2, lv_pct(100));
        lv_obj_set_height(column_2, LV_SIZE_CONTENT);
        lv_obj_t * row_4 = row_create(column_2, 0, 0, 14, 14, 12, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_4, lv_pct(100));
        lv_obj_set_height(row_4, LV_SIZE_CONTENT);
        lv_obj_t * column_3 = column_create(row_4, 0, 0, 0, 0, 1, 1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_3, 0);
        lv_obj_set_height(column_3, LV_SIZE_CONTENT);
        lv_obj_t * label_8 = label_create(column_3);
        lv_obj_set_height(label_8, 18);
        lv_label_set_translation_tag(label_8, "off_peak");
        lv_obj_set_style_text_color(label_8, lv_color_hex(0x14181B), 0);
        lv_obj_add_style(label_8, &style_body_strong_global, 0);

        lv_obj_t * label_9 = label_create(column_3);
        lv_obj_set_height(label_9, 14);
        lv_label_set_translation_tag(label_9, "charge_peak");
        lv_obj_set_style_text_color(label_9, lv_color_hex(0x8B9197), 0);
        lv_obj_add_style(label_9, &style_caption_global, 0);

        lv_obj_t * control_switch_0 = control_switch_create(row_4);
        lv_obj_set_state(control_switch_0, LV_STATE_CHECKED, control_switch_on);

        lv_obj_t * panel_0 = panel_create(column_2);
        lv_obj_set_width(panel_0, lv_pct(100));
        lv_obj_set_height(panel_0, 1);
        lv_obj_set_style_bg_color(panel_0, CONST_DIVIDER_GLOBAL, 0);

        lv_obj_t * row_5 = row_create(column_2, 0, 0, 14, 14, 12, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_5, lv_pct(100));
        lv_obj_set_height(row_5, LV_SIZE_CONTENT);
        lv_obj_t * column_4 = column_create(row_5, 0, 0, 0, 0, 1, 1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_4, 0);
        lv_obj_set_height(column_4, LV_SIZE_CONTENT);
        lv_obj_t * label_10 = label_create(column_4);
        lv_obj_set_height(label_10, 18);
        lv_label_set_translation_tag(label_10, "notify_done");
        lv_obj_set_style_text_color(label_10, lv_color_hex(0x14181B), 0);
        lv_obj_add_style(label_10, &style_body_strong_global, 0);

        lv_obj_t * label_11 = label_create(column_4);
        lv_obj_set_height(label_11, 14);
        lv_label_set_translation_tag(label_11, "text_80");
        lv_obj_set_style_text_color(label_11, lv_color_hex(0x8B9197), 0);
        lv_obj_add_style(label_11, &style_caption_global, 0);

        lv_obj_t * control_checkbox_0 = control_checkbox_create(row_5);
        lv_obj_set_width(control_checkbox_0, 26);
        lv_obj_set_height(control_checkbox_0, 26);
        lv_obj_set_state(control_checkbox_0, LV_STATE_CHECKED, control_checkbox_checked);

        lv_obj_t * button_primary_0 = button_primary_create(card_0, "save_changes", button_primary_disabled, false);
        lv_obj_set_width(button_primary_0, lv_pct(100));
        lv_obj_add_subject_set_int_event(button_primary_0, &subject_preferences_modal_state, LV_EVENT_CLICKED, 0);

        the_root = card_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

