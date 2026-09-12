#ifndef DISPLAY_H
#define DISPLAY_H

#include <U8g2lib.h>
#include "config.h"

extern U8G2_SSD1306_128X64_NONAME_F_HW_I2C u8g2;

void displayInit();
void displayMenu(const char* items[], int count, int selected);
void displayClock(int h, int m, int s);
void displayApp(const char* title, const char* status);
void displayResults(const char* title, String results[], int count);
void displaySplash();

#endif