#include "app_music.h"
#include "../drivers/i2s_driver.h"
#include "../core/display.h"
#include "../core/buttons.h"

void appMusicEnter() {
    displayApp("Music", "Playing...");
    i2sPlayWAV("/song.wav");
}

void appMusicLoop() {
    if (btnSelPressed()) return;
}

void appMusicExit() {}