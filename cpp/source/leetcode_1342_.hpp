#pragma once
#ifndef _LEETCODE_1342_H_
#define _LEETCODE_1342_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-11 09:39:05
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-11 10:01:57
*/
#include <algorithm>

using std::cout;
using std::endl;

/*
Given a non-negative integer num, 
return the number of steps to reduce it to zero. 
If the current number is even, 
you have to divide it by 2, otherwise, you have to subtract 1 from it.
EX:
14->7->6->3->2->1->0,cost 6 steps.
8->4->2->1,cost 4 steps.
123->122->61->60->30->15->14,then 6 steps,add 14->0,6+6=12 steps.
because every double actions the number at least be half,so it is O(logn).
*/
class Solution1342 {
public:
    int numberOfSteps(int num) {
        int will_return = 0;
        while (num > 0) {
            will_return++;
            if (1 == num % 2) {
                num--;
            } else {
                num /= 2;
            }
        }
        return will_return;
    }

    void test() {
        assert(numberOfSteps(8) == 4);
        assert(numberOfSteps(14) == 6);
        assert(numberOfSteps(123) == 12);
        assert(numberOfSteps(114514) == 27);
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.2 MB,
100%,100%.
*/
#endif
