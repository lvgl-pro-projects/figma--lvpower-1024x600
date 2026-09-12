/**
 * @file field_slider_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "field_slider_gen.h"
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

lv_obj_t * field_slider_create(lv_obj_t * parent, const char * title, const char * value_field_slider, bool control_slider_checked, lv_subject_t * value_field_slider_2, lv_subject_t * control_slider)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * column_0 = column_create(parent, 0, 0, 16, 16, 12, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_name_static(column_0, "field_slider_#");
        lv_obj_set_width(column_0, 320);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);

        lv_obj_t * row_0 = row_create(column_0, 0, 0, 0, 0, 0, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_0, lv_pct(100));
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(row_0);
        lv_label_set_translation_tag(label_0, title);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);
        lv_obj_add_style(label_0, &style_body_strong_global, 0);

        lv_obj_t * label_1 = label_create(row_0);
        lv_label_bind_text(label_1, value_field_slider_2, "%d%%");
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);
        lv_obj_add_style(label_1, &style_body_strong_global, 0);

        lv_obj_t * control_slider_0 = control_slider_create(column_0, 55);
        lv_obj_set_width(control_slider_0, lv_pct(100));
        lv_obj_set_state(control_slider_0, LV_STATE_CHECKED, control_slider_checked);
        lv_slider_bind_value(control_slider_0, control_slider);

        the_root = column_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

