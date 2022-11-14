cmake_minimum_required(VERSION 3.5)
project(NavDemo VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)

# ----------------------------------------------------------------------------
# Define build folders
# ----------------------------------------------------------------------------
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

# ----------------------------------------------------------------------------
# Define build type
# ----------------------------------------------------------------------------
if (NOT CMAKE_BUILD_TYPE)
    SET(CMAKE_BUILD_TYPE Release)
endif ()

if (CMAKE_BUILD_TYPE STREQUAL "Debug")
    set(CMAKE_BUILD_TYPE "Debug")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17 -O0 -pthread -ldl -rdynamic -Wall -g ")
else ()
    set(CMAKE_BUILD_TYPE "Release")
    set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS}")
endif ()

message("Build Type:" ${CMAKE_BUILD_TYPE} ${CMAKE_CXX_FLAGS})

# ----------------------------------------------------------------------------
# Find dependencies. 
# ----------------------------------------------------------------------------
find_package(OpenCV 4 REQUIRED)
include_directories(${OpenCV_INCLUDE_DIRS})

if(OPENCV_FOUND)
    message("-- OpenCV 4 found, VERSION: " ${OpenCV_VERSION})
else()
    message("-- OpenCV not found")
endif()

find_package(Eigen3 REQUIRED)
include_directories(${EIGEN3_INCLUDE_DIR})

if(Eigen3_FOUND)
    message("-- Eigen3 found, VERSION: " ${EIGEN3_VERSION_STRING})
else()
    message("-- Eigen3 not found")
endif()

add_subdirectory(Map)

set(CPACK_PROJECT_NAME ${PROJECT_NAME})
set(CPACK_PROJECT_VERSION ${PROJECT_VERSION})
include(CPack)

