/*
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-27 11:59:52
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-22 20:56:07
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
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_11_H
#define LEETCODE_CPP_SOURCE_LEETCODE_11_H

#include <vector>
#include <algorithm>

using std::vector;

/*
Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i 
is at (i, ai) and (i, 0). Find two lines, 
which together with x-axis forms a container, 
uch that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
class Solution11 {
public:
    int maxArea_n2(const vector<int> &height) {
        // O(n^2) unused
        int maxv = INT32_MIN;
        int h_size = height.size();
        for (int i = 0; i < h_size; i++) {
            for (int j = i + 1; j < h_size; j++) {
                maxv = std::max(maxv, std::min(height[i], height[j]) * (j - i));
            }
        }
        return maxv;
    }

    int maxArea(const vector<int> &height) {
        int begin = 0;
        int end = height.size() - 1;
        int will_return = (end - begin) * std::min(height[begin], height[end]);
        while (begin < end) {
            if (height[begin] >= height[end]) {
                end--;
            } else {
                begin++;
            }
            will_return = std::max(will_return, (end - begin) * std::min(height[begin], height[end]));
        }
        return will_return;
    }
};
/*
Brute Force:
Runtime: 1988 ms,
Memory Usage: 9.9 MB,
5%,50.00%.
two pointer:
Runtime: 4 ms,
Memory Usage: 9.8 MB,
99.99%,68.04%.
*/
#endif //LEETCODE_CPP_SOURCE_LEETCODE_11_H