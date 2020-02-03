#pragma once
#ifndef _LEETCODE_7_H
#define _LEETCODE_7_H
#include <vector>
#include <array>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a 32-bit signed integer, reverse digits of an integer.
*/
class Solution7 {
public:
   int  reverse(long long x) {
        if (x < 0) {
            return -1 * reverse(-1 * x);
        }
        vector<int> nums;
        while (x > 0) {
            nums.push_back(x % 10);
           x /= 10;
        }
        int i = 0;
        while (i<nums.size() && nums[i] == 0) {
            i++;
        }
        long will_return = 0;
        for (; i < nums.size(); i++) {
            will_return = will_return * 10 + nums[i];
            if (will_return > INT32_MAX) {
                return 0;
            }
        }
        return int(will_return);
    }
    void test() {
        cout << reverse(123) << endl;
        cout << reverse(-123) << endl;
        cout << reverse(120) << endl;
        cout << reverse(0) << endl;
        cout << reverse(-2147483648) << endl;
    }
};
/*
Runtime: 4 ms,
Memory Usage: 8.6 MB,
69.76%,10.48%.
*/
#endif
