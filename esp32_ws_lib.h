/*
    ESP32 WS2812B Control Library

    Created on: July 27, 2022

    Author: Coskun ERGAN

*/

#ifndef ESP32_WS2812B_LIB_H
#define ESP32_WS2812B_LIB_H

#include <Wire.h>
#include <bits/stdc++.h>
using namespace std;

#define WS_API_VERSION         100 //V1.0.0
#define WS_UPDATE_DELAY_PERIOD 500
#define LED_CHIP_ON_PCB_SIZE     8
#define LED_PCB_SIZE            (sizeof(LedZoneArray) / sizeof(int))
#define LED_COUNT               LED_PCB_SIZE * LED_CHIP_ON_PCB_SIZE
#define ESP32_TIME_MS           millis()

typedef enum
{
    BLANK = 0,
    RED,
    GREEN,
    BLUE,
    CYAN,
    MAGENTA,
    YELLOW,
    WHITE,
    NUMBER_OF_COLOR
} Colors_t;

typedef struct
{
    uint8_t red;
    uint8_t green;
    uint8_t blue;
} LedColorBuffer_t;

typedef enum
{
    LED_ZONE1 = 0,
    LED_ZONE2,
    LED_ZONE3,
    LED_ZONE4,
    LED_ZONE_NUMBER
} Led_Zone_t;

const Led_Zone_t LedZoneArray[] =
{
    LED_ZONE1,
    LED_ZONE2,
    LED_ZONE2,
    LED_ZONE1,
    LED_ZONE4,
    LED_ZONE3,
    LED_ZONE3,
    LED_ZONE4
};

class WsLed_Control
{
private:
    long last_time;
    uint8_t tempcolor_r;
    uint8_t tempcolor_g;
    uint8_t tempcolor_b;
    uint8_t led_zone_index;
    LedColorBuffer_t led_color_zone[LED_ZONE_NUMBER];
public:
    WsLed_Control(uint8_t pin);
    void init();
    void loop();
    void set_zone_color(Led_Zone_t zone, Colors_t color);
    void set_brightness(uint8_t brightness);
    uint8_t get_api_version();
};

#endif
