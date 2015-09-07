# this is for emacs file handling -*- mode: cmake; indent-tabs-mode: nil -*-
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

set(PROJECT_NAME_STR xkcd_binpack)
project(${PROJECT_NAME_STR} C CXX)

# The version number.
set (xkcd_binpack_VERSION_MAJOR 0)
set (xkcd_binpack_VERSION_MINOR 1a)

set(CMAKE_INCLUDE_CURRENT_DIR_ON)


find_package(Threads REQUIRED)

find_package( OpenCV REQUIRED )
find_package(Boost COMPONENTS system filesystem REQUIRED)

# Enable C++11 support in GNU-Compiler
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

#-------------------
# set common include folder for module
#-------------------
set(COMMON_INCLUDES ${PROJECT_SOURCE_DIR}/src)
set(EXT_PROJECTS_DIR ${PROJECT_SOURCE_DIR}/ext)

#-------------------
# Build location
#-------------------
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_SOURCE_DIR}/build)

#-------------------
# Module source
#-------------------
#set(PROJECT_LIB_NAME ${PROJECT_NAME_STR}_impl)

#include_directories(${COMMON_INCLUDES})
#file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
#add_library(${PROJECT_LIB_NAME} ${SRC_FILES})

add_subdirectory(${EXT_PROJECTS_DIR}/gtest)

add_subdirectory(src/tinyxml2)

add_subdirectory(src/xkcd_binpack)

add_subdirectory(src/tools)

add_subdirectory(src/test)
