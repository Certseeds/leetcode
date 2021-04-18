/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-23 23:13:38
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
#ifndef LEETCODE_SOURCE_LEETCODE_64_H
#define LEETCODE_SOURCE_LEETCODE_64_H

#include <vector>

namespace Solution64 {
using std::vector;

class Solution64 {
public:
    int minPathSum(vector<vector<int>> &grid) {
        if (grid.empty() || grid[0].empty()) {
            return 0;
        }
        int m = grid.size();
        int n = grid[0].size();
        for (int32_t i{1}; i < m; i++) {
            grid[i][0] += grid[i - 1][0];
        }
        for (int32_t i{1}; i < n; i++) {
            grid[0][i] += grid[0][i - 1];
        }
        for (int32_t i{1}; i < m; i++) {
            for (int j = 1; j < n; j++) {
                grid[i][j] += std::min(grid[i - 1][j], grid[i][j - 1]);
            }
        }
        return grid.back().back();
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_64_H