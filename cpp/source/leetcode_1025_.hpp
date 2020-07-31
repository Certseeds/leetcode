/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-31 23:15:18
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
#ifndef LEETCODE_SOURCE_LEETCODE_1025_H
#define LEETCODE_SOURCE_LEETCODE_1025_H

#include <vector>

using std::vector;

class Solution1025 {
public:
    bool divorGame1(int N) {
        return !(N & 1);
    }

    bool divorGame1_2(const int N) {
        vector<uint8_t> DP(N + 3, false);
        DP[1] = false;
        DP[2] = true;
        for (int i = 3; i <= N; i++) {
            for (int j = 1; j < i; ++j) {
                if (i % j == 0 && DP[i - j] == 0) {
                    DP[i] = true;
                    break;
                }
            }
        }
        return DP[N];
    }
};

#endif //LEETCODE_CPP_SOURCE_LEETCODE_1025_H