/*
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-20 23:47:54
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-20 23:57:14
 */
/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-20 23:47:54
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
#ifndef LEETCODE_SOURCE_LEETCODE_167_H
#define LEETCODE_SOURCE_LEETCODE_167_H

#include <algorithm>
#include <unordered_map>
#include <vector>

using std::unordered_map;
using std::vector;

class Solution167 {
public:
    vector<int> twoSum(const vector<int> &numbers, int target) {
        unordered_map<int32_t, int32_t> umap;
        for (int32_t i = 0; i < static_cast<int32_t>(numbers.size()); i++) {
            if (umap.count(target - numbers[i]) != 0) {
                return vector<int32_t>{umap[target - numbers[i]], i + 1};
            } else {
                umap[numbers[i]] = i + 1;
            }
        }
        return vector<int32_t>{-1, -1};
    }

    vector<int> twoSum2(const vector<int> &numbers, int target) {
        int32_t begin = 0;
        int32_t ends = numbers.size() - 1;
        int32_t sum = numbers[begin] + numbers[ends];
        while (begin < ends && sum != target) {
            if (sum > target) {
                ends--;
            } else if (sum < target) {
                begin++;
            }
            sum = numbers[begin] + numbers[ends];
        }
        return vector<int32_t>{begin + 1, ends + 1};
    }
};

#endif  //LEETCODE_CPP_SOURCE_LEETCODE_167_H