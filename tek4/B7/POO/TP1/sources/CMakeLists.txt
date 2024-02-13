set(INCROOT ${PROJECT_SOURCE_DIR}/include)
#Directories
set(SRCROOT ${PROJECT_SOURCE_DIR}/sources)

include_directories(
    ${EMPLOYEESROOT}
)

# Root Directory
set(SRC
    ${SRCROOT}/main.cpp
    ${SRCROOT}/Task.cpp
    ${SRCROOT}/User.cpp
    ${SRCROOT}/FileAdministrator.cpp
)

add_executable (${PROJECT_NAME} ${SRC})

install(TARGETS ${PROJECT_NAME}
    RUNTIME
    DESTINATION ${PROJECT_SOURCE_DIR_BIS})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCROOT})