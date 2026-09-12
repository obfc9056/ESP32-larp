#include "app_led.h"
#include "../drivers/led_driver.h"
#include "../core/display.h"
#include "../core/buttons.h"

static int mode = 0;

void appLedEnter() {
    mode = 0;
    ledSetMode(mode);
    displayApp("LED Effects", "UP = next");
}

void appLedLoop() {
    ledUpdate();
    if (btnUpPressed()) {
        mode = (mode + 1) % 4;
        ledSetMode(mode);
        const char* names[] = {"Rainbow", "Chase", "Breath", "Off"};
        displayApp("LED Effects", names[mode]);
    }
    if (btnSelPressed()) return;
}

void appLedExit() {
    ledSetMode(3);
    ledUpdate();
}