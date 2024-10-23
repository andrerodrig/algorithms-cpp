enable_testing()

add_executable(CppTests test.cpp)

target_include_directories(
    CppTests
    PRIVATE ${PROJECT_SOURCE_DIR}/tools ${PROJECT_SOURCE_DIR}/tree
)
target_link_directories(
    CppTests
    PRIVATE ${PROJECT_SOURCE_DIR}/tools ${PROJECT_SOURCE_DIR}/tree)
target_link_libraries(CppTests tools tree)

add_test(NAME TestTools COMMAND CppTests)