#pragma once
#ifndef _LEETCODE_1304_H
#define _LEETCODE_1304_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution1304 {
public:
    vector<int> sumZero(int n) {
        vector<int> willreturn;
        for (int i = 1; i <= (n) >> 1; i++) {
            willreturn.push_back(i);
            willreturn.push_back(-1 * i);
        }
        if (n & 1) {
            willreturn.push_back(0);
        }
        return willreturn;
    }

};

#endif
