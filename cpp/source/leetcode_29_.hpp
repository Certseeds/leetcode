#pragma once
#ifndef _LEETCODE_29_H_
#define _LEETCODE_29_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-07 20:27:47
*/
#include <vector>
#include <algorithm>

using std::abs;
using std::min;
using std::cout;
using std::endl;
using std::vector;

/*
Given two integers dividend and divisor, divide two integers without using multiplication, 
division and mod operator.

Return the quotient after dividing dividend by divisor.

The integer division should truncate toward zero.

Example 1:

Input: dividend = 10, divisor = 3
Output: 3
Example 2:

Input: dividend = 7, divisor = -3
Output: -2
Note:

Both dividend and divisor will be 32-bit signed integers.
The divisor will never be 0.
Assume we are dealing with an environment which could only 
store integers within the 32-bit signed integer range: [−2^31,  2^31 − 1]. 
For the purpose of this problem, 
assume that your function returns 231 − 1 when the division result overflows.
*/
class Solution29 {
public:
    int divide(int dividend, int divisor) {
        if (dividend == divisor) {
            return 1;
        } else if (divisor == INT32_MIN) {
            return 0;
        } else if (divisor == 1) {
            return dividend;
        }
        int will_return = 0;
        int signs = 1;
        if (dividend == INT32_MIN) {
            if (divisor == -1) {
                return INT32_MAX;
            }
            will_return += 1;
            dividend += sign(divisor) * divisor;
        }
        signs *= sign(dividend) * sign(divisor);
        dividend *= sign(dividend);
        divisor *= sign(divisor);
        while (dividend >= divisor) {
            short temp = 0;
            //cout << dividend << " " << divisor << endl;
            while (dividend >= divisor) {
                //cout << dividend << " " << temp << " " << divisor << endl;
                if ((dividend >> 1) < (divisor << temp)) {
                    dividend -= (divisor << temp);
                    will_return += (1 << temp);
                    break;
                }
                temp++;
            }
        }
        return will_return * signs;
    }

    void test() {
        //cout << divide(INT32_MIN, -1) << endl;
        assert(divide(INT32_MIN, -1) == INT32_MAX);
        //cout << divide(INT32_MIN, 1) << endl;
        assert(divide(INT32_MIN, 1) == INT32_MIN);
        //cout << divide(INT32_MIN, 2) << endl;
        //cout << divide(INT32_MIN, 2) << endl;
        assert(divide(INT32_MIN, 2) == -1073741824);
        assert(divide(INT32_MIN, -2) == 1073741824);
        assert(divide(10, 3) == 3);
        assert(divide(7, -3) == -2);
        assert(divide(INT32_MIN, INT32_MIN) == 1);
        assert(divide(-1010369383, -2147483648) == 0);
    }
};
/*
Runtime: 4 ms,
Memory Usage: 8.4 MB,
76.24%,8.00%.
*/
#endif
