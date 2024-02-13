cmake_minimum_required (VERSION 3.12)
project(GestionGarage LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(PROJECT_SOURCE_DIR_BIS ${PROJECT_SOURCE_DIR}/..)

add_compile_options(
    "-Wall" "-Wextra" "-Wshadow" "-pedantic" "-Wpointer-arith"
    "$<$<CONFIG:RELEASE>:-O3;-fno-builtin;-Werror>"
    "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

add_subdirectory(sources)