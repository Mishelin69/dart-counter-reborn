#include "../../include/app/time_sync.hpp"
#include "esp_wifi.h"
#include "esp_event.h"
#include "esp_log.h"
#include "esp_netif.h"
#include "esp_sntp.h"
#include <string.h>
#include <time.h>

#include "nvs_flash.h"

static const char *TAG = "time_sync";

/*
 * REQUIRES:
 *      esp_wifi
 *      esp_netif
 *      esp_event
 *      nvs_flash
*/

void connect_to_wifi(const char* ssid, const char* password) {
    esp_err_t ret = nvs_flash_init();
    if (ret == ESP_ERR_NVS_NO_FREE_PAGES || ret == ESP_ERR_NVS_NEW_VERSION_FOUND) {
        ESP_ERROR_CHECK(nvs_flash_erase());
        ret = nvs_flash_init();
    }
    ESP_ERROR_CHECK(ret);

    ESP_ERROR_CHECK(esp_netif_init());
    ESP_ERROR_CHECK(esp_event_loop_create_default());
    esp_netif_create_default_wifi_sta();

    wifi_init_config_t cfg = WIFI_INIT_CONFIG_DEFAULT();
    ESP_ERROR_CHECK(esp_wifi_init(&cfg));
    ESP_ERROR_CHECK(esp_wifi_set_mode(WIFI_MODE_STA));
    ESP_ERROR_CHECK(esp_wifi_start());

    wifi_config_t wifi_config = { 0 };
    strncpy((char *)wifi_config.sta.ssid, ssid, sizeof(wifi_config.sta.ssid));
    strncpy((char *)wifi_config.sta.password, password, sizeof(wifi_config.sta.password));

    ESP_ERROR_CHECK(esp_wifi_set_config(WIFI_IF_STA, &wifi_config));
    ESP_ERROR_CHECK(esp_wifi_connect());

    ESP_LOGI(TAG, "Connecting to WiFi SSID:%s ...", ssid);
}

bool check_if_connection_successful(void) {
    wifi_ap_record_t ap_info;
    esp_netif_ip_info_t ip_info;

    if (esp_wifi_sta_get_ap_info(&ap_info) != ESP_OK) {
        return false; 
    }

    esp_netif_t* sta_netif = esp_netif_get_handle_from_ifkey("WIFI_STA_DEF");
    if (!sta_netif || esp_netif_get_ip_info(sta_netif, &ip_info) != ESP_OK) {
        return false;        
    }

    if (ip_info.ip.addr == 0 || ip_info.gw.addr == 0) {
        return false;
    }

    ESP_LOGI(TAG, "WiFi connected with valid network config");
    return true;
}

void sync_time_with_ntp(const char* ntp_server, int time_zone_offset) {
    ESP_LOGI(TAG, "Initializing SNTP");

    if (esp_sntp_enabled()) {
        return;
        //esp_sntp_stop();
    }

    esp_sntp_setoperatingmode(SNTP_OPMODE_POLL);
    esp_sntp_setservername(0, ntp_server);
    esp_sntp_init();

    setenv("TZ", "GMT-2", 1); // default UTC
    tzset();

    ESP_LOGI(TAG, "Time sync started with NTP server: %s", ntp_server);
}

bool is_time_synced(void) {
    return sntp_get_sync_status() == SNTP_SYNC_STATUS_COMPLETED;
}

void update_buffer_with_current_time(char buffer[32]) {
    time_t now;
    struct tm timeinfo;

    time(&now);
    if (localtime_r(&now, &timeinfo) == NULL) {
        ESP_LOGW(TAG, "Failed to obtain local time");
        return;
    }

    strftime(buffer, 32, "%H:%M", &timeinfo);
}
