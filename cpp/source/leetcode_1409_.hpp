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
/**
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-04-15 10:13:12
 * @LastEditors  : nanoseeds
 */
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_1409_H
#define LEETCODE_CPP_SOURCE_LEETCODE_1409_H

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_map>

using std::max;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_map;

class Solution1409 {
    vector<int32_t> processQueries(vector<int32_t> &queries, int32_t m) {
        vector<int32_t> will_return;
        if (queries.empty()) {
            return will_return;
        }
        unordered_map<int32_t, int32_t> num_pos;
        for (int32_t i{0}; i < m; ++i) {
            num_pos[i + 1] = i;
        }
        for (const auto &i:queries) {
            int32_t pos = num_pos[i];
            will_return.push_back(pos);
            for (auto &j:num_pos) {
                if (j.second < pos) {
                    j.second++;
                }
            }
            num_pos[i] = 0;
        }
        return will_return;
    }
};

#endif //LEETCODE_CPP_SOURCE_LEETCODE_1409_H
