#include "app_wifi_scan.h"
#include <WiFi.h>
#include "../core/display.h"
#include "../core/buttons.h"
#include "config.h"

static String results[SCAN_MAX_RESULTS];
static int count = 0;

void appWifiScanEnter() {
    displayApp("WiFi Scan", "Scanning...");
    WiFi.mode(WIFI_STA);
    WiFi.disconnect();
    delay(100);
    int n = WiFi.scanNetworks();
    count = min(n, SCAN_MAX_RESULTS);
    for (int i = 0; i < count; i++) {
        results[i] = WiFi.SSID(i) + " " + String(WiFi.RSSI(i)) + "dB";
    }
    WiFi.scanDelete();
}

void appWifiScanLoop() {
    displayResults("WiFi Networks", results, count);
    if (btnSelPressed()) return;
}

void appWifiScanExit() {}