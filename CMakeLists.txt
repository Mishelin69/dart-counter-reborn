cmake_minimum_required(VERSION 3.6)

include($ENV{IDF_PATH}/tools/cmake/project.cmake)

add_compile_options("-Wno-attributes")
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

project(dart_counter_reborn.cmake)
