// This file was generated by SquareLine Studio
// SquareLine Studio version: SquareLine Studio 1.2.3
// LVGL version: 8.3.4
// Project name: Rabbit

#include "ui.h"
#include "ui_helpers.h"

///////////////////// VARIABLES ////////////////////
void bounce_Animation( lv_obj_t *TargetObject, int delay);
void earsDown_Animation( lv_obj_t *TargetObject, int delay);
void earsUp_Animation( lv_obj_t *TargetObject, int delay);
void ears_Animation( lv_obj_t *TargetObject, int delay);
void ui_event_homeScreen( lv_event_t * e);
lv_obj_t *ui_homeScreen;
lv_obj_t *ui_rabbit;
lv_obj_t *ui_earRight;
lv_obj_t *ui_body;
lv_obj_t *ui_earLeft;
lv_obj_t *ui_timeLabel;
lv_obj_t *ui_batteryLabel;
lv_obj_t *ui_alertlabel;
void ui_event_musicPanel( lv_event_t * e);
lv_obj_t *ui_musicPanel;
void ui_event_musicPrevious( lv_event_t * e);
lv_obj_t *ui_musicPrevious;
void ui_event_musicPlay( lv_event_t * e);
lv_obj_t *ui_musicPlay;
void ui_event_musicNext( lv_event_t * e);
lv_obj_t *ui_musicNext;
void ui_event_weatherScreen( lv_event_t * e);
lv_obj_t *ui_weatherScreen;
lv_obj_t *ui_tempLabel;
lv_obj_t *ui_cityLabel;
lv_obj_t *ui_weatherIcon;
lv_obj_t *ui_rainLabel;
lv_obj_t *ui_humidityLabel;
lv_obj_t *ui_windLabel;
lv_obj_t *ui_forecastPanel;
lv_obj_t *ui_forecastItem;
lv_obj_t *ui_forecastDay;
lv_obj_t *ui_forecastIcon;
lv_obj_t *ui_forecastLabel;
lv_obj_t *ui_forecastTitle;
lv_obj_t *ui_tempHighLabel;
lv_obj_t *ui_tempLowLabel;
void ui_event_notificationScreen( lv_event_t * e);
lv_obj_t *ui_notificationScreen;
lv_obj_t *ui_notificationPanel;
lv_obj_t *ui_notificationItem;
lv_obj_t *ui_notificationTitle;
lv_obj_t *ui_notificationTime;
lv_obj_t *ui_notificationText;
void ui_event____initial_actions0( lv_event_t * e);
lv_obj_t *ui____initial_actions0;
const lv_img_dsc_t *ui_imgset_1214590012[1] = {&ui_img_2052995423};
const lv_img_dsc_t *ui_imgset_1214590010[1] = {&ui_img_484901176};
const lv_img_dsc_t *ui_imgset_back_[1] = {&ui_img_back_32_png};
const lv_img_dsc_t *ui_imgset_back_l[1] = {&ui_img_back_l32_png};
const lv_img_dsc_t *ui_imgset_close_l[1] = {&ui_img_close_l32_png};
const lv_img_dsc_t *ui_imgset_dy[8] = {&ui_img_dy0_png, &ui_img_dy1_png, &ui_img_dy2_png, &ui_img_dy3_png, &ui_img_dy4_png, &ui_img_dy5_png, &ui_img_dy6_png, &ui_img_dy7_png};
const lv_img_dsc_t *ui_imgset_electron_[1] = {&ui_img_electron_32_png};
const lv_img_dsc_t *ui_imgset_heart[1] = {&ui_img_heart2_png};
const lv_img_dsc_t *ui_imgset_hw[1] = {&ui_img_hw21_png};
const lv_img_dsc_t *ui_imgset_kb_[2] = {&ui_img_kb_1_png, &ui_img_kb_2_png};
const lv_img_dsc_t *ui_imgset_kg_[2] = {&ui_img_kg_1_png, &ui_img_kg_2_png};
const lv_img_dsc_t *ui_imgset_k_[2] = {&ui_img_k_1_png, &ui_img_k_2_png};
const lv_img_dsc_t *ui_imgset_next_[1] = {&ui_img_next_32_png};
const lv_img_dsc_t *ui_imgset_next_l[1] = {&ui_img_next_l32_png};
const lv_img_dsc_t *ui_imgset_nt[8] = {&ui_img_nt0_png, &ui_img_nt1_png, &ui_img_nt2_png, &ui_img_nt3_png, &ui_img_nt4_png, &ui_img_nt5_png, &ui_img_nt6_png, &ui_img_nt7_png};
const lv_img_dsc_t *ui_imgset_r_body_[1] = {&ui_img_r_body_90_png};
const lv_img_dsc_t *ui_imgset_r_ear_[1] = {&ui_img_r_ear_54_png};
const lv_img_dsc_t *ui_imgset_search_[1] = {&ui_img_search_32_png};

