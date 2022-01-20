cmake_minimum_required(VERSION 3.0.2)
set(CMP0048 NEW)

# definitions and compile options
add_definitions(-DWIN32)
add_definitions(-DNDEBUG)
if(CMAKE_CL_64)
add_definitions(-D_64BITS)
if(MSVC14)
add_definitions(-D_TIMERS_T_)
endif(MSVC14)
else(CMAKE_CL_64)
add_definitions(-DJPG_USE_ASM)
endif(CMAKE_CL_64)
# include directories
set(TANGO_INCLUDES "$ENV{TANGO_ROOT}/include")
# link directories
set(TANGO_LNK_DIR "$ENV{TANGO_ROOT}/bin;$ENV{TANGO_ROOT}/lib")
# link files

set(TANGO_STA_LIBS "$ENV{TANGO_ROOT}/lib/libtango.lib;$ENV{TANGO_ROOT}/lib/omniORB4.lib;$ENV{TANGO_ROOT}/lib/omniDynamic4.lib;$ENV{TANGO_ROOT}/lib/COS4.lib;$ENV{TANGO_ROOT}/lib/omnithread.lib;$ENV{TANGO_ROOT}/lib/msvcstub.lib;$ENV{TANGO_ROOT}/lib/pthreadVC2-s.lib")                                            
set(TANGO_DYN_LIBS "$ENV{TANGO_ROOT}/lib/tango.lib;$ENV{TANGO_ROOT}/lib/omniORB4_rt.lib;$ENV{TANGO_ROOT}/lib/omniDynamic4_rt.lib;$ENV{TANGO_ROOT}/lib/COS4_rt.lib;$ENV{TANGO_ROOT}/lib/omnithread_rt.lib;$ENV{TANGO_ROOT}/lib/msvcstub.lib;$ENV{TANGO_ROOT}/lib/pthreadVC2.lib")                                            
set(WIN_LIBS ws2_32 mswsock advapi32 comctl32 odbc32)
if(MSVC90)
    set(ZMQ_LIB_STA $ENV{TANGO_ROOT}/lib/libzmq-v90-mt-s-4_0_5.lib)
    set(ZMQ_LIB_DYN $ENV{TANGO_ROOT}/lib/libzmq-v90-mt-4_0_5.lib)
elseif(MSVC10)
    set(ZMQ_LIB_STA $ENV{TANGO_ROOT}/lib/libzmq-v100-mt-s-4_0_5.lib)
    set(ZMQ_LIB_DYN $ENV{TANGO_ROOT}/lib/libzmq-v100-mt-4_0_5.lib)
elseif(MSVC12)
    set(ZMQ_LIB_STA $ENV{TANGO_ROOT}/lib/libzmq-v120-mt-s-4_0_5.lib)
    set(ZMQ_LIB_DYN $ENV{TANGO_ROOT}/lib/libzmq-v120-mt-4_0_5.lib)
elseif(MSVC14)
    set(ZMQ_LIB_STA $ENV{TANGO_ROOT}/lib/libzmq-v140-mt-s-4_0_5.lib)
    set(ZMQ_LIB_DYN $ENV{TANGO_ROOT}/lib/libzmq-v140-mt-4_0_5.lib)
endif(MSVC90)

#easy packagin with cpack and NSIS

set (CPACK_PACKAGE_VENDOR "www.tango-controls.org")
set (CPACK_PACKAGE_DESCRIPTION_SUMMARY "Tango - Connecting Things Together")
set (CPACK_PACKAGE_VERSION "${MAJOR_VERSION}.${MINOR_VERSION}.${PATCH_VERSION}")
set (CPACK_PACKAGE_VERSION_MAJOR ${MAJOR_VERSION})
set (CPACK_PACKAGE_VERSION_MINOR ${MINOR_VERSION})
set (CPACK_PACKAGE_VERSION_PATCH ${PATCH_VERSION})
  
set(CPACK_NSIS_HELP_LINK "http://www.tango-controls.org")
set(CPACK_NSIS_URL_INFO_ABOUT "http://www.tango-controls.org")
set(CPACK_NSIS_MODIFY_PATH ON)
set(CPACK_NSIS_ENABLE_UNINSTALL_BEFORE_INSTALL ON)
set(CPACK_NSIS_MENU_LINKS
    "http://tango-controls.readthedocs.io/en/latest/" "Tango Doc")

include(CPack)
