cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

project(testlib)

include_directories(.)


add_executable(testlib-runner src/main.cpp)

add_executable(testlib-test test/main.cpp)
