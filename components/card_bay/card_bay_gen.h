/**
 * @file card_bay_gen.h
 */

#ifndef LVGL_PRO_CARD_BAY_GEN_H
#define LVGL_PRO_CARD_BAY_GEN_H

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

lv_obj_t * card_bay_create(lv_obj_t * parent, const char * bay_name, const char * value_card_bay, const char * unit, const char * meta, lv_subject_t * value_card_bay_2, lv_subject_t * bar, const char * chip_text, lv_style_t * tone, lv_style_t * tone_dot, lv_style_t * tone_label, lv_style_t * bartone);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_CARD_BAY_GEN_H*/