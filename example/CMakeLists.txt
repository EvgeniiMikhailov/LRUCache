cmake_minimum_required(VERSION 3.11)

project(example CXX)
set(CMAKE_CXX_STANDARD 17)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../LRUCache)

add_executable(example main.cpp)
