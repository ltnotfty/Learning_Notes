cmake_minimum_required(VERSION 3.18)
project(simpleRpc)

set(CMAKE_CXX_STANDARD 14)


file(GLOB_RECURSE  all_source  src/*.cpp )
add_executable(simpleRpc main.cpp ${all_source})
