cmake_minimum_required(VERSION 3.1.3)
set(CMP0048 NEW)
project(TangoTest LANGUAGES CXX
        VERSION 3.0)

include(FindPkgConfig)
if(WIN32)
include(CmakeTangoWin.cmake)
add_definitions(-D_UNICODE)
add_definitions(-DUNICODE)
else(win32)
pkg_search_module(TANGO_PKG REQUIRED tango)
endif(WIN32)


set(SOURCES
        ClassFactory.cpp
        TangoTest.cpp
        TangoTestClass.cpp
        TangoTestStateMachine.cpp
        main.cpp)

set(HEADERS
        TangoTest.h
        TangoTestClass.h)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_STANDARD_REQUIRED YES)

include_directories(${CMAKE_SOURCE_DIR} ${TANGO_PKG_INCLUDE_DIRS})
link_directories(${TANGO_PKG_LIBRARY_DIRS})
#
# Device Server generation
#
set(SERVER_NAME ${PROJECT_NAME})
if(WIN32)
  include_directories(${ALL_CLASS_INCLUDE}  ${USER_INCL_DIR} ${TANGO_INCLUDES})
  add_executable(${PROJECT_NAME} ${SOURCES})
  target_compile_options(${PROJECT_NAME} PUBLIC ${TANGO_PKG_CFLAGS_OTHER})
  target_link_libraries(${PROJECT_NAME} PUBLIC ${TANGO_DYN_LIBS} ${WIN_LIBS} ${ZMQ_LIB_DYN})
  install(TARGETS ${PROJECT_NAME} 
          RUNTIME DESTINATION bin
          LIBRARY DESTINATION bin
          ARCHIVE DESTINATION bin)
  add_compile_options(/MT)
  add_executable(${PROJECT_NAME}_sta ${SOURCES})
  target_link_libraries(${PROJECT_NAME}_sta PUBLIC ${TANGO_STA_LIBS} ${WIN_LIBS} ${ZMQ_LIB_STA})
  target_compile_options(${PROJECT_NAME}_sta PUBLIC "/MT")
  install(TARGETS ${PROJECT_NAME}_sta 
        RUNTIME DESTINATION bin
        LIBRARY DESTINATION bin
        ARCHIVE DESTINATION bin)
        
  set_property(TARGET ${PROJECT_NAME}_sta PROPERTY COMPILE_DEFINITIONS "_WINSTATIC;")
  set_property(TARGET ${PROJECT_NAME} PROPERTY COMPILE_DEFINITIONS "LOG4TANGO_HAS_DLL;TANGO_HAS_DLL;")
  set_property(TARGET ${PROJECT_NAME}_sta PROPERTY LINK_FLAGS "/force:multiple")
  set_property(TARGET  ${PROJECT_NAME} PROPERTY LINK_FLAGS "/force:multiple")
else(WIN32)

add_executable(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR} ${TANGO_PKG_INCLUDE_DIRS})
target_compile_options(${PROJECT_NAME} PUBLIC ${TANGO_PKG_CFLAGS_OTHER})
target_link_libraries(${PROJECT_NAME} PUBLIC ${TANGO_PKG_LIBRARIES})
  target_link_libraries(${PROJECT_NAME} ${TANGO_PKG_LIBRARIES} -Wl,-z,now -pie)
  target_compile_options(${PROJECT_NAME} PUBLIC ${TANGO_PKG_CFLAGS_OTHER} -Wall -Wextra -D_FORTIFY_SOURCE=2 -O1 -fpie)
  
install(TARGETS ${PROJECT_NAME}
        RUNTIME DESTINATION "${CMAKE_INSTALL_FULL_BINDIR}"
        CONFIGURATIONS ${CMAKE_BUILD_TYPE})
endif(WIN32)
