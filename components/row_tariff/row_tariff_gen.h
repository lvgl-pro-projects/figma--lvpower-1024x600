/**
 * @file row_tariff_gen.h
 */

#ifndef LVGL_PRO_ROW_TARIFF_GEN_H
#define LVGL_PRO_ROW_TARIFF_GEN_H

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

lv_obj_t * row_tariff_create(lv_obj_t * parent, const void * icon, const char * tier, const char * detail, const char * price, const char * unit, bool pressed, bool checked);

/**********************
 *      MACROS
 **********************/

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_ROW_TARIFF_GEN_H*/