cmake_minimum_required(VERSION 3.17)

project(oop_exercise_03)

set(SOURCE main.cpp dot.cpp octagon.cpp square.cpp triangle.cpp)
set(EXEC lr3)

add_definitions(-std=c++17 -pedantic -Wall)
include_directories(${CMAKE_CURRENT_SOURCE_DIR})
add_executable(${EXEC} ${SOURCE})
