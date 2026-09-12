/**
 * @file complete_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "complete_gen.h"
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

lv_obj_t * complete_create(void)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * lv_obj_0 = lv_obj_create(NULL);
        lv_obj_set_name_static(lv_obj_0, "complete_#");
        lv_obj_set_style_bg_color(lv_obj_0, lv_color_hex(0xF1F1F1), 0);
        lv_obj_set_style_bg_grad_color(lv_obj_0, lv_color_hex(0xECECEC), 0);
        lv_obj_set_style_bg_grad_dir(lv_obj_0, LV_GRAD_DIR_VER, 0);
        lv_obj_set_flag(lv_obj_0, LV_OBJ_FLAG_SCROLLABLE, false);
        lv_obj_set_style_pad_all(lv_obj_0, 0, 0);

        lv_obj_add_style(lv_obj_0, &style_screen_base_global, 0);
        lv_obj_t * row_0 = row_create(lv_obj_0, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_END, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_y(row_0, 138);
        lv_obj_set_width(row_0, LV_SIZE_CONTENT);
        lv_obj_set_height(row_0, LV_SIZE_CONTENT);
        lv_obj_set_align(row_0, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_x(row_0, -90);
        lv_obj_t * column_0 = column_create(row_0, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_END);
        lv_obj_set_width(column_0, LV_SIZE_CONTENT);
        lv_obj_set_height(column_0, LV_SIZE_CONTENT);
        lv_obj_t * label_0 = label_create(column_0);
        lv_obj_set_height(label_0, 49);
        lv_label_set_translation_tag(label_0, "turbo_complete");
        lv_obj_set_style_text_font(label_0, font_gabarito_semibold_40_959999084472656, 0);
        lv_obj_set_style_text_letter_space(label_0, -1, 0);
        lv_obj_set_style_text_color(label_0, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_1 = label_create(column_0);
        lv_obj_set_height(label_1, 23);
        lv_label_set_translation_tag(label_1, "charged_to_80");
        lv_obj_set_style_text_font(label_1, font_gabarito_regular_19_19999885559082, 0);
        lv_obj_set_style_text_color(label_1, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * image_0 = image_create(row_0);
        lv_obj_set_width(image_0, 42);
        lv_obj_set_height(image_0, 44);
        lv_image_set_src(image_0, image_vec_328_444);

        lv_obj_t * img_car = image_create(lv_obj_0);
        lv_obj_set_name(img_car, "img_car");
        lv_obj_set_x(img_car, -824);
        lv_obj_set_y(img_car, 124);
        lv_obj_set_width(img_car, 1039);
        lv_obj_set_height(img_car, 365);
        lv_image_set_src(img_car, image_back_byd_1039x365);

        lv_obj_t * wheel_front_base = image_create(lv_obj_0);
        lv_obj_set_name(wheel_front_base, "wheel_front_base");
        lv_image_set_src(wheel_front_base, img_wheel_base);
        lv_obj_set_x(wheel_front_base, -732);
        lv_obj_set_y(wheel_front_base, 312);

        lv_obj_t * wheel_front_rim = image_create(lv_obj_0);
        lv_obj_set_name(wheel_front_rim, "wheel_front_rim");
        lv_image_set_src(wheel_front_rim, img_wheel_rim);
        lv_obj_set_x(wheel_front_rim, -732);
        lv_obj_set_y(wheel_front_rim, 315);
        lv_obj_set_style_transform_pivot_x(wheel_front_rim, 65, 0);
        lv_obj_set_style_transform_pivot_y(wheel_front_rim, 65, 0);

        lv_obj_t * wheel_back_base = image_create(lv_obj_0);
        lv_obj_set_name(wheel_back_base, "wheel_back_base");
        lv_image_set_src(wheel_back_base, img_wheel_base);
        lv_obj_set_x(wheel_back_base, -38);
        lv_obj_set_y(wheel_back_base, 312);

        lv_obj_t * wheel_back_rim = image_create(lv_obj_0);
        lv_obj_set_name(wheel_back_rim, "wheel_back_rim");
        lv_image_set_src(wheel_back_rim, img_wheel_rim);
        lv_obj_set_x(wheel_back_rim, -38);
        lv_obj_set_y(wheel_back_rim, 315);
        lv_obj_set_style_transform_pivot_x(wheel_back_rim, 65, 0);
        lv_obj_set_style_transform_pivot_y(wheel_back_rim, 65, 0);

        lv_obj_t * row_1 = row_create(lv_obj_0, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_x(row_1, 51);
        lv_obj_set_y(row_1, 297);
        lv_obj_set_width(row_1, LV_SIZE_CONTENT);
        lv_obj_set_height(row_1, LV_SIZE_CONTENT);
        lv_obj_t * card_energy = tile_stat_create(row_1, "42.0", "kWh", "energy_delivered", &subject_unbound_tile_stat_value_tile_stat_2);
        lv_obj_set_name(card_energy, "card_energy");
        lv_obj_set_width(card_energy, 220);
        lv_obj_set_height(card_energy, 123);
        lv_obj_set_style_opa(card_energy, 240, 0);

        lv_obj_t * card_duration = tile_stat_create(row_1, "1h 24m", "", "duration", &subject_unbound_tile_stat_value_tile_stat_2);
        lv_obj_set_name(card_duration, "card_duration");
        lv_obj_set_width(card_duration, 220);
        lv_obj_set_height(card_duration, 123);

        lv_obj_t * card_range = tile_stat_create(row_1, "+268", "km", "range_added", &subject_km_added);
        lv_obj_set_name(card_range, "card_range");
        lv_obj_set_width(card_range, 220);
        lv_obj_set_height(card_range, 123);

        lv_obj_t * card_total = tile_stat_create(row_1, "€18.90", "", "total_cost", &subject_current_cost);
        lv_obj_set_name(card_total, "card_total");
        lv_obj_set_width(card_total, 220);
        lv_obj_set_height(card_total, 123);

        lv_obj_t * row_2 = row_create(lv_obj_0, 0, 0, 0, 0, 15, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
        lv_obj_set_x(row_2, 51);
        lv_obj_set_y(row_2, 481);
        lv_obj_set_width(row_2, LV_SIZE_CONTENT);
        lv_obj_set_height(row_2, LV_SIZE_CONTENT);
        code_qr_create(row_2);

        lv_obj_t * column_1 = column_create(row_2, 0, 0, 0, 0, 3, 0, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START);
        lv_obj_set_width(column_1, LV_SIZE_CONTENT);
        lv_obj_set_height(column_1, LV_SIZE_CONTENT);
        lv_obj_t * label_2 = label_create(column_1);
        lv_obj_set_height(label_2, 28);
        lv_label_set_translation_tag(label_2, "scan_receipt");
        lv_obj_set_style_text_font(label_2, font_gabarito_semibold_23_03999900817871, 0);
        lv_obj_set_style_text_letter_space(label_2, 0, 0);
        lv_obj_set_style_text_color(label_2, CONST_TEXT_PRIMARY_GLOBAL, 0);

        lv_obj_t * label_3 = label_create(column_1);
        lv_obj_set_height(label_3, 20);
        lv_label_set_translation_tag(label_3, "sent_email");
        lv_obj_set_style_text_font(label_3, font_gabarito_regular_16_639999389648438, 0);
        lv_obj_set_style_text_color(label_3, CONST_TEXT_SECONDARY_GLOBAL, 0);

        lv_obj_t * button_primary_0 = button_primary_create(lv_obj_0, "unplug_finish", false, false);
        lv_obj_set_align(button_primary_0, LV_ALIGN_TOP_RIGHT);
        lv_obj_set_x(button_primary_0, -50);
        lv_obj_set_y(button_primary_0, 507);
        lv_obj_add_screen_create_event(button_primary_0, LV_EVENT_CLICKED, idle_create, LV_SCREEN_LOAD_ANIM_NONE, 0, 0);

        lv_obj_t * nav_header_0 = nav_header_create(lv_obj_0, image_icon_supercharge, "L-04", "Complete", &style_chip_header_green_global);
        lv_obj_set_x(nav_header_0, 0);
        lv_obj_set_y(nav_header_0, 0);
        lv_obj_set_width(nav_header_0, 1311);


        /* create animation timeline(s) */
        lv_anim_timeline_t ** at_array = lv_malloc(sizeof(lv_anim_timeline_t *) * _COMPLETE_TIMELINE_CNT);
        at_array[COMPLETE_TIMELINE_LAUNCH] = timeline_launch_create(lv_obj_0);
        lv_obj_set_user_data(lv_obj_0, at_array);
        lv_obj_add_event_cb(lv_obj_0, free_timeline_event_cb, LV_EVENT_DELETE, at_array);

        lv_obj_add_play_timeline_event(lv_obj_0, LV_EVENT_SCREEN_LOADED, complete_get_timeline(lv_obj_0, COMPLETE_TIMELINE_LAUNCH), 0, false);

        the_root = lv_obj_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

