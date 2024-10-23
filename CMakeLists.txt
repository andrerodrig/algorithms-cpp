cmake_minimum_required(VERSION 3.15)

project(trees VERSION 0.1)

add_executable(trees)
target_sources(trees PRIVATE main.cpp)

add_subdirectory(tools)
add_subdirectory(tree)

target_include_directories(trees PRIVATE tools tree)
target_link_directories(trees PRIVATE tools tree)
target_link_libraries(trees PRIVATE tools tree)

add_subdirectory(tests)