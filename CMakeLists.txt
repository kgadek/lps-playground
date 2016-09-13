cmake_minimum_required(VERSION 3.1)
project(LongestPalindromeSubsequence)

set (CMAKE_CXX_STANDARD 14)

add_definitions(-O2)

# MAIN EXECUTABLE
# ==============================================================================

add_executable(main main.cpp)


# GOOGLE TEST
# ==============================================================================
add_executable(t t.cpp)

find_package(Threads)

add_subdirectory("vendor/gtest-HEAD/googlemock" "gmock-build")
include_directories(${gmock_SOURCE_DIR}/include)

target_link_libraries(t gmock gtest gtest_main)
target_link_libraries(t ${CMAKE_THREAD_LIBS_INIT})


# NONIUS BENCHMARK
# ==============================================================================

add_executable(b b.cpp)
include_directories("vendor/nonius-v1.1.2/include")