///////////////////// TEST LVGL SETTINGS ////////////////////
#if LV_COLOR_DEPTH != 16
    #error "LV_COLOR_DEPTH should be 16bit to match SquareLine Studio's settings"
#endif
#if LV_COLOR_16_SWAP !=1
    #error "LV_COLOR_16_SWAP should be 1 to match SquareLine Studio's settings"
#endif

///////////////////// ANIMATIONS ////////////////////
void bounce_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 1000);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_y );
lv_anim_set_values(&PropertyAnimation_0, 0, 30 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_ease_out);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 1000);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE );
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_start(&PropertyAnimation_0);

}
void earsDown_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 500);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle );
lv_anim_set_values(&PropertyAnimation_0, 0, 360 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_ease_out);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 0);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_start(&PropertyAnimation_0);

}
void earsUp_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 500);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle );
lv_anim_set_values(&PropertyAnimation_0, 360, 0 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_ease_out);
lv_anim_set_delay( &PropertyAnimation_0, delay + 0 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 0);
lv_anim_set_playback_delay(&PropertyAnimation_0, 0);
lv_anim_set_repeat_count(&PropertyAnimation_0, 0);
lv_anim_set_repeat_delay(&PropertyAnimation_0, 0);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_start(&PropertyAnimation_0);

}
void ears_Animation( lv_obj_t *TargetObject, int delay)
{
ui_anim_user_data_t *PropertyAnimation_0_user_data = lv_mem_alloc(sizeof(ui_anim_user_data_t));
PropertyAnimation_0_user_data->target = TargetObject;
PropertyAnimation_0_user_data->val = -1;
lv_anim_t PropertyAnimation_0;
lv_anim_init(&PropertyAnimation_0);
lv_anim_set_time(&PropertyAnimation_0, 500);
lv_anim_set_user_data(&PropertyAnimation_0, PropertyAnimation_0_user_data);
lv_anim_set_custom_exec_cb(&PropertyAnimation_0, _ui_anim_callback_set_image_angle );
lv_anim_set_values(&PropertyAnimation_0, 0, 360 );
lv_anim_set_path_cb( &PropertyAnimation_0, lv_anim_path_ease_out);
lv_anim_set_delay( &PropertyAnimation_0, delay + 2000 );
lv_anim_set_deleted_cb( &PropertyAnimation_0, _ui_anim_callback_free_user_data );
lv_anim_set_playback_time(&PropertyAnimation_0, 500);
lv_anim_set_playback_delay(&PropertyAnimation_0, 6000);
lv_anim_set_repeat_count(&PropertyAnimation_0, LV_ANIM_REPEAT_INFINITE );
lv_anim_set_repeat_delay(&PropertyAnimation_0, 1500);
lv_anim_set_early_apply( &PropertyAnimation_0, false );
lv_anim_start(&PropertyAnimation_0);

}

///////////////////// FUNCTIONS ////////////////////
void ui_event_homeScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT  ) {
      _ui_screen_change( ui_weatherScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
      _ui_screen_change( ui_notificationScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_TOP  ) {
      _ui_flag_modify( ui_musicPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_REMOVE);
}
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_BOTTOM  ) {
      _ui_flag_modify( ui_musicPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_musicPanel( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      _ui_flag_modify( ui_musicPanel, LV_OBJ_FLAG_HIDDEN, _UI_MODIFY_FLAG_ADD);
}
}
void ui_event_musicPrevious( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      onMusicPrevious( e );
}
}
void ui_event_musicPlay( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      onMusicPlay( e );
}
}
void ui_event_musicNext( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_CLICKED) {
      onMusicNext( e );
}
}
void ui_event_weatherScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_RIGHT  ) {
      _ui_screen_change( ui_homeScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      onWeatherOpen( e );
}
}
void ui_event_notificationScreen( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_GESTURE &&  lv_indev_get_gesture_dir(lv_indev_get_act()) == LV_DIR_LEFT  ) {
      _ui_screen_change( ui_homeScreen, LV_SCR_LOAD_ANIM_FADE_ON, 500, 0);
}
if ( event_code == LV_EVENT_SCREEN_LOADED) {
      onNotificationOpen( e );
}
}
void ui_event____initial_actions0( lv_event_t * e) {
    lv_event_code_t event_code = lv_event_get_code(e);lv_obj_t * target = lv_event_get_target(e);
if ( event_code == LV_EVENT_SCREEN_LOAD_START) {
      bounce_Animation(ui_rabbit, 0);
      ears_Animation(ui_earRight, 0);
      ears_Animation(ui_earLeft, 0);
}
}

