cmake_minimum_required(VERSION 3.16)

project(sample_project LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

include_directories(include)

add_library(mymath lib/add.cpp)

add_executable(main main.cpp)
target_link_libraries(main PRIVATE mymath)

include(FetchContent)

set(INSTALL_GTEST OFF CACHE BOOL "Disable GoogleTest installation" FORCE)

FetchContent_Declare(
    googletest
    GIT_REPOSITORY https://github.com/google/googletest.git
    GIT_TAG v1.14.0
)

FetchContent_MakeAvailable(googletest)

enable_testing()

add_executable(tests tests/test_add.cpp)
target_link_libraries(tests PRIVATE GTest::gtest_main mymath)

include(GoogleTest)
gtest_discover_tests(tests)

set(BENCHMARK_ENABLE_TESTING OFF CACHE BOOL "Disable Google Benchmark tests" FORCE)
set(BENCHMARK_ENABLE_INSTALL OFF CACHE BOOL "Disable Google Benchmark install" FORCE)

FetchContent_Declare(
    googlebenchmark
    GIT_REPOSITORY https://github.com/google/benchmark.git
    GIT_TAG v1.8.3
)

FetchContent_MakeAvailable(googlebenchmark)

add_executable(benchmark_add benchmark/benchmark_add.cpp)
target_link_libraries(benchmark_add PRIVATE benchmark::benchmark mymath)