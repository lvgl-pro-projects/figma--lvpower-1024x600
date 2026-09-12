/**
 * @file auth_member_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "auth_member_gen.h"
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

lv_obj_t * auth_member_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "auth_member_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xF1F1F1), 0);
        lv_obj_set_style_bg_grad_color(lv_obj_0, lv_color_hex(0xECECEC), 0);
        lv_obj_set_style_bg_grad_dir(lv_obj_0, LV_GRAD_DIR_VER, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);

        lv_obj_add_style(lv_obj_0, &style_screen_base_global, 0);
        lv_obj_t * column_0 = column_create(lv_obj_0, 0, 0, 0, 0, 5, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(column_0, 51);
        lv_obj_set_y(column_0, 125);
        lv_obj_set_width(column_0, LV_SIZE_CONTENT);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(column_0);
        lv_obj_set_height(label_0, 49);
        lv_label_set_translation_tag(label_0, "cable_connected");
        lv_obj_set_style_text_font(label_0, font_gabarito_semibold_40_959999084472656, 0);
        lv_obj_set_style_text_letter_space(label_0, -1, 0);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_1 = label_create(column_0);
        lv_obj_set_height(label_1, 23);
        lv_label_set_translation_tag(label_1, "ccs_150");
        lv_obj_set_style_text_font(label_1, font_gabarito_regular_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * column_1 = column_create(lv_obj_0, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(column_1, 51);
        lv_obj_set_y(column_1, 230);
        lv_obj_set_width(column_1, 517);
        lv_obj_set_height(column_1, LV_SIZE_CONTENT);
        lv_obj_t * row_supercharge_0 = row_supercharge_create(column_1, image_icon_supercharge_green_24419, "supercharge", "charge_150", "€0.45", "kWh", true, false);
        lv_obj_set_width(row_supercharge_0, 517);
        lv_obj_set_height(row_supercharge_0, 82);

        lv_obj_t * row_tariff_0 = row_tariff_create(column_1, image_icon_zap_19913, "fast", "charge_80", "€0.30", "kWh", false, false);
        lv_obj_set_width(row_tariff_0, 517);
        lv_obj_set_height(row_tariff_0, 82);

        lv_obj_t * row_tariff_1 = row_tariff_create(column_1, image_icon_plug_19916, "basic", "charge_overnight", "€0.15", "kWh", false, false);
        lv_obj_set_width(row_tariff_1, 517);
        lv_obj_set_height(row_tariff_1, 82);

        lv_obj_t * card_0 = card_create(lv_obj_0);
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_pad_all(card_0, 20, 0);
        lv_obj_set_style_pad_row(card_0, 10, 0);
        lv_obj_set_x(card_0, 608);
        lv_obj_set_y(card_0, 99);
        lv_obj_set_width(card_0, 364);
        lv_obj_set_height(card_0, 457);
        lv_obj_set_style_bg_color(card_0, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_radius(card_0, 23, 0);
        lv_obj_set_style_shadow_width(card_0, 31, 0);
        lv_obj_set_style_shadow_offset_y(card_0, 10, 0);
        lv_obj_set_style_shadow_spread(card_0, -8, 0);
        lv_obj_set_style_shadow_color(card_0, lv_color_hex(0x141C22), 0);
        lv_obj_set_style_shadow_opa(card_0, 26, 0);
        lv_obj_t * column_2 = column_create(card_0, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_2, LV_SIZE_CONTENT);
        lv_obj_set_height(column_2, LV_SIZE_CONTENT);
        lv_obj_t * label_2 = label_create(column_2);
        lv_obj_set_height(label_2, 18);
        lv_label_set_translation_tag(label_2, "welcome_back");
        lv_obj_set_style_text_font(label_2, font_gabarito_regular_15_359999656677246, 0);
        lv_obj_set_style_text_color(label_2, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * label_3 = label_create(column_2);
        lv_obj_set_height(label_3, 34);
        lv_label_set_text(label_3, "Andrzej");
        lv_obj_set_style_text_font(label_3, font_gabarito_semibold_28_15999984741211, 0);
        lv_obj_set_style_text_letter_space(label_3, 0, 0);
        lv_obj_set_style_text_color(label_3, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * image_0 = image_create(card_0);
        lv_obj_set_width(image_0, 425);
        lv_obj_set_height(image_0, 149);
        lv_image_set_src(image_0, image_back_byd_425x149);

        lv_obj_t * column_3 = column_create(card_0, 0, 0, 0, 0, 5, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_3, lv_pct(100));
        lv_obj_set_height(column_3, LV_SIZE_CONTENT);
        lv_obj_t * row_0 = row_create(column_3, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_0, lv_pct(100));
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * label_4 = label_create(row_0);
        lv_obj_set_height(label_4, 23);
        lv_label_set_text(label_4, "Aurex EX40 · 2025");
        lv_obj_set_style_text_font(label_4, font_gabarito_semibold_19_19999885559082, 0);
        lv_obj_set_style_text_letter_space(label_4, 0, 0);
        lv_obj_set_style_text_color(label_4, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * row_1 = row_create(row_0, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_1, LV_SIZE_CONTENT);
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * label_5 = label_create(row_1);
        lv_obj_set_height(label_5, 52);
        lv_label_bind_text(label_5, &subject_chg_pct, "%d");
        lv_obj_set_style_text_font(label_5, font_gabarito_semibold_43_52000045776367, 0);
        lv_obj_set_style_text_letter_space(label_5, -1, 0);
        lv_obj_set_style_text_color(label_5, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_6 = label_create(row_1);
        lv_obj_set_height(label_6, 18);
        lv_label_set_text(label_6, "%");
        lv_obj_set_style_text_font(label_6, font_gabarito_regular_15_359999656677246, 0);
        lv_obj_set_style_text_color(label_6, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * bar_b_0 = bar_b_create(column_3, 59, &style_bar_b_green_global);
        lv_obj_set_width(bar_b_0, 323);
        lv_obj_set_height(bar_b_0, 10);
        lv_bar_bind_value(bar_b_0, &subject_chg_pct);

        lv_obj_t * column_4 = column_create(card_0, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_4, lv_pct(100));
        lv_obj_set_height(column_4, LV_SIZE_CONTENT);
        lv_obj_t * label_7 = label_create(column_4);
        lv_obj_set_height(label_7, 17);
        lv_label_set_translation_tag(label_7, "payment");
        lv_obj_set_style_text_font(label_7, font_gabarito_medium_14_079999923706055, 0);
        lv_obj_set_style_text_letter_space(label_7, 2, 0);
        lv_obj_set_style_text_color(label_7, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * row_2 = row_create(column_4, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_2, lv_pct(100));
        lv_obj_set_height(row_2, LV_SIZE_CONTENT);
        lv_obj_t * row_3 = row_create(row_2, 0, 0, 0, 0, 5, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_3, 287);
        lv_obj_set_height(row_3, LV_SIZE_CONTENT);
        lv_obj_t * label_8 = label_create(row_3);
        lv_label_set_translation_tag(label_8, "card_ending");
        lv_obj_set_style_text_font(label_8, font_gabarito_semibold_19_19999885559082, 0);
        lv_obj_set_style_text_letter_space(label_8, 0, 0);
        lv_obj_set_style_text_color(label_8, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_9 = label_create(row_3);
        lv_label_bind_text(label_9, &subject_card_ending, "%d");
        lv_obj_set_style_text_font(label_9, font_gabarito_semibold_19_19999885559082, 0);
        lv_obj_set_style_text_letter_space(label_9, 0, 0);
        lv_obj_set_style_text_color(label_9, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * image_1 = image_create(row_2);
        lv_obj_set_width(image_1, 36);
        lv_obj_set_height(image_1, 12);
        lv_image_set_src(image_1, image_4);

        lv_obj_t * container_0 = container_create(card_0);
        lv_obj_set_flex_flow(container_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(container_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(container_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(container_0, 0, 0);
        lv_obj_set_style_pad_column(container_0, 10, 0);
        lv_obj_set_width(container_0, lv_pct(100));
        lv_obj_set_height(container_0, LV_SIZE_CONTENT);
        lv_obj_t * button_primary_0 = button_primary_create(container_0, "start_charging", false, false);
        lv_obj_add_screen_create_event(button_primary_0, LV_EVENT_CLICKED, charging_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * nav_header_0 = nav_header_create(lv_obj_0, image_icon_supercharge, "L-04", "Connected", &style_chip_header_green_global);
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

