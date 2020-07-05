#pragma once
#ifndef _LEETCODE_304_H_
#define _LEETCODE_304_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
Given a 2D matrix matrix, 
ind the sum of the elements inside the rectangle 
defined by its upper left corner (row1, col1) and 
lower right corner (row2, col2).
*/
class Solution304 {
public:
    vector<vector<int>> sumRange;

    void NumMatrix(vector<vector<int>> &matrix) {
        if (matrix.size() == 0 || matrix[0].size() == 0) {
            return;
        }
        vector<vector<int>> sumRange(matrix.size() + 1, vector<int>(matrix[0].size() + 1));
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                sumRange[i + 1][j + 1] = sumRange[i][j + 1] + sumRange[i + 1][j]
                                         - sumRange[i][j] + matrix[i][j];
            }
        }
        this->sumRange = sumRange;
        return;
    }

    int sumRegion(int row1, int col1, int row2, int col2) {
        return this->sumRange[row2 + 1][col2 + 1] - this->sumRange[row1][col2 + 1] -
               this->sumRange[row2 + 1][col1] + this->sumRange[row1][col1];
    }

    void test() {
        vector<vector<int>> matrix1 = {
                {3, 0, 1, 4, 2},
                {5, 6, 3, 2, 1},
                {1, 2, 0, 1, 5},
                {4, 1, 0, 1, 7},
                {1, 0, 3, 0, 5}
        };
        NumMatrix(matrix1);
        cout << sumRegion(2, 1, 4, 3) << endl;
        cout << sumRegion(1, 1, 2, 2) << endl;
        cout << sumRegion(1, 2, 2, 4) << endl;
        vector<vector<int>> matrix2 = {{}};
        NumMatrix(matrix2);

    }
};
/*
Runtime: 24 ms, 
Memory Usage: 16.8 MB,
79.68%,66.67%.
*/
#endif
