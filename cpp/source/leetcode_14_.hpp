/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @LastEditDate: 2020-08-01 00:00:12
 * @LastEditors: nanoseeds
 */
/*  leetcode
    Copyright (C) 2020 nanoseeds

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
#ifndef LEETCODE_SOURCE_LEETCODE_14_H
#define LEETCODE_SOURCE_LEETCODE_14_H

#include <vector>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

/*
Write a function to find the longest common prefix string amongst an array of strings.
If there is no common prefix, 
return an empty string "".
*/
class Solution14 {
public:
    string longestCommonPrefix(const vector<string> &strs) {
        if (strs.empty()) {
            return "";
        }
        auto length = std::min_element(std::begin(strs), std::end(strs),
                                       [](const string &s1, const string &s2) {
                                           return s1.size() < s2.size();
                                       })->size();
        string will_return = "";
        will_return.reserve(10000);
        for (size_t i = 0; i < length; i++) {
            char judge = strs[0][i];
            for (const auto &item : strs) {
                if (item[i] != judge) {
                    return will_return;
                }
            }
            will_return += judge;
        }
        return will_return;
    }
};
/*
Runtime: 4 ms,
Memory Usage: 9.2 MB,
96.09%,6.45%.
*/
#endif
