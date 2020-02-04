#pragma once
#ifndef _LEETCODE_MACRO_H_
#define _LEETCODE_MACRO_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-04 20:40:55
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-04 20:40:57
*/

#define function_head() function_head1(leetcode_NUM)
#define function_head1(EXP) function_head2(EXP)
//#define function_head2(EXP) main_##EXP()
#define function_head2(EXP)  sums_of_three(main_,EXP,())


#define Solution_head Solution_head1(leetcode_NUM)
#define Solution_head1(EXP) Solution_head2(EXP)
//#define Solution_head2(EXP) Solution##EXP
#define Solution_head2(EXP)  sums_of_two(Solution,EXP)


#define Solution_object Solution_object1(leetcode_NUM)
#define Solution_object1(EXP) Solution_object2(EXP)
//#define Solution_object2(EXP) Solution##EXP
#define Solution_object2(EXP)  sums_of_two(sol,EXP)


#define leetcode_include leetcode_include2(leetcode_NUM)
#define leetcode_include2(EXP) leetcode_include3(EXP)
//#define leetcode_include3(EXP) leetcode_##EXP.h
#define leetcode_include3(EXP)  sums_of_three(leetcode_,EXP,.h)

#define sums_of_three(x,y,z) x##y##z
#define sums_of_two(x,y) x##y

#define TO_STRING(str) _TO_STRING(str)
#define _TO_STRING(str) #str

#endif