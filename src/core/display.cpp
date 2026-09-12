#include "display.h"
#include <Arduino.h>

U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2(U8G2_R0, U8X8_PIN_NONE, OLED_SCL, OLED_SDA);

void displayInit() {
    u8g2.begin();
    u8g2.setFont(u8g2_font_6x10_tf);
}

void displaySplash() {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x13B_tf);
    u8g2.drawStr(20, 25, "DEVAICE");
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(35, 45, "v" VERSION);
    u8g2.sendBuffer();
    delay(1500);
}

void displayMenu(const char* items[], int count, int selected) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 9, "DEVAICE");
    u8g2.drawHLine(0, 12, 128);
    for (int i = 0; i < count; i++) {
        int y = 22 + i * 8;
        if (i == selected) {
            u8g2.drawBox(0, y - 7, 128, 8);
            u8g2.setDrawColor(0);
            u8g2.drawStr(2, y, items[i]);
            u8g2.setDrawColor(1);
        } else {
            u8g2.drawStr(2, y, items[i]);
        }
    }
    u8g2.sendBuffer();
}

void displayClock(int h, int m, int s) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_fub30_tf);
    char buf[10];
    sprintf(buf, "%02d:%02d:%02d", h, m, s);
    u8g2.drawStr(5, 50, buf);
    u8g2.sendBuffer();
}

void displayApp(const char* title, const char* status) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_7x13B_tf);
    u8g2.drawStr(0, 12, title);
    u8g2.drawHLine(0, 15, 128);
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 35, status);
    u8g2.drawStr(0, 55, "SEL = back");
    u8g2.sendBuffer();
}

void displayResults(const char* title, String results[], int count) {
    u8g2.clearBuffer();
    u8g2.setFont(u8g2_font_6x10_tf);
    u8g2.drawStr(0, 9, title);
    u8g2.drawHLine(0, 12, 128);
    for (int i = 0; i < min(count, 5); i++) {
        u8g2.drawStr(0, 24 + i * 9, results[i].c_str());
    }
    u8g2.sendBuffer();
}