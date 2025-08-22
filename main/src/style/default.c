#include "../../include/style/default.h"

#include "../../include/style/color.h"
#include "../../include/style/icon.h"

#include <lvgl.h>

lv_obj_t* default_create_default_object(lv_obj_t* parent, lv_style_selector_t selector) {
    if (!parent) {
        return NULL;
    }

    lv_obj_t* obj = lv_obj_create(parent);
    lv_obj_set_style_margin_all(obj, 0, selector);
    lv_obj_set_style_pad_all(obj, 0, selector);
    lv_obj_set_style_border_width(obj, 0, selector);
    lv_obj_set_style_radius(obj, 0, selector);
    lv_obj_set_style_bg_opa(obj, LV_OPA_TRANSP, selector);
    lv_obj_set_style_pad_gap(obj, 10, selector);

    return obj;
}

lv_obj_t* default_create_default_button(lv_obj_t* parent, lv_style_selector_t selector) {
    lv_obj_t* btn = lv_button_create(parent);
    lv_obj_set_style_bg_opa(btn, LV_OPA_TRANSP, selector);
    lv_obj_set_style_border_width(btn, 0, selector);
    lv_obj_set_style_outline_width(btn, 0, selector);
    lv_obj_set_style_shadow_width(btn, 0, selector);
    lv_obj_set_style_radius(btn, 0, selector);
    lv_obj_set_style_pad_all(btn, 0, selector);
    lv_obj_set_style_margin_all(btn, 0, selector);

    return btn;
}


lv_obj_t* default_create_default_horizontal_flex(lv_obj_t* parent) {
    if (!parent) {
        return NULL;
    }

    lv_obj_t* container = default_create_default_object(parent, LV_STATE_DEFAULT);
    default_set_default_horizontal_flex_styles(container);

    return container;
}

void default_set_default_horizontal_flex_styles(lv_obj_t* container) {
    lv_obj_align(container, LV_ALIGN_CENTER, 0, 0);
    lv_obj_set_layout(container, LV_LAYOUT_FLEX);
    lv_obj_set_flex_flow(container, LV_FLEX_FLOW_ROW);
    lv_obj_set_flex_align(container, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_SPACE_EVENLY, LV_FLEX_ALIGN_SPACE_EVENLY);
    lv_obj_set_style_pad_gap(container, 0, LV_STATE_DEFAULT);
}

lv_obj_t* default_create_single_button_container(lv_obj_t* parent) {
    if (!parent) {
        return NULL;
    }

    lv_obj_t* button_box = default_create_default_object(parent, LV_STATE_DEFAULT);

    lv_obj_set_style_bg_color(button_box, background_red, LV_STATE_DEFAULT);
    lv_obj_set_style_bg_opa(button_box, LV_OPA_COVER, LV_STATE_DEFAULT);

    return button_box;
}

lv_obj_t* default_create_grid_vertical_container(lv_obj_t* parent, lv_style_selector_t selector) {
    if (!parent) {
        return NULL;
    }

    lv_obj_t* container = default_create_default_object(parent, selector);

    static int32_t col_dsc_cgvc[] = {LV_GRID_FR(1), LV_GRID_TEMPLATE_LAST};
    static int32_t row_dsc_cgvc[] = {LV_GRID_FR(63), LV_GRID_FR(37), LV_GRID_TEMPLATE_LAST};
    
    lv_obj_set_layout(container, LV_LAYOUT_GRID);
    lv_obj_set_grid_dsc_array(container, col_dsc_cgvc, row_dsc_cgvc);
    lv_obj_set_align(container, LV_ALIGN_CENTER);
    
    return container;
}

void default_add_logo_and_text_to_button(lv_obj_t* button, const char* text, const void* img_src) {
    if (!button || !text || !img_src) {
        return;
    }

    lv_obj_t* container = default_create_grid_vertical_container(button, LV_STATE_DEFAULT);
    lv_obj_set_size(container, lv_pct(100), lv_pct(100));
    lv_obj_remove_flag(container, LV_OBJ_FLAG_CLICKABLE);

    lv_obj_t* image = create_icon(container, img_src);
    lv_obj_set_grid_cell(image, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_END, 0, 1);
    
    //lv_obj_t* text_label = create_text_label_bold(container, text, TEXT_COLOR_WHITE, LV_STATE_DEFAULT);
    lv_obj_t* text_label = lv_label_create(container);
    lv_label_set_text(text_label, text);
    lv_obj_set_grid_cell(text_label, LV_GRID_ALIGN_CENTER, 0, 1, LV_GRID_ALIGN_CENTER, 1, 1);
}
