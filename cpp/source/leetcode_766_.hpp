#pragma once
#ifndef _LEETCODE_766_H_
#define _LEETCODE_766_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
A matrix is Toeplitz 
if every diagonal from top-left to bottom-right has the same element.
Now given an M x N matrix, 
return True if and only if the matrix is Toeplitz.
*/
class Solution766 {
public:
    bool isToeplitzMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 1 || matrix[0].size() == 1) {
            return true;
        }
        int min_v = min(matrix.size(), matrix[0].size());
        for (int i = 1; i < matrix.size(); i++) {
            int val = i + 1;
            int num = matrix[i][0];
            for (int j = 1; j < min(matrix.size() - i, matrix[0].size()); j++) {
                if (num != matrix[val][j]) {
                    return false;
                }
                val += 1;
            }
        }
        int num = matrix[0][0];
        for (int i = 1; i < min_v; i++) {
            if (num != matrix[i][i]) {
                return false;
            }
        }
        cout << "middle" << endl;
        for (int i = 1; i < matrix[0].size(); i++) {
            num = matrix[0][i];
            int val = i + 1;
            for (int j = 1; j < min(matrix.size(), matrix[0].size() - i); j++) {
                if (num != matrix[j][val]) {
                    return false;
                }
                val += 1;
            }
        }
        return true;
    }

    void test() {
        vector<vector<int>> vec1 = {
                {1, 2, 3, 4},
                {5, 1, 2, 3},
                {9, 5, 1, 2}};
        cout << isToeplitzMatrix(vec1) << endl;
        vector<vector<int>> vec2 = {
                {11, 74, 0,  93},
                {40, 11, 74, 7}};
        cout << isToeplitzMatrix(vec2) << endl;

    }
};
/*
Runtime: 8 ms,
Memory Usage: 9.7 MB,
96.17%,71.43%.
*/
#endif
