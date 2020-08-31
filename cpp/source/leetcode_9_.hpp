/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-23 23:17:17
 * @LastEditors  : nanoseeds
 */
/*  leetcode
    Copyright (C) 2020  nanoseeds

    leetcode is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    leetcode is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
#pragma once
#ifndef LEETCODE_SOURCE_LEETCODE_9_H
#define LEETCODE_SOURCE_LEETCODE_9_H

#include <vector>
#include <algorithm>

using std::vector;

/*
Determine whether an integer is a palindrome.
An int32_teger is a palindrome when it reads the same backward as forward.
*/
class Solution9 {
public:
    bool isPalindrome(int32_t x) {
        vector<int32_t> nums;
        if (x < 0) {
            return false;
        }
        while (x > 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
        for (int32_t i = 0; i < static_cast<int32_t>(nums.size() / 2); i++) {
            if (nums[i] != nums[nums.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }
};
/*
Runtime: 28 ms,
Memory Usage: 12 MB,
13.43%,5.45%.
*/
#endif //LEETCODE_CPP_SOURCE_LEETCODE_9_H