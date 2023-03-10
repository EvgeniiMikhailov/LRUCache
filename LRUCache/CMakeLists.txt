cmake_minimum_required(VERSION 3.21)
project(LRUCache)

set(CMAKE_CXX_STANDARD 17)

include(FetchContent)
FetchContent_Declare(
        googletest
        URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
        DOWNLOAD_EXTRACT_TIMESTAMP true
)
set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(
        LRUCache_test
        LRUCache.h LRUCache_test.cpp
)
target_link_libraries(
        LRUCache_test
        GTest::gtest_main
)

include(GoogleTest)
gtest_discover_tests(LRUCache_test)

add_test(LRUCache_test LRUCache_test)
