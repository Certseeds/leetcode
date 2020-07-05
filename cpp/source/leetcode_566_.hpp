#pragma once
#ifndef _LEETCODE_566_H_
#define _LEETCODE_566_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
In MATLAB, there is a very useful function called 'reshape', 
which can reshape a matrix into a new one with different size but keep its original data.

You're given a matrix represented by a two-dimensional array, 
and two positive integers r and c representing the row number and column number of the wanted reshaped matrix, 
respectively.

The reshaped matrix need to be filled with all the elements of 
the original matrix in the same row-traversing order as they were.

If the 'reshape' operation with given parameters is possible and legal, 
output the new reshaped matrix; Otherwise, output the original matrix.
*/
class Solution566 {
public:
    vector<vector<int>> matrixReshape(vector<vector<int>> &nums, int r, int c) {
        int out = nums.size();
        int in = nums[0].size();
        if ((r * c) != (out * in)) {
            return nums;
        }
        vector<vector<int>> willreturn(r, vector<int>(c));
        int sum = 0;
        for (int i = 0; i < r; i++) {
            for (int j = 0; j < c; j++) {
                willreturn[i][j] = nums[sum / in][sum % in];
                sum++;
            }
        }
        return willreturn;
    }

    void test() {
        vector<vector<int>> vec1 = {
                {1, 2,  3,  4},
                {5, 6,  7,  8},
                {9, 10, 11, 12}};
        vector<vector<int>> out1 = matrixReshape(vec1, 1, 12);
        for (auto i : out1) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        vector<vector<int>> vec2 = {
                {1, 2},
                {3, 4}};
        vector<vector<int>> out2 = matrixReshape(vec2, 4, 1);
        for (auto i : out2) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        vector<vector<int>> out3 = matrixReshape(vec2, 1, 4);
        for (auto i : out3) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
/*
Runtime: 32 ms,
Memory Usage: 11.7 MB,
92.5%,68.0%.
*/
#endif
