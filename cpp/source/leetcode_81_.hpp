/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-18 22:59:48
 * @LastEditors: nanoseeds
 */
/*  leetcode
    Copyright (C) 2020-2021 nanoseeds

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
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_81_H
#define LEETCODE_CPP_SOURCE_LEETCODE_81_H

#include <algorithm>
#include <array>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Solution81 {
using std::array;
using std::queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;

class Solution81 {
public:
    bool search(const vector<int> &nums, int target) {
        const auto nums_size = static_cast<int32_t>(nums.size());
        if (nums.empty()) {
            return false;
        } else if (nums_size == 1) {
            return target == nums[0];
        }
        int32_t first{0}, last{nums_size - 1}, middle{0};
        while (first <= last) {
            if (nums[first] == target || nums[last] == target) {
                return true;
            }
            middle = (last - first) / 2 + first;
            if (nums[middle] == target) {
                return true;
            } else {
                while (nums[middle] == nums[first]) {
                    first++;
                }
                while (nums[middle] == nums[last]) {
                    last--;
                }
                if(first > last){
                    return false;
                }
                if (nums[first] == target || nums[last] == target) {
                    return true;
                }
                if (nums[first] < nums[middle]) {
                    if (nums[first] < target && target < nums[middle]) {
                        last = middle;
                    } else {
                        first = middle + 1;
                    }
                } else {
                    if (nums[middle] < target && target < nums[last]) {
                        first = middle + 1;
                    } else {
                        last = middle;
                    }
                }
            }
        }
        return false;
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_81_H