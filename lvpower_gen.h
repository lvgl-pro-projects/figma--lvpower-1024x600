/**
 * @file lvpower_gen.h
 */

#ifndef LVGL_PRO_LVPOWER_GEN_H
#define LVGL_PRO_LVPOWER_GEN_H

#ifndef UI_SUBJECT_STRING_LENGTH
#define UI_SUBJECT_STRING_LENGTH 256
#endif

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



/* Prototypes for target functions, needed by responsive const definitions */

void lvpower_set_target(uint32_t target);
uint32_t lvpower_get_target(void);
bool lvpower_check_target(uint32_t target);

/*********************
 *      DEFINES
 *********************/

#define LVPOWER_TARGET_UNDEFINED  (0 << 1)
#define LVPOWER_TARGET_TARGET1    (1 << 1)
#define LVPOWER_TARGET_ALL        0x0FFFFFFF

/* By default compile for all targets, allowing to switch to any targets at runtime */
#ifndef LVPOWER_COMPILE_TARGET
#define LVPOWER_COMPILE_TARGET LVPOWER_TARGET_ALL
#endif

#define LVPOWER_CHECK_COMPILE_TARGET(target) (LVPOWER_COMPILE_TARGET & (target) ? 1 : 0)

#define CONST_TEXT_PRIMARY_GLOBAL lv_color_hex(0x14181B)
#define CONST_TEXT_SECONDARY_GLOBAL lv_color_hex(0x8B9197)
#define CONST_TEXT_TERTIARY_GLOBAL lv_color_hex(0xAEB4B9)
#define CONST_SURFACE_CANVAS_GLOBAL lv_color_hex(0xF0F4F6)
#define CONST_SURFACE_CARD_GLOBAL lv_color_hex(0xFBFBFC)
#define CONST_BORDER_GLOBAL lv_color_hex(0xE4E6EB)
#define CONST_DIVIDER_GLOBAL lv_color_hex(0xEDEFF1)
#define CONST_TRACK_GLOBAL lv_color_hex(0xE4E7E9)
#define CONST_ACCENT_GLOBAL lv_color_hex(0x0FA958)
#define CONST_ACCENT_BRIGHT_GLOBAL lv_color_hex(0x25E07C)
#define CONST_DANGER_GLOBAL lv_color_hex(0xDC2626)
#define CONST_WARN_GLOBAL lv_color_hex(0xD97706)
#define CONST_ON_ACCENT_GLOBAL lv_color_hex(0xFFFFFF)
#define CONST_SPACE_2_GLOBAL 2
#define CONST_SPACE_4_GLOBAL 4
#define CONST_SPACE_8_GLOBAL 8
#define CONST_SPACE_12_GLOBAL 12
#define CONST_SPACE_16_GLOBAL 16
#define CONST_SPACE_20_GLOBAL 20
#define CONST_SPACE_24_GLOBAL 24
#define CONST_RADIUS_SM_GLOBAL 10
#define CONST_RADIUS_MD_GLOBAL 14
#define CONST_RADIUS_LG_GLOBAL 18
#define CONST_RADIUS_XL_GLOBAL 22
#define CONST_RADIUS_PILL_GLOBAL 999
#define CONST_CONTROL_OFF_GLOBAL lv_color_hex(0xCDD2D6)
#define CONST_TINT_NEUTRAL_GLOBAL lv_color_hex(0xEEF1F3)
#define CONST_TINT_ACCENT_GLOBAL lv_color_hex(0xE7F5EE)
#define CONST_TINT_DANGER_GLOBAL lv_color_hex(0xFCECE9)
#define CONST_TINT_WARN_GLOBAL lv_color_hex(0xFBF0E1)
#define CONST_INK_PRESSED_GLOBAL lv_color_hex(0x2C313A)
#define CONST_DANGER_PRESSED_GLOBAL lv_color_hex(0xB91C1C)
#define CONST_SURFACE_CANVAS_85_GLOBAL lv_color_hex(0xF0F4F6)
#define CONST_BASELIB_ACCENT_GLOBAL lv_color_hex(0x70609C)
#define CONST_BASELIB_ACCENT_TEXT_GLOBAL lv_color_hex(0xFFFFFF)
#define CONST_BASELIB_RADIUS_GLOBAL 8
#define CONST_BASELIB_UNIT_SM_GLOBAL 4


