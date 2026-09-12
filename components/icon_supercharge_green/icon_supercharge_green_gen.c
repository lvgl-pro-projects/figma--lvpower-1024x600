/**
 * @file icon_supercharge_green_gen.c
 * @brief Template source file for LVGL objects
 */

/*********************
 *      INCLUDES
 *********************/

#include "icon_supercharge_green_gen.h"
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

lv_obj_t * icon_supercharge_green_create(lv_obj_t * parent)
{
    LV_TRACE_OBJ_CREATE("begin");


    lv_obj_t * the_root = NULL;

    #if LVPOWER_CHECK_COMPILE_TARGET(LVPOWER_TARGET_ALL)
    if (lvpower_check_target(LVPOWER_TARGET_ALL)) {
        lv_obj_t * image_0 = image_create(parent);
        lv_obj_set_name_static(image_0, "icon_supercharge_green_#");
        lv_obj_set_width(image_0, 23);
        lv_obj_set_height(image_0, 24);
        lv_image_set_src(image_0, image_icon_supercharge_green_24419);
        lv_obj_set_flag(image_0, LV_OBJ_FLAG_SCROLLABLE, false);

        the_root = image_0;
    }
    #endif

    LV_TRACE_OBJ_CREATE("finished");

    return the_root;
}

/**********************
 *   STATIC FUNCTIONS
 **********************/

