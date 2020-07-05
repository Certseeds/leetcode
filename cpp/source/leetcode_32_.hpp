#pragma once
#ifndef _LEETCODE_32_H_
#define _LEETCODE_32_H_

#include <stack>
#include <vector>
#include <string>
#include <algorithm>

using std::max;
using std::swap;
using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::string;
using std::reverse;

class Solution32 {
public:
    int longestValidParentheses(const string &s) {
        int32_t s_size = s.size();
        if (s_size <= 1) {
            return 0;
        }
        // size = 6, DP(7).
        vector<int32_t> DP(s_size);
        for (int32_t i = 1; i < s_size; i++) {
            if (s[i - 1] == '(' && s[i] == ')') {
                DP[i] = 2;
                if (i >= 2) {
                    DP[i] += DP[i - 2];
                }
            } else if (s[i] == ')') {
                if (i - DP[i - 1] > 0 && s[i - DP[i - 1] - 1] == '(') {
                    DP[i] = DP[i - 1] + 2;
                    if (i - DP[i - 1] - 2 >= 0) {
                        DP[i] += DP[i - DP[i - 1] - 2];
                    }
                }
            }
        }
        return *std::max_element(DP.cbegin(), DP.cend());
    }

    void test() {
        cout << longestValidParentheses("") << endl;
        cout << longestValidParentheses("(()") << endl;
        cout << longestValidParentheses("())") << endl;
        cout << longestValidParentheses(")()())") << endl;
        cout << longestValidParentheses("()(())") << endl;
        cout << longestValidParentheses("()(()") << endl;
        cout << longestValidParentheses("(()())") << endl;


    }
};

#endif
