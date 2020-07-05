#pragma once
#ifndef _LEETCODE_44_H
#define _LEETCODE_44_H

#include <vector>
#include <string>
#include <algorithm>

using std::vector;
using std::string;
const string end = "\n";

class Solution44 {
public:
    bool isMatch(const string &s, const string &p) {
        int32_t s_size = s.size();
        int32_t p_size = p.size();
        vector<vector<uint8_t>> DP(s_size + 1, vector<uint8_t>(p_size + 1, false));
        DP[0][0] = true;
        for (int i = 1; i <= p_size; i++) {
            DP[0][i] = (p[i - 1] == '*') && DP[0][i - 1];
        }
        for (int32_t i = 1; i <= s_size; i++) {
            for (int32_t j = 1; j <= p_size; j++) {
                switch (p[j - 1]) {
                    case '?': {
                        DP[i][j] = DP[i - 1][j - 1];
                        break;
                    }
                    case '*': {
                        DP[i][j] = DP[i][j - 1] || DP[i - 1][j];
                        break;
                    }
                    default: {
                        DP[i][j] = DP[i - 1][j - 1] && (s[i - 1] == p[j - 1]);
                        break;
                    }
                }
            }
        }
        return DP.back().back();
    }

    void test() {

    }
};

#endif
