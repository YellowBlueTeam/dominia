cmake_minimum_required(VERSION 4.0 FATAL_ERROR)
project(dominia)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

find_package(SDL3 REQUIRED CONFIG REQUIRED COMPONENTS SDL3)
find_package(OpenGL REQUIRED)

add_executable(dominia src/main.cpp)
target_link_libraries(dominia PRIVATE SDL3::SDL3 OpenGL)