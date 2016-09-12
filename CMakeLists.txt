cmake_minimum_required(VERSION 2.6)
project(LongestPalindromeSubsequence)


# ==============================================================================


add_definitions(-std=c++1z)
#add_definitions(-pedantic)
#add_definitions(-Weverything)
#add_definitions(-Wno-c++98-compat -Wno-c++98-compat-pedantic)
add_definitions(-O2)


add_executable(main main.cpp)


# GOOGLE TEST
# ==============================================================================
add_executable(t t.cpp)

find_package(Threads)

add_subdirectory("vendor/gtest-HEAD/googlemock" "gmock-build")
include_directories(${gmock_SOURCE_DIR}/include)

target_link_libraries(t gmock gtest gtest_main)
target_link_libraries(t ${CMAKE_THREAD_LIBS_INIT})
