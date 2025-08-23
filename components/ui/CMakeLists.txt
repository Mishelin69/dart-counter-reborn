idf_component_register(
    SRCS
        src/style/color.c
        src/style/default.c
        src/style/icon.c

        src/app/app.c
        src/app/app_page_manager.c

        src/app_pages/home_page.c

        icons/player_icon.c
    INCLUDE_DIRS
        include
    REQUIRES 
        lvgl lvgl_port
)
