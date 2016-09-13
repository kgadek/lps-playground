cmake_minimum_required(VERSION 3.1)
project(LongestPalindromeSubsequence)


# ==============================================================================

add_definitions(-O2)


add_executable(main main.cpp)
set_property(TARGET main PROPERTY CXX_STANDARD 14)


# GOOGLE TEST
# ==============================================================================
add_executable(t t.cpp)
set_property(TARGET t PROPERTY CXX_STANDARD 14)

find_package(Threads)

add_subdirectory("vendor/gtest-HEAD/googlemock" "gmock-build")
include_directories(${gmock_SOURCE_DIR}/include)

target_link_libraries(t gmock gtest gtest_main)
target_link_libraries(t ${CMAKE_THREAD_LIBS_INIT})

