set(INCROOT ${PROJECT_SOURCE_DIR}/include)
#Directories
set(SRCROOT ${PROJECT_SOURCE_DIR}/sources)

include_directories(
    ${INCROOT}
)

# Root Directory
set(SRC
    ${SRCROOT}/main.cpp
    ${SRCROOT}/Facture.cpp
    ${SRCROOT}/Errors.cpp
    ${SRCROOT}/Piece.cpp
    ${SRCROOT}/Client.cpp
    ${SRCROOT}/Produit.cpp
    ${SRCROOT}/Vehicle.cpp
    ${SRCROOT}/Service.cpp
    ${SRCROOT}/ProduitFacture.cpp
)

add_executable (${PROJECT_NAME} ${SRC})

install(TARGETS ${PROJECT_NAME}
    RUNTIME
    DESTINATION ${PROJECT_SOURCE_DIR_BIS})

set_target_properties(${PROJECT_NAME} PROPERTIES RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR})
target_include_directories(${PROJECT_NAME} PUBLIC ${INCROOT})