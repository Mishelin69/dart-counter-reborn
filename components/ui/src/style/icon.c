#include "../../include/style/icon.h"

lv_obj_t* create_icon(lv_obj_t* parent, const void* src) {
    lv_obj_t* img = lv_image_create(parent);
    lv_image_set_src(img, src);
    
    return img;
}
