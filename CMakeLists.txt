# this is for emacs file handling -*- mode: cmake; indent-tabs-mode: nil -*-
CMAKE_MINIMUM_REQUIRED(VERSION 2.8)

PROJECT(xkcd_binpack)


SET(CMAKE_INCLUDE_CURRENT_DIR_ON)


enable_testing()

ADD_SUBDIRECTORY(src/tinyxml2)

ADD_SUBDIRECTORY(src/xkcd_binpack)

ADD_SUBDIRECTORY(src/tools)

IF(BUILD_TESTS)
  ADD_SUBDIRECTORY(src/test)
ENDIF(BUILD_TESTS)

