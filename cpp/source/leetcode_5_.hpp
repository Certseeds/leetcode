/*
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-27 11:59:54
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-13 22:16:15
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
#ifndef _LEETCODE_5_H_
#define _LEETCODE_5_H_

#include <vector>
#include <array>
#include <string>
#include <algorithm>

using std::string;
using std::vector;

class Solution5 {
public:
    string longestPalindrome(const string &s) {
        int32_t s_size = s.size();
        if (s_size <= 1) {
            return s;
        } else if (s.size() == 2) {
            if (s[0] != s[1]) {
                return s;
            } else {
                return s.substr(0, 1);
            }
        }
        vector<vector<uint8_t>> dp(s_size, vector<uint8_t>(s_size, false));
        std::pair<int32_t, int32_t> begin_end{0, 1};
        int32_t max_size = 1;
        for (int32_t i = 0; i < s_size - 1; i++) {
            dp[i][i] = true;
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if (dp[i][i + 1]) {
                max_size = 2;
                begin_end = {i, max_size};
            }
        }
        dp.back().back() = true;
        for (int32_t i = 0; i < s_size; i++) {
            for (int j = i + 2; j < s_size; j++) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (j - i + 1 > max_size && dp[i][j]) {
                    max_size = j - i + 1;
                    begin_end = {i, max_size};
                }
            }
        }
        return s.substr(begin_end.first, begin_end.second);
    }
};

#endif
