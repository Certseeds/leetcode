/*
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-27 11:59:52
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-13 22:16:55
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
#ifndef _LEETCODE_1_H
#define _LEETCODE_1_H

#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Given an array of integers, 
return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution,
and you may not use the same element twice.
*/
class Solution1 {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        int32_t nums_size = nums.size();
        unordered_map<int32_t, int32_t> umaps;
        for (int32_t i = 0; i < nums_size; i++) {
            if (umaps.find(target - nums[i]) != std::end(umaps)) {
                return vector<int32_t>{i, umaps[target - nums[i]] - 1};
            }
            umaps[nums[i]] = i + 1;
        }
        return vector<int32_t>{};
    }
    /*
    if the number is not so big, it's better to use brute force,
    if number > 50,choose hashmap.
     */
};
/*
Runtime: 8 ms, 
Memory Usage: 10.9 MB,
92.85%,9.17%.
*/
#endif
