#pragma once
#ifndef _LEETCODE_1351_H_
#define _LEETCODE_1351_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-16 10:30:33
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-16 10:53:22
*/
#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

/*
Given a m * n matrix grid which is sorted in
non-increasing order both row-wise and column-wise.
Return the number of negative numbers in grid.

Example 1:
Input: grid = [[4,3,2,-1],[3,2,1,-1],[1,1,-1,-2],[-1,-1,-2,-3]]
Output: 8
Explanation: There are 8 negatives number in the matrix.

Example 2:
Input: grid = [[3,2],[1,0]]
Output: 0

Example 3:
Input: grid = [[1,-1],[-1,-1]]
Output: 3

Example 4:
Input: grid = [[-1]]
Output: 1

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 100
-100 <= grid[i][j] <= 100
*/
class Solution1351 {
public:
    int countNegatives(const vector<vector<int>> &grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return 0;
        }
        int begin_1 = 0;
        int end_1 = grid.size();
        int middle_1 = 0;
        while (begin_1 < end_1) {
            middle_1 = (end_1 - begin_1) / 2 + begin_1;
            if (grid[middle_1][0] >= 0) {
                begin_1 = middle_1 + 1;
            } else {
                end_1 = middle_1;
            }
        }
        int begin_2 = 0;
        int end_2 = grid[0].size();
        int middle_2 = 0;
        int will_return = (grid.size() - begin_1) * grid[0].size();
        //cout << " middle count is " << will_return << endl;
        for (int32_t i{0}; i < begin_1; i++) {
            while (begin_2 < end_2) {
                middle_2 = (end_2 - begin_2) / 2 + begin_2;
                if (grid[i][middle_2] >= 0) {
                    begin_2 = middle_2 + 1;
                } else {
                    end_2 = middle_2;
                }
            }
            //cout << begin_2 << " " << (grid[0].size() - begin_2) << endl;
            will_return += (grid[0].size() - begin_2);
            begin_2 = 0;
            middle_2 = begin_2;
        }
        return will_return;
    }

    void test() {
        vector<vector<int>> vec1 = {
                {4,  3,  2,  -1},
                {3,  2,  1,  -1},
                {1,  1,  -1, -2},
                {-1, -1, -2, -3}};
        vector<vector<int>> vec2 = {{3, 2},
                                    {1, 0}};
        vector<vector<int>> vec3 = {{1,  -1},
                                    {-1, -1}};
        vector<vector<int>> vec4 = {{-1}};
        cout << "basic test" << endl;
        assert(8 == countNegatives(vec1));
        cout << "non-negetive test" << endl;
        assert(0 == countNegatives(vec2));
        cout << "normal test" << endl;
        assert(3 == countNegatives(vec3));
        cout << "just one element test" << endl;
        assert(1 == countNegatives(vec4));

    }
};
/*
Runtime: 8 ms,
Memory Usage: 10.3 MB,
100%,100%.
*/
#endif
