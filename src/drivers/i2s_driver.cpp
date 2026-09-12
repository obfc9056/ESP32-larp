#include "i2s_driver.h"
#include "config.h"
#include <driver/i2s.h>
#include <SD.h>

void i2sInit() {
    i2s_config_t cfg = {
        .mode = (i2s_mode_t)(I2S_MODE_MASTER | I2S_MODE_TX),
        .sample_rate = 44100,
        .bits_per_sample = I2S_BITS_PER_SAMPLE_16BIT,
        .channel_format = I2S_CHANNEL_FMT_ONLY_LEFT,
        .communication_format = I2S_COMM_FORMAT_STAND_I2S,
        .intr_alloc_flags = 0,
        .dma_buf_count = 8,
        .dma_buf_len = 256
    };
    i2s_pin_config_t pin = {
        .bck_io_num = I2S_BCK,
        .ws_io_num = I2S_LRC,
        .data_out_num = I2S_DIN,
        .data_in_num = I2S_PIN_NO_CHANGE
    };
    i2s_driver_install(I2S_NUM_0, &cfg, 0, NULL);
    i2s_set_pin(I2S_NUM_0, &pin);
}

void i2sPlayWAV(const char* filename) {
    File file = SD.open(filename);
    if (!file) return;
    file.seek(44);
    uint8_t buf[512];
    while (file.available()) {
        size_t bytes = file.read(buf, 512);
        size_t written;
        i2s_write(I2S_NUM_0, buf, bytes, &written, portMAX_DELAY);
    }
    file.close();
}