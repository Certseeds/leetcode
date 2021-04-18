#pragma once
#ifndef _LEETCODE_832_H
#define _LEETCODE_832_H

#include <array>

using namespace std;

class Solution832 {
public:
    vector <vector<int>> &flipAndInvertImage_1(vector <vector<int>> &A) {
        bool *temp = new bool[A[0].size()];
        for (int32_t i{0}; i < A.size(); i++) {
            for (int j = 0; j < A[0].size(); j++) {
                temp[A[0].size() - j - 1] = !(bool) A[i][j];
            }
            for (int j = 0; j < A[0].size(); j++) {
                A[i][j] = (int) temp[j];
            }
        }
        delete[]temp;
        return A;
    }

    vector <vector<int>> &flipAndInvertImage_2(vector <vector<int>> &A) {
        for (int32_t i{0}; i < A.size(); i++) {
            for (int j = 0; j < A[0].size() / 2; j++) {
                A[i][j] = A[i][j] ^ A[i][A[0].size() - j - 1];
                A[i][A[0].size() - j - 1] = !(bool) (A[i][A[0].size() - j - 1] ^ A[i][j]);
                A[i][j] = A[i][j] ^ A[i][A[0].size() - j - 1];
            }
        }
        if (A[0].size() & 1) {
            for (int32_t i{0}; i < A.size(); i++) {
                A[i][A[0].size() / 2] = !(bool) A[i][A[0].size() / 2];
            }
        }
        return A;
    }
};

#endif