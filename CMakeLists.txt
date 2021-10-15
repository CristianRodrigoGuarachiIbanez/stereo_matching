cmake_minimum_required(VERSION 3.19)
project(stereo_matching)

set(CMAKE_CXX_STANDARD 14)

add_executable(stereo ssd_stereo.cpp main.cpp)