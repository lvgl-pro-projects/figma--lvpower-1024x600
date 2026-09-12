/**
 * @file diagnostics_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "diagnostics_gen.h"
#include "../lvpower.h"

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

lv_obj_t * diagnostics_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "diagnostics_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xF1F1F1), 0);
        lv_obj_set_style_bg_grad_color(lv_obj_0, lv_color_hex(0xECECEC), 0);
        lv_obj_set_style_bg_grad_dir(lv_obj_0, LV_GRAD_DIR_VER, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);

        lv_obj_add_style(lv_obj_0, &style_screen_base_global, 0);
        lv_obj_t * row_0 = row_create(lv_obj_0, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_align(row_0, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_x(row_0, -80);
        lv_obj_set_y(row_0, 99);
        lv_obj_set_width(row_0, LV_SIZE_CONTENT);
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * column_0 = column_create(row_0, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(column_0, LV_SIZE_CONTENT);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(column_0);
        lv_obj_set_height(label_0, 17);
        lv_label_set_translation_tag(label_0, "asset_tag");
        lv_obj_set_style_text_font(label_0, font_gabarito_medium_14_079999923706055, 0);
        lv_obj_set_style_text_letter_space(label_0, 2, 0);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * label_1 = label_create(column_0);
        lv_obj_set_height(label_1, 23);
        lv_label_set_text(label_1, "L-04-2291");
        lv_obj_set_style_text_font(label_1, font_gabarito_semibold_19_19999885559082, 0);
        lv_obj_set_style_text_letter_space(label_1, 0, 0);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * code_qr_0 = code_qr_create(row_0);
        lv_obj_add_screen_create_event(code_qr_0, LV_EVENT_CLICKED, charging_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * tile_2_0 = tile_2_create(lv_obj_0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, false);
        lv_obj_set_style_pad_row(tile_2_0, 0, 0);
        lv_obj_set_x(tile_2_0, 51);
        lv_obj_set_y(tile_2_0, 215);
        lv_obj_set_width(tile_2_0, 451);
        lv_obj_set_height(tile_2_0, 352);
        lv_obj_t * label_2 = label_create(tile_2_0);
        lv_obj_set_height(label_2, 17);
        lv_label_set_translation_tag(label_2, "safety_interlocks");
        lv_obj_set_style_text_font(label_2, font_gabarito_medium_14_079999923706055, 0);
        lv_obj_set_style_text_letter_space(label_2, 2, 0);
        lv_obj_set_style_text_color(label_2, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * row_1 = row_create(tile_2_0, 0, 0, 20, 20, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_1, lv_pct(100));
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * control_checkbox_0 = control_checkbox_create(row_1);
        lv_obj_set_width(control_checkbox_0, 31);
        lv_obj_set_height(control_checkbox_0, 31);
        lv_obj_set_state(control_checkbox_0, LV_STATE_CHECKED, true);

        lv_obj_t * label_3 = label_create(row_1);
        lv_obj_set_width(label_3, 0);
        lv_obj_set_flex_grow(label_3, 1);
        lv_label_set_translation_tag(label_3, "emergency_stop");
        lv_obj_set_style_text_font(label_3, font_gabarito_medium_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_3, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_4 = label_create(row_1);
        lv_label_set_translation_tag(label_4, "ok");
        lv_obj_set_style_text_font(label_4, font_gabarito_medium_15_359999656677246, 0);
        lv_obj_set_style_text_color(label_4, CONST_ACCENT_GLOBAL, 0);

        lv_obj_t * row_2 = row_create(tile_2_0, 0, 0, 20, 20, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_2, lv_pct(100));
        lv_obj_set_height(row_2, LV_SIZE_CONTENT);
        lv_obj_t * control_checkbox_1 = control_checkbox_create(row_2);
        lv_obj_set_width(control_checkbox_1, 31);
        lv_obj_set_height(control_checkbox_1, 31);
        lv_obj_set_state(control_checkbox_1, LV_STATE_CHECKED, true);

        lv_obj_t * label_5 = label_create(row_2);
        lv_obj_set_width(label_5, 0);
        lv_obj_set_flex_grow(label_5, 1);
        lv_label_set_translation_tag(label_5, "enclosure_panel");
        lv_obj_set_style_text_font(label_5, font_gabarito_medium_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_5, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_6 = label_create(row_2);
        lv_label_set_translation_tag(label_6, "ok");
        lv_obj_set_style_text_font(label_6, font_gabarito_medium_15_359999656677246, 0);
        lv_obj_set_style_text_color(label_6, CONST_ACCENT_GLOBAL, 0);

        lv_obj_t * row_3 = row_create(tile_2_0, 0, 0, 20, 20, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_3, lv_pct(100));
        lv_obj_set_height(row_3, LV_SIZE_CONTENT);
        lv_obj_t * control_checkbox_2 = control_checkbox_create(row_3);
        lv_obj_set_width(control_checkbox_2, 31);
        lv_obj_set_height(control_checkbox_2, 31);
        lv_obj_set_state(control_checkbox_2, LV_STATE_CHECKED, true);

        lv_obj_t * label_7 = label_create(row_3);
        lv_obj_set_width(label_7, 0);
        lv_obj_set_flex_grow(label_7, 1);
        lv_label_set_translation_tag(label_7, "ground_fault");
        lv_obj_set_style_text_font(label_7, font_gabarito_medium_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_7, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_8 = label_create(row_3);
        lv_label_set_translation_tag(label_8, "ok");
        lv_obj_set_style_text_font(label_8, font_gabarito_medium_15_359999656677246, 0);
        lv_obj_set_style_text_color(label_8, CONST_ACCENT_GLOBAL, 0);

        lv_obj_t * row_4 = row_create(tile_2_0, 0, 0, 20, 20, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_4, lv_pct(100));
        lv_obj_set_height(row_4, LV_SIZE_CONTENT);
        lv_obj_t * control_checkbox_3 = control_checkbox_create(row_4);
        lv_obj_set_width(control_checkbox_3, 31);
        lv_obj_set_height(control_checkbox_3, 31);

        lv_obj_t * label_9 = label_create(row_4);
        lv_obj_set_width(label_9, 0);
        lv_obj_set_flex_grow(label_9, 1);
        lv_label_set_translation_tag(label_9, "cable_connected");
        lv_obj_set_style_text_font(label_9, font_gabarito_regular_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_9, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * label_10 = label_create(row_4);
        lv_label_set_translation_tag(label_10, "pending");
        lv_obj_set_style_text_font(label_10, font_gabarito_medium_15_359999656677246, 0);
        lv_obj_set_style_text_color(label_10, CONST_WARN_GLOBAL, 0);

        lv_obj_t * tile_0 = tile_create(lv_obj_0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, false);
        lv_obj_set_style_pad_row(tile_0, 15, 0);
        lv_obj_set_x(tile_0, 535);
        lv_obj_set_y(tile_0, 215);
        lv_obj_set_width(tile_0, 438);
        lv_obj_set_height(tile_0, LV_SIZE_CONTENT);
        lv_obj_t * label_11 = label_create(tile_0);
        lv_obj_set_height(label_11, 17);
        lv_label_set_translation_tag(label_11, "thermals");
        lv_obj_set_style_text_font(label_11, font_gabarito_medium_14_079999923706055, 0);
        lv_obj_set_style_text_letter_space(label_11, 2, 0);
        lv_obj_set_style_text_color(label_11, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * column_1 = column_create(tile_0, 0, 0, 0, 0, 10, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_1, lv_pct(100));
        lv_obj_set_height(column_1, LV_SIZE_CONTENT);
        lv_obj_t * row_5 = row_create(column_1, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START);
        lv_obj_set_width(row_5, lv_pct(100));
        lv_obj_set_height(row_5, LV_SIZE_CONTENT);
        lv_obj_t * label_12 = label_create(row_5);
        lv_obj_set_height(label_12, 23);
        lv_label_set_translation_tag(label_12, "cable");
        lv_obj_set_style_text_font(label_12, font_gabarito_medium_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_12, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * row_6 = row_create(row_5, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_6, LV_SIZE_CONTENT);
        lv_obj_set_height(row_6, LV_SIZE_CONTENT);
        lv_obj_t * label_13 = label_create(row_6);
        lv_obj_set_height(label_13, 31);
        lv_label_bind_text(label_13, &subject_cable_thermal, "%d");
        lv_obj_set_style_text_font(label_13, font_gabarito_semibold_25_599998474121094, 0);
        lv_obj_set_style_text_letter_space(label_13, -1, 0);
        lv_obj_set_style_text_color(label_13, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_14 = label_create(row_6);
        lv_obj_set_height(label_14, 18);
        lv_label_set_text(label_14, "°C");
        lv_obj_set_style_text_font(label_14, font_gabarito_regular_15_359999656677246, 0);
        lv_obj_set_style_text_color(label_14, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * bar_b_0 = bar_b_create(column_1, 59, &style_bar_b_green_global);
        lv_obj_set_width(bar_b_0, 397);
        lv_obj_set_height(bar_b_0, 10);
        lv_bar_bind_value(bar_b_0, &subject_cable_thermal);

        lv_obj_t * column_2 = column_create(tile_0, 0, 0, 0, 0, 10, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_2, lv_pct(100));
        lv_obj_set_height(column_2, LV_SIZE_CONTENT);
        lv_obj_t * row_7 = row_create(column_2, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_START);
        lv_obj_set_width(row_7, lv_pct(100));
        lv_obj_set_height(row_7, LV_SIZE_CONTENT);
        lv_obj_t * label_15 = label_create(row_7);
        lv_obj_set_height(label_15, 23);
        lv_label_set_translation_tag(label_15, "power_stage");
        lv_obj_set_style_text_font(label_15, font_gabarito_medium_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_15, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * row_8 = row_create(row_7, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_8, LV_SIZE_CONTENT);
        lv_obj_set_height(row_8, LV_SIZE_CONTENT);
        lv_obj_t * label_16 = label_create(row_8);
        lv_obj_set_height(label_16, 31);
        lv_label_bind_text(label_16, &subject_power_stage, "%d");
        lv_obj_set_style_text_font(label_16, font_gabarito_semibold_25_599998474121094, 0);
        lv_obj_set_style_text_letter_space(label_16, -1, 0);
        lv_obj_set_style_text_color(label_16, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_17 = label_create(row_8);
        lv_obj_set_height(label_17, 18);
        lv_label_set_text(label_17, "°C");
        lv_obj_set_style_text_font(label_17, font_gabarito_regular_15_359999656677246, 0);
        lv_obj_set_style_text_color(label_17, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * bar_b_1 = bar_b_create(column_2, 59, &style_bar_b_warn_global);
        lv_obj_set_width(bar_b_1, 397);
        lv_obj_set_height(bar_b_1, 10);
        lv_bar_bind_value(bar_b_1, &subject_power_stage);

        lv_obj_t * column_3 = column_create(lv_obj_0, 0, 0, 0, 0, 10, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(column_3, 535);
        lv_obj_set_y(column_3, 417);
        lv_obj_set_width(column_3, 438);
        lv_obj_set_height(column_3, LV_SIZE_CONTENT);
        lv_obj_t * label_18 = label_create(column_3);
        lv_obj_set_height(label_18, 17);
        lv_label_set_translation_tag(label_18, "service_note");
        lv_obj_set_style_text_font(label_18, font_gabarito_medium_14_079999923706055, 0);
        lv_obj_set_style_text_letter_space(label_18, 2, 0);
        lv_obj_set_style_text_color(label_18, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * card_0 = card_create(column_3);
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_all(card_0, 15, 0);
        lv_obj_set_style_pad_row(card_0, 0, 0);
        lv_obj_set_width(card_0, lv_pct(100));
        lv_obj_set_height(card_0, 123);
        lv_obj_set_style_bg_color(card_0, CONST_ON_ACCENT_GLOBAL, 0);
        lv_obj_set_style_border_color(card_0, lv_color_hex(0xDDE1E4), 0);
        lv_obj_set_style_border_width(card_0, 1, 0);
        lv_obj_set_style_radius(card_0, 13, 0);
        lv_obj_set_flag(card_0, LV_OBJ_FLAG_SCROLLABLE, true);
        lv_obj_t * label_19 = label_create(card_0);
        lv_obj_set_width(label_19, lv_pct(100));
        lv_label_set_translation_tag(label_19, "service_replace");
        lv_obj_set_style_text_font(label_19, font_gabarito_regular_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_19, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * nav_header_0 = nav_header_create(lv_obj_0, image_icon_supercharge, "L-04", "Service", &style_chip_header_orange_global);
        lv_obj_set_x(nav_header_0, 0);
        lv_obj_set_y(nav_header_0, 0);
        lv_obj_set_width(nav_header_0, 1311);

        lv_obj_t * container_0 = container_create(lv_obj_0);
        lv_obj_set_x(container_0, 49);
        lv_obj_set_y(container_0, 105);
        lv_obj_set_width(container_0, 323);
        lv_obj_set_height(container_0, 69);
        lv_obj_t * column_4 = column_create(container_0, 0, 0, 0, 0, -3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(column_4, 54);
        lv_obj_set_y(column_4, 0);
        lv_obj_set_width(column_4, LV_SIZE_CONTENT);
        lv_obj_set_height(column_4, LV_SIZE_CONTENT);
        lv_obj_set_flag(column_4, LV_OBJ_FLAG_CLICKABLE, false);
        lv_obj_set_flag(column_4, LV_OBJ_FLAG_EVENT_BUBBLE, true);
        lv_obj_t * label_20 = label_create(column_4);
        lv_obj_set_height(label_20, 49);
        lv_label_set_translation_tag(label_20, "diagnostics");
        lv_obj_set_style_text_font(label_20, font_gabarito_semibold_40_959999084472656, 0);
        lv_obj_set_style_text_letter_space(label_20, -1, 0);
        lv_obj_set_style_text_color(label_20, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_21 = label_create(column_4);
        lv_obj_set_height(label_21, 23);
        lv_label_set_translation_tag(label_21, "station_technician");
        lv_obj_set_style_text_font(label_21, font_gabarito_regular_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_21, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * icon_back_0 = icon_back_create(container_0);
        lv_obj_set_x(icon_back_0, 0);
        lv_obj_set_y(icon_back_0, 19);
        lv_obj_set_width(icon_back_0, 31);
        lv_obj_set_height(icon_back_0, 31);

        lv_obj_add_screen_create_event(container_0, LV_EVENT_CLICKED, charging_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

