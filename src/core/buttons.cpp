#include "buttons.h"
#include "config.h"
#include <Arduino.h>

void buttonsInit() {
    pinMode(BTN_UP, INPUT_PULLUP);
    pinMode(BTN_DOWN, INPUT_PULLUP);
    pinMode(BTN_SEL, INPUT_PULLUP);
}

bool btnUpPressed() {
    if (digitalRead(BTN_UP) == LOW) { delay(200); return true; }
    return false;
}

bool btnDownPressed() {
    if (digitalRead(BTN_DOWN) == LOW) { delay(200); return true; }
    return false;
}

bool btnSelPressed() {
    if (digitalRead(BTN_SEL) == LOW) { delay(200); return true; }
    return false;
}