#ifndef LV_XML_EVAL_STRING_BUF_SIZE
    #define LV_XML_EVAL_STRING_BUF_SIZE 256
#endif

/**********************
 *      TYPEDEFS
 **********************/

/**********************
 * GLOBAL VARIABLES
 **********************/

/*-------------------
 * Permanent screens
 *------------------*/

/*----------------
 * Global styles
 *----------------*/

extern lv_style_t style_heading_global;
extern lv_style_t style_font_title_global;
extern lv_style_t style_body_global;
extern lv_style_t style_body_strong_global;
extern lv_style_t style_chip_global;
extern lv_style_t style_caption_global;
extern lv_style_t style_overline_global;
extern lv_style_t style_stat_lg_global;
extern lv_style_t style_stat_md_global;
extern lv_style_t style_hero_global;
extern lv_style_t style_hero_unit_global;
extern lv_style_t style_font_subtitle_global;
extern lv_style_t style_stat_sm_global;
extern lv_style_t style_stat_xs_global;
extern lv_style_t style_font_label_global;
extern lv_style_t style_font_meta_global;
extern lv_style_t style_badge_global;
extern lv_style_t style_micro_global;
extern lv_style_t style_shadow_card_global;
extern lv_style_t style_shadow_modal_global;
extern lv_style_t style_shadow_knob_global;
extern lv_style_t style_screen_base_global;
extern lv_style_t style_bar_b_danger_global;
extern lv_style_t style_bar_b_green_global;
extern lv_style_t style_bar_b_warn_global;
extern lv_style_t style_chip_card_dot_green_global;
extern lv_style_t style_chip_card_dot_grey_global;
extern lv_style_t style_chip_card_dot_red_global;
extern lv_style_t style_chip_card_green_global;
extern lv_style_t style_chip_card_grey_global;
extern lv_style_t style_chip_card_label_green_global;
extern lv_style_t style_chip_card_label_grey_global;
extern lv_style_t style_chip_card_label_red_global;
extern lv_style_t style_chip_card_red_global;
extern lv_style_t style_chip_header_green_global;
extern lv_style_t style_chip_header_grey_global;
extern lv_style_t style_chip_header_orange_global;

/*----------------
 * Fonts
 *----------------*/

