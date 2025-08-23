#include "../../include/app/app_page_manager.h"

#include "../../include/style/default.h"
#include "../../include/style/color.h"

#include "../../include/app_pages/home_page.h"

void app_create_app_pages(lv_obj_t* parent) {
    app_create_app_pages_containers(parent);    
    app_create_home_page();
}

void app_create_app_pages_containers(lv_obj_t* parent) {
    home_page_window = default_create_default_object(parent, LV_STATE_DEFAULT);
    lv_obj_set_size(home_page_window, lv_pct(100), lv_pct(100));
}

void app_create_home_page() {
    home_page_create(home_page_window);
}
