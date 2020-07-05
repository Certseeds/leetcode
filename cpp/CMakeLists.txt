# header begin
cmake_minimum_required(VERSION 3.10.2)
project(leetcode_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O0")
include_directories(./source)

add_executable(${PROJECT_NAME}
        ./source/leetcode.cpp)

#
#add_subdirectory(source/vivo_20200610)
#add_subdirectory(source/kauishou_2019_algorithm_A)
#add_subdirectory(source/basic_algorithms)
