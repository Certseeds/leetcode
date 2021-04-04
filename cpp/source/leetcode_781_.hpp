/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-04 09:40:11
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
#ifndef LEETCODE_SOURCE_LEETCODE_781_H
#define LEETCODE_SOURCE_LEETCODE_781_H

#include <unordered_map>
#include <vector>

namespace Solution781 {
using std::vector;
using std::unordered_map;

class Solution781 {
public:
    int32_t numRabbits(const vector<int32_t> &answers) {
        unordered_map<int32_t, int32_t> umap;
        for (const auto &num: answers) {
            umap[num]++;
        }
        int32_t will_return{0};
        for (const auto &k_v:umap) {
            const auto &key1 = k_v.first + 1;
            const auto &value = k_v.second;
            will_return += key1 * (value / key1 + static_cast<int32_t>(value % key1 != 0));
        }
        return will_return;
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_781_H