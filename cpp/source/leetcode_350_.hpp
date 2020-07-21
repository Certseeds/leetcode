/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-13 21:43:38
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
#ifndef LEETCODE_SOURCE_LEETCODE_350_H
#define LEETCODE_SOURCE_LEETCODE_350_H

#include <algorithm>
#include <array>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using std::array;
using std::queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;

class Solution350 {
public:
    vector<int> intersect(vector<int> &nums1, vector<int> &nums2) {
        if (nums1.size() >= nums2.size()) {
            std::swap(nums1, nums2);
        }
        // nums1.size() < nums2.size()
        unordered_map<int32_t, int32_t> umap1;
        for (const auto &i:nums1) {
            umap1[i]++;
        }
        vector<int32_t> will_return;
        will_return.reserve(nums2.size());
        for (const auto &i:nums2) {
            if (umap1[i] > 0) {
                umap1[i]--;
                will_return.push_back(i);
            }
        }
        return will_return;
    }
};

#endif //LEETCODE_CPP_SOURCE_LEETCODE_350_H