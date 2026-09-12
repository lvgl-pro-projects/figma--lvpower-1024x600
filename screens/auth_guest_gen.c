/**
 * @file auth_guest_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "auth_guest_gen.h"
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

lv_obj_t * auth_guest_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "auth_guest_#");
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
        lv_obj_set_style_text_font(label_0, font_gabarito_semibold_40_96000289916992, 0);
        lv_obj_set_style_text_letter_space(label_0, -1, 0);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_1 = label_create(column_0);
        lv_obj_set_height(label_1, 23);
        lv_label_set_translation_tag(label_1, "ccs_150");
        lv_obj_set_style_text_font(label_1, font_gabarito_regular_19_200000762939453, 0);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * column_1 = column_create(lv_obj_0, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(column_1, 51);
        lv_obj_set_y(column_1, 230);
        lv_obj_set_width(column_1, 563);
        lv_obj_set_height(column_1, LV_SIZE_CONTENT);
        lv_obj_t * row_supercharge_0 = row_supercharge_create(column_1, image_icon_supercharge_green_24419, "supercharge", "charge_150", "€0.45", "kWh", true, false);
        lv_obj_set_width(row_supercharge_0, 563);
        lv_obj_set_height(row_supercharge_0, 82);

        lv_obj_t * row_tariff_0 = row_tariff_create(column_1, image_icon_zap_19913, "fast", "charge_80", "€0.30", "kWh", false, false);
        lv_obj_set_width(row_tariff_0, 563);
        lv_obj_set_height(row_tariff_0, 82);

        lv_obj_t * row_tariff_1 = row_tariff_create(column_1, image_icon_plug_19916, "basic", "charge_overnight", "€0.15", "kWh", false, false);
        lv_obj_set_width(row_tariff_1, 563);
        lv_obj_set_height(row_tariff_1, 82);

        lv_obj_t * tile_0 = tile_create(lv_obj_0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, false);
        lv_obj_set_style_pad_row(tile_0, 10, 0);
        lv_obj_set_x(tile_0, 662);
        lv_obj_set_y(tile_0, 164);
        lv_obj_set_width(tile_0, 312);
        lv_obj_set_height(tile_0, 371);
        lv_obj_t * label_2 = label_create(tile_0);
        lv_obj_set_height(label_2, 28);
        lv_label_set_translation_tag(label_2, "authorize_payment");
        lv_obj_set_style_text_font(label_2, font_gabarito_semibold_23_040000915527344, 0);
        lv_obj_set_style_text_letter_space(label_2, 0, 0);
        lv_obj_set_style_text_color(label_2, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * card_0 = card_create(tile_0);
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_hor(card_0, 0, 0);
        lv_obj_set_style_pad_ver(card_0, 15, 0);
        lv_obj_set_style_pad_row(card_0, 5, 0);
        lv_obj_set_width(card_0, lv_pct(100));
        lv_obj_set_height(card_0, 179);
        lv_obj_set_style_bg_color(card_0, CONST_SURFACE_CANVAS_GLOBAL, 0);
        lv_obj_set_style_radius(card_0, 13, 0);
        lv_obj_t * icon_nfc_0 = icon_nfc_create(card_0);
        lv_obj_set_width(icon_nfc_0, 31);
        lv_obj_set_height(icon_nfc_0, 31);

        lv_obj_t * label_3 = label_create(card_0);
        lv_obj_set_width(label_3, lv_pct(90));
        lv_obj_set_style_text_align(label_3, LV_TEXT_ALIGN_CENTER, 0);
        lv_label_set_translation_tag(label_3, "tap_card");
        lv_obj_set_style_text_font(label_3, font_gabarito_medium_15_360000610351562, 0);
        lv_obj_set_style_text_color(label_3, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * row_0 = row_create(tile_0, 0, 0, 0, 0, 10, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_0, lv_pct(100));
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * control_checkbox_0 = control_checkbox_create(row_0);
        lv_obj_set_width(control_checkbox_0, 31);
        lv_obj_set_height(control_checkbox_0, 31);

        lv_obj_t * label_4 = label_create(row_0);
        lv_label_set_translation_tag(label_4, "accept_terms");
        lv_obj_set_style_text_font(label_4, font_gabarito_regular_15_360000610351562, 0);
        lv_obj_set_style_text_color(label_4, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * button_primary_0 = button_primary_create(tile_0, "start_charging", false, false);
        lv_obj_set_width(button_primary_0, 271);
        lv_obj_add_screen_create_event(button_primary_0, LV_EVENT_CLICKED, charging_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * nav_header_0 = nav_header_create(lv_obj_0, image_icon_supercharge, "L-04", "connected", &style_chip_header_green_global);
        lv_obj_set_x(nav_header_0, 0);
        lv_obj_set_y(nav_header_0, 0);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

