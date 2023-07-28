cmake_minimum_required(VERSION 3.18)
project(PcapRead)

set(CMAKE_CXX_STANDARD 14)

add_executable(PcapRead main.cpp pktHandler.cpp RadiusInfo.cpp lt_debug.cpp)


target_include_directories(PcapRead PUBLIC /usr/include)
target_link_libraries(PcapRead PUBLIC pcap)


