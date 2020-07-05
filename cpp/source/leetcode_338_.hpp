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
 * @Date: 2020-06-11 10:04:22 
 * @LastEditors  : nanoseeds
 */
#ifndef LEETCODE_SOURCE_LEETCODE_338_H
#define LEETCODE_SOURCE_LEETCODE_338_H

#include <iostream>
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution338 {

public:
    vector<int> countBits(const int &num) {
        int range_max = get_range(num + 1);
        vector<int32_t> will_return = {0, 1};
        will_return.reserve(pow(2, range_max));
        for (int i = 1; i < range_max; ++i) {
            vector<int32_t> temp(will_return);
            for (auto &j:temp) {
                j++;
            }
            will_return.insert(will_return.begin(), temp.begin(), temp.end());
        }
        will_return.resize(num + 1);
        return will_return;
    }

    vector<int> countBits2(const int &num) {
        vector<int32_t> will_return(num + 1, 0);
        will_return[0] = 0;
        will_return[1] = 1;
        for (int i = 2; i < num + 1; ++i) {
            will_return[i] = will_return[i / 2] + i % 2;
        }
        return will_return;
    }

    int get_range(const int &x) {
        for (int i = 0; i < x; ++i) {
            if (std::pow(2, i) >= x) {
                return i;
            }
        }
        return -1;
    }

    void test() {
        std::cout << get_range(63) << std::endl;
        std::cout << get_range(64) << std::endl;
        std::cout << get_range(32) << std::endl;
        std::cout << get_range(31) << std::endl;
        std::cout << get_range(33) << std::endl;
        vector<int32_t> temp = countBits(2);
    }
};

#endif //LEETCODE_SOURCE_LEETCODE_338_H
