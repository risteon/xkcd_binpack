# this is for emacs file handling -*- mode: cmake; indent-tabs-mode: nil -*-
## TESTS

#Setup
# Enable ExternalProject CMake module
include(ExternalProject)

find_package(GTest REQUIRED)


add_executable( test_ShapeAlignedRectangle tests/test_ShapeAlignedRectangle.cpp ${SOURCES} )

target_link_libraries( test_ShapeAlignedRectangle
  ${OpenCV_LIBS}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  tinyxml2
)
