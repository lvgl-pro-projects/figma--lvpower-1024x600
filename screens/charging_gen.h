/**
 * @file charging_gen.h
 */

#ifndef LVGL_PRO_CHARGING_GEN_H
#define LVGL_PRO_CHARGING_GEN_H

#ifdef __cplusplus
extern "C" {
#endif

/*********************
 *      INCLUDES
 *********************/

#ifdef LV_LVGL_H_INCLUDE_SIMPLE
    #include "lvgl.h"
    #include "lvgl_private.h"
#else
    #include "lvgl/lvgl.h"
    #include "lvgl/lvgl_private.h"
#endif

#if defined(LV_USE_XML) && LV_USE_XML
    #include "lv_xml/lv_xml.h"
#endif

/*********************
 *      DEFINES
 *********************/

/**********************
 *      TYPEDEFS
 **********************/

typedef enum {
    CHARGING_TIMELINE_LAUNCH = 0,
    _CHARGING_TIMELINE_CNT = 1
}charging_timeline_t;

/**********************
 * GLOBAL PROTOTYPES
 **********************/



lv_obj_t * charging_create(void);

/**
 * Get a timeline of a charging
 * @param obj          pointer to a charging component
 * @param timeline_id  ID of the the timeline
 * @return             pointer to the timeline or NULL if not found
 */
lv_anim_timeline_t * charging_get_timeline(lv_obj_t * obj, charging_timeline_t timeline_id);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_CHARGING_GEN_H*/