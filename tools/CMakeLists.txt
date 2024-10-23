cmake_minimum_required(VERSION 3.15)
project(tools)

add_library(tools)

target_sources(tools
    PUBLIC compare_helper.hpp dummy_class.hpp memory_cell.hpp square.hpp
    PRIVATE  dummy_class.cpp square.cpp
)
target_include_directories(tools PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
