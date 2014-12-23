cmake_minimum_required(VERSION 2.8.3)

set(LIBRARY_NAME    tinyxml2)

include_directories(.)

set(SOURCE_FILES
  tinyxml2.cpp
)

set(HEADER_FILES
  tinyxml2.h
)

add_library(${LIBRARY_NAME} SHARED ${SOURCE_FILES} )

install(FILES ${HEADER_FILES}
		DESTINATION ${CMAKE_INSTALL_PREFIX}/include)
install(TARGETS ${LIBRARY_NAME} 
        DESTINATION ${CMAKE_INSTALL_PREFIX})
