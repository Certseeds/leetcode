#pragma once
#ifndef _LEETCODE_5_H_
#define _LEETCODE_5_H_

#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

class Solution5 {
public:
    string longestPalindrome(const string &s) {
        int32_t s_size = s.size();
        if (s_size <= 1) {
            return s;
        } else if (s.size() == 2) {
            if (s[0] != s[1]) {
                return s;
            } else {
                return s.substr(0, 1);
            }
        }
        vector<vector<uint8_t>> dp(s_size, vector<uint8_t>(s_size, false));
        std::pair<int32_t, int32_t> begin_end{0, 1};
        int32_t max_size = 1;
        for (int32_t i = 0; i < s_size - 1; i++) {
            dp[i][i] = true;
            dp[i][i + 1] = (s[i] == s[i + 1]);
            if (dp[i][i + 1]) {
                max_size = 2;
                begin_end = {i, max_size};
            }
        }
        dp.back().back() = true;
        for (int32_t i = 0; i < s_size; i++) {
            for (int j = i + 2; j < s_size; j++) {
                dp[i][j] = s[i] == s[j] && dp[i + 1][j - 1];
                if (j - i + 1 > max_size && dp[i][j]) {
                    max_size = j - i + 1;
                    begin_end = {i, max_size};
                }
            }
        }
        return s.substr(begin_end.first, begin_end.second);
    }
};

#endif