lv_anim_timeline_t * complete_get_timeline(lv_obj_t * obj, complete_timeline_t timeline_id)
{
    if (timeline_id >= _COMPLETE_TIMELINE_CNT) {
        LV_LOG_WARN("complete has no timeline with %d ID", timeline_id);
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
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "img_car"));
    lv_anim_set_values(&a, 0, -824);
    lv_anim_set_duration(&a, 2000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "wheel_back_base"));
    lv_anim_set_values(&a, 786, -38);
    lv_anim_set_duration(&a, 2000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "wheel_back_rim"));
    lv_anim_set_values(&a, 786, -38);
    lv_anim_set_duration(&a, 2000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_ROTATION & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "wheel_back_rim"));
    lv_anim_set_values(&a, 3600, 0);
    lv_anim_set_duration(&a, 2000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "wheel_front_base"));
    lv_anim_set_values(&a, 92, -732);
    lv_anim_set_duration(&a, 2000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_X & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "wheel_front_rim"));
    lv_anim_set_values(&a, 92, -732);
    lv_anim_set_duration(&a, 2000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_TRANSFORM_ROTATION & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "wheel_front_rim"));
    lv_anim_set_values(&a, 3600, 0);
    lv_anim_set_duration(&a, 2000);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "card_total"));
    lv_anim_set_values(&a, 0, 225);
    lv_anim_set_duration(&a, 300);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 0, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "card_range"));
    lv_anim_set_values(&a, 0, 225);
    lv_anim_set_duration(&a, 300);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 600, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "card_duration"));
    lv_anim_set_values(&a, 0, 225);
    lv_anim_set_duration(&a, 300);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 1200, &a);

    selector_and_prop = ((LV_STYLE_OPA & 0xff) << 24) | 0;
    lv_anim_init(&a);
    lv_anim_set_custom_exec_cb(&a, int_anim_exec_cb);
    lv_anim_set_var(&a, lv_obj_find_by_name(obj, "card_energy"));
    lv_anim_set_values(&a, 0, 225);
    lv_anim_set_duration(&a, 300);
    lv_anim_set_user_data(&a, (void *)((uintptr_t)selector_and_prop));
    lv_anim_timeline_add(at, 1800, &a);

    return at;
}

static void free_timeline_event_cb(lv_event_t * e)
{
    lv_anim_timeline_t ** at_array = lv_event_get_user_data(e);
    uint32_t i;
    for(i = 0; i < _COMPLETE_TIMELINE_CNT; i++) {
        lv_anim_timeline_delete(at_array[i]);
    }
    lv_free(at_array);
}

