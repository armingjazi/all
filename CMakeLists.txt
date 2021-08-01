cmake_minimum_required(VERSION 3.13)

project(all)

set(CMAKE_CXX_STANDARD 14)

include_directories(entw entw/include)

add_subdirectory(core)

add_subdirectory(test)