/*
   MIT License

  Copyright (c) 2024 Felix Biego

  Permission is hereby granted, free of charge, to any person obtaining a copy
  of this software and associated documentation files (the "Software"), to deal
  in the Software without restriction, including without limitation the rights
  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
  copies of the Software, and to permit persons to whom the Software is
  furnished to do so, subject to the following conditions:

  The above copyright notice and this permission notice shall be included in all
  copies or substantial portions of the Software.

  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
  SOFTWARE.

  ______________  _____
  ___  __/___  /_ ___(_)_____ _______ _______
  __  /_  __  __ \__  / _  _ \__  __ `/_  __ \
  _  __/  _  /_/ /_  /  /  __/_  /_/ / / /_/ /
  /_/     /_.___/ /_/   \___/ _\__, /  \____/
                              /____/

*/

#include <Arduino.h>
#include "main.h"
#include <lvgl.h>
#include "PanelLan.h"
#include <ChronosESP32.h>
#include <Timber.h>

#ifdef USE_UI
#include "ui/ui.h"
#endif

#ifdef PLUS
#define SCR 30
// BOARD_SC01, BOARD_SC01_PLUS, BOARD_SC02, BOARD_SC05, BOARD_KC01, BOARD_BC02
PanelLan tft(BOARD_SC01_PLUS);
#else
#define SCR 8
// BOARD_SC01, BOARD_SC01_PLUS, BOARD_SC02, BOARD_SC05, BOARD_KC01, BOARD_BC02
PanelLan tft(BOARD_SC01);

#endif

ChronosESP32 watch("Rabbit");

ChronosTimer alertTimer;

static lv_disp_draw_buf_t draw_buf;
static lv_disp_drv_t disp_drv;

static lv_color_t disp_draw_buf[screenWidth * SCR];
static lv_color_t disp_draw_buf2[screenWidth * SCR];

bool weatherUpdate = true, notificationUpdate = true;
int prevBatteryPercentage = -1;
bool prevIsCharging = false;
bool prevIsConnected = false;

String days[7] = {"SUN", "MON", "TUE", "WED", "THU", "FRI", "SAT"};

const lv_img_dsc_t *weatherIcons[] = {
    &ui_img_dy0_png,
    &ui_img_dy1_png,
    &ui_img_dy2_png,
    &ui_img_dy3_png,
    &ui_img_dy4_png,
    &ui_img_dy5_png,
    &ui_img_dy6_png,
    &ui_img_dy7_png};

/* Display flushing */
void my_disp_flush(lv_disp_drv_t *disp, const lv_area_t *area, lv_color_t *color_p)
{
  if (tft.getStartCount() == 0)
  {
    tft.endWrite();
  }

  tft.pushImageDMA(area->x1, area->y1, area->x2 - area->x1 + 1, area->y2 - area->y1 + 1, (lgfx::swap565_t *)&color_p->full);

  lv_disp_flush_ready(disp); /* tell lvgl that flushing is done */
}

/*Read the touchpad*/
void my_touchpad_read(lv_indev_drv_t *indev_driver, lv_indev_data_t *data)
{
  uint16_t touchX, touchY;

  bool touched = tft.getTouch(&touchX, &touchY);

  if (!touched)
  {
    data->state = LV_INDEV_STATE_REL;
  }
  else
  {
    data->state = LV_INDEV_STATE_PR;

    /*Set the coordinates*/
    data->point.x = touchX;
    data->point.y = touchY;
  }
}

