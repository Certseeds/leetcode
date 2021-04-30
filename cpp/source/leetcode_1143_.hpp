/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-03 10:07:21
 * @LastEditors: nanoseeds
 */
/*  leetcode
    Copyright (C) 2020-2021 nanoseeds

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
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_1143_H
#define LEETCODE_CPP_SOURCE_LEETCODE_1143_H

#include <string>
#include <vector>

namespace Solution1143 {
using std::string;
using std::vector;

class Solution1143 {
public:
    int32_t longestCommonSubsequence(const string &text1, const string &text2) {
        vector<vector<int32_t>> dp(text1.size() + 1, vector<int32_t>(text2.size() + 1, 0));
        // init vector for 0 can except init [0][...],[...][0] to 0
        for (size_t i{1}; i <= text1.size(); i++) {
            for (size_t j{1}; j <= text2.size(); j++) {
                if (text1[i - 1] == text2[j - 1]) {
                    dp[i][j] = dp[i - 1][j - 1] + 1;
                } else {
                    dp[i][j] = std::max(dp[i][j - 1], dp[i - 1][j]);
                }
            }
            //std::cout << std::endl;
        }
        return dp.back().back();
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_1143_H