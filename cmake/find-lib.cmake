#set(CMAKE_FIND_DEBUG_MODE TRUE)

include(CMakeParseArguments)

function(find_libraries)

    # Parse the parameters
    set(MULTIVALUEARGS LIBRARIES SEARCH_PATHS)
    cmake_parse_arguments(FIND_LIBRARIES "" "" "${MULTIVALUEARGS}" ${ARGN})

    # Clear the found libraries
    unset(FOUND_LIBRARIES PARENT_SCOPE)

    foreach(LIB ${FIND_LIBRARIES_LIBRARIES})

        # try the user provided paths first
        find_library(FOUND_LIB_${LIB} ${LIB} PATHS ${FIND_LIBRARIES_SEARCH_PATHS} NO_DEFAULT_PATH)

        # if we could not find it, drop to the system paths
        if(NOT FOUND_LIB_${LIB})
            find_library(FOUND_LIB_${LIB} ${LIB})
        endif(NOT FOUND_LIB_${LIB})

        if(FOUND_LIB_${LIB})
            message(STATUS "Found " ${LIB} " at: " ${FOUND_LIB_${LIB}})
            list(APPEND FOUND_LIBRARIES ${FOUND_LIB_${LIB}})
        else()
            message(FATAL "Could not find " ${LIB})
        endif(FOUND_LIB_${LIB})
        
    endforeach(LIB ${LIBRARIES})

    set(FOUND_LIBRARIES ${FOUND_LIBRARIES} PARENT_SCOPE)
endfunction(find_libraries)

# Load Tango
message("# FIND Tango LIB")

# First try find_package
find_package(Tango)

# if it didn't work, try pkg-config
if(Tango_FOUND)
    message(STATUS "${USER_PREFIX}::Registering the global library ${LIB_NAME} ${${LIB_NAME}_LIB_VERSION} ...")
    message(STATUS "${USER_PREFIX}:: - ${LIB_NAME}_LIB_DIR     = ${${LIB_NAME}_LIB_DIR}")
    message(STATUS "${USER_PREFIX}:: - ${LIB_NAME}_INCLUDE_DIR = ${${LIB_NAME}_INCLUDE_DIR}")
    list(APPEND GLOBAL_LIB ${LIB_NAME})
    list(APPEND GLOBAL_LIB_DIR ${${LIB_NAME}_LIB_DIR})
        list(APPEND GLOBAL_INCLUDE_DIR ${${LIB_NAME}_INCLUDE_DIR})

    list(APPEND GLOBAL_LIB ${DEFAULT_LIB_SYSTEM})
    message(STATUS "${USER_PREFIX}::External default libraries founded: ${GLOBAL_LIB}")

else()

    find_package(PkgConfig REQUIRED)

    # Now search for the tango.pc file, this is a required dependency
    message(STATUS "Search for Tango package config...")
    pkg_search_module(TANGO REQUIRED tango>=9.2.5)

    find_libraries(LIBRARIES ${TANGO_LIBRARIES} SEARCH_PATHS ${TANGO_LIBRARY_DIRS})

    # Create an interface library to represent the tango linkage
    add_library(TangoInterfaceLibrary INTERFACE)

    set_target_properties(TangoInterfaceLibrary 
        PROPERTIES 
            INTERFACE_INCLUDE_DIRECTORIES "${TANGO_INCLUDE_DIRS}"
            INTERFACE_LINK_LIBRARIES "${FOUND_LIBRARIES}"
            INTERFACE_COMPILE_OPTIONS "${TANGO_CFLAGS}")

    list(APPEND GLOBAL_LIB TangoInterfaceLibrary)
endif()

# Load external Tango classes (shared lib)
if(PROJECT_LIB_EXTERNAL)
    message("# FIND PROJECT EXTERNAL LIB")
    set(PROJECT_LIB_EXTERNAL_clone ${PROJECT_LIB_EXTERNAL})
    while(PROJECT_LIB_EXTERNAL_clone)
        list(POP_FRONT PROJECT_LIB_EXTERNAL_clone LIB_NAME LIB_VERSION)
        if(${LIB_VERSION} EQUAL 0)
            unset(LIB_VERSION)
        endif()
        find_package(${LIB_NAME} ${LIB_VERSION} REQUIRED
            PATHS
                ${USER_REPO_LIB_DIRS}
        )
        message(STATUS "${USER_PREFIX}::Find library ${LIB_NAME} in version ${LIB_VERSION}")
        message(STATUS "${USER_PREFIX}:: - ${LIB_NAME}_LIB         = ${${LIB_NAME}_LIB}")
        message(STATUS "${USER_PREFIX}:: - ${LIB_NAME}_LIB_DIR     = ${${LIB_NAME}_LIB_DIR}")
        message(STATUS "${USER_PREFIX}:: - ${LIB_NAME}_INCLUDE_DIR = ${${LIB_NAME}_INCLUDE_DIR}")
        list(APPEND PROJECT_LIB_EXT ${${LIB_NAME}_LIB})
        list(APPEND PROJECT_LIB_EXT_DIR ${${LIB_NAME}_LIB_DIR})
        list(APPEND PROJECT_LIB_EXT_INCLUDE_DIR ${${LIB_NAME}_INCLUDE_DIR})
    endwhile()
    message(STATUS "${USER_PREFIX}::External project libraries founded: ${PROJECT_LIB_EXT}")
endif()

#set(CMAKE_FIND_DEBUG_MODE FALSE)
