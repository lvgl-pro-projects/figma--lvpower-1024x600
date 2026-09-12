/**
 * @file row_toggle_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "row_toggle_gen.h"
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

lv_obj_t * row_toggle_create(lv_obj_t * parent, const char * title, const char * subtitle, bool control_switch_on, lv_subject_t * control_switch)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * row_0 = row_create(parent, 0, 0, 12, 12, 12, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_name_static(row_0, "row_toggle_#");
        lv_obj_set_width(row_0, 316);
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);

        lv_obj_t * column_0 = column_create(row_0, 0, 0, 0, 0, 2, 1, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_0, 0);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(column_0);
        lv_obj_set_height(label_0, 18);
        lv_label_set_translation_tag(label_0, title);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);
        lv_obj_add_style(label_0, &style_body_strong_global, 0);

        lv_obj_t * label_1 = label_create(column_0);
        lv_obj_set_height(label_1, 14);
        lv_label_set_translation_tag(label_1, subtitle);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);
        lv_obj_add_style(label_1, &style_caption_global, 0);

        lv_obj_t * control_switch_0 = control_switch_create(row_0);
        lv_obj_set_state(control_switch_0, LV_STATE_CHECKED, control_switch_on);
        lv_obj_bind_checked(control_switch_0, control_switch);

        the_root = row_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

