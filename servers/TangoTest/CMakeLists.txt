###############################################################################
project(TangoTest
    VERSION 
        3.3.0
    DESCRIPTION
        "A device to test generic clients. It offers a echo like command for each TANGO data type (i.e. each command returns an exact copy of argin)."
    LANGUAGES
        CXX
)
set(PROJECT_DEPENDENCIES
    TangoTest
)

###############################################################################

message(STATUS "${USER_PREFIX}::Build TANGO device server ${PROJECT_NAME} in version ${PROJECT_VERSION}")
# If your build need more specific directives, replace include file by it's containt and custom your build.

# Add project source files
unset(SOURCE_FILES)
AUX_SOURCE_DIRECTORY(./src SOURCE_FILES)

set(BINARY_TARGET ${PROJECT_NAME}_binary)
add_executable(${BINARY_TARGET})
message(STATUS "${USER_PREFIX}:: - building binary ${PROJECT_NAME} via target ${BINARY_TARGET}")

target_sources(${BINARY_TARGET}
    PRIVATE
        ${SOURCE_FILES}
)

target_link_libraries(${BINARY_TARGET}
    PRIVATE
        $<BUILD_INTERFACE:TangoTest_lib>
        ${GLOBAL_LIB}
        ${TARGET_EXT_LIB}
        ${TARGET_INT_LIB_TARGET}
)

target_link_directories(${BINARY_TARGET}
    PRIVATE
        ${GLOBAL_LIB_DIR}
        ${TARGET_EXT_LIB_DIR}
)

target_include_directories(${BINARY_TARGET}
    PRIVATE
        $<TARGET_PROPERTY:TangoTest_lib,INTERFACE_INCLUDE_DIRECTORIES>
        ${GLOBAL_INCLUDE_DIR}
        ${TARGET_EXT_LIB_INCLUDE_DIR}
        ${TARGET_INT_LIB_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src
    PUBLIC
        ${CMAKE_CURRENT_SOURCE_DIR}/include
)

target_compile_options(${BINARY_TARGET}
    PRIVATE
        ${COMPILE_OPTIONS}  
)

target_compile_features(${BINARY_TARGET}
    PRIVATE
        ${COMPILE_FEATURES}
)

set_target_properties(${BINARY_TARGET}
    PROPERTIES 
        OUTPUT_NAME ${PROJECT_NAME}-${PROJECT_VERSION}
        OUTPUT_NAME_RELEASE ${PROJECT_NAME}-${PROJECT_VERSION}
        OUTPUT_NAME_DEBUG ${PROJECT_NAME}-${PROJECT_VERSION}
)

install(TARGETS ${BINARY_TARGET} EXPORT ${BINARY_TARGET}_export
    RUNTIME DESTINATION ${CMAKE_INSTALL_BINDIR}/${PROJECT_NAME}
    PERMISSIONS  ${DEFAULT_PERMISSIONS_BIN}
)
