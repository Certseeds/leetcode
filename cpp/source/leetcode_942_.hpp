#pragma once
#ifndef _LEETCODE_942_H
#define _LEETCODE_942_H

#include <vector>

using namespace std;


class Solution942 {
public:
    vector<int> diStringMatch(const string &S) {
        int min = 0;
        int max = S.size();
        vector<int> willreturn(max + 1);
        for (int i = 0; i < S.size(); i++) {
            if (S[i] == 73) {
                willreturn[i] = min;
                min++;
            } else {
                willreturn[i] = max;
                max--;
            }
        }
        willreturn[S.size()] = min;
        return willreturn;
    }
};

#endif
