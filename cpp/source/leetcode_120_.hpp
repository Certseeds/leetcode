/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-14 21:52:58
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
#ifndef LEETCODE_SOURCE_LEETCODE_120_H
#define LEETCODE_SOURCE_LEETCODE_120_H

#include <algorithm>
#include <vector>
#include <string>
#include <iostream>

namespace Solution120 {

using std::vector;
using std::string;

class Solution120 {
public:
    int minimumTotal(vector<vector<int>> &dp) {
        int m = dp.size();
        // ensure the size is 一个首项为1，间距为1的递增数列。
        for (int32_t i{1}; i < m; i++) {
            dp[i].front() += dp[i - 1].front();
            for (int j = 1; j < i; j++) {
                dp[i][j] += std::min(dp[i - 1][j - 1], dp[i - 1][j]);
            }
            dp[i].back() += dp[i - 1].back();
        }
        return *std::min_element(dp.back().cbegin(), dp.back().cend());
    }

    string multiply_0(string num1, string num2) {
        if (num1.size() < num2.size()) {
            std::swap(num1, num2);
        }
        // make num1.size() > num2.size()
        vector<string> nums_vec(num2.size());
        for (auto i = num2.crbegin(); i != num2.crend(); i++) {
            nums_vec.push_back(multiply(num1, *i));
        }
        for (size_t j = 0; j < nums_vec.size(); ++j) {
            nums_vec[j].append('0', j);
        }
        for (size_t j = 0; j < nums_vec.size() - 1; ++j) {
            nums_vec[j + 1] = add_str(nums_vec[j], nums_vec[j + 1]);
        }
        return nums_vec.back();
    }

    string add_str(string num1, string num2) {
        if (num1.size() < num2.size()) {
            std::swap(num1, num2);
            // make num1 >= num2
        }
        string will_return{num1};
        int f_size = num1.size();
        int s_size = num2.size();
        int add_in = 0;
        for (int32_t i = 0; i < s_size; i++) {
            int32_t sum = (num1[f_size - i - 1] - '0') + (num2[s_size - i - 1] - '0') + add_in;
            will_return[f_size - i - 1] = sum % 10 + '0';
            add_in = sum / 10;
        }
        string head = "0";
        if (add_in > 0) {
            head[0] += add_in;
            will_return = head + will_return;
        }
        return will_return;
    }

    string multiply(const string &num, char ch) {
        string num1(num);
        ch -= '0';
        if (ch == 0) {
            return "0";
        } else if (ch == 1) {
            return num1;
        }
        int num_size = num1.size();
        int add_in = 0;
        for (int i = num_size - 1; i >= 0; i--) {
            int middle_number = (num1[i] - '0') * ch + add_in;
            num1[i] = middle_number % 10 + '0';
            add_in = middle_number / 10;
        }
        string head = "0";
        if (add_in > 0) {
            head[0] += add_in;
            num1 = head + num1;
        }
        return num1;
    }
};
}

#endif //LEETCODE_CPP_SOURCE_LEETCODE_120_H