/* Targets: any */
extern lv_font_t * font_gabarito_semibold_32;
extern lv_font_t * font_gabarito_semibold_22;
extern lv_font_t * font_gabarito_regular_15;
extern lv_font_t * font_gabarito_semibold_15;
extern lv_font_t * font_gabarito_medium_13;
extern lv_font_t * font_gabarito_regular_12;
extern lv_font_t * font_gabarito_medium_11;
extern lv_font_t * font_gabarito_semibold_34;
extern lv_font_t * font_gabarito_semibold_26;
extern lv_font_t * font_gabarito_bold_132;
extern lv_font_t * font_gabarito_medium_44;
extern lv_font_t * font_gabarito_semibold_18;
extern lv_font_t * font_gabarito_semibold_24;
extern lv_font_t * font_gabarito_semibold_20;
extern lv_font_t * font_gabarito_medium_15;
extern lv_font_t * font_gabarito_regular_13;
extern lv_font_t * font_gabarito_medium_12;
extern lv_font_t * font_gabarito_regular_11;
extern lv_font_t * font_inter_bold_86;
extern lv_font_t * font_inter_semi_bold_41;
extern lv_font_t * font_inter_semi_bold_38;
extern lv_font_t * font_inter_semi_bold_30;
extern lv_font_t * font_inter_semi_bold_13;
extern lv_font_t * font_inter_bold_46;
extern lv_font_t * font_inter_regular_20;
extern lv_font_t * font_inter_medium_15;
extern lv_font_t * font_inter_semi_bold_15;
extern lv_font_t * font_inter_bold_14;
extern lv_font_t * font_inter_semi_bold_12;
extern lv_font_t * font_inter_semi_bold_21;
extern lv_font_t * font_inter_regular_15;
extern lv_font_t * font_inter_medium_12;
extern lv_font_t * font_inter_bold_11;
extern lv_font_t * font_inter_semi_bold_10;
extern lv_font_t * font_inter_regular_12_5;
extern lv_font_t * font_gabarito_semibold_19_200000762939453;
extern lv_font_t * font_gabarito_semibold_43_52000427246094;
extern lv_font_t * font_gabarito_regular_19_200000762939453;
extern lv_font_t * font_gabarito_regular_15_360000610351562;
extern lv_font_t * font_gabarito_semibold_28_160001754760742;
extern lv_font_t * font_gabarito_regular_16_64000129699707;
extern lv_font_t * font_gabarito_medium_19_200000762939453;
extern lv_font_t * font_gabarito_medium_15_360000610351562;
extern lv_font_t * font_gabarito_semibold_24_57600212097168;
extern lv_font_t * font_gabarito_regular_24_57600212097168;
extern lv_font_t * font_gabarito_medium_21_299203872680664;
extern lv_font_t * font_gabarito_semibold_36_044803619384766;
extern lv_font_t * font_gabarito_semibold_40_96000289916992;
extern lv_font_t * font_gabarito_semibold_33_28000259399414;
extern lv_font_t * font_gabarito_semibold_23_040000915527344;
extern lv_font_t * font_gabarito_semibold_40_959999084472656;
extern lv_font_t * font_gabarito_regular_19_19999885559082;
extern lv_font_t * font_gabarito_semibold_19_19999885559082;
extern lv_font_t * font_gabarito_regular_15_359999656677246;
extern lv_font_t * font_gabarito_semibold_33_279998779296875;
extern lv_font_t * font_gabarito_semibold_28_15999984741211;
extern lv_font_t * font_gabarito_semibold_43_52000045776367;
extern lv_font_t * font_gabarito_medium_14_079999923706055;
extern lv_font_t * font_gabarito_semibold_24_576000213623047;
extern lv_font_t * font_gabarito_regular_24_576000213623047;
extern lv_font_t * font_gabarito_medium_21_29920196533203;
extern lv_font_t * font_gabarito_semibold_36_0447998046875;
extern lv_font_t * font_gabarito_bold_168_95999145507812;
extern lv_font_t * font_gabarito_medium_56_31999969482422;
extern lv_font_t * font_gabarito_semibold_23_03999900817871;
extern lv_font_t * font_gabarito_semibold_30_719999313354492;
extern lv_font_t * font_gabarito_regular_16_639999389648438;
extern lv_font_t * font_gabarito_regular_14_079999923706055;
extern lv_font_t * font_gabarito_medium_16_639999389648438;
extern lv_font_t * font_gabarito_semibold_25_599998474121094;
extern lv_font_t * font_gabarito_medium_19_19999885559082;
extern lv_font_t * font_gabarito_medium_15_359999656677246;
extern lv_font_t * font_gabarito_medium_16_64000129699707;


/*----------------
 * Images
 *----------------*/

/* Targets: any */
extern const void * image_qr_receipt_115x115;
extern const void * image_qr_receipt_64x64;
extern const void * image_plug_large;
extern const void * image_back_byd_1039x365;
extern const void * image_back_byd_755x265;
extern const void * image_back_byd_425x149;
extern const void * image_4;
extern const void * image_front_byd;
extern const void * image_icon_supercharge_green_24419;
extern const void * image_icon_zap_19913;
extern const void * image_icon_plug_19916;
extern const void * image_icon_supercharge;
extern const void * image_icon_nfc_19919;
extern const void * image_vec_263_32;
extern const void * image_icon_diagnostic_323653;
extern const void * image_icon_settings_1988;
extern const void * image_vec_263_263;
extern const void * image_icon_back_323661;
extern const void * image_icon_close_30435;
extern const void * image_vec_270_4;
extern const void * image_vec_270_5;
extern const void * image_vec_270_6;
extern const void * image_vec_270_7;
extern const void * image_vec_270_8;
extern const void * image_lucide_nfc;
extern const void * image_vec_273_184;
extern const void * image_vec_273_185;
extern const void * image_vec_273_186;
extern const void * image_vec_328_444;
extern const void * img_wheel_base;
extern const void * img_wheel_rim;
extern const void * img_wheel_base_98;
extern const void * img_wheel_rim_98;

/*----------------
 * Subjects
 *----------------*/

