###############################################################################
project(TangoTest
    VERSION 
        3.3.0
    DESCRIPTION
        "A device to test generic clients. It offers a echo like command for each TANGO data type (i.e. each command returns an exact copy of argin)."
    LANGUAGES
        CXX
)
###############################################################################

message(STATUS "${USER_PREFIX}::Build TANGO class ${PROJECT_NAME} in version ${PROJECT_VERSION}")

# Add project source files
unset(SOURCE_FILES)
AUX_SOURCE_DIRECTORY(./src SOURCE_FILES)

message(STATUS "${USER_PREFIX}:: - building library ${PROJECT_NAME} via target ${LIB_TARGET}")

unset(PUBLIC_HEADER)
GET_HEADER_FILES(_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/include)
foreach(_HEADER IN ITEMS ${_HEADERS})
    list(APPEND PUBLIC_HEADER include/${_HEADER})
endforeach()

set(TARGET_LIB ${PROJECT_NAME}_lib)

add_library(${TARGET_LIB})

target_sources(${TARGET_LIB}
    PRIVATE
        ${SOURCE_FILES}
)

target_link_libraries(${TARGET_LIB}
    PRIVATE
        ${GLOBAL_LIB}
    PUBLIC
        ${TARGET_EXT_LIB}
        ${TARGET_INT_LIB_TARGET}
)

target_include_directories(${TARGET_LIB}
    PRIVATE
        ${GLOBAL_INCLUDE_DIR}
        ${CMAKE_CURRENT_SOURCE_DIR}/src
        ${TARGET_INT_LIB_INCLUDE_DIR}
    PUBLIC
        ${TARGET_EXT_LIB_INCLUDE_DIR}
        $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
        $<INSTALL_INTERFACE:$<INSTALL_PREFIX>${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}-${PROJECT_VERSION}/include>  
)

#set_property(TARGET ${TARGET_OBJECT} PROPERTY POSITION_INDEPENDENT_CODE ON)

#target_compile_options(${TARGET_OBJECT}
#    PRIVATE
#        ${COMPILE_OPTIONS}  
#        -fPIC
#)

target_compile_features(${TARGET_LIB}
    PRIVATE
        ${COMPILE_FEATURES}
)

set_target_properties(${TARGET_LIB}
    PROPERTIES
        OUTPUT_NAME         ${PROJECT_NAME}
        OUTPUT_NAME_RELEASE ${PROJECT_NAME}
        OUTPUT_NAME_DEBUG   ${PROJECT_NAME}
        PUBLIC_HEADER       "${PUBLIC_HEADER}"
        SOVERSION           ${PROJECT_VERSION_MAJOR}
        VERSION             ${PROJECT_VERSION}
)

install(TARGETS ${TARGET_LIB} EXPORT ${TARGET_LIB}_export
    ARCHIVE         DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}-${PROJECT_VERSION}/lib
    LIBRARY         DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}-${PROJECT_VERSION}/lib
    PUBLIC_HEADER   DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}-${PROJECT_VERSION}/include
    INCLUDES        DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}-${PROJECT_VERSION}/include
    PERMISSIONS     ${DEFAULT_PERMISSIONS_LIB}
)

configure_package_config_file(
    ${CMAKE_SOURCE_DIR}/cmake/template/Config.cmake.in
    "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
    INSTALL_DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}-${PROJECT_VERSION}/cmake
)

write_basic_package_version_file(
    ${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake
    COMPATIBILITY AnyNewerVersion
)

if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    unset(SOURCES)
    GET_HEADER_FILES(_HEADERS ${CMAKE_CURRENT_SOURCE_DIR}/src)
    foreach(_HEADER IN ITEMS ${_HEADERS})
        list(APPEND SOURCES src/${_HEADER})
    endforeach()
    GET_SOURCE_FILES(_SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src)
    foreach(_SRC IN ITEMS ${_SRC_FILES})
        list(APPEND SOURCES src/${_SRC})
    endforeach()

    install(
        FILES
            ${SOURCES}
        DESTINATION 
            ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}-${PROJECT_VERSION}/src
        PERMISSIONS     
            ${DEFAULT_PERMISSIONS_LIB}
    )
endif()

install(
    FILES 
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}Config.cmake"
        "${CMAKE_CURRENT_BINARY_DIR}/${PROJECT_NAME}ConfigVersion.cmake"
    DESTINATION 
        ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}-${PROJECT_VERSION}/cmake
    PERMISSIONS     
        ${DEFAULT_PERMISSIONS_LIB}
)

install(EXPORT ${TARGET_LIB}_export
    FILE ${PROJECT_NAME}Targets.cmake
    NAMESPACE ${PROJECT_NAME}::
    DESTINATION ${CMAKE_INSTALL_LIBDIR}/${PROJECT_NAME}-${PROJECT_VERSION}/cmake
    PERMISSIONS ${DEFAULT_PERMISSIONS_LIB}
)
