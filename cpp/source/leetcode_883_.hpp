#pragma once
#ifndef _LEETCODE_883_H
#define _LEETCODE_883_H

#include <vector>

using namespace std;


class Solution883 {
public:
    int projectionArea(vector<vector<int>> &grid) {
        int willreturn = 0;
        for (int32_t i{0}; i < grid.size(); i++) {
            int max1 = 0;
            int max2 = 0;
            for (int j = 0; j < grid.size(); j++) {
                if (grid[i][j]) {
                    willreturn++;
                }
                max1 = max1 > grid[j][i] ? max1 : grid[j][i];
                max2 = max2 > grid[i][j] ? max2 : grid[i][j];
            }
            willreturn += max1 + max2;
        }
        return (willreturn);
    }
};

#endif
