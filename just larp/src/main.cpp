#include <Arduino.h>
#include "config.h"
#include "core/display.h"
#include "core/buttons.h"
#include "core/clock.h"
#include "drivers/ir_driver.h"
#include "drivers/i2s_driver.h"
#include "drivers/led_driver.h"
#include "drivers/sd_driver.h"
#include "apps/app_tv.h"
#include "apps/app_wifi_scan.h"
#include "apps/app_ble_scan.h"
#include "apps/app_led.h"
#include "apps/app_music.h"

// ===== МЕНЮ =====
const char* menuItems[MENU_MAX_ITEMS] = {
    "Clock", "TV Remote", "WiFi Scan", "BLE Scan", "LED Effects", "Music"
};
int selected = 0;
int currentApp = -1;

// ===== ИНИЦИАЛИЗАЦИЯ =====
void setup() {
    Serial.begin(115200);
    Serial.println("DEVAICE v" VERSION);

    buttonsInit();
    displayInit();
    displaySplash();
    clockInit();
    irInit();
    i2sInit();
    ledInit();

    if (!sdInit()) Serial.println("SD init failed");
    Serial.println("Ready");
}

// ===== ГЛАВНЫЙ ЦИКЛ =====
void loop() {
    clockTick();

    if (currentApp == -1) {
        displayMenu(menuItems, MENU_MAX_ITEMS, selected);
        if (btnUpPressed())   selected = (selected - 1 + MENU_MAX_ITEMS) % MENU_MAX_ITEMS;
        if (btnDownPressed()) selected = (selected + 1) % MENU_MAX_ITEMS;
        if (btnSelPressed()) {
            currentApp = selected;
            switch (currentApp) {
                case 0: break;
                case 1: appTvEnter(); break;
                case 2: appWifiScanEnter(); break;
                case 3: appBleScanEnter(); break;
                case 4: appLedEnter(); break;
                case 5: appMusicEnter(); break;
            }
        }
    } else {
        switch (currentApp) {
            case 0:
                displayClock(clockGetHour(), clockGetMinute(), clockGetSecond());
                if (btnSelPressed()) currentApp = -1;
                break;
            case 1: appTvLoop();      if (btnSelPressed()) { appTvExit(); currentApp = -1; } break;
            case 2: appWifiScanLoop();if (btnSelPressed()) { appWifiScanExit(); currentApp = -1; } break;
            case 3: appBleScanLoop(); if (btnSelPressed()) { appBleScanExit(); currentApp = -1; } break;
            case 4: appLedLoop();     if (btnSelPressed()) { appLedExit(); currentApp = -1; } break;
            case 5: appMusicLoop();   if (btnSelPressed()) { appMusicExit(); currentApp = -1; } break;
        }
    }
    delay(30);
}