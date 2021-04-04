#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_32_H
#define LEETCODE_CPP_SOURCE_LEETCODE_32_H

#include <vector>
#include <string>

using std::max;
using std::vector;
using std::string;
namespace Solution32 {
class Solution32 {
public:
    int32_t longestValidParentheses(const string &s) {
        int32_t s_size = s.size();
        if (s_size <= 1) {
            return 0;
        }
        vector<int32_t> DP(s_size, 0);
        for (int32_t i = 1; i < s_size; i++) {
            if (s[i] == ')') {
                if (s[i - 1] == '(') {
                    DP[i] = 2;
                    if (i >= 2) {
                        DP[i] += DP[i - 2];
                    }
                } else if (i - DP[i - 1] > 0 && s[i - DP[i - 1] - 1] == '(') {
                    DP[i] = DP[i - 1] + 2;
                    if (i - DP[i - 1] - 2 >= 0) {
                        DP[i] += DP[i - DP[i - 1] - 2];
                    }
                }
            }
        }
        return *std::max_element(DP.cbegin(), DP.cend());
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_32_H