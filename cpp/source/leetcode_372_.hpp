/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-03 00:17:41
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
#ifndef LEETCODE_SOURCE_LEETCODE_372_H
#define LEETCODE_SOURCE_LEETCODE_372_H

#include <algorithm>
#include <array>
#include <vector>

namespace Solution372 {
using std::array;
using std::vector;

class Solution372 {
public:
    static constexpr const int32_t divided{1337};
    std::array<int32_t, 10> nums{0,};

    int32_t superPow(int32_t a, const vector<int32_t> &b) {
        assert(1 <= a && a <= std::numeric_limits<int32_t>::max());
        nums = power10(a);
        return superPower(a, b, b.size());
    }

    int32_t superPower(int32_t a, const vector<int32_t> &b, size_t length) {
        assert(0 < length && length <= 2000);
        assert(0 <= b[length - 1] && b[length - 1] <= 9);
        int32_t will_return{nums[b[length - 1]]};
        if (length == 1) {
            return will_return;
        }
        auto next = superPower(a, b, length - 1);
        const auto next2{(next * next) % divided};
        next = (next2 * next2) % divided;
        next = (next * next) % divided;
        return (will_return * ((next * next2) % divided)) % divided;
    }

    static std::array<int32_t, 10> power10(int32_t a) {
        std::array<int32_t, 10> power10{1, a % divided,};
        for (size_t i = 2; i < 10; i++) {
            power10[i] = (power10[i - 1] * power10[1]) % divided;
        }
        return power10;
    }

};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_372_H