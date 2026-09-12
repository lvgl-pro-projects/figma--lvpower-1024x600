/**
 * @file station_settings_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "station_settings_gen.h"
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

lv_obj_t * station_settings_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "station_settings_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xF1F1F1), 0);
        lv_obj_set_style_bg_grad_color(lv_obj_0, lv_color_hex(0xECECEC), 0);
        lv_obj_set_style_bg_grad_dir(lv_obj_0, LV_GRAD_DIR_VER, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);

        lv_obj_add_style(lv_obj_0, &style_screen_base_global, 0);
        lv_obj_t * column_0 = column_create(lv_obj_0, 0, 0, 0, 0, -3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(column_0, 51);
        lv_obj_set_y(column_0, 105);
        lv_obj_set_width(column_0, LV_SIZE_CONTENT);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(column_0);
        lv_obj_set_height(label_0, 49);
        lv_label_set_translation_tag(label_0, "station_settings");
        lv_obj_set_style_text_font(label_0, font_gabarito_semibold_40_959999084472656, 0);
        lv_obj_set_style_text_letter_space(label_0, -1, 0);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_1 = label_create(column_0);
        lv_obj_set_height(label_1, 23);
        lv_label_set_translation_tag(label_1, "station_bays");
        lv_obj_set_style_text_font(label_1, font_gabarito_regular_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * tile_2_0 = tile_2_create(lv_obj_0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, false);
        lv_obj_set_style_pad_row(tile_2_0, 0, 0);
        lv_obj_set_x(tile_2_0, 51);
        lv_obj_set_y(tile_2_0, 183);
        lv_obj_set_width(tile_2_0, 451);
        lv_obj_set_height(tile_2_0, 288);
        lv_obj_t * label_2 = label_create(tile_2_0);
        lv_obj_set_height(label_2, 17);
        lv_label_set_translation_tag(label_2, "display_sound");
        lv_obj_set_style_text_font(label_2, font_gabarito_medium_14_079999923706055, 0);
        lv_obj_set_style_text_letter_space(label_2, 2, 0);
        lv_obj_set_style_text_color(label_2, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * field_slider_0 = field_slider_create(tile_2_0, "screen_brightness", "70%", false, &subject_screen_brightness, &subject_screen_brightness);
        lv_obj_set_width(field_slider_0, 410);

        lv_obj_t * panel_0 = panel_create(tile_2_0);
        lv_obj_set_width(panel_0, lv_pct(100));
        lv_obj_set_height(panel_0, 1);
        lv_obj_set_style_bg_color(panel_0, CONST_DIVIDER_GLOBAL, 0);

        lv_obj_t * field_slider_1 = field_slider_create(tile_2_0, "alert_volume", "40%", false, &subject_alert_volume, &subject_alert_volume);
        lv_obj_set_width(field_slider_1, 410);

        lv_obj_t * panel_1 = panel_create(tile_2_0);
        lv_obj_set_width(panel_1, lv_pct(100));
        lv_obj_set_height(panel_1, 1);
        lv_obj_set_style_bg_color(panel_1, CONST_DIVIDER_GLOBAL, 0);

        lv_obj_t * row_toggle_0 = row_toggle_create(tile_2_0, "animations", "enable_transitions", true, &subject_animations);
        lv_obj_set_width(row_toggle_0, 410);

        lv_obj_t * row_0 = row_create(lv_obj_0, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_x(row_0, 51);
        lv_obj_set_y(row_0, 484);
        lv_obj_set_width(row_0, 451);
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        code_qr_create(row_0);

        lv_obj_t * column_1 = column_create(row_0, 0, 0, 0, 0, 5, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_1, LV_SIZE_CONTENT);
        lv_obj_set_height(column_1, LV_SIZE_CONTENT);
        lv_obj_t * row_1 = row_create(column_1, 0, 0, 0, 0, 10, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_1, LV_SIZE_CONTENT);
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * card_0 = card_create(row_1);
        lv_obj_set_width(card_0, 9);
        lv_obj_set_height(card_0, 9);
        lv_obj_set_style_bg_color(card_0, CONST_ACCENT_GLOBAL, 0);
        lv_obj_set_style_radius(card_0, 32767, 0);

        lv_obj_t * label_3 = label_create(row_1);
        lv_label_set_translation_tag(label_3, "firmware_ver");
        lv_obj_set_style_text_font(label_3, font_gabarito_semibold_19_19999885559082, 0);
        lv_obj_set_style_text_letter_space(label_3, 0, 0);
        lv_obj_set_style_text_color(label_3, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_4 = label_create(row_1);
        lv_label_set_translation_tag(label_4, "up_to_date");
        lv_obj_set_style_text_font(label_4, font_gabarito_regular_16_639999389648438, 0);
        lv_obj_set_style_text_color(label_4, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * label_5 = label_create(column_1);
        lv_obj_set_width(label_5, 350);
        lv_label_set_translation_tag(label_5, "scan_docs");
        lv_obj_set_style_text_font(label_5, font_gabarito_regular_16_639999389648438, 0);
        lv_obj_set_style_text_color(label_5, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * tile_0 = tile_create(lv_obj_0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, false);
        lv_obj_set_style_pad_row(tile_0, 0, 0);
        lv_obj_set_x(tile_0, 527);
        lv_obj_set_y(tile_0, 183);
        lv_obj_set_width(tile_0, 445);
        lv_obj_set_height(tile_0, LV_SIZE_CONTENT);
        lv_obj_t * column_2 = column_create(tile_0, 0, 0, 15, 15, 10, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_2, lv_pct(100));
        lv_obj_set_height(column_2, LV_SIZE_CONTENT);
        lv_obj_t * label_6 = label_create(column_2);
        lv_obj_set_height(label_6, 17);
        lv_label_set_translation_tag(label_6, "language");
        lv_obj_set_style_text_font(label_6, font_gabarito_medium_14_079999923706055, 0);
        lv_obj_set_style_text_letter_space(label_6, 2, 0);
        lv_obj_set_style_text_color(label_6, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * field_dropdown_0 = field_dropdown_create(column_2, "English\nPortuguese\nGerman\nSpanish\nFrench\nHungarian", 0);
        lv_obj_set_width(field_dropdown_0, 404);
        lv_obj_set_height(field_dropdown_0, 56);
        lv_dropdown_bind_value(field_dropdown_0, &subject_language_id);

        lv_obj_t * label_7 = label_create(tile_0);
        lv_obj_set_height(label_7, 17);
        lv_label_set_translation_tag(label_7, "network_access");
        lv_obj_set_style_text_font(label_7, font_gabarito_medium_14_079999923706055, 0);
        lv_obj_set_style_text_letter_space(label_7, 2, 0);
        lv_obj_set_style_text_color(label_7, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * row_toggle_1 = row_toggle_create(tile_0, "wifi", "wifi_state", true, &subject_wifi);
        lv_obj_set_width(row_toggle_1, 404);

        lv_obj_t * panel_2 = panel_create(tile_0);
        lv_obj_set_width(panel_2, lv_pct(100));
        lv_obj_set_height(panel_2, 1);
        lv_obj_set_style_bg_color(panel_2, CONST_DIVIDER_GLOBAL, 0);

        lv_obj_t * row_toggle_2 = row_toggle_create(tile_0, "contactless_payments", "accept_tap", true, &subject_contactless);
        lv_obj_set_width(row_toggle_2, 404);

        lv_obj_t * panel_3 = panel_create(tile_0);
        lv_obj_set_width(panel_3, lv_pct(100));
        lv_obj_set_height(panel_3, 1);
        lv_obj_set_style_bg_color(panel_3, CONST_DIVIDER_GLOBAL, 0);

        lv_obj_t * row_toggle_3 = row_toggle_create(tile_0, "bay_reserve", "pre_book", false, &subject_bay_reserve);
        lv_obj_set_width(row_toggle_3, 404);

        lv_obj_t * nav_header_0 = nav_header_create(lv_obj_0, image_icon_supercharge, "L-04", "Service", &style_chip_header_orange_global);
        lv_obj_set_x(nav_header_0, 0);
        lv_obj_set_y(nav_header_0, 0);
        lv_obj_set_width(nav_header_0, 1311);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

