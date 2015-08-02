find_package( OpenCV REQUIRED )
find_package(Boost COMPONENTS system filesystem REQUIRED)

# Enable C++11 support in GNU-Compiler
SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

SET(CMAKE_BUILD_TYPE "Debug")

include_directories(
  export/include
)

set(HEADERS
  Canvas.h
  MessageException.h
  Pixel.h
  ShapeCreator.h
  ShapeAlignedRectangle.h
  ShapePackerBase.h
  ShapePackerGrid.h
)

set(xkcd_binpack_SOURCES
  Canvas.cpp
  Pixel.cpp
  ShapeCreator.cpp
  ShapeAlignedRectangle.cpp
  ShapePackerBase.cpp
  ShapePackerGrid.cpp
  main.cpp
)

add_executable( xkcd_binpack ${xkcd_binpack_SOURCES} )

target_link_libraries( xkcd_binpack
  ${OpenCV_LIBS}
  ${Boost_SYSTEM_LIBRARY}
  ${Boost_FILESYSTEM_LIBRARY}
  tinyxml2
)
