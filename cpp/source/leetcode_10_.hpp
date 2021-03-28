/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @LastEditDate: 2020-07-31 23:49:58
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
#ifndef LEETCODE_SOURCE_LEETCODE_10_H
#define LEETCODE_SOURCE_LEETCODE_10_H

#include <regex>
#include <string>
#include <algorithm>
/*
Given an input string (s) and a pattern (p),
implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/
namespace Solution10 {
using namespace std;

class Solution10 {
public:
    bool isMatch(const string &s, const string &p) {
        return std::regex_match(s, std::regex(p));
    }
};
}
/*
Runtime: 148 ms,
Memory Usage: 12.1 MB,
22.29%,16.95%.
*/
#endif // LEETCODE_SOURCE_LEETCODE_10_H