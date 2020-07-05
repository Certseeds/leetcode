#pragma once
#ifndef _LEETCODE_977_H
#define _LEETCODE_977_H

#include <string>
#include <vector>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution977 {
public:
    vector<int> &sortedSquares(vector<int> &A) {
        for (int i = 0; i < A.size(); i++) {
            A[i] = A[i] * A[i];
        }
        std::sort(A.begin(), A.end());
        return A;
    }

};

#endif
