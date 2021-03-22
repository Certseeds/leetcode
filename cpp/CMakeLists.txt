# header begin
cmake_minimum_required(VERSION 3.10.2)
project(leetcode_cpp LANGUAGES CXX)

set(CMAKE_CXX_STANDARD 14)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Wextra -O0")
add_definitions(-D__LOCAL__)

include_directories(./third_party)
include_directories(./includes)
include_directories(./source)
include_directories(./test)

ENABLE_TESTING()
set(dependencies 1 3 5 6 7 9 11 12 13 14 17 44 64 95 120 153 154 167 174 343 350 785 0803 1025)
foreach (LEETCODE_NUMBER IN LISTS dependencies)
    MESSAGE(${LEETCODE_NUMBER})
    add_executable(${PROJECT_NAME}_${LEETCODE_NUMBER}
            ./source/leetcode_${LEETCODE_NUMBER}_.hpp
            ./test/leetcode_test_${LEETCODE_NUMBER}_.cpp
            )
    ADD_TEST(${PROJECT_NAME}_${LEETCODE_NUMBER}_CTEST ${PROJECT_NAME}_${LEETCODE_NUMBER})
endforeach ()
unset(dependencies)

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