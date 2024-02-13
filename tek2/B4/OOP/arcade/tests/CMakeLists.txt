cmake_minimum_required (VERSION 3.12)


set(SRCROOT "${PROJECT_SOURCE_DIR}/tests")
set(SRC
    ${SRCROOT}/test_basic.cpp)

add_executable(unit_test ${SRC})

source_group("" FILES ${SRC})
set_target_properties(unit_test PROPERTIES FOLDER "tests")

if (CMAKE_COMPILER_IS_GNUCXX)
    target_compile_options(unit_test PRIVATE 
        -Wall 
        -Wextra 
        -pedantic
        -Wshadow
        -Wpointer-arith
        -g
        -Og
        -Werror )
endif()

target_link_libraries(unit_test PRIVATE project_lib ${CRITERION_LIBRARIES})

# Link to gcov if build type is set to 'static'
if (CMAKE_COMPILER_IS_GNUCXX AND USE_GCOV)
    target_link_libraries(unit_test PRIVATE gcov)
endif()

add_test(NAME unit_test COMMAND unit_test WORKING_DIRECTORY ${SRCROOT})
