# header begin
cmake_minimum_required(VERSION 3.16.6)
project(leetcode_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra")
add_definitions(-D__LOCAL__)

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/third_party)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/includes)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/source)
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/test)
#add_library(CATCH_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/includes/catch_main.hpp)
#target_precompile_headers(CATCH_MAIN ${CMAKE_CURRENT_SOURCE_DIR}/includes/catch_main.hpp)
ENABLE_TESTING()
set(dependencies
        1 3 4 5 6 7 8 9 10 11 12 13 14 15 17 19 20 21 22 23 24 25 26 27 28 29 30 31 32
        44 50 56 64 80 88 95 120 153 154 167 174 208 263 343 350 530 372 743 781 783 785 0803 1010 1025 1143)
foreach (LEETCODE_NUMBER IN LISTS dependencies)
    add_executable(${PROJECT_NAME}_${LEETCODE_NUMBER}
            ${CMAKE_CURRENT_SOURCE_DIR}/source/leetcode_${LEETCODE_NUMBER}_.hpp
            ${CMAKE_CURRENT_SOURCE_DIR}/test/leetcode_test_${LEETCODE_NUMBER}_.cpp
            )
    ADD_TEST(${PROJECT_NAME}_${LEETCODE_NUMBER}_CTEST ${PROJECT_NAME}_${LEETCODE_NUMBER})
endforeach ()
unset(dependencies)

add_executable(${PROJECT_NAME}_pch ${CMAKE_CURRENT_SOURCE_DIR}/test/all.cpp) # only for ci

#file(GLOB USER_LIBS_PATH ./source/leetcode_*_.hpp)
#foreach(elementName IN LISTS USER_LIBS_PATH)
#    string(REGEX REPLACE ".*leetcode_" "" LEETCODE_NUMBER ${elementName})
#    string(REGEX REPLACE "_.hpp" "" LEETCODE_NUMBER ${LEETCODE_NUMBER})
#    add_executable(${PROJECT_NAME}_${LEETCODE_NUMBER}
#            ./includes/catch_main.hpp
#            ./source/leetcode_${LEETCODE_NUMBER}_.hpp
#            ./test/leetcode_test_${LEETCODE_NUMBER}_.cpp
#            )
#endforeach()
#unset(elementName)