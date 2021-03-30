/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-31 23:36:44
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
#ifndef LEETCODE_SOURCE_LEETCODE_343_H
#define LEETCODE_SOURCE_LEETCODE_343_H

#include <vector>
#include <cmath>

namespace Solution343 {

using std::vector;

class Solution343 {
public:
    int integerBreak(int n) {
        if (n <= 3) {
            return n - 1;
        }
        switch (n % 3) {
            case (0): {
                return std::pow(3, n / 3);
            }
            case (1): {
                return std::pow(3, n / 3 - 1) * 4;
            }
            case (2): {
                return std::pow(3, n / 3) * 2;
            }
        }
        return -1;
    }

    int integerBreak_DP(int n) {
        vector<int> DP(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                DP[i] = std::max(DP[i], std::max(j * (i - j), j * DP[i - j]));
            }
        }
        return DP[n];
    }

    int integerBreak_DP2(int n) {
        if (n <= 3) {
            return n - 1;
        }
        vector<int> DP(n + 4, 0);
        DP[1] = 1;
        DP[2] = 2;
        DP[3] = 3;
        for (int i = 4; i <= n; i++) {
            DP[i] = std::max(2 * DP[i - 2], 3 * DP[i - 3]);
        }
        return DP[n];
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_343_H