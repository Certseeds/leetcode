#pragma once
#ifndef _LEETCODE_840_H
#define _LEETCODE_840_H

#include <vector>
#include <algorithm>

using namespace std;

/*
A 3 x 3 magic square is a 3 x 3 grid filled
with distinct numbers from 1 to 9 such that each row,
column, and both diagonals all have the same sum.

Given an grid of integers,
how many 3 x 3 "magic square" subgrids are there?
(Each subgrid is contiguous).
*/
class Solution840 {
public:
    int numMagicSquaresInside(vector<vector<int>> &grid) {
        if (grid.size() < 3 || grid[0].size() < 3) {
            return 0;
        }
        int count = 0;
        for (int32_t i{0}; i <= grid.size() - 3; i++) {
            for (int j = 0; j <= grid[0].size() - 3; j++) {
                count += numMagicSquaresInside_help(grid, i, j);
            }
        }
        return count;
    }

    bool numMagicSquaresInside_help(vector<vector<int>> &grid, int x, int y) {
        for (int32_t i{0}; i < 3; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[x + i][y + j] > 9 || grid[x + i][y + j] < 1) {
                    return 0;
                }
            }
        }
        return (
                grid[x + 1][y + 1] == 5 &&
                grid[x][y] + grid[x + 2][y + 2] == 10 &&
                grid[x + 1][y] + grid[x + 1][y + 2] == 10 &&
                grid[x + 2][y] + grid[x][y + 2] == 10 &&
                grid[x][y] != grid[x + 2][y + 2] &&
                grid[x + 1][y] != grid[x + 1][y + 2] &&
                grid[x + 2][y] != grid[x][y + 2] &&
                grid[x][y] + grid[x][y + 1] + grid[x][y + 2] == 15 &&
                grid[x][y] + grid[x + 1][y] + grid[x + 2][y] == 15 &&
                grid[x + 2][y] + grid[x + 2][y + 1] + grid[x + 2][y + 2] == 15
        );
    }

    void test() {
    }
};
/*
Runtime: 8 ms,
Memory Usage: 8.6 MB,
18.06%,100%.
*/
#endif
