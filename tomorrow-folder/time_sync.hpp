#pragma once

#define WIFI_SSID "Majkak"
#define WIFI_PASSWORD "maria2310"
#define NTP_SERVER "pool.ntp.org"

#ifdef __cplusplus
extern "C" {
#endif

void connect_to_wifi(const char* ssid, const char* password);

bool check_if_connection_successful();

void sync_time_with_ntp(const char* ntp_server, int time_zone_offset);

void update_buffer_with_current_time(char buffer[32]);

bool is_time_synced();

#ifdef __cplusplus
}
#endif
