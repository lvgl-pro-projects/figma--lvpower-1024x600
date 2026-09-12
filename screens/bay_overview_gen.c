/**
 * @file bay_overview_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "bay_overview_gen.h"
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

lv_obj_t * bay_overview_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "bay_overview_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xF1F1F1), 0);
        lv_obj_set_style_bg_grad_color(lv_obj_0, lv_color_hex(0xECECEC), 0);
        lv_obj_set_style_bg_grad_dir(lv_obj_0, LV_GRAD_DIR_VER, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);

        lv_obj_add_style(lv_obj_0, &style_screen_base_global, 0);
        lv_obj_t * nav_header_0 = nav_header_create(lv_obj_0, image_icon_supercharge, "L-04", "Operator", &style_chip_header_grey_global);
        lv_obj_set_x(nav_header_0, 0);
        lv_obj_set_y(nav_header_0, 0);
        lv_obj_set_width(nav_header_0, 1311);

        lv_obj_t * card_bay_0 = card_bay_create(lv_obj_0, "Bay L-01", "47", "%", "42 kW", &subject_unbound_card_bay_value_card_bay_2, &subject_unbound_card_bay_bar, "Charging", &style_chip_card_green_global, &style_chip_card_dot_green_global, &style_chip_card_label_green_global, &style_bar_b_green_global);
        lv_obj_set_x(card_bay_0, 51);
        lv_obj_set_y(card_bay_0, 133);
        lv_obj_set_width(card_bay_0, 294);
        lv_obj_set_height(card_bay_0, 189);

        lv_obj_t * card_bay_1 = card_bay_create(lv_obj_0, "Bay L-02", "82", "%", "38 kW", &subject_unbound_card_bay_value_card_bay_2, &subject_unbound_card_bay_bar, "Charging", &style_chip_card_green_global, &style_chip_card_dot_green_global, &style_chip_card_label_green_global, &style_bar_b_green_global);
        lv_obj_set_x(card_bay_1, 364);
        lv_obj_set_y(card_bay_1, 133);
        lv_obj_set_width(card_bay_1, 294);
        lv_obj_set_height(card_bay_1, 189);

        lv_obj_t * card_bay_2 = card_bay_create(lv_obj_0, "Bay L-03", "0", "%", "Ready to charge", &subject_unbound_card_bay_value_card_bay_2, &subject_unbound_card_bay_bar, "Available", &style_chip_card_grey_global, &style_chip_card_dot_grey_global, &style_chip_card_label_grey_global, &style_bar_b_green_global);
        lv_obj_set_x(card_bay_2, 676);
        lv_obj_set_y(card_bay_2, 133);
        lv_obj_set_width(card_bay_2, 294);
        lv_obj_set_height(card_bay_2, 189);

        lv_obj_t * card_bay_3 = card_bay_create(lv_obj_0, "Bay L-04", "21", "%", "42 kW · this unit", &subject_chg_pct, &subject_chg_pct, "Charging", &style_chip_card_green_global, &style_chip_card_dot_green_global, &style_chip_card_label_green_global, &style_bar_b_warn_global);
        lv_obj_set_x(card_bay_3, 51);
        lv_obj_set_y(card_bay_3, 340);
        lv_obj_set_width(card_bay_3, 294);
        lv_obj_set_height(card_bay_3, 189);

        lv_obj_t * card_bay_4 = card_bay_create(lv_obj_0, "Bay L-05", "0", "%", "Check connector", &subject_unbound_card_bay_value_card_bay_2, &subject_unbound_card_bay_bar, "Fault", &style_chip_card_red_global, &style_chip_card_dot_red_global, &style_chip_card_label_red_global, &style_bar_b_danger_global);
        lv_obj_set_x(card_bay_4, 364);
        lv_obj_set_y(card_bay_4, 340);
        lv_obj_set_width(card_bay_4, 294);
        lv_obj_set_height(card_bay_4, 189);

        lv_obj_t * card_bay_5 = card_bay_create(lv_obj_0, "Bay L-06", "0", "%", "Ready to charge", &subject_unbound_card_bay_value_card_bay_2, &subject_unbound_card_bay_bar, "Available", &style_chip_card_grey_global, &style_chip_card_dot_grey_global, &style_chip_card_label_grey_global, &style_bar_b_green_global);
        lv_obj_set_x(card_bay_5, 676);
        lv_obj_set_y(card_bay_5, 340);
        lv_obj_set_width(card_bay_5, 294);
        lv_obj_set_height(card_bay_5, 189);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

