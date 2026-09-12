/**
 * @file lvpower.c
 */

/*********************
 *      INCLUDES
 *********************/

#include "lvpower.h"

/*********************
 *      DEFINES
 *********************/
#define LANG_TAG_COUNT (sizeof(lang_tags) / sizeof(lang_tags[0]))
/**********************
 *      TYPEDEFS
 **********************/

/**********************
 *  STATIC PROTOTYPES
 **********************/
static void on_language_change(lv_event_t * e);
static void language_observer_cb(lv_observer_t *observer, lv_subject_t *subject);
static const char * lang_tag_get_by_index(int index);
static int lang_tag_get_index(const char * str, int def);

static void charging_timer_cb(lv_timer_t *timer);
void screen_brightness_change(lv_observer_t *observer, lv_subject_t *subject);
/**********************
 *  STATIC VARIABLES
 **********************/
static const char * lang_tags[] = {
    "en", "pt", "de", "es", "fr", "hu"
};
static lv_timer_t *charge_timer = NULL;

/**********************
 *      MACROS
 **********************/

/**********************
 *   GLOBAL FUNCTIONS
 **********************/

void lvpower_init(const char * asset_path)
{
    LV_LOG("Initializing custom C code using LVGL v%d.%d.%d", LVGL_VERSION_MAJOR, LVGL_VERSION_MINOR, LVGL_VERSION_PATCH);

    lvpower_init_gen(asset_path);

    /* Add your own custom code here if needed */
    lv_obj_add_event_cb(lv_screen_active(), on_language_change, LV_EVENT_TRANSLATION_LANGUAGE_CHANGED, NULL);

    lv_subject_add_observer(&subject_language_id, language_observer_cb, NULL);

#if defined(LV_EDITOR_PREVIEW) || defined (LV_SIM_BUILD)
    lv_obj_set_style_bg_color(lv_layer_top(), lv_color_hex(0x000000), 0);
    lv_obj_set_style_bg_opa(lv_layer_top(), 0, 0);
    lv_subject_add_observer(&subject_screen_brightness, screen_brightness_change, NULL);
#endif


#if !defined(LV_EDITOR_PREVIEW)
    lv_screen_load(idle_create());
#endif
}

/**********************
 *   STATIC FUNCTIONS
 **********************/


void charge_screen_events_cb(lv_event_t * e)
{

    lv_event_code_t code = lv_event_get_code(e);
    if (code == LV_EVENT_SCREEN_LOAD_START) {
        lv_subject_set_int(&subject_chg_pct, 20);
        lv_subject_set_int(&subject_current_cost, 0);
        lv_subject_set_int(&subject_km_added, 0);
    } else if (code == LV_EVENT_SCREEN_LOADED) {
        if (charge_timer == NULL) {
            charge_timer = lv_timer_create(charging_timer_cb, 500, NULL);
        }
    } else if (code == LV_EVENT_SCREEN_UNLOAD_START) {
        if (charge_timer != NULL) {
            lv_timer_delete(charge_timer);
            charge_timer = NULL;
        }
    }
}


/**********************
*   STATIC FUNCTIONS
**********************/
static void charging_timer_cb(lv_timer_t *timer)
{

    int32_t value = lv_subject_get_int(&subject_chg_pct);

    if (value < 100) {
        lv_subject_set_int(&subject_chg_pct, value + 1);

        lv_subject_set_int(&subject_current_cost, ((value -  19) * 0.35));
        lv_subject_set_int(&subject_km_added, ((value -  19) * 4.5));
    }
    if (value == 100)
    {
        lv_screen_load(complete_create());
    }

    
}


void screen_brightness_change(lv_observer_t *observer, lv_subject_t *subject)
{
#if defined(LV_EDITOR_PREVIEW) || defined (LV_SIM_BUILD)
    int32_t value = lv_subject_get_int(subject);
    lv_obj_set_style_bg_opa(lv_layer_top(), lv_map(value, 0, 100, 255, 0), 0);
#endif
}

static void on_language_change(lv_event_t * e)
{
    const char * language = lv_event_get_param(e);
    LV_LOG_USER("Language changed to %s", language);

    lv_subject_set_int(&subject_language_id, lang_tag_get_index(language, 0));
}

static void language_observer_cb(lv_observer_t *observer, lv_subject_t *subject)
{
    int32_t index = lv_subject_get_int(subject);
    LV_LOG_USER("Language index %d", index);

    lv_translation_set_language(lang_tag_get_by_index(index));

}

static const char * lang_tag_get_by_index(int index)
{
    if(index < 0 || index >= LANG_TAG_COUNT) {
        return lang_tags[0];
    }

    return lang_tags[index];
}

static int lang_tag_get_index(const char * str, int def)
{
    if(str == NULL) {
        return 0;
    }

    for(int i = 0; i < LANG_TAG_COUNT; i++) {
        if(lv_streq(lang_tags[i], str)) {
            return i;
        }
    }

    return 0;
}
