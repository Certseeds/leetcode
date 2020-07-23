/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-23 23:26:46
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
#ifndef LEETCODE_SOURCE_LEETCODE_17_H
#define LEETCODE_SOURCE_LEETCODE_17_H

#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;

/*
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.
*/
class Solution17 {
public:
    vector<string> letterCombinations(const string &digits) {
        if (digits.empty()) {
            return vector<string>{};
        }
        const vector<vector<char>> chars{
                {},
                {'a', 'b', 'c'},
                {'d', 'e', 'f'},
                {'g', 'h', 'i'},
                {'j', 'k', 'l'},
                {'m', 'n', 'o'},
                {'p', 'q', 'r', 's'},
                {'t', 'u', 'v'},
                {'w', 'x', 'y', 'z'}
        };
        vector<string> will_return = {""};
        for (const char &digit : digits) {
            vector<string> temp;
            for (const string &temp_str : will_return) {
                for (const char &k : chars[digit - '1']) {
                    temp.push_back(temp_str + k);
                }
            }
            will_return = temp;
        }
        return will_return;
    }
};
/*
Runtime: 0 ms,
Memory Usage: 9.8 MB,
100%,5.71%.
*/
#endif //LEETCODE_CPP_SOURCE_LEETCODE_17_H