///////////////////// SCREENS ////////////////////
void ui_homeScreen_screen_init(void)
{
ui_homeScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_homeScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_homeScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_homeScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_rabbit = lv_obj_create(ui_homeScreen);
lv_obj_set_width( ui_rabbit, 201);
lv_obj_set_height( ui_rabbit, 172);
lv_obj_set_x( ui_rabbit, 0 );
lv_obj_set_y( ui_rabbit, 22 );
lv_obj_set_align( ui_rabbit, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_rabbit, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_rabbit, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_rabbit, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_rabbit, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_rabbit, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_earRight = lv_img_create(ui_rabbit);
lv_img_set_src(ui_earRight, &ui_img_r_ear_54_png);
lv_obj_set_width( ui_earRight, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_earRight, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_earRight, 74 );
lv_obj_set_y( ui_earRight, -62 );
lv_obj_set_align( ui_earRight, LV_ALIGN_LEFT_MID );
lv_obj_add_flag( ui_earRight, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_earRight, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_pivot(ui_earRight,10,70);

ui_body = lv_img_create(ui_rabbit);
lv_img_set_src(ui_body, &ui_img_r_body_90_png);
lv_obj_set_width( ui_body, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_body, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_body, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_body, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_body, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_earLeft = lv_img_create(ui_rabbit);
lv_img_set_src(ui_earLeft, &ui_img_r_ear_54_png);
lv_obj_set_width( ui_earLeft, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_earLeft, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_earLeft, 109 );
lv_obj_set_y( ui_earLeft, -43 );
lv_obj_set_align( ui_earLeft, LV_ALIGN_LEFT_MID );
lv_obj_add_flag( ui_earLeft, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_earLeft, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_pivot(ui_earLeft,10,70);

ui_timeLabel = lv_label_create(ui_homeScreen);
lv_obj_set_width( ui_timeLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_timeLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_timeLabel, 0 );
lv_obj_set_y( ui_timeLabel, -106 );
lv_obj_set_align( ui_timeLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_timeLabel,"12:59");
lv_obj_set_style_text_font(ui_timeLabel, &lv_font_montserrat_48, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_batteryLabel = lv_label_create(ui_homeScreen);
lv_obj_set_width( ui_batteryLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_batteryLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_batteryLabel, 0 );
lv_obj_set_y( ui_batteryLabel, -149 );
lv_obj_set_align( ui_batteryLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_batteryLabel,"90%#FF00ff");
lv_label_set_recolor(ui_batteryLabel,"true");
lv_obj_set_style_text_font(ui_batteryLabel, &lv_font_montserrat_20, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_alertlabel = lv_label_create(ui_homeScreen);
lv_obj_set_width( ui_alertlabel, 250);
lv_obj_set_height( ui_alertlabel, 64);
lv_obj_set_x( ui_alertlabel, 0 );
lv_obj_set_y( ui_alertlabel, -10 );
lv_obj_set_align( ui_alertlabel, LV_ALIGN_BOTTOM_MID );
lv_label_set_text(ui_alertlabel,"Text\nzf\nsf\nsf");
lv_obj_add_flag( ui_alertlabel, LV_OBJ_FLAG_HIDDEN );   /// Flags

ui_musicPanel = lv_obj_create(ui_homeScreen);
lv_obj_set_width( ui_musicPanel, 268);
lv_obj_set_height( ui_musicPanel, 55);
lv_obj_set_x( ui_musicPanel, 3 );
lv_obj_set_y( ui_musicPanel, 116 );
lv_obj_set_align( ui_musicPanel, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_musicPanel,LV_FLEX_FLOW_ROW);
lv_obj_set_flex_align(ui_musicPanel, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
lv_obj_add_flag( ui_musicPanel, LV_OBJ_FLAG_HIDDEN );   /// Flags
lv_obj_clear_flag( ui_musicPanel, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_musicPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_musicPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_musicPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_musicPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_musicPrevious = lv_img_create(ui_musicPanel);
lv_img_set_src(ui_musicPrevious, &ui_img_back_32_png);
lv_obj_set_width( ui_musicPrevious, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_musicPrevious, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_musicPrevious, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_musicPrevious, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_musicPrevious, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_musicPrevious, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_opa(ui_musicPrevious, 255, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_outline_color(ui_musicPrevious, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_outline_opa(ui_musicPrevious, 255, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_outline_width(ui_musicPrevious, 5, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_outline_pad(ui_musicPrevious, 0, LV_PART_MAIN| LV_STATE_PRESSED);

ui_musicPlay = lv_img_create(ui_musicPanel);
lv_img_set_src(ui_musicPlay, &ui_img_32_play_png);
lv_obj_set_width( ui_musicPlay, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_musicPlay, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_musicPlay, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_musicPlay, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_musicPlay, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_musicPlay, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_opa(ui_musicPlay, 255, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_outline_color(ui_musicPlay, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_outline_opa(ui_musicPlay, 255, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_outline_width(ui_musicPlay, 5, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_outline_pad(ui_musicPlay, 0, LV_PART_MAIN| LV_STATE_PRESSED);

ui_musicNext = lv_img_create(ui_musicPanel);
lv_img_set_src(ui_musicNext, &ui_img_next_32_png);
lv_obj_set_width( ui_musicNext, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_musicNext, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_musicNext, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_musicNext, LV_OBJ_FLAG_CLICKABLE | LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_musicNext, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_musicNext, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_bg_opa(ui_musicNext, 255, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_outline_color(ui_musicNext, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_PRESSED );
lv_obj_set_style_outline_opa(ui_musicNext, 255, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_outline_width(ui_musicNext, 5, LV_PART_MAIN| LV_STATE_PRESSED);
lv_obj_set_style_outline_pad(ui_musicNext, 0, LV_PART_MAIN| LV_STATE_PRESSED);

lv_obj_add_event_cb(ui_musicPrevious, ui_event_musicPrevious, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_musicPlay, ui_event_musicPlay, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_musicNext, ui_event_musicNext, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_musicPanel, ui_event_musicPanel, LV_EVENT_ALL, NULL);
lv_obj_add_event_cb(ui_homeScreen, ui_event_homeScreen, LV_EVENT_ALL, NULL);

}
void ui_weatherScreen_screen_init(void)
{
ui_weatherScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_weatherScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_weatherScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_weatherScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_tempLabel = lv_label_create(ui_weatherScreen);
lv_obj_set_width( ui_tempLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_tempLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_tempLabel, 40 );
lv_obj_set_y( ui_tempLabel, 41 );
lv_label_set_text(ui_tempLabel,"--");
lv_obj_set_style_text_font(ui_tempLabel, &lv_font_montserrat_42, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_cityLabel = lv_label_create(ui_weatherScreen);
lv_obj_set_width( ui_cityLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_cityLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_cityLabel, 40 );
lv_obj_set_y( ui_cityLabel, 91 );
lv_label_set_text(ui_cityLabel,"");
lv_obj_set_style_text_font(ui_cityLabel, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_weatherIcon = lv_img_create(ui_weatherScreen);
lv_img_set_src(ui_weatherIcon, &ui_img_dy0_png);
lv_obj_set_width( ui_weatherIcon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_weatherIcon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_weatherIcon, 45 );
lv_obj_set_y( ui_weatherIcon, 137 );
lv_obj_add_flag( ui_weatherIcon, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_weatherIcon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags

ui_rainLabel = lv_label_create(ui_weatherScreen);
lv_obj_set_width( ui_rainLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_rainLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_rainLabel, 120 );
lv_obj_set_y( ui_rainLabel, 155 );
lv_label_set_text(ui_rainLabel,"UV Index: -");
lv_obj_set_style_text_font(ui_rainLabel, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_humidityLabel = lv_label_create(ui_weatherScreen);
lv_obj_set_width( ui_humidityLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_humidityLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_humidityLabel, 120 );
lv_obj_set_y( ui_humidityLabel, 170 );
lv_label_set_text(ui_humidityLabel,"Humidity: --");
lv_obj_set_style_text_font(ui_humidityLabel, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_windLabel = lv_label_create(ui_weatherScreen);
lv_obj_set_width( ui_windLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_windLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_windLabel, 120 );
lv_obj_set_y( ui_windLabel, 140 );
lv_label_set_text(ui_windLabel,"Wind Speed: --");
lv_obj_set_style_text_font(ui_windLabel, &lv_font_montserrat_12, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_forecastPanel = lv_obj_create(ui_weatherScreen);
lv_obj_set_width( ui_forecastPanel, 281);
lv_obj_set_height( ui_forecastPanel, 213);
lv_obj_set_x( ui_forecastPanel, 0 );
lv_obj_set_y( ui_forecastPanel, -11 );
lv_obj_set_align( ui_forecastPanel, LV_ALIGN_BOTTOM_MID );
lv_obj_set_flex_flow(ui_forecastPanel,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_forecastPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
lv_obj_set_scrollbar_mode(ui_forecastPanel, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_scroll_dir(ui_forecastPanel, LV_DIR_VER);
lv_obj_set_style_bg_color(ui_forecastPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_forecastPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_forecastPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_left(ui_forecastPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_right(ui_forecastPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_top(ui_forecastPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_bottom(ui_forecastPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_row(ui_forecastPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_pad_column(ui_forecastPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_forecastItem = lv_obj_create(ui_forecastPanel);
lv_obj_set_width( ui_forecastItem, 244);
lv_obj_set_height( ui_forecastItem, 50);
lv_obj_set_align( ui_forecastItem, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_forecastItem,LV_FLEX_FLOW_ROW);
lv_obj_set_flex_align(ui_forecastItem, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
lv_obj_clear_flag( ui_forecastItem, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_forecastItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_forecastItem, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_forecastItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_forecastItem, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_forecastItem, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_forecastItem, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_forecastDay = lv_label_create(ui_forecastItem);
lv_obj_set_width( ui_forecastDay, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_forecastDay, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_forecastDay, LV_ALIGN_CENTER );
lv_label_set_text(ui_forecastDay,"--");

ui_forecastIcon = lv_img_create(ui_forecastItem);
lv_img_set_src(ui_forecastIcon, &ui_img_dy3_png);
lv_obj_set_width( ui_forecastIcon, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_forecastIcon, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_forecastIcon, LV_ALIGN_CENTER );
lv_obj_add_flag( ui_forecastIcon, LV_OBJ_FLAG_ADV_HITTEST );   /// Flags
lv_obj_clear_flag( ui_forecastIcon, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_img_set_zoom(ui_forecastIcon,150);

ui_forecastLabel = lv_label_create(ui_forecastItem);
lv_obj_set_width( ui_forecastLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_forecastLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_forecastLabel, LV_ALIGN_CENTER );
lv_label_set_text(ui_forecastLabel,"--");

ui_forecastTitle = lv_label_create(ui_weatherScreen);
lv_obj_set_width( ui_forecastTitle, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_forecastTitle, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_forecastTitle, 43 );
lv_obj_set_y( ui_forecastTitle, -228 );
lv_obj_set_align( ui_forecastTitle, LV_ALIGN_BOTTOM_LEFT );
lv_label_set_text(ui_forecastTitle,"Forecast");
lv_obj_set_style_text_decor(ui_forecastTitle, LV_TEXT_DECOR_UNDERLINE, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_text_font(ui_forecastTitle, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_tempHighLabel = lv_label_create(ui_weatherScreen);
lv_obj_set_width( ui_tempHighLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_tempHighLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_tempHighLabel, 160 );
lv_obj_set_y( ui_tempHighLabel, 45 );
lv_label_set_text(ui_tempHighLabel,"High: --");

ui_tempLowLabel = lv_label_create(ui_weatherScreen);
lv_obj_set_width( ui_tempLowLabel, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_tempLowLabel, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_tempLowLabel, 160 );
lv_obj_set_y( ui_tempLowLabel, 65 );
lv_label_set_text(ui_tempLowLabel,"Low: --");

lv_obj_add_event_cb(ui_weatherScreen, ui_event_weatherScreen, LV_EVENT_ALL, NULL);

}
void ui_notificationScreen_screen_init(void)
{
ui_notificationScreen = lv_obj_create(NULL);
lv_obj_clear_flag( ui_notificationScreen, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_bg_color(ui_notificationScreen, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_notificationScreen, 255, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_notificationPanel = lv_obj_create(ui_notificationScreen);
lv_obj_set_width( ui_notificationPanel, 300);
lv_obj_set_height( ui_notificationPanel, 450);
lv_obj_set_align( ui_notificationPanel, LV_ALIGN_CENTER );
lv_obj_set_flex_flow(ui_notificationPanel,LV_FLEX_FLOW_COLUMN);
lv_obj_set_flex_align(ui_notificationPanel, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_START, LV_FLEX_ALIGN_CENTER);
lv_obj_set_scrollbar_mode(ui_notificationPanel, LV_SCROLLBAR_MODE_OFF);
lv_obj_set_scroll_dir(ui_notificationPanel, LV_DIR_VER);
lv_obj_set_style_bg_color(ui_notificationPanel, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_notificationPanel, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_notificationPanel, 0, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_notificationItem = lv_obj_create(ui_notificationPanel);
lv_obj_set_width( ui_notificationItem, 277);
lv_obj_set_height( ui_notificationItem, LV_SIZE_CONTENT);   /// 70
lv_obj_set_align( ui_notificationItem, LV_ALIGN_CENTER );
lv_obj_clear_flag( ui_notificationItem, LV_OBJ_FLAG_SCROLLABLE );    /// Flags
lv_obj_set_style_radius(ui_notificationItem, 2, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_bg_color(ui_notificationItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_bg_opa(ui_notificationItem, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_notificationItem, lv_color_hex(0x5B5B5B), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_notificationItem, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_notificationItem, 1, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_notificationTitle = lv_label_create(ui_notificationItem);
lv_obj_set_width( ui_notificationTitle, 250);
lv_obj_set_height( ui_notificationTitle, LV_SIZE_CONTENT);   /// 1
lv_label_set_text(ui_notificationTitle,"Whatsapp");
lv_obj_set_style_text_font(ui_notificationTitle, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_color(ui_notificationTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT );
lv_obj_set_style_border_opa(ui_notificationTitle, 255, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_width(ui_notificationTitle, 1, LV_PART_MAIN| LV_STATE_DEFAULT);
lv_obj_set_style_border_side(ui_notificationTitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_notificationTime = lv_label_create(ui_notificationItem);
lv_obj_set_width( ui_notificationTime, LV_SIZE_CONTENT);  /// 1
lv_obj_set_height( ui_notificationTime, LV_SIZE_CONTENT);   /// 1
lv_obj_set_align( ui_notificationTime, LV_ALIGN_TOP_RIGHT );
lv_label_set_text(ui_notificationTime,"10:45");
lv_obj_set_style_text_font(ui_notificationTime, &lv_font_montserrat_16, LV_PART_MAIN| LV_STATE_DEFAULT);

ui_notificationText = lv_label_create(ui_notificationItem);
lv_obj_set_width( ui_notificationText, 240);
lv_obj_set_height( ui_notificationText, LV_SIZE_CONTENT);   /// 1
lv_obj_set_x( ui_notificationText, 0 );
lv_obj_set_y( ui_notificationText, 25 );
lv_label_set_text(ui_notificationText,"Text\nshfsd\nsfds\nsfd");
lv_obj_set_style_text_font(ui_notificationText, &lv_font_montserrat_14, LV_PART_MAIN| LV_STATE_DEFAULT);

lv_obj_add_event_cb(ui_notificationScreen, ui_event_notificationScreen, LV_EVENT_ALL, NULL);

}

void ui_init( void )
{
lv_disp_t *dispp = lv_disp_get_default();
lv_theme_t *theme = lv_theme_default_init(dispp, lv_palette_main(LV_PALETTE_BLUE), lv_palette_main(LV_PALETTE_RED), true, LV_FONT_DEFAULT);
lv_disp_set_theme(dispp, theme);
ui_homeScreen_screen_init();
ui_weatherScreen_screen_init();
ui_notificationScreen_screen_init();
ui____initial_actions0 = lv_obj_create(NULL);
lv_obj_add_event_cb(ui____initial_actions0, ui_event____initial_actions0, LV_EVENT_ALL, NULL);

lv_disp_load_scr(ui____initial_actions0);
lv_disp_load_scr( ui_homeScreen);
}
