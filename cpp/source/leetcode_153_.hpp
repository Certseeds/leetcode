/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-22 20:41:21
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
#ifndef LEETCODE_SOURCE_LEETCODE_153_H
#define LEETCODE_SOURCE_LEETCODE_153_H

#include <vector>
#include <algorithm>

using std::vector;

class Solution153 {
public:
    int findMin(const vector<int> &numbers) {
        int begin = 0;
        int end = numbers.size() - 1;
        int middle = 0;
        while (begin < end) {
            middle = (end - begin) / 2 + begin;
            if (numbers[middle] > numbers[end]) {
                begin = middle + 1;
            } else if (numbers[middle] < numbers[end]) {
                end = middle;
            } else {
                end--;
            }
        }
        return numbers[begin];
    }
};

#endif //LEETCODE_CPP_SOURCE_LEETCODE_153_H