message("# LOAD USER CONFIGURATION - user-config.cmake")

set(USER_PREFIX "ESRF")
set(USER_REPOSITORY "/opt/os_dev")

OPTION(BUILD_SHARED_LIBS "Make Tango classes as Shared libraries" YES)

# Set the build type as Release (with debug info) if no Debug mode is requested
if(CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(BUILD_TYPE_DIR "debug")
else()
    set(CMAKE_BUILD_TYPE RelWithDebInfo)
    set(BUILD_TYPE_DIR "release")
endif()

# Set specific search directories for find_package() cmd
set(USER_REPO_TANGO_DIRS
    ${USER_REPOSITORY}/${BUILD_TYPE_DIR}/lib/cmake
    ${CMAKE_INSTALL_PREFIX}/lib/cmake
)
message(STATUS "${USER_PREFIX}::Add Tango lib search dir: ${USER_TANGO_DIRS}")

set(USER_REPO_LIB_DIRS 
    ${USER_REPOSITORY}/${BUILD_TYPE_DIR}/lib/classes
    ${CMAKE_INSTALL_PREFIX}/lib/classes
)
message(STATUS "${USER_PREFIX}::Add Tango classes lib search dir: ${USER_LIB_DIRS}")

# Check if execute from GitLab
if(DEFINED ENV{CI_COMMIT_SHA})
    set(IN_GITLAB YES)
    message(STATUS "${USER_PREFIX}::Build type: ${CMAKE_BUILD_TYPE} (GitLab)")
else()
    set(IN_GITLAB NO)
    message(STATUS "${USER_PREFIX}::Build type: ${CMAKE_BUILD_TYPE} (interactive)")
endif()

# Set intallation directory path
set(CMAKE_INSTALL_LIBDIR ${CMAKE_INSTALL_LIBDIR}/classes)

# Set installation files PERMISSIONS
set(DEFAULT_PERMISSIONS_CONF
    OWNER_READ OWNER_WRITE 
    GROUP_READ GROUP_WRITE
    WORLD_READ
)
set(DEFAULT_PERMISSIONS_LIB 
    OWNER_READ OWNER_WRITE 
    GROUP_READ GROUP_WRITE
    WORLD_READ
)
set(DEFAULT_PERMISSIONS_BIN 
    OWNER_READ OWNER_WRITE OWNER_EXECUTE
    GROUP_READ GROUP_WRITE GROUP_EXECUTE
    WORLD_READ             WORLD_EXECUTE
)