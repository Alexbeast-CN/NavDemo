cmake_minimum_required(VERSION 3.5)
project(Map)

include_directories(include)

file (GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)
file (GLOB_RECURSE SRC_FILES ${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/include)

add_executable(Plot_map      test/Plot_map.cpp ${SRC_FILES})
add_executable(Draw_map         test/Draw_map.cpp)

target_link_libraries(Plot_map  ${OpenCV_LIBS})
target_link_libraries(Draw_map     ${OpenCV_LIBS})