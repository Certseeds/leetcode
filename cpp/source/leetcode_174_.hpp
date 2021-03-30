/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-12 21:54:57
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
#ifndef LEETCODE_SOURCE_LEETCODE_174_H
#define LEETCODE_SOURCE_LEETCODE_174_H
namespace Solution174 {

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

class Solution174 {
public:
    int calculateMinimumHP(vector<vector<int>> &dp) {
        int m = dp.size();
        if (m == 0) {
            return 0;
        }
        int n = dp[0].size();
        if (n == 0) {
            return 0;
        }
        // i,j -> 到i,j点时,可以到达终点的最低血量.
        dp[m - 1][n - 1] = std::max(1 - dp[m - 1][n - 1], 1);
        for (int i = m - 2; i >= 0; i--) {
            dp[i].back() = std::max(dp[i + 1].back() - dp[i].back(), 1);
        }
        for (int i = n - 2; i >= 0; i--) {
            dp.back()[i] = std::max(dp.back()[i + 1] - dp.back()[i], 1);
        }

        for (int i = m - 2; i >= 0; i--) {
            for (int j = n - 2; j >= 0; j--) {
                dp[i][j] = std::max(std::min(dp[i + 1][j], dp[i][j + 1]) - dp[i][j], 1);
            }
        }
        return dp[0][0];
    }

};

}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_174_H