/**
 * @file preferences_modal_gen.h
 */

#ifndef LVGL_PRO_PREFERENCES_MODAL_GEN_H
#define LVGL_PRO_PREFERENCES_MODAL_GEN_H

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

/**********************
 * GLOBAL PROTOTYPES
 **********************/

lv_obj_t * preferences_modal_create(lv_obj_t * parent, bool close_button_checked, bool control_slider_checked, bool control_switch_on, bool control_checkbox_checked, bool button_primary_disabled);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_PREFERENCES_MODAL_GEN_H*/