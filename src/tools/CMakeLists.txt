include_directories( ${xkcd_binpack_INCLUDE_DIRS} )

add_executable(packer packer.cpp)

target_link_libraries(packer xkcd_binpack)