extern lv_subject_t subject_alert_volume;
extern lv_subject_t subject_bay_reserve;
extern lv_subject_t subject_cable_thermal;
extern lv_subject_t subject_card_ending;
extern lv_subject_t subject_chg_limit;
extern lv_subject_t subject_chg_pct;
extern lv_subject_t subject_contactless;
extern lv_subject_t subject_current_cost;
extern lv_subject_t subject_km_added;
extern lv_subject_t subject_power_stage;
extern lv_subject_t subject_preferences_modal_state;
extern lv_subject_t subject_screen_brightness;
extern lv_subject_t subject_time;
extern lv_subject_t subject_wifi;
extern lv_subject_t subject_unbound_card_bay_bar;
extern lv_subject_t subject_unbound_card_bay_value_card_bay_2;
extern lv_subject_t subject_unbound_field_slider_control_slider;
extern lv_subject_t subject_unbound_field_slider_value_field_slider_2;
extern lv_subject_t subject_unbound_row_toggle_control_switch;
extern lv_subject_t subject_unbound_tile_stat_value_tile_stat_2;
extern lv_subject_t subject_language_id;
extern lv_subject_t subject_animations;

/**********************
 * GLOBAL PROTOTYPES
 **********************/

/*----------------
 * Event Callbacks
 *----------------*/

void charge_screen_events_cb(lv_event_t * e);

/**
 * Initialize the component library
 */

void lvpower_init_gen(const char * asset_path);

/**********************
 *      MACROS
 **********************/

/**********************
 *   POST INCLUDES
 **********************/

/*Include all the widgets, components and screens of this library*/
#include "components/bar_b/bar_b_gen.h"
#include "components/base/bar/bar_gen.h"
#include "components/base/button_subtle/button_subtle_gen.h"
#include "components/base/button/button_gen.h"
#include "components/base/card/card_gen.h"
#include "components/base/checkbox/checkbox_gen.h"
#include "components/base/column/column_gen.h"
#include "components/base/container/container_gen.h"
#include "components/base/dropdown/dropdown_gen.h"
#include "components/base/image/image_gen.h"
#include "components/base/label/label_gen.h"
#include "components/base/panel/panel_gen.h"
#include "components/base/qrcode/qrcode_gen.h"
#include "components/base/row/row_gen.h"
#include "components/base/slider/slider_gen.h"
#include "components/base/switch/switch_gen.h"
#include "components/button_danger/button_danger_gen.h"
#include "components/button_icon/button_icon_gen.h"
#include "components/button_primary/button_primary_gen.h"
#include "components/card_bay/card_bay_gen.h"
#include "components/card_supercharge/card_supercharge_gen.h"
#include "components/card_tariff/card_tariff_gen.h"
#include "components/chip_card/chip_card_gen.h"
#include "components/chip_header/chip_header_gen.h"
#include "components/code_qr/code_qr_gen.h"
#include "components/control_checkbox/control_checkbox_gen.h"
#include "components/control_slider/control_slider_gen.h"
#include "components/control_switch/control_switch_gen.h"
#include "components/derived/tile_2/tile_2_gen.h"
#include "components/derived/tile/tile_gen.h"
#include "components/field_dropdown/field_dropdown_gen.h"
#include "components/field_slider/field_slider_gen.h"
#include "components/icon_back/icon_back_gen.h"
#include "components/icon_close/icon_close_gen.h"
#include "components/icon_diagnostic/icon_diagnostic_gen.h"
#include "components/icon_nfc/icon_nfc_gen.h"
#include "components/icon_plug/icon_plug_gen.h"
#include "components/icon_settings/icon_settings_gen.h"
#include "components/icon_supercharge_green/icon_supercharge_green_gen.h"
#include "components/icon_supercharge/icon_supercharge_gen.h"
#include "components/icon_zap/icon_zap_gen.h"
#include "components/nav_header/nav_header_gen.h"
#include "components/preferences_modal/preferences_modal_gen.h"
#include "components/progress/progress_gen.h"
#include "components/qr_code/qr_code_gen.h"
#include "components/row_supercharge/row_supercharge_gen.h"
#include "components/row_tariff/row_tariff_gen.h"
#include "components/row_toggle/row_toggle_gen.h"
#include "components/tile_stat/tile_stat_gen.h"
#include "screens/auth_guest_gen.h"
#include "screens/auth_member_gen.h"
#include "screens/bay_overview_gen.h"
#include "screens/charging_gen.h"
#include "screens/complete_gen.h"
#include "screens/diagnostics_gen.h"
#include "screens/idle_gen.h"
#include "screens/station_settings_gen.h"

#ifdef __cplusplus
} /*extern "C"*/
#endif

#endif /*LVGL_PRO_LVPOWER_GEN_H*/