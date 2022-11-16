cmake_minimum_required(VERSION 3.5)
project(Map)

file (GLOB_RECURSE MAP_SRC ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(Plot_map      test/Plot_map.cpp ${MAP_SRC})
add_executable(Draw_map         test/Draw_map.cpp)

target_link_libraries(Plot_map  ${OpenCV_LIBS})
target_link_libraries(Draw_map     ${OpenCV_LIBS})