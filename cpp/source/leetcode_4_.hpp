#pragma once
#ifndef _LEETCODE_4_H
#define _LEETCODE_4_H
/*
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-27 11:59:53
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-13 22:16:33
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
#include <vector>
#include <array>
#include <string>
#include <algorithm>

namespace Solution4 {

using namespace std;

class Solution4 {
public:

    double findMedianSortedArrays(const vector<int> &nums1, const vector<int> &nums2) {
        auto left = (nums1.size() + nums2.size() + 1) / 2;
        auto right = (nums1.size() + nums2.size() + 2) / 2;
        return (get_nums(nums1, 0, nums2, 0, left) * 1.0f +
                get_nums(nums1, 0, nums2, 0, right) * 1.0f) / 2;
    }

    int get_nums(const vector<int> &nums1, size_t begin1, const vector<int> &nums2, size_t begin2, int k) {
        if (begin1 >= nums1.size()) {
            return nums2[begin2 + k - 1];
        } else if (begin2 >= nums2.size()) {
            return nums1[begin1 + k - 1];
        } else if (k == 1) {
            return std::min(nums1[begin1], nums2[begin2]);
        }
        int half = k / 2;
        int newIndex1 = std::min(begin1 + half, nums1.size()) - 1;
        int newIndex2 = std::min(begin2 + half, nums2.size()) - 1;
        if (nums1[newIndex1] <= nums2[newIndex2]) {
            k -= (newIndex1 - begin1 + 1);
            begin1 = newIndex1 + 1;
        } else {
            k -= (newIndex2 - begin2 + 1);
            begin2 = newIndex2 + 1;
        }
        return get_nums(nums1, begin1, nums2, begin2, k);
    }
};
}
#endif
