cmake_minimum_required(VERSION 3.7 FATAL_ERROR)
set(CMP0048 NEW)
project(TangoTest LANGUAGES CXX
        VERSION 3.0)
include(FindPkgConfig)

if(NOT WIN32)
  pkg_search_module(TANGO_PKG REQUIRED tango)
ENDIF()

if(NOT DEFINED CMAKE_CXX_STANDARD)
    set(CMAKE_CXX_STANDARD 14)
endif()

set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_STANDARD_REQUIRED YES)

set(SOURCES
        ClassFactory.cpp
        TangoTest.cpp
        TangoTestClass.cpp
        TangoTestStateMachine.cpp
        main.cpp)

set(HEADERS
        TangoTest.h
        TangoTestClass.h)

link_directories(${TANGO_PKG_LIBRARY_DIRS})

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${TANGO_PKG_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${TANGO_PKG_CFLAGS_OTHER})
target_link_libraries(${PROJECT_NAME} PUBLIC ${TANGO_PKG_LIBRARIES})
install(TARGETS ${PROJECT_NAME} RUNTIME DESTINATION bin)

option(TANGO_WARNINGS_AS_ERRORS "Treat compiler warnings as errors" OFF)

if(TANGO_WARNINGS_AS_ERRORS)
  target_compile_options(${PROJECT_NAME} PUBLIC -Werror -Wall -Wextra -Wformat -Werror=format-security -pedantic)
endif()
