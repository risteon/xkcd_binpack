# this is for emacs file handling -*- mode: cmake; indent-tabs-mode: nil -*-
CMAKE_MINIMUM_REQUIRED(VERSION 2.8.8)

set(PROJECT_NAME_STR xkcd_binpack)
project(${PROJECT_NAME_STR} C CXX)

# The version number.
set (Tutorial_VERSION_MAJOR 0)
set (Tutorial_VERSION_MINOR 1a)

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

#-------------------
# Test
#-------------------
enable_testing()
set(PROJECT_TEST_NAME ${PROJECT_NAME_STR}_test)
include_directories(${GTEST_INCLUDE_DIRS} ${COMMON_INCLUDES})

set(xkcd_binpack_SOURCES
  src/xkcd_binpack/Canvas.cpp
  src/xkcd_binpack/Pixel.cpp
  src/xkcd_binpack/ShapeCreator.cpp
  src/xkcd_binpack/ShapeAlignedRectangle.cpp
  src/xkcd_binpack/ShapePackerBase.cpp
  src/xkcd_binpack/ShapePackerGrid.cpp
)

file(GLOB TEST_SRC_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(${PROJECT_TEST_NAME} ${TEST_SRC_FILES} ${xkcd_binpack_SOURCES})
add_dependencies(${PROJECT_TEST_NAME} googletest)


target_link_libraries(${PROJECT_TEST_NAME}
  ${GTEST_LIBS_DIR}/libgtest.a
  ${GTEST_LIBS_DIR}/libgtest_main.a
  ${OpenCV_LIBS}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  tinyxml2
)


target_link_libraries(${PROJECT_TEST_NAME} ${CMAKE_THREAD_LIBS_INIT})

add_test(test1 ${PROJECT_TEST_NAME})
