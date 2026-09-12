#include "app_tv.h"
#include "ir_driver.h"
#include "../core/display.h"
#include "../core/buttons.h"

void appTvEnter() {
    displayApp("TV Remote", "UP=POWER");
}

void appTvLoop() {
    if (btnUpPressed())    irSendPower();
    if (btnDownPressed())  irSendVolumeUp();
    if (btnSelPressed())   return;
}

void appTvExit() {}