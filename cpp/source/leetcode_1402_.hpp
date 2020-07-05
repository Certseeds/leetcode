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
 * @Date: 2020-06-11 14:45:46 
 * @LastEditors  : nanoseeds
 */
#ifndef LEETCODE_SOURCE_LEETCODE_1402_H
#define LEETCODE_SOURCE_LEETCODE_1402_H

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <cmath>
#include <deque>
#include <numeric>

using namespace std;

class Solution1402 {
// DP
public:

    int maxSatisfaction(vector<int> &satisfaction) {
        int32_t will_return = 0;
        std::sort(satisfaction.begin(), satisfaction.end());
        std::deque<int32_t> deq;
        deq.insert(deq.end(), satisfaction.begin(), satisfaction.end());
        int sum = std::accumulate(deq.begin(), deq.end(), 0);
        while (!deq.empty() && sum <= 0) {
            sum -= deq.front();
            deq.pop_front();
        }
        for (size_t i = 0; i < deq.size(); ++i) {
            will_return += (i + 1) * deq[i];
        }
        return will_return;
    }

    void test() {
        vector<int32_t> vec1 = {-9, -8, -1, 0, 5};
        vector<int32_t> vec2 = {-1, -4, -5};
        vector<int32_t> vec3 = {4, 3, 2};
        vector<int32_t> vec4 = {-2, 5, -1, 0, 3, -3};
        vector<int32_t> vec5 = {-3, -2, 1, 2};
        std::cout << maxSatisfaction(vec1) << "\n";
        std::cout << maxSatisfaction(vec2) << "\n";
        std::cout << maxSatisfaction(vec3) << "\n";
        std::cout << maxSatisfaction(vec4) << "\n";
        std::cout << maxSatisfaction(vec5) << "\n";
    }
};

#endif //LEETCODE_SOURCE_LEETCODE_1402_H
