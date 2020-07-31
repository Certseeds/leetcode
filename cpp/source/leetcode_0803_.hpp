/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-31 23:49:58
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
#ifndef LEETCODE_SOURCE_LEETCODE_0803_H
#define LEETCODE_SOURCE_LEETCODE_0803_H

#include <vector>

using std::vector;

class Solution0803 {
public:
    int findMagicIndex(vector<int> &nums) {
        return magic_rec(nums, 0, nums.size() - 1);
    }

    int magic_rec(const vector<int> &nums, int first, int last) {
        if (first > last) {
            return -1;
        } else if (first == last) {
            return (nums[first] == first) ? first : -1;
        }
        int middle = (last - first) / 2 + first;
        int left_min = magic_rec(nums, first, middle - 1);
        if (middle == nums[middle]) {
            if (left_min == -1) {
                return middle;
            }
            return left_min;
        }
        int right_min = magic_rec(nums, middle + 1, last);
        if (left_min == -1) {
            return right_min;
        }
        return left_min;
    }
};

#endif //LEETCODE_CPP_SOURCE_LEETCODE_0803_H