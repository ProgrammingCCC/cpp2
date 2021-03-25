cmake_minimum_required(VERSION 2.8)
set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
project(Week9)

include_directories(.)

include(gtest.cmake)

find_package(Threads)

add_executable(week9 src/main.cpp src/fib.cpp)

add_executable(week9-test test/main.cpp src/fib.cpp)
target_link_libraries(week9-test gtest ${CMAKE_THREAD_LIBS_INIT})
