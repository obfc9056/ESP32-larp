#include "ir_driver.h"
#include "config.h"

IRsend irsend(IR_LED);

// Пример кодов Samsung (замени на свои)
#define CODE_POWER       0xE0E040BF
#define CODE_VOL_UP      0xE0E0E01F
#define CODE_VOL_DOWN    0xE0E0D02F
#define CODE_CH_UP       0xE0E048B7
#define CODE_CH_DOWN     0xE0E008F7

void irInit() { irsend.begin(); }
void irSendPower()       { irsend.sendNEC(CODE_POWER, 32); }
void irSendVolumeUp()    { irsend.sendNEC(CODE_VOL_UP, 32); }
void irSendVolumeDown()  { irsend.sendNEC(CODE_VOL_DOWN, 32); }
void irSendChannelUp()   { irsend.sendNEC(CODE_CH_UP, 32); }
void irSendChannelDown() { irsend.sendNEC(CODE_CH_DOWN, 32); }