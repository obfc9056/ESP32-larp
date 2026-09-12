#include "sd_driver.h"
#include "config.h"
#include <SD.h>

bool sdInit() {
    return SD.begin(SD_CS);
}