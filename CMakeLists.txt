cmake_minimum_required(VERSION 2.8)
project( xkcd_binpack )

find_package( OpenCV REQUIRED )
find_package(Boost COMPONENTS system filesystem REQUIRED)

# Enable C++11 support in GNU-Compiler
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(CMAKE_BUILD_TYPE "Debug")

add_subdirectory(tinyxml2)

include_directories(
  export/include
)

set(HEADERS
  src/MessageException.h
  src/Point.h
  src/ShapeContainer.h
  src/Shape.h
)

set(SOURCES
  src/Point.cpp
  src/ShapeContainer.cpp
  src/Shape.cpp
  src/main.cpp
)

add_executable( xkcd_binpack ${SOURCES} )

target_link_libraries( xkcd_binpack
  ${OpenCV_LIBS}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  tinyxml2
)
