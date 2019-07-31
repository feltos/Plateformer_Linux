cmake_minimum_required(VERSION 3.1)
project(Platformer)


file(GLOB_RECURSE Platformer_SRC Src/*.cpp Include/*.hpp)

find_package(Box2D REQUIRED)
include_directories(${BOX2D_INCLUDE_DIR})

set (CMAKE_MODULE_PATH "${CMAKE_SOURCE_DIR}/CMake/;${CMAKE_MODULE_PATH}")

find_package(SFML 2.4 COMPONENTS system window graphics audio REQUIRED)
include_directories(${SFML_INCLUDE_DIR})

include_directories(Include/)
add_executable(Platformer ${Platformer_SRC})

target_link_libraries(Platformer ${BOX2D_LIBRARY})
target_link_libraries(Platformer ${SFML_LIBRARIES})