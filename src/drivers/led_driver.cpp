#include "led_driver.h"
#include "config.h"
#include <Adafruit_NeoPixel.h>

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);
static int currentMode = 0;
static int breathBright = 0;
static int breathDir = 5;
static int rainbowPos = 0;

void ledInit() {
    strip.begin();
    strip.show();
}

void ledSetMode(int mode) { currentMode = mode; }

void ledUpdate() {
    switch (currentMode) {
        case 0:
            for (int i = 0; i < LED_COUNT; i++)
                strip.setPixelColor(i, strip.ColorHSV((i * 65536L / LED_COUNT + rainbowPos) % 65536));
            rainbowPos += 256;
            strip.show();
            break;
        case 1:
            for (int i = 0; i < LED_COUNT; i++) strip.setPixelColor(i, 0);
            strip.setPixelColor((rainbowPos / 5000) % LED_COUNT, strip.Color(255, 0, 0));
            rainbowPos += 1;
            strip.show();
            break;
        case 2:
            breathBright += breathDir;
            if (breathBright >= 255 || breathBright <= 0) breathDir = -breathDir;
            for (int i = 0; i < LED_COUNT; i++)
                strip.setPixelColor(i, strip.Color(0, 0, breathBright));
            strip.show();
            break;
        case 3:
            for (int i = 0; i < LED_COUNT; i++) strip.setPixelColor(i, 0);
            strip.show();
            break;
    }
}