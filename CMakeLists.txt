cmake_minimum_required(VERSION 3.4)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)
set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --std=c++14 -g")
set(PROJECT_NAME "enigma")

project(${PROJECT_NAME})

include_directories(
    include)

file(GLOB_RECURSE SOURCES
    src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})
