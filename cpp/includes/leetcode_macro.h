/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-04 20:40:55
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-07-05 16:29:57
*/
#pragma once
#ifndef _LEETCODE_MACRO_H_
#define _LEETCODE_MACRO_H_

#define function_head sums_of_two(main_,leetcode_NUM)

#define Solution_head sums_of_two(Solution,leetcode_NUM)

#define Solution_object sums_of_two(sol,leetcode_NUM)

#define postfix _.hpp
#define leetcode_include sums_of_three(leetcode_test_,leetcode_NUM,postfix)

#define sums_of_three_3(x, y, z) x##y##z
#define sums_of_three_2(x, y, z) sums_of_three_3(x,y,z)
#define sums_of_three(x, y, z) sums_of_three_2(x,y,z)

#define sums_of_two_3(x, y) x##y
#define sums_of_two_2(x, y) sums_of_two_3(x,y)
#define sums_of_two(x, y) sums_of_two_2(x,y)

#define TO_STRING(str) _TO_STRING(str)
#define _TO_STRING(str) #str


#endif