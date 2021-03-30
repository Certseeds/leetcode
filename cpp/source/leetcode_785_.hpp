/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-20 23:59:37
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
#ifndef LEETCODE_SOURCE_LEETCODE_785_H
#define LEETCODE_SOURCE_LEETCODE_785_H

#include <algorithm>
#include <array>
#include <queue>
#include <stack>
#include <string>
#include <vector>
namespace Solution785 {

using std::array;
using std::queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
enum class Color {
    uncolor = -1,
    red = 0,
    black = 1
};

class Solution785 {
public:
    bool isBipartite(const vector<vector<int32_t>> &graph) {
        int32_t node_number = graph.size();
        vector<Color> color_vec(node_number, Color::uncolor);
        for (int32_t i = 0; i < node_number; i++) {
            if (!graph[i].empty() && color_vec[i] == Color::uncolor) {
                color_vec[i] = Color::red;
                queue<int32_t> que;
                que.push(i);
                while (!que.empty()) {
                    int32_t head = que.front();
                    que.pop();
                    Color next_color = (color_vec[head] == Color::red) ? Color::black : Color::red;
                    for (const auto &j: graph[head]) {
                        if (color_vec[j] == Color::uncolor) {
                            color_vec[j] = next_color;
                            que.push(j);
                        } else if (color_vec[j] == color_vec[head]) {
                            return false;
                        }
                    }
                }
            }
        }
        return true;
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_785_H