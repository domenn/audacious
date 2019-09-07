cmake_minimum_required(VERSION 3.14)
project(Audacious)
set(CMAKE_CXX_STANDARD 17)
set (CMAKE_VERBOSE_MAKEFILE true)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -include config.h")

#
#include_directories(audacious)
#include_directories(audacious/src)
#include_directories(audacious-plugins/src)
#include_directories(C:\\GTK\\include\\glib-2.0)
#
#file(GLOB_RECURSE aud_srcs "./src/*.cpp" "./src/*.hpp" "./src/*.c" "./src/*.cc" "./src/*.h")
#
#add_executable(audacious ${aud_srcs})


# set(PKG_CONFIG_PATH /C/GTK/lib/pkgconfig)
if(WIN32)
  set(ENV{PKG_CONFIG_PATH} "C:/GTK/lib/pkgconfig;C:/libs/lib/pkgconfig")
else()
endif()

find_package(PkgConfig REQUIRED)
pkg_check_modules(GTK2 REQUIRED glib-2.0 gtk+-2.0)
message(STATUS "gtk2 at: ${GTK2_INCLUDE_DIRS}")
include_directories(${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src ${CMAKE_SOURCE_DIR}/src/dbus ${GTK2_INCLUDE_DIRS})

file(GLOB_RECURSE aud_srcs "./src/*.cpp" "./src/*.hpp" "./src/*.c" "./src/*.cc" "./src/*.h")

add_executable(audacious ${aud_srcs})