void addNotification(lv_obj_t *parent, Notification n)
{
  ui_notificationItem = lv_obj_create(parent);
  lv_obj_set_width(ui_notificationItem, 277);
  lv_obj_set_height(ui_notificationItem, LV_SIZE_CONTENT); /// 70
  lv_obj_set_align(ui_notificationItem, LV_ALIGN_CENTER);
  lv_obj_clear_flag(ui_notificationItem, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_obj_set_style_radius(ui_notificationItem, 2, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_color(ui_notificationItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_notificationItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_notificationItem, lv_color_hex(0x5B5B5B), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_notificationItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_notificationItem, 1, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_notificationTitle = lv_label_create(ui_notificationItem);
  lv_obj_set_width(ui_notificationTitle, 250);
  lv_obj_set_height(ui_notificationTitle, LV_SIZE_CONTENT); /// 1
  lv_label_set_text(ui_notificationTitle, n.app.c_str());
  lv_obj_set_style_text_font(ui_notificationTitle, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_notificationTitle, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_notificationTitle, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_notificationTitle, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_notificationTitle, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_notificationTime = lv_label_create(ui_notificationItem);
  lv_obj_set_width(ui_notificationTime, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(ui_notificationTime, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(ui_notificationTime, LV_ALIGN_TOP_RIGHT);
  lv_label_set_text(ui_notificationTime, n.time.c_str());
  lv_obj_set_style_text_font(ui_notificationTime, &lv_font_montserrat_16, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_notificationText = lv_label_create(ui_notificationItem);
  lv_obj_set_width(ui_notificationText, 240);
  lv_obj_set_height(ui_notificationText, LV_SIZE_CONTENT); /// 1
  lv_obj_set_x(ui_notificationText, 0);
  lv_obj_set_y(ui_notificationText, 25);
  lv_label_set_text(ui_notificationText, n.message.c_str());
  lv_obj_set_style_text_font(ui_notificationText, &lv_font_montserrat_14, LV_PART_MAIN | LV_STATE_DEFAULT);
}

void addForecast(Weather weather)
{
  ui_forecastItem = lv_obj_create(ui_forecastPanel);
  lv_obj_set_width(ui_forecastItem, 244);
  lv_obj_set_height(ui_forecastItem, 50);
  lv_obj_set_align(ui_forecastItem, LV_ALIGN_CENTER);
  lv_obj_set_flex_flow(ui_forecastItem, LV_FLEX_FLOW_ROW);
  lv_obj_set_flex_align(ui_forecastItem, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_CENTER, LV_FLEX_ALIGN_CENTER);
  lv_obj_clear_flag(ui_forecastItem, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_obj_set_style_bg_color(ui_forecastItem, lv_color_hex(0x000000), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_bg_opa(ui_forecastItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_color(ui_forecastItem, lv_color_hex(0xFFFFFF), LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_opa(ui_forecastItem, 255, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_width(ui_forecastItem, 1, LV_PART_MAIN | LV_STATE_DEFAULT);
  lv_obj_set_style_border_side(ui_forecastItem, LV_BORDER_SIDE_BOTTOM, LV_PART_MAIN | LV_STATE_DEFAULT);

  ui_forecastDay = lv_label_create(ui_forecastItem);
  lv_obj_set_width(ui_forecastDay, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(ui_forecastDay, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(ui_forecastDay, LV_ALIGN_CENTER);
  lv_label_set_text(ui_forecastDay, days[weather.day].c_str());

  ui_forecastIcon = lv_img_create(ui_forecastItem);
  lv_img_set_src(ui_forecastIcon, weatherIcons[weather.icon]);
  lv_obj_set_width(ui_forecastIcon, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(ui_forecastIcon, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(ui_forecastIcon, LV_ALIGN_CENTER);
  lv_obj_add_flag(ui_forecastIcon, LV_OBJ_FLAG_ADV_HITTEST);  /// Flags
  lv_obj_clear_flag(ui_forecastIcon, LV_OBJ_FLAG_SCROLLABLE); /// Flags
  lv_img_set_zoom(ui_forecastIcon, 150);

  ui_forecastLabel = lv_label_create(ui_forecastItem);
  lv_obj_set_width(ui_forecastLabel, LV_SIZE_CONTENT);  /// 1
  lv_obj_set_height(ui_forecastLabel, LV_SIZE_CONTENT); /// 1
  lv_obj_set_align(ui_forecastLabel, LV_ALIGN_CENTER);
  lv_label_set_text_fmt(ui_forecastLabel, "%d°C", weather.temp);
}

void onMusicPrevious(lv_event_t *e)
{
  watch.musicControl(MUSIC_PREVIOUS);
}

void onMusicPlay(lv_event_t *e)
{
  watch.musicControl(MUSIC_TOGGLE);
}

void onMusicNext(lv_event_t *e)
{
  watch.musicControl(MUSIC_NEXT);
}

void onWeatherOpen(lv_event_t *e)
{
  if (!weatherUpdate)
  {
    return;
  }
  weatherUpdate = false;

  if (watch.getWeatherCount() > 0)
  {
    String updateTime = "Updated at\n" + watch.getWeatherTime();
    lv_label_set_text(ui_cityLabel, watch.getWeatherCity().c_str());

    lv_label_set_text_fmt(ui_tempLabel, "%d°C", watch.getWeatherAt(0).temp);
    lv_label_set_text_fmt(ui_tempHighLabel, "High: %d°C", watch.getWeatherAt(0).high);
    lv_label_set_text_fmt(ui_tempLowLabel, "Low: %d°C", watch.getWeatherAt(0).low);

    lv_img_set_src(ui_weatherIcon, weatherIcons[watch.getWeatherAt(0).icon]);

    lv_obj_clean(ui_forecastPanel);
    int c = watch.getWeatherCount();
    for (int i = 0; i < c; i++)
    {
      addForecast(watch.getWeatherAt(i));
    }
  }
}

void updateBatteryLabel(int batteryPercentage, bool isCharging, bool isConnected) {
    // Check if there's a change in any of the states
    if (batteryPercentage != prevBatteryPercentage || isCharging != prevIsCharging || isConnected != prevIsConnected) {
        // Update the global variables with the current states
        prevBatteryPercentage = batteryPercentage;
        prevIsCharging = isCharging;
        prevIsConnected = isConnected;

        char batterySymbol[20];
        if (batteryPercentage >= 80) {
            strcpy(batterySymbol, "#14e03a " LV_SYMBOL_BATTERY_FULL "#");
        } else if (batteryPercentage >= 60) {
            strcpy(batterySymbol, "#70e014 " LV_SYMBOL_BATTERY_3 "#");
        } else if (batteryPercentage >= 40) {
            strcpy(batterySymbol, "#ade014 " LV_SYMBOL_BATTERY_2 "#");
        } else if (batteryPercentage >= 20) {
            strcpy(batterySymbol, "#e0cc14 " LV_SYMBOL_BATTERY_1 "#");
        } else {
            strcpy(batterySymbol, "#e05514 " LV_SYMBOL_BATTERY_EMPTY "#");
        }
        
        char chargeSymbol[20];
        if (isCharging) {
            strcpy(chargeSymbol, "#14e03a " LV_SYMBOL_CHARGE "#");
        } else {
            strcpy(chargeSymbol, "");
        }

        char connectedSymbol[20];
        if (isConnected) {
            strcpy(connectedSymbol, "#145fe0 " LV_SYMBOL_BLUETOOTH "#");
        } else {
            strcpy(connectedSymbol, ""); // No Bluetooth symbol if not connected
        }

        // Update the label to display battery, charging symbol, and Bluetooth symbol
        lv_label_set_text_fmt(ui_batteryLabel, "%d%% %s %s %s", batteryPercentage, batterySymbol, chargeSymbol, connectedSymbol);
    }
}

void onNotificationOpen(lv_event_t *e)
{

  if (!notificationUpdate)
  {
    return;
  }
  notificationUpdate = false;

  lv_obj_clean(ui_notificationPanel);
  int c = watch.getNotificationCount();
  if (c == 0)
  {
    Notification n;
    n.app = "System";
    n.time = "";
    n.message = "There are no notifications";
    addNotification(ui_notificationPanel, n);
  }

  for (int i = 0; i < c; i++)
  {
    addNotification(ui_notificationPanel, watch.getNotificationAt(i));
  }
}

void connectionCallback(bool state)
{
  Timber.d("Connection change");
}

void notificationCallback(Notification notification)
{

  Timber.d("Notification Received from " + notification.app + " at " + notification.time);
  Timber.d(notification.message);
  notificationUpdate = true;

  lv_label_set_text(ui_alertlabel, notification.message.c_str());
  lv_obj_clear_flag(ui_alertlabel, LV_OBJ_FLAG_HIDDEN);

  alertTimer.time = millis();
  alertTimer.active = true;
}

void configCallback(Config config, uint32_t a, uint32_t b)
{
  switch (config)
  {
  case CF_RTW:
    break;
  case CF_WEATHER:

    if (a == 2)
    {
      weatherUpdate = true;
    }

    break;
  case CF_FONT:
    break;
  case CF_CAMERA:
    break;
  }
}

void logCallback(Level level, unsigned long time, String message)
{
  Serial.print(message);

  switch (level)
  {
  case ERROR:
    // maybe save only errors to local storage
    break;
  }
}

void setup()
{
  Serial.begin(115200);

  Timber.setLogCallback(logCallback);

  tft.init();
  tft.initDMA();
  tft.startWrite();

  lv_init();

  Timber.i("Width %d\tHeight %d", screenWidth, screenHeight);

  if (!disp_draw_buf)
  {
    Timber.e("LVGL disp_draw_buf allocate failed!");
  }
  else
  {

    lv_disp_draw_buf_init(&draw_buf, disp_draw_buf, disp_draw_buf2, screenWidth * SCR);

    /* Initialize the display */
    lv_disp_drv_init(&disp_drv);
    /* Change the following line to your display resolution */
    disp_drv.hor_res = screenWidth;
    disp_drv.ver_res = screenHeight;
    disp_drv.flush_cb = my_disp_flush;
    disp_drv.draw_buf = &draw_buf;
    lv_disp_drv_register(&disp_drv);

    /* Initialize the input device driver */
    static lv_indev_drv_t indev_drv;
    lv_indev_drv_init(&indev_drv);
    indev_drv.type = LV_INDEV_TYPE_POINTER;
    indev_drv.read_cb = my_touchpad_read;
    lv_indev_drv_register(&indev_drv);

#ifdef USE_UI
    ui_init();

#else
    lv_obj_t *label1 = lv_label_create(lv_scr_act());
    lv_obj_align(label1, LV_ALIGN_TOP_MID, 0, 100);
    lv_label_set_long_mode(label1, LV_LABEL_LONG_WRAP);
    lv_obj_set_width(label1, screenWidth - 30);
    lv_label_set_text(label1, "Hello there! You have not included UI files, add you UI files and "
                              "uncomment this line\n'//#define USE_UI' in include/main.h\n"
                              "You should be able to move the slider below");

    /*Create a slider below the label*/
    lv_obj_t *slider1 = lv_slider_create(lv_scr_act());
    lv_obj_set_width(slider1, screenWidth - 40);
    lv_obj_align_to(slider1, label1, LV_ALIGN_OUT_BOTTOM_MID, 0, 50);
#endif

    watch.setConnectionCallback(connectionCallback);
    watch.setNotificationCallback(notificationCallback);
    watch.setConfigurationCallback(configCallback);
    watch.begin();
    watch.set24Hour(true);
    watch.setBattery(85);

    lv_obj_clean(ui_notificationPanel);
    lv_obj_clean(ui_forecastPanel);

    Timber.i("Setup done");
  }
}

void loop()
{
  lv_timer_handler(); /* let the GUI do its work */
  delay(5);
  watch.loop();

  String time = watch.getHourZ() + watch.getTime(":%M");

  lv_label_set_text(ui_timeLabel, time.c_str());
  
  updateBatteryLabel(watch.getPhoneBattery(), watch.isPhoneCharging(), watch.isConnected());

  if (alertTimer.active)
  {
    if (alertTimer.time + alertTimer.duration < millis())
    {
      alertTimer.active = false;
      lv_obj_add_flag(ui_alertlabel, LV_OBJ_FLAG_HIDDEN);
    }
  }
}