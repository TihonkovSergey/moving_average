cmake_minimum_required(VERSION 3.16)

project(moving_average)

set(SOURCE_EXE main.cpp)

set(SOURCE_MOVING_AVERAGE_LIB maverage.cpp)

add_library(maverage STATIC ${SOURCE_MOVING_AVERAGE_LIB})

add_executable(main ${SOURCE_EXE})

target_link_libraries(main maverage)	

