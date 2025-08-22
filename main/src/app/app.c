#include "../../include/app/app.h"

#include "../../include/app/app_page_manager.h"

#include "../../include/style/default.h"
#include "../../include/style/color.h"

#include <lvgl.h>

void app_create() {
    app_create_main_window();
    app_create_app_pages(main_window);
}

void app_create_main_window() {
   main_window = default_create_default_object(lv_screen_active(), LV_STATE_DEFAULT);
   app_main_window_set_styles();
}

void app_main_window_set_styles() {
    lv_obj_set_size(main_window, lv_pct(100), lv_pct(100));
    lv_obj_set_style_bg_opa(main_window, LV_OPA_MAX, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_color(main_window, background_grey, LV_STATE_DEFAULT);
}

