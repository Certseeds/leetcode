#pragma once
#ifndef _LEETCODE_1330_H_
#define _LEETCODE_1330_H_

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given a m * n matrix mat of integers, 
sort it diagonally in ascending order 
from the top-left to the bottom-right then return the sorted array.
*/
class Solution1330 {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        vector<vector<int>> temp = transfer(mat);
        for (auto &i : temp) {
            std::sort(i.begin(), i.end(), less<int>());
        }
        std::sort(temp.begin(), temp.end(), less<vector<int>>());
        return transfer(temp);
    }

    vector<vector<int>> transfer(vector<vector<int>> &begin) {
        int R, C;
        if (!(R = begin.size()) || !(C = begin[0].size())) {
            return vector<vector<int>>();
        }
        vector<vector<int>> ans(C, vector<int>(R));
        for (int i = 0; i < C; ++i) {
            for (int j = 0; j < R; ++j) {
                ans[i][j] = begin[j][i];
            }
        }
        return ans;
    }

    void test() {
        vector<vector<int>> vec1 = {
                {3, 3, 1, 1},
                {2, 2, 1, 2},
                {1, 1, 1, 2}};
        vector<vector<int>> out1 = diagonalSort(vec1);
        for (auto i : vec1) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
/*

*/
#endif
