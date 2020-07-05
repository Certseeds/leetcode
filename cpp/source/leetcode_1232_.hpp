#pragma once
#ifndef _LEETCODE_1232_H_
#define _LEETCODE_1232_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
You are given an array coordinates, coordinates[i] = [x, y],
where [x, y] represents the coordinate of a point.
Check if these points make a straight line in the XY plane.
*/
class Solution1232 {
public:
    bool checkStraightLine(vector<vector<int>> &coo) {
        if (coo.size() < 3) {
            return true;
        }
        for (int i = 2; i < coo.size(); i++) {
            if ((coo[i][0] - coo[i - 1][0]) * (coo[i - 1][1] - coo[i - 2][1])
                != (coo[i][1] - coo[i - 1][1]) * (coo[i - 1][0] - coo[i - 2][0])) {
                return false;
            }
        }
        return true;
    }

    void test() {
        vector<vector<int>> vec1 = {{1, 2},
                                    {2, 3},
                                    {3, 4},
                                    {4, 5},
                                    {5, 6}};
        vector<vector<int>> vec2 = {{1, 1},
                                    {2, 2},
                                    {3, 4},
                                    {4, 5},
                                    {5, 6},
                                    {6, 7}};
        cout << checkStraightLine(vec1) << endl;
        cout << checkStraightLine(vec2) << endl;

    }
};
/*
Runtime: 8 ms, 
Memory Usage: 10.3 MB,
93.30%,100%.
*/
#endif
