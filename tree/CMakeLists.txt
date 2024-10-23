cmake_minimum_required(VERSION 3.15)
project(tree)

add_library(tree)

target_sources(tree
    PUBLIC tree.hpp tree.cpp
)

target_include_directories(tree PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})
