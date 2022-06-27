/*
    Examples

    Created on: Jul 27, 2022

    Author: Coskun ERGAN
*/

#include "esp32_ws_lib.h"

#define DATA_PIN  3

WsLed_Control WsLed_Control(DATA_PIN);

/*****************************************************************/
void setup()
{
    WsLed_Control.set_zone_color(LED_ZONE1, RED);
    WsLed_Control.set_zone_color(LED_ZONE2, BLUE);
    WsLed_Control.set_zone_color(LED_ZONE3, GREEN);
    WsLed_Control.set_zone_color(LED_ZONE4, WHITE);
    randomSeed(analogRead(0));
}
/*****************************************************************/
void loop()
{
    WsLed_Control.loop();
    delay(500);
    WsLed_Control.set_zone_color(LED_ZONE1, (Colors_t)random(0, NUMBER_OF_COLOR));
    WsLed_Control.set_zone_color(LED_ZONE2, (Colors_t)random(0, NUMBER_OF_COLOR));
    WsLed_Control.set_zone_color(LED_ZONE3, (Colors_t)random(0, NUMBER_OF_COLOR));
    WsLed_Control.set_zone_color(LED_ZONE4, (Colors_t)random(0, NUMBER_OF_COLOR));
}
/*****************************************************************/
/*****************************************************************/
/*****************************************************************/
