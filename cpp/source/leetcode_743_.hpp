/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-11 22:51:17
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
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_743_H
#define LEETCODE_CPP_SOURCE_LEETCODE_743_H

#include <algorithm>
#include <array>
#include <queue>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

namespace Solution743 {
using std::array;
using std::queue;
using std::sort;
using std::stack;
using std::string;
using std::vector;
using std::unordered_map;
using std::unordered_set;
using std::priority_queue;

class Solution743 {
public:
    int networkDelayTime(const vector<vector<int>> &times, int n, int k) {
        struct time_ {
            int32_t end, cost;

            time_(int32_t end, int32_t cost) : end(end), cost(cost) {}
        };
        k -= 1;
        vector<vector<time_>> dis(n, vector<time_>{});
        vector<int32_t> results(n, 0x3f3f3f3f);
        for (const auto &time: times) {
            const auto &first = time[0];
            const auto &second = time[1];
            const auto &third = time[2];
            dis[first - 1].emplace_back(second - 1, third);
        }
        const auto cmp = [](const time_ &v1, const time_ &v2) {
            return v1.cost > v2.cost;
        };
        priority_queue<time_, vector<time_>, decltype(cmp)> priorityQueue{cmp};
        results[k] = 0;
        priorityQueue.push(time_(k, -1));

        while (!priorityQueue.empty()) {
            auto head = priorityQueue.top();
            priorityQueue.pop();
            for (auto &i: dis[head.end]) {
                const auto val = results[head.end] + i.cost;
                if (results[i.end] >= val) {
                    results[i.end] = val;
                    priorityQueue.push(i);
                }
            }
        }
        int32_t will_return = *std::max_element(std::cbegin(results), std::cend(results));
        return will_return == 0x3f3f3f3f ? -1 : will_return;
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_743_H