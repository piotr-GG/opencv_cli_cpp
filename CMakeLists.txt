cmake_minimum_required(VERSION 3.12)
project( DisplayImage )
find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS} )
file(GLOB DisplayImage_SRC CONFIGURE_DEPENDS "source/include/*.h" "source/*.cpp")
add_executable( DisplayImage ${DisplayImage_SRC} )
target_link_libraries( DisplayImage ${OpenCV_LIBS} )