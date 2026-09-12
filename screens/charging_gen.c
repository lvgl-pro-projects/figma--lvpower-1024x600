/**
 * @file charging_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "charging_gen.h"
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

static lv_anim_timeline_t * timeline_launch_create(lv_obj_t * obj);
static void free_timeline_event_cb(lv_event_t * e);

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

lv_obj_t * charging_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "charging_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xF1F1F1), 0);
        lv_obj_set_style_bg_grad_color(lv_obj_0, lv_color_hex(0xECECEC), 0);
        lv_obj_set_style_bg_grad_dir(lv_obj_0, LV_GRAD_DIR_VER, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);

        lv_obj_add_style(lv_obj_0, &style_screen_base_global, 0);
        lv_obj_t * row_0 = row_create(lv_obj_0, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(row_0, 714);
        lv_obj_set_y(row_0, 69);
        lv_obj_set_width(row_0, LV_SIZE_CONTENT);
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(row_0);
        lv_obj_set_height(label_0, 203);
        lv_label_bind_text(label_0, &subject_chg_pct, "%d");
        lv_obj_set_style_text_font(label_0, font_gabarito_bold_168_95999145507812, 0);
        lv_obj_set_style_text_letter_space(label_0, -6, 0);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_1 = label_create(row_0);
        lv_obj_set_height(label_1, 68);
        lv_label_set_text(label_1, "%");
        lv_obj_set_style_text_font(label_1, font_gabarito_medium_56_31999969482422, 0);
        lv_obj_set_style_text_letter_space(label_1, -1, 0);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * column_0 = column_create(lv_obj_0, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(column_0, 50);
        lv_obj_set_y(column_0, 130);
        lv_obj_set_width(column_0, LV_SIZE_CONTENT);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_t * row_1 = row_create(column_0, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(row_1, LV_SIZE_CONTENT);
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * container_0 = container_create(row_1);
        lv_obj_set_width(container_0, 25);
        lv_obj_set_height(container_0, 26);
        lv_obj_t * image_0 = image_create(container_0);
        lv_obj_set_x(image_0, 3);
        lv_obj_set_y(image_0, 3);
        lv_obj_set_width(image_0, 18);
        lv_obj_set_height(image_0, 20);
        lv_image_set_src(image_0, image_vec_273_184);

        lv_obj_t * image_1 = image_create(container_0);
        lv_obj_set_x(image_1, 13);
        lv_obj_set_y(image_1, 14);
        lv_obj_set_width(image_1, 12);
        lv_obj_set_height(image_1, 12);
        lv_image_set_src(image_1, image_vec_273_185);

        lv_obj_t * image_2 = image_create(container_0);
        lv_obj_set_x(image_2, 0);
        lv_obj_set_y(image_2, 0);
        lv_obj_set_width(image_2, 12);
        lv_obj_set_height(image_2, 12);
        lv_image_set_src(image_2, image_vec_273_186);

        lv_obj_t * container_1 = container_create(row_1);
        lv_obj_set_width(container_1, LV_SIZE_CONTENT);
        lv_obj_set_height(container_1, 54);
        lv_obj_t * label_2 = label_create(container_1);
        lv_obj_set_x(label_2, 0);
        lv_obj_set_y(label_2, 0);
        lv_obj_set_height(label_2, 28);
        lv_label_set_translation_tag(label_2, "supercharge_80");
        lv_obj_set_style_text_font(label_2, font_gabarito_semibold_23_03999900817871, 0);
        lv_obj_set_style_text_letter_space(label_2, 0, 0);
        lv_obj_set_style_text_color(label_2, CONST_ACCENT_GLOBAL, 0);

        lv_obj_t * label_3 = label_create(container_1);
        lv_obj_set_x(label_3, 0);
        lv_obj_set_y(label_3, 31);
        lv_obj_set_height(label_3, 23);
        lv_label_set_translation_tag(label_3, "time_left");
        lv_obj_set_style_text_font(label_3, font_gabarito_regular_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_3, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * row_2 = row_create(lv_obj_0, 0, 0, 0, 0, 31, 0, LV_FLEX_ALIGN_SPACE_BETWEEN, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_x(row_2, 55);
        lv_obj_set_y(row_2, 467);
        lv_obj_set_width(row_2, 913);
        lv_obj_set_height(row_2, LV_SIZE_CONTENT);
        lv_obj_t * row_3 = row_create(row_2, 0, 0, 0, 0, 31, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(row_3, LV_SIZE_CONTENT);
        lv_obj_set_height(row_3, LV_SIZE_CONTENT);
        lv_obj_t * column_1 = column_create(row_3, 0, 0, 0, 0, -3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_1, LV_SIZE_CONTENT);
        lv_obj_set_height(column_1, LV_SIZE_CONTENT);
        lv_obj_t * row_4 = row_create(column_1, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_4, LV_SIZE_CONTENT);
        lv_obj_set_height(row_4, LV_SIZE_CONTENT);
        lv_obj_t * label_4 = label_create(row_4);
        lv_obj_set_height(label_4, 37);
        lv_label_set_text(label_4, "42");
        lv_obj_set_style_text_font(label_4, font_gabarito_semibold_30_719999313354492, 0);
        lv_obj_set_style_text_letter_space(label_4, -1, 0);
        lv_obj_set_style_text_color(label_4, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_5 = label_create(row_4);
        lv_obj_set_height(label_5, 20);
        lv_label_set_text(label_5, "kW");
        lv_obj_set_style_text_font(label_5, font_gabarito_regular_16_639999389648438, 0);
        lv_obj_set_style_text_color(label_5, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * label_6 = label_create(column_1);
        lv_obj_set_height(label_6, 17);
        lv_label_set_translation_tag(label_6, "power");
        lv_obj_set_style_text_font(label_6, font_gabarito_regular_14_079999923706055, 0);
        lv_obj_set_style_text_color(label_6, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * column_2 = column_create(row_3, 0, 0, 0, 0, -3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_2, LV_SIZE_CONTENT);
        lv_obj_set_height(column_2, LV_SIZE_CONTENT);
        lv_obj_t * row_5 = row_create(column_2, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_5, LV_SIZE_CONTENT);
        lv_obj_set_height(row_5, LV_SIZE_CONTENT);
        lv_obj_t * label_7 = label_create(row_5);
        lv_obj_set_height(label_7, 37);
        lv_label_set_text(label_7, "18.5");
        lv_obj_set_style_text_font(label_7, font_gabarito_semibold_30_719999313354492, 0);
        lv_obj_set_style_text_letter_space(label_7, -1, 0);
        lv_obj_set_style_text_color(label_7, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_8 = label_create(row_5);
        lv_obj_set_height(label_8, 20);
        lv_label_set_text(label_8, "kWh");
        lv_obj_set_style_text_font(label_8, font_gabarito_regular_16_639999389648438, 0);
        lv_obj_set_style_text_color(label_8, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * label_9 = label_create(column_2);
        lv_obj_set_height(label_9, 17);
        lv_label_set_translation_tag(label_9, "energy");
        lv_obj_set_style_text_font(label_9, font_gabarito_regular_14_079999923706055, 0);
        lv_obj_set_style_text_color(label_9, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * column_3 = column_create(row_3, 0, 0, 0, 0, -3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_3, LV_SIZE_CONTENT);
        lv_obj_set_height(column_3, LV_SIZE_CONTENT);
        lv_obj_t * row_6 = row_create(column_3, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(row_6, LV_SIZE_CONTENT);
        lv_obj_set_height(row_6, LV_SIZE_CONTENT);
        lv_obj_t * label_10 = label_create(row_6);
        lv_obj_set_height(label_10, 37);
        lv_label_bind_text(label_10, &subject_km_added, "+%d");
        lv_obj_set_style_text_font(label_10, font_gabarito_semibold_30_719999313354492, 0);
        lv_obj_set_style_text_letter_space(label_10, -1, 0);
        lv_obj_set_style_text_color(label_10, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_11 = label_create(row_6);
        lv_obj_set_height(label_11, 20);
        lv_label_set_text(label_11, "km");
        lv_obj_set_style_text_font(label_11, font_gabarito_regular_16_639999389648438, 0);
        lv_obj_set_style_text_color(label_11, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * label_12 = label_create(column_3);
        lv_obj_set_height(label_12, 17);
        lv_label_set_translation_tag(label_12, "range_added");
        lv_obj_set_style_text_font(label_12, font_gabarito_regular_14_079999923706055, 0);
        lv_obj_set_style_text_color(label_12, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * column_4 = column_create(row_3, 0, 0, 0, 0, -3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_4, LV_SIZE_CONTENT);
        lv_obj_set_height(column_4, LV_SIZE_CONTENT);
        lv_obj_t * row_7 = row_create(column_4, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(row_7, LV_SIZE_CONTENT);
        lv_obj_set_height(row_7, LV_SIZE_CONTENT);
        lv_obj_t * label_13 = label_create(row_7);
        lv_obj_set_height(label_13, 37);
        lv_label_bind_text(label_13, &subject_current_cost, "€%d");
        lv_obj_set_style_text_font(label_13, font_gabarito_semibold_30_719999313354492, 0);
        lv_obj_set_style_text_letter_space(label_13, -1, 0);
        lv_obj_set_style_text_color(label_13, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_14 = label_create(column_4);
        lv_obj_set_height(label_14, 17);
        lv_label_set_translation_tag(label_14, "cost_so_far");
        lv_obj_set_style_text_font(label_14, font_gabarito_regular_14_079999923706055, 0);
        lv_obj_set_style_text_color(label_14, CONST_TEXT_TERTIARY_GLOBAL, 0);

        lv_obj_t * row_8 = row_create(row_2, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_width(row_8, LV_SIZE_CONTENT);
        lv_obj_set_height(row_8, LV_SIZE_CONTENT);
        lv_obj_t * button_icon_0 = button_icon_create(row_8, image_icon_diagnostic_323653, false);
        lv_obj_set_width(button_icon_0, 56);
        lv_obj_set_height(button_icon_0, 56);
        lv_obj_add_screen_create_event(button_icon_0, LV_EVENT_CLICKED, diagnostics_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * button_icon_1 = button_icon_create(row_8, image_icon_settings_1988, false);
        lv_obj_set_width(button_icon_1, 56);
        lv_obj_set_height(button_icon_1, 56);
        lv_obj_add_subject_set_int_event(button_icon_1, &subject_preferences_modal_state, LV_EVENT_CLICKED, 1);

        lv_obj_t * button_danger_0 = button_danger_create(row_8, "stop_charging", false);
        lv_obj_set_height(button_danger_0, 56);
        lv_obj_add_screen_create_event(button_danger_0, LV_EVENT_CLICKED, complete_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * car_container = container_create(lv_obj_0);
        lv_obj_set_name(car_container, "car_container");
        lv_obj_set_x(car_container, 133);
        lv_obj_set_y(car_container, 188);
        lv_obj_set_width(car_container, 755);
        lv_obj_set_height(car_container, 265);
        lv_obj_t * image_3 = image_create(car_container);
        lv_obj_set_x(image_3, 0);
        lv_obj_set_y(image_3, 0);
        lv_obj_set_width(image_3, 755);
        lv_obj_set_height(image_3, 265);
        lv_image_set_src(image_3, image_back_byd_755x265);

        lv_obj_t * progress_0 = progress_create(car_container, &subject_chg_pct);
        lv_obj_set_x(progress_0, 179);
        lv_obj_set_y(progress_0, 90);
        lv_obj_set_width(progress_0, 403);
        lv_obj_set_height(progress_0, 38);

        lv_obj_t * image_4 = image_create(car_container);
        lv_obj_set_x(image_4, 0);
        lv_obj_set_y(image_4, 0);
        lv_obj_set_width(image_4, 755);
        lv_obj_set_height(image_4, 265);
        lv_image_set_src(image_4, image_front_byd);

        lv_obj_t * image_5 = image_create(car_container);
        lv_image_set_src(image_5, img_wheel_base_98);
        lv_obj_set_x(image_5, 66);
        lv_obj_set_y(image_5, 140);

        lv_obj_t * wheel_front_rim = image_create(car_container);
        lv_obj_set_name(wheel_front_rim, "wheel_front_rim");
        lv_image_set_src(wheel_front_rim, img_wheel_rim_98);
        lv_obj_set_x(wheel_front_rim, 66);
        lv_obj_set_y(wheel_front_rim, 140);
        lv_obj_set_style_transform_pivot_x(wheel_front_rim, 48, 0);
        lv_obj_set_style_transform_pivot_y(wheel_front_rim, 48, 0);
        lv_obj_set_style_transform_rotation(wheel_front_rim, 1800, 0);

        lv_obj_t * image_6 = image_create(car_container);
        lv_image_set_src(image_6, img_wheel_base_98);
        lv_obj_set_x(image_6, 570);
        lv_obj_set_y(image_6, 138);

        lv_obj_t * wheel_back_rim = image_create(car_container);
        lv_obj_set_name(wheel_back_rim, "wheel_back_rim");
        lv_image_set_src(wheel_back_rim, img_wheel_rim_98);
        lv_obj_set_x(wheel_back_rim, 570);
        lv_obj_set_y(wheel_back_rim, 138);
        lv_obj_set_style_transform_pivot_x(wheel_back_rim, 48, 0);
        lv_obj_set_style_transform_pivot_y(wheel_back_rim, 48, 0);
        lv_obj_set_style_transform_rotation(wheel_back_rim, 1800, 0);

        lv_obj_t * nav_header_0 = nav_header_create(lv_obj_0, image_icon_supercharge, "L-04", "Charging", &style_chip_header_green_global);
        lv_obj_set_x(nav_header_0, 0);
        lv_obj_set_y(nav_header_0, 0);
        lv_obj_set_width(nav_header_0, 1311);

        lv_obj_t * bar_b_0 = bar_b_create(lv_obj_0, 59, &style_bar_b_green_global);
        lv_obj_set_x(bar_b_0, 54);
        lv_obj_set_y(bar_b_0, 561);
        lv_obj_set_width(bar_b_0, 914);
        lv_obj_set_height(bar_b_0, 10);
        lv_bar_bind_value(bar_b_0, &subject_chg_pct);

        lv_obj_add_subject_set_int_event(lv_obj_0, &subject_preferences_modal_state, LV_EVENT_SCREEN_LOADED, 0);
        lv_obj_t * lv_obj_1 = lv_obj_create(lv_obj_0);
        lv_obj_set_width(lv_obj_1, lv_pct(100));
        lv_obj_set_height(lv_obj_1, lv_pct(100));
        lv_obj_set_x(lv_obj_1, 0);
        lv_obj_set_y(lv_obj_1, 0);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_FLOATING, true);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_IGNORE_LAYOUT, true);
        lv_obj_set_flag(lv_obj_1, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_radius(lv_obj_1, 0, 0);
        lv_obj_set_style_border_width(lv_obj_1, 0, 0);
        lv_obj_set_style_pad_all(lv_obj_1, 0, 0);
        lv_obj_set_style_bg_opa(lv_obj_1, (255 * 80 / 100), 0);
        lv_obj_set_style_bg_color(lv_obj_1, lv_color_hex(0x000000), 0);
        lv_obj_bind_flag_if_eq(lv_obj_1, &subject_preferences_modal_state, LV_OBJ_FLAG_HIDDEN, 0);
        lv_obj_add_subject_set_int_event(lv_obj_1, &subject_preferences_modal_state, LV_EVENT_CLICKED, 0);
        lv_obj_t * preferences_modal_0 = preferences_modal_create(lv_obj_1, false, false, false, false, false);
        lv_obj_set_x(preferences_modal_0, 333);
        lv_obj_set_y(preferences_modal_0, 93);

        lv_obj_add_event_cb(lv_obj_0, charge_screen_events_cb, LV_EVENT_ALL, NULL);

        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _CHARGING_TIMELINE_CNT);
        at_array[CHARGING_TIMELINE_LAUNCH] = timeline_launch_create(lv_obj_0);
        lv_obj_set_user_data(lv_obj_0, at_array);
        lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, charging_get_timeline(lv_obj_0, CHARGING_TIMELINE_LAUNCH), 0, false);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * charging_get_timeline(lv_obj_t * obj, charging_timeline_t timeline_id)
{
    if (timeline_id >= _CHARGING_TIMELINE_CNT) {
        LV_LOG_WARN("charging has no timeline with %d ID", timeline_id);
        return NULL;
    }

    lv_anim_timeline_t ** at_array = lv_obj_get_user_data(obj);
    return at_array[timeline_id];
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

/* Helper function to execute animations */
static void int_anim_exec_cb(lv_anim_t * a, int32_t v)
{
    uint32_t data = (lv_uintptr_t)lv_anim_get_user_data(a);
    lv_style_prop_t prop = data >> 24;
    lv_style_selector_t selector = data & 0x00ffffff;

    lv_style_value_t style_value;
    style_value.num = v;
    lv_obj_set_local_style_prop(a->var, prop, style_value, selector);
}

static lv_anim_timeline_t * timeline_launch_create(lv_obj_t * obj)
{
    lv_anim_timeline_t * at = lv_anim_timeline_create();
    lv_anim_timeline_t * at_to_merge = NULL;

    lv_anim_t a;
    uint32_t selector_and_prop;

    selector_and_prop = ((LV_STYLE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "car_container"));
    lv_anim_set_values(&a, 600, 133);
    lv_anim_set_duration(&a, 1000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_ROTATION & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "wheel_front_rim"));
    lv_anim_set_values(&a, 4000, 0);
    lv_anim_set_duration(&a, 1000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_ROTATION & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "wheel_back_rim"));
    lv_anim_set_values(&a, 4000, 0);
    lv_anim_set_duration(&a, 1000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_set_early_apply(&a, true);
    lv_anim_timeline_add(at, 0, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _CHARGING_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

