cmake_minimum_required(VERSION 3.15)
project(AdvancedRTCPP)

set(CMAKE_CXX_STANDARD 17)

include_directories(./include)
add_executable(AdvancedRTCPP src/main.cpp src/Display.cpp src/Generator.cpp src/Alarm.cpp src/Pipe.cpp src/Pipeline.cpp)