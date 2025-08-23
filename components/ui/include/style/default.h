#pragma once

#include <lvgl.h>

lv_obj_t* default_create_default_object(lv_obj_t* parent, lv_style_selector_t selector);

lv_obj_t* default_create_default_button(lv_obj_t* parent, lv_style_selector_t selector);

lv_obj_t* default_create_default_horizontal_flex(lv_obj_t* parent);

void default_set_default_horizontal_flex_styles(lv_obj_t* container);

lv_obj_t* default_create_single_button_container(lv_obj_t* parent);

lv_obj_t* default_create_grid_vertical_container(lv_obj_t* parent, lv_style_selector_t selector);

void default_add_logo_and_text_to_button(lv_obj_t* button, const char* text, const void* img_src); 
