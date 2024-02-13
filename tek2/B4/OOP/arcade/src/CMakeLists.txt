cmake_minimum_required(VERSION 3.9.0)

project(Day07 LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED TRUE)

set(PROJECT_SOURCE_DIR_BIS ${PROJECT_SOURCE_DIR}/..)

# Add ./cmake to the module path
list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/../cmake)

# Unit Testing
if (BUILD_TEST_SUITE)
    # Check for Criterion
    find_package(Criterion REQUIRED)
    # disable assertions when running unit tests
    add_compile_definitions(NDEBUG=1)
    enable_testing()
endif()

add_compile_options(
    "-Wall" "-Wextra" "-Wshadow" "-pedantic" "-Wpointer-arith"
    "$<$<CONFIG:RELEASE>:-O3;-fno-builtin;-Werror>"
    "$<$<CONFIG:DEBUG>:-O0;-g3;-ggdb>"
)

# Enable test coverage
if (USE_GCOV)
    add_link_options("-lgcov" "--coverage")
    add_compile_options("--coverage" "-fprofile-arcs" "-ftest-coverage")
endif()

add_subdirectory(arcade)

if (BUILD_TEST_SUITE)
    # add_subdirectory(../tests)
endif()
