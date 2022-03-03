# Generic main project
project(Root)
cmake_minimum_required (VERSION 3.15)

###############################################################################
# List of TANGO device servers to build (from defined classes/lib below)
set(PROJECT_BIN
    TangoTest
)
# External shared libraries needed on this project
set(PROJECT_LIB_EXTERNAL
)
# Local shared libraries needed on this project
set(PROJECT_LIB_INTERNAL
    TangoTest
)
option(BUILD_SHARED_LIBS "True to build shared libraries." ON)

# Load base cmake macro
include(./cmake/macro/default-macro.cmake)
# Load user cmake macro
include(./cmake/macro/user-macro.cmake)

# Load base cmake configuration
include(./cmake/config/default-config.cmake)
# Load user cmake configuration
include(./cmake/config/user-config.cmake)

# Load external libraries
include(./cmake/find-lib.cmake)

# Build internal libraries
if(PROJECT_LIB_INTERNAL)
    message("# BUILD INTERNAL LIB")
    unset(CLASS CACHE)
    foreach(CLASS IN ITEMS ${PROJECT_LIB_INTERNAL})
        add_subdirectory(./classes/${CLASS})
    endforeach()
endif()

# Build TANGO device servers
if(PROJECT_BIN)
    message("# BUILD TANGO DEVICE SERVERS")
    unset(DEVICE_SERVER CACHE)
    foreach(DEVICE_SERVER IN ITEMS ${PROJECT_BIN})
        add_subdirectory(servers/${DEVICE_SERVER})
    endforeach()
endif()
