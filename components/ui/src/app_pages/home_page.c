#include "../../include/app_pages/home_page.h"

#include "../../include/style/default.h"
#include "../../include/style/icon.h"

lv_obj_t* home_page_container;

void home_page_create(lv_obj_t* parent) {
    home_page_create_container(parent);

    lv_obj_t* home_page_grid = home_page_create_grid();
    lv_obj_set_size(home_page_grid, lv_pct(100), lv_pct(100));

    home_page_init_grid(home_page_grid);
}

void home_page_create_container(lv_obj_t* parent) {
    home_page_container = default_create_default_object(parent, LV_STATE_DEFAULT);
    lv_obj_set_size(home_page_container, lv_pct(100), lv_pct(100));
}

lv_obj_t* home_page_create_grid() {
    lv_obj_t* container = default_create_default_object(home_page_container, LV_STATE_DEFAULT);

    static int32_t col_dsc[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static int32_t row_dsc[] = {HOME_PAGE_LOGO_CONTAINER_SIZE, HOME_PAGE_MENU_CONTAINER_SIZE, LV_GRID_TEMPLATE_LAST};
    
    lv_obj_set_layout(container, LV_LAYOUT_GRID);
    lv_obj_set_grid_dsc_array(container, col_dsc, row_dsc);
    lv_obj_set_align(container, LV_ALIGN_CENTER);
    
    return container;

}

void home_page_init_grid(lv_obj_t* grid) {
    lv_obj_t* logo_container = default_create_default_object(grid, LV_STATE_DEFAULT);
    lv_obj_set_size(logo_container, lv_pct(100), HOME_PAGE_LOGO_CONTAINER_SIZE);
    lv_obj_set_grid_cell(logo_container, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_END, 0, 1);
    home_page_create_logo(logo_container);

    lv_obj_t* menu_container = default_create_default_object(grid, LV_STATE_DEFAULT);
    lv_obj_set_size(menu_container, lv_pct(100), HOME_PAGE_MENU_CONTAINER_SIZE);
    lv_obj_set_grid_cell(menu_container, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1); 
    home_page_create_menu(menu_container);
}

void home_page_create_logo(lv_obj_t* item) {

}

lv_obj_t* home_page_create_menu_button(lv_obj_t* parent) {
    lv_obj_t* button_container = default_create_single_button_container(parent); 
    lv_obj_set_size(button_container, 150, HOME_PAGE_MENU_SIZE-50);

    lv_obj_t* button = default_create_default_button(button_container, LV_STATE_DEFAULT);
    lv_obj_set_size(button, lv_pct(100), lv_pct(100));

    return button;
}

void home_page_create_menu(lv_obj_t* item) {
    lv_obj_t* menu_item_list = default_create_default_horizontal_flex(item);
    lv_obj_set_size(menu_item_list, lv_pct(100), HOME_PAGE_MENU_SIZE-10);

    home_page_create_duo_game_button(menu_item_list);
    home_page_create_trio_game_button(menu_item_list);
    home_page_create_quadra_game_button(menu_item_list);
}

void home_page_create_duo_game_button(lv_obj_t* parent) {
    lv_obj_t* button = home_page_create_menu_button(parent);
    default_add_logo_and_text_to_button(button, "2 players", &player_icon);
}

void home_page_create_trio_game_button(lv_obj_t* parent) {
    lv_obj_t* button = home_page_create_menu_button(parent);
    default_add_logo_and_text_to_button(button, "3 players", &player_icon);
}

void home_page_create_quadra_game_button(lv_obj_t* parent) {
    lv_obj_t* button = home_page_create_menu_button(parent);
    default_add_logo_and_text_to_button(button, "4 players", &player_icon);
}
