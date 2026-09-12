/**
 * @file idle_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "idle_gen.h"
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

lv_obj_t * idle_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "idle_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xF1F1F1), 0);
        lv_obj_set_style_bg_grad_color(lv_obj_0, lv_color_hex(0xECECEC), 0);
        lv_obj_set_style_bg_grad_dir(lv_obj_0, LV_GRAD_DIR_VER, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);

        lv_obj_add_style(lv_obj_0, &style_screen_base_global, 0);
        lv_obj_t * container_0 = container_create(lv_obj_0);
        lv_obj_set_x(container_0, 17);
        lv_obj_set_y(container_0, 106);
        lv_obj_set_width(container_0, 569);
        lv_obj_set_height(container_0, 142);
        lv_obj_t * image_0 = image_create(container_0);
        lv_obj_set_x(image_0, 442);
        lv_obj_set_y(image_0, 0);
        lv_obj_set_width(image_0, 127);
        lv_obj_set_height(image_0, 142);
        lv_image_set_src(image_0, image_vec_270_4);

        lv_obj_t * image_1 = image_create(container_0);
        lv_obj_set_x(image_1, 338);
        lv_obj_set_y(image_1, 0);
        lv_obj_set_width(image_1, 121);
        lv_obj_set_height(image_1, 142);
        lv_image_set_src(image_1, image_vec_270_5);

        lv_obj_t * image_2 = image_create(container_0);
        lv_obj_set_x(image_2, 204);
        lv_obj_set_y(image_2, 0);
        lv_obj_set_width(image_2, 132);
        lv_obj_set_height(image_2, 142);
        lv_image_set_src(image_2, image_vec_270_6);

        lv_obj_t * image_3 = image_create(container_0);
        lv_obj_set_x(image_3, 114);
        lv_obj_set_y(image_3, 0);
        lv_obj_set_width(image_3, 90);
        lv_obj_set_height(image_3, 142);
        lv_image_set_src(image_3, image_vec_270_7);

        lv_obj_t * image_4 = image_create(container_0);
        lv_obj_set_x(image_4, 0);
        lv_obj_set_y(image_4, 0);
        lv_obj_set_width(image_4, 107);
        lv_obj_set_height(image_4, 142);
        lv_image_set_src(image_4, image_vec_270_8);

        lv_obj_t * row_0 = row_create(lv_obj_0, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_x(row_0, 31);
        lv_obj_set_y(row_0, 412);
        lv_obj_set_width(row_0, 780);
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * card_supercharge_0 = card_supercharge_create(row_0, image_icon_supercharge_green_24419, "supercharge", "€0.45", "charge_150", "kWh");
        lv_obj_set_width(card_supercharge_0, 243);
        lv_obj_set_height(card_supercharge_0, 172);

        lv_obj_t * card_tariff_0 = card_tariff_create(row_0, image_icon_zap_19913, "fast", "€0.30", "charge_80", "kWh");
        lv_obj_set_width(card_tariff_0, 243);
        lv_obj_set_height(card_tariff_0, 172);

        lv_obj_t * card_tariff_1 = card_tariff_create(row_0, image_icon_plug_19916, "basic", "€0.15", "charge_overnight", "kWh");
        lv_obj_set_width(card_tariff_1, 243);
        lv_obj_set_height(card_tariff_1, 172);

        lv_obj_t * column_0 = column_create(lv_obj_0, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(column_0, 34);
        lv_obj_set_y(column_0, 211);
        lv_obj_set_width(column_0, 480);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(column_0);
        lv_obj_set_width(label_0, lv_pct(100));
        lv_label_set_translation_tag(label_0, "plugin_start");
        lv_obj_set_style_text_font(label_0, font_gabarito_semibold_28_160001754760742, 0);
        lv_obj_set_style_text_letter_space(label_0, 0, 0);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * row_1 = row_create(column_0, 0, 0, 0, 0, 10, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_1, LV_SIZE_CONTENT);
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * label_1 = label_create(row_1);
        lv_label_set_translation_tag(label_1, "or_pair");
        lv_obj_set_style_text_font(label_1, font_gabarito_regular_16_64000129699707, 0);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * card_0 = card_create(row_1);
        lv_obj_set_flex_flow(card_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(card_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_hor(card_0, 10, 0);
        lv_obj_set_style_pad_ver(card_0, 5, 0);
        lv_obj_set_style_pad_column(card_0, 0, 0);
        lv_obj_set_width(card_0, LV_SIZE_CONTENT);
        lv_obj_set_height(card_0, LV_SIZE_CONTENT);
        lv_obj_set_style_bg_color(card_0, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_radius(card_0, 13, 0);
        lv_obj_t * label_2 = label_create(card_0);
        lv_label_set_text(label_2, "52L205JWHJ");
        lv_obj_set_style_text_font(label_2, font_gabarito_medium_19_200000762939453, 0);
        lv_obj_set_style_text_color(label_2, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * image_5 = image_create(lv_obj_0);
        lv_obj_set_x(image_5, 527);
        lv_obj_set_y(image_5, 42);
        lv_obj_set_width(image_5, 460);
        lv_obj_set_height(image_5, 603);
        lv_image_set_src(image_5, image_plug_large);

        lv_obj_t * card_1 = card_create(lv_obj_0);
        lv_obj_set_flex_flow(card_1, LV_FLEX_FLOW_COLUMN);
        lv_obj_set_style_flex_main_place(card_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_cross_place(card_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(card_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_hor(card_1, 15, 0);
        lv_obj_set_style_pad_ver(card_1, 10, 0);
        lv_obj_set_style_pad_row(card_1, 5, 0);
        lv_obj_set_x(card_1, 829);
        lv_obj_set_y(card_1, 412);
        lv_obj_set_width(card_1, 163);
        lv_obj_set_height(card_1, 172);
        lv_obj_set_style_bg_color(card_1, CONST_SURFACE_CARD_GLOBAL, 0);
        lv_obj_set_style_radius(card_1, 23, 0);
        lv_obj_set_style_shadow_width(card_1, 31, 0);
        lv_obj_set_style_shadow_offset_y(card_1, 10, 0);
        lv_obj_set_style_shadow_spread(card_1, -8, 0);
        lv_obj_set_style_shadow_color(card_1, lv_color_hex(0x141C22), 0);
        lv_obj_set_style_shadow_opa(card_1, 26, 0);
        lv_obj_t * container_1 = container_create(card_1);
        lv_obj_set_flex_flow(container_1, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(container_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(container_1, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(container_1, 0, 0);
        lv_obj_set_style_pad_column(container_1, 5, 0);
        lv_obj_set_width(container_1, lv_pct(100));
        lv_obj_set_height(container_1, LV_SIZE_CONTENT);
        lv_obj_t * image_6 = image_create(container_1);
        lv_obj_set_width(image_6, 18);
        lv_obj_set_height(image_6, 18);
        lv_image_set_src(image_6, image_lucide_nfc);
        lv_obj_set_style_bg_color(image_6, CONST_ON_ACCENT_GLOBAL, 0);
        lv_obj_set_flag(image_6, LV_OBJ_FLAG_SCROLLABLE, false);

        lv_obj_t * label_3 = label_create(container_1);
        lv_label_set_translation_tag(label_3, "tap_or_scan");
        lv_obj_set_style_text_font(label_3, font_gabarito_medium_15_360000610351562, 0);
        lv_obj_set_style_text_color(label_3, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_add_screen_create_event(container_1, LV_EVENT_CLICKED, auth_member_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * qr_code_0 = qr_code_create(card_1);
        lv_obj_set_flag(qr_code_0, LV_OBJ_FLAG_CLICKABLE, true);
        lv_obj_add_screen_create_event(qr_code_0, LV_EVENT_CLICKED, auth_guest_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * nav_header_0 = nav_header_create(lv_obj_0, image_icon_supercharge, "L-04", "ready", &style_chip_header_green_global);
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

