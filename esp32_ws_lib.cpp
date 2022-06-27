/*
    ESP32 WS2812B Control Library

    Created on: July 27, 2022

    Author: Coskun ERGAN

*/

#include "esp32_ws_lib.h"
#include "Freenove_WS2812_Lib_for_ESP32.h"

Freenove_ESP32_WS2812 strip;

const LedColorBuffer_t ws_color_table[NUMBER_OF_COLOR] =
{
    {0x00, 0x00, 0x00}, // BLANK_COLOR
    {0x00, 0xFF, 0x00}, // RED_COLOR
    {0xFF, 0x00, 0x00}, // GREEN_COLOR
    {0x00, 0x00, 0xFF}, // BLUE_COLOR
    {0x00, 0xFF, 0xFF}, // CYAN_COLOR
    {0xFF, 0x00, 0xFF}, // MAGENTA_COLOR
    {0xFF, 0xFF, 0x00}, // YELLOW_COLOR
    {0xFF, 0xFF, 0xFF}  // WHITE_COLOR
};

/******************************************************/
/******************************************************/
/******************************************************/
WsLed_Control::WsLed_Control(uint8_t pin)
{
    strip = Freenove_ESP32_WS2812(LED_COUNT, pin, 0, TYPE_GRB);
    init();
}
/******************************************************/
void WsLed_Control::init()
{
    for(int zone = 0; zone < LED_ZONE_NUMBER; zone++)
    {
        set_zone_color((LedPcb_t)zone, BLANK);
    }
    strip.begin();
    strip.setBrightness(20);
}
/******************************************************/
void WsLed_Control::loop()
{
    if((ESP32_TIME_MS - last_time) > WS_UPDATE_DELAY_PERIOD)
    {
        last_time = ESP32_TIME_MS;
        for(int i = 0; i < LED_COUNT; i++)
        {
            if((i % 8) == 0)
            {
                tempcolor_r = led_color_zone[LedZoneArray[led_zone_index]].red;
                tempcolor_g = led_color_zone[LedZoneArray[led_zone_index]].green;
                tempcolor_b = led_color_zone[LedZoneArray[led_zone_index]].blue;
                led_zone_index++;
            }
            strip.setLedColorData(i, tempcolor_r, tempcolor_g, tempcolor_b);
        }
        led_zone_index = 0;
        strip.show();
    }
}
/******************************************************/
void WsLed_Control::set_zone_color(LedPcb_t zone, Colors_t color)
{
    led_color_zone[zone].red = ws_color_table[color].red;
    led_color_zone[zone].green = ws_color_table[color].green;
    led_color_zone[zone].blue = ws_color_table[color].blue;
    last_time += WS_UPDATE_DELAY_PERIOD; // for quick update
}
/******************************************************/
void WsLed_Control::set_brightness(uint8_t brightness)
{
    strip.setBrightness(brightness);
}
/******************************************************/
uint8_t WsLed_Control::get_api_version(void)
{
    return WS_API_VERSION;
}
/******************************************************/
/******************************************************/
/******************************************************/
