/**
 * @file nav_header_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "nav_header_gen.h"
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

lv_obj_t * nav_header_create(lv_obj_t * parent, const void * icon, const char * station_name, const char * chip_text, lv_style_t * tone)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * row_0 = row_create(parent, 31, 31, 20, 20, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_name_static(row_0, "nav_header_#");
        lv_obj_set_width(row_0, 1024);
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);

        lv_obj_t * row_1 = row_create(row_0, 0, 0, 0, 0, 10, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_1, LV_SIZE_CONTENT);
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * image_0 = image_create(row_1);
        lv_obj_set_width(image_0, 23);
        lv_obj_set_height(image_0, 23);
        lv_image_set_src(image_0, icon);

        lv_obj_t * label_0 = label_create(row_1);
        lv_label_set_translation_tag(label_0, "lvpower");
        lv_obj_set_style_text_font(label_0, font_gabarito_semibold_19_200000762939453, 0);
        lv_obj_set_style_text_letter_space(label_0, 0, 0);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * button_subtle_0 = button_subtle_create(row_1);
        lv_obj_set_flex_flow(button_subtle_0, LV_FLEX_FLOW_ROW);
        lv_obj_set_style_flex_cross_place(button_subtle_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_flex_track_place(button_subtle_0, LV_FLEX_ALIGN_CENTER, 0);
        lv_obj_set_style_pad_all(button_subtle_0, 0, 0);
        lv_obj_set_style_pad_column(button_subtle_0, 10, 0);
        lv_obj_set_width(button_subtle_0, LV_SIZE_CONTENT);
        lv_obj_set_height(button_subtle_0, LV_SIZE_CONTENT);
        lv_obj_t * label_1 = label_create(button_subtle_0);
        lv_label_set_translation_tag(label_1, "station");
        lv_obj_set_style_text_font(label_1, font_gabarito_regular_19_200000762939453, 0);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * label_2 = label_create(button_subtle_0);
        lv_label_set_text(label_2, station_name);
        lv_obj_set_style_text_font(label_2, font_gabarito_regular_19_200000762939453, 0);
        lv_obj_set_style_text_color(label_2, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_add_screen_create_event(button_subtle_0, LV_EVENT_CLICKED, station_settings_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_add_screen_create_event(row_1, LV_EVENT_CLICKED, idle_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * row_2 = row_create(row_0, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_2, LV_SIZE_CONTENT);
        lv_obj_set_height(row_2, LV_SIZE_CONTENT);
        chip_header_create(row_2, tone, chip_text);

        lv_obj_t * label_3 = label_create(row_2);
        lv_label_bind_text(label_3, &subject_time, NULL);
        lv_obj_set_style_text_font(label_3, font_gabarito_semibold_28_160001754760742, 0);
        lv_obj_set_style_text_letter_space(label_3, 0, 0);
        lv_obj_set_style_text_color(label_3, CONST_TEXT_PRIMARY_GLOBAL, 0);

        the_root = row_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

