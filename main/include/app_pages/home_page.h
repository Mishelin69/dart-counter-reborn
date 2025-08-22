#pragma once

#define HOME_PAGE_LOGO_CONTAINER_SIZE (160)
#define HOME_PAGE_LOGO_SIZE (160)

#define HOME_PAGE_MENU_CONTAINER_SIZE (310)
#define HOME_PAGE_MENU_SIZE (HOME_PAGE_MENU_CONTAINER_SIZE-20)

#include "../lvgl_commons_light_import.h"

extern lv_obj_t* home_page_container;

void home_page_create(lv_obj_t* parent);

void home_page_create_container(lv_obj_t* parent);

lv_obj_t* home_page_create_grid();

void home_page_init_grid(lv_obj_t* grid);

void home_page_create_logo(lv_obj_t* item);

void home_page_create_menu(lv_obj_t* item);

lv_obj_t* home_page_create_menu_button(lv_obj_t* parent);

void home_page_create_duo_game_button(lv_obj_t* parent);

void home_page_create_trio_game_button(lv_obj_t* parent);

void home_page_create_quadra_game_button(lv_obj_t* parent);
