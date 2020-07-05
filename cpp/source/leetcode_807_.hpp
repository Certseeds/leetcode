#pragma once
#ifndef _LEETCODE_807_H_
#define _LEETCODE_807_H_

#include <vector>
#include <unordered_map>

using namespace std;

/*There are n people
whose IDs go from 0 to n - 1 and each person belongs exactly to one group.
Given the array groupSizes of length n telling the group size each person belongs to,
return the groups there are and the people's IDs each group includes.
You can return any solution in any order and the same applies for IDs.
Also, it is guaranteed that there exists at least one solution.
*/
class Solution807 {
public:
    int maxIncreaseKeepingSkyline(vector<vector<int>> &grid) {
        int willreturn = 0;
        vector<int> row;
        vector<int> line;
        for (int i = 0; i < grid.size(); i++) {
            int maxrow = INT16_MIN;
            int maxline = INT16_MIN;
            for (int j = 0; j < grid[0].size(); j++) {
                maxrow = max(maxrow, grid[i][j]);
                maxline = max(maxline, grid[j][i]);
            }
            row.push_back(maxrow);
            line.push_back(maxline);
        }
        for (int i = 0; i < grid.size(); i++) {
            for (int j = 0; j < grid[0].size(); j++) {
                willreturn += min(row[i], line[j]) - grid[i][j];
            }
        }
        return willreturn;
    }

    void test() {
        vector<vector<int>> vec1 = {
                {3, 0, 8, 4},
                {2, 4, 5, 7},
                {9, 2, 6, 3},
                {0, 3, 1, 0}
        };
        cout << maxIncreaseKeepingSkyline(vec1) << endl;
    }
};

#endif
