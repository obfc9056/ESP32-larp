#include "clock.h"
#include <Arduino.h>

static unsigned long lastSecond = 0;
static int hr = 0, mn = 0, sc = 0;

void clockInit() {
    lastSecond = millis();
}

void clockTick() {
    if (millis() - lastSecond >= 1000) {
        lastSecond = millis();
        sc++;
        if (sc >= 60) { sc = 0; mn++; }
        if (mn >= 60) { mn = 0; hr++; }
        if (hr >= 24) hr = 0;
    }
}

int clockGetHour()   { return hr; }
int clockGetMinute() { return mn; }
int clockGetSecond() { return sc; }