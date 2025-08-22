#include "waveshare_rgb_lcd_port.h"
#include "./app/app.h"

void ram_monitor_task() {
    while (true) {
        size_t free_ram = heap_caps_get_free_size(MALLOC_CAP_INTERNAL);
        size_t free_psram = heap_caps_get_free_size(MALLOC_CAP_SPIRAM);

        ESP_LOGI(TAG, "Free RAM: %d bytes\nFree PSRAM: %d bytes", free_ram, free_psram);
        vTaskDelay(pdMS_TO_TICKS(10000));
    }
}

void app_main() {
    waveshare_esp32_s3_rgb_lcd_init(); // Initialize the Waveshare ESP32-S3 RGB LCD 
    // wavesahre_rgb_lcd_bl_on();  //Turn on the screen backlight 
    // wavesahre_rgb_lcd_bl_off(); //Turn off the screen backlight 
    
    ESP_LOGI(TAG, "Display LVGL demos");
    // Lock the mutex due to the LVGL APIs are not thread-safe
    if (lvgl_port_lock(-1)) {
        app_create();
        // Release the mutex
        lvgl_port_unlock();
    }

    xTaskCreatePinnedToCore(
        ram_monitor_task, 
        "memory monitor", 
        4096,
        NULL,
        5,
        NULL, 
        0
    );
}
