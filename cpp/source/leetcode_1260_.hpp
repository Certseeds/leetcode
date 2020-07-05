#pragma once
#ifndef _LEETCODE_1260_H_
#define _LEETCODE_1260_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
Given a 2D grid of size m x n and an integer k.
You need to shift the grid k times.
In one shift operation:
Element at grid[i][j] moves to grid[i][j + 1].
Element at grid[i][n - 1] moves to grid[i + 1][0].
Element at grid[m - 1][n - 1] moves to grid[0][0].
Return the 2D grid after applying shift operation k times.
vector's pop,pop_back and emplace()
quickly transpose matrix
*/
class Solution1260 {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>> &grid, int k) {
        grid = transfer(grid);
        for (int i = 0; i < k; i++) {
            vector<int> temp = grid.back();
            grid.pop_back();
            int temp_int = temp.back();
            temp.pop_back();
            temp.emplace(std::begin(temp), temp_int);
            grid.emplace(std::begin(grid), temp);
        }
        return transfer(grid);
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
                {1, 2,  3,  4},
                {5, 6,  7,  8},
                {9, 10, 11, 12}};
        vector<vector<int>> vec2 = shiftGrid(vec1, 1);
        for (auto i : vec2) {
            for (auto j: i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
/*
Runtime: 56 ms, 
Memory Usage: 16.3 MB, 
99.27%,100%.
If k goes bigger, it will beat more people.
*/
#endif
