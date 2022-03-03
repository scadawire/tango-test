message("# LOAD DEFAULT CONFIGURATION - default-config.cmake")

if(${CMAKE_SOURCE_DIR} STREQUAL ${CMAKE_BINARY_DIR})
    message(FATAL_ERROR "In-source builds not allowed. Please make a new directory (called a build directory) and run CMake from there." )
endif()

set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)
set(CMAKE_DISABLE_SOURCE_CHANGES  ON)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

set(CMAKE_VERBOSE_MAKEFILE OFF)
set(CMAKE_COLOR_MAKEFILE ON)
set(CMAKE_SKIP_RPATH true)

set(USER_PREFIX "LOG")

#include(FindPkgConfig)
include(GNUInstallDirs)
include(CMakePackageConfigHelpers)

# Compilation features & options
set(COMPILE_FEATURES cxx_std_11)
set(COMPILE_OPTIONS
    #-Werror                    # Make all warnings into errors.
    -Wall                       # This enables all the warnings.
    -Wextra                     # This enables some extra warning flags. 
    -Wpedantic                  # Issue all the warnings demanded by strict ISO C and ISO C++
    -Wnon-virtual-dtor          # warns whenever a class with virtual function does not declare a virtual destructor.
    -Wshadow                    # Warn whenever a local variable or type declaration shadows another variable
)

