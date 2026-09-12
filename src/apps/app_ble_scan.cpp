#include "app_ble_scan.h"
#include <BLEDevice.h>
#include <BLEScan.h>
#include "../core/display.h"
#include "../core/buttons.h"
#include "config.h"

static String results[SCAN_MAX_RESULTS];
static int count = 0;

void appBleScanEnter() {
    displayApp("BLE Scan", "Scanning...");
    BLEDevice::init("");
    BLEScan* scan = BLEDevice::getScan();
    scan->setActiveScan(false);
    BLEScanResults res = scan->start(3, false);
    count = min((int)res.getCount(), SCAN_MAX_RESULTS);
    for (int i = 0; i < count; i++) {
        BLEAdvertisedDevice d = res.getDevice(i);
        results[i] = String(d.getName().c_str()) + " " + String(d.getRSSI());
    }
    scan->clearResults();
    BLEDevice::deinit();
}

void appBleScanLoop() {
    displayResults("BLE Devices", results, count);
    if (btnSelPressed()) return;
}

void appBleScanExit() {}