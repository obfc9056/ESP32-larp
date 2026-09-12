#ifndef IR_DRIVER_H
#define IR_DRIVER_H

#include <IRremote.h>

void irInit();
void irSendPower();
void irSendVolumeUp();
void irSendVolumeDown();
void irSendChannelUp();
void irSendChannelDown();

#endif