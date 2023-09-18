cmake_minimum_required(VERSION 3.25)
project(PEOT)

set(CMAKE_CXX_STANDARD 14)

include_directories(.)
set(CMAKE_MODULE_PATH ${CMAKE_MODULE_PATH} ${CMAKE_CURRENT_SOURCE_DIR}/cmake-modules)

find_package(OpenCV REQUIRED)
include_directories( ${OpenCV_INCLUDE_DIRS})

add_executable(PEOT
        main.cpp
        Particle.cpp
        Particle.h)

target_link_libraries( PEOT ${OpenCV_LIBS})