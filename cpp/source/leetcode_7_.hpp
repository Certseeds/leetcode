/**
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @LastEditDate: 2020-07-13 22:00:00
 * @LastEditors  : nanoseeds
 */
/*  leetcode_cpp
   Copyright (C) 2020  nanoseeds

   leetcode_cpp is free software: you can redistribute it and/or modify
   it under the terms of the GNU Affero General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   leetcode_cpp is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
   */
#pragma once
#ifndef _LEETCODE_7_H
#define _LEETCODE_7_H

#include <vector>
#include <algorithm>

namespace Solution7 {

using std::vector;

/*
Given a 32-bit signed integer, reverse digits of an integer.
*/
class Solution7 {
public:
    int reverse(long long x) {
        if (x < 0) {
            return -1 * reverse(-1 * x);
        }
        vector<int> nums;
        while (x > 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
        int i = 0;
        while (i < static_cast<int>(nums.size()) && nums[i] == 0) {
            i++;
        }
        long will_return = 0;
        for (; i < static_cast<int>(nums.size()); i++) {
            will_return = will_return * 10 + nums[i];
            if (will_return > INT32_MAX) {
                return 0;
            }
        }
        return static_cast<int32_t>(will_return);
    }

    int reverse2(int32_t x) {
        if (x == INT32_MIN) {
            return 0;
        } else if (x < 0) {
            return -1 * reverse(-x);
        }
        vector<uint8_t> vec;
        vec.reserve(32);
        while (x > 0) {
            vec.push_back(x % 10);
            x /= 10;
        }
        int32_t will_return = 0;
        for (const auto &i:vec) {
            if (will_return > INT32_MAX / 10) {
                return 0;
            }
            will_return = 10 * will_return + i;
        }
        return will_return;
    }
};
}
/*
Runtime: 4 ms,
Memory Usage: 8.6 MB,
69.76%,10.48%.
Runtime: 0 ms,
Memory Usage: 6 MB,
100%,100%.
*/
#endif
