idf_component_register(
    SRCS
        waveshare_rgb_lcd_port.c
        lvgl_v9_port.cpp
        main.c

        src/style/color.c
        src/style/default.c

        src/app/app.c
    INCLUDE_DIRS
        include
        .
    REQUIRES 
        lvgl
)

# Get the LVGL library target
idf_component_get_property(lvgl_lib lvgl__lvgl COMPONENT_LIB)

# Tell LVGL to use LV_CONF_INCLUDE_SIMPLE
# This makes LVGL look for lv_conf.h in the include directories
target_compile_definitions(${lvgl_lib} PRIVATE LV_CONF_INCLUDE_SIMPLE=1)

# Add main folder (or wherever your custom lv_conf.h is) to LVGL include path
target_include_directories(${lvgl_lib} PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}")

# Optional: suppress format warnings from LVGL
target_compile_options(${lvgl_lib} PRIVATE -Wno-format)
