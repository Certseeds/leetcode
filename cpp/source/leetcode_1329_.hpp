#pragma once
#ifndef _LEETCODE_1329_H_
#define _LEETCODE_1329_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-25 22:06:19
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-13 17:54:41
*/
#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::cout;
using std::endl;
using std::less;
using std::vector;

/*
Given a m * n matrix mat of integers, 
sort it diagonally in ascending order from the top-left 
to the bottom-right then return the sorted array.

Example :
Input: mat = [
[3,3,1,1],
[2,2,1,2],
[1,1,1,2]]
Output: [
[1,1,1,1],
[1,2,2,2],
[1,2,3,3]]

Constraints:
m == mat.length
n == mat[i].length
1 <= m, n <= 100
1 <= mat[i][j] <= 100
*/
class Solution1329 {
public:
    vector<vector<int>> diagonalSort(vector<vector<int>> &mat) {
        if (mat.size() == 0 || mat[0].size() == 0) {
            return mat;
        }
        int min_size = min(mat.size(), mat[0].size());
        int max_size = max(mat.size(), mat[0].size());
        int out_size = mat.size();
        int in_size = mat[0].size();
        int length = 0;
        vector<int> nums;
        nums.reserve(min_size);
        for (int i = 0; i < mat.size(); i++) {
            length = min(min_size, out_size - i);
            for (int j = 0; j < length; j++) {
                nums.push_back(mat[i + j][j]);
            }
            sort(nums.begin(), nums.end(), less<int>());
            for (int j = 0; j < length; j++) {
                mat[i + j][j] = nums[j];
            }
            nums.clear();
        }
        for (int i = 1; i < mat[0].size(); i++) {
            length = min(min_size, in_size - i);
            for (int j = 0; j < length; j++) {
                nums.push_back(mat[j][i + j]);
            }
            sort(nums.begin(), nums.end(), less<int>());
            for (int j = 0; j < length; j++) {
                mat[j][i + j] = nums[j];
            }
            nums.clear();
        }
        return mat;
    }

    void test() {
        vector<vector<int>> input1 = {
                {3, 3, 1, 1},
                {2, 2, 1, 2},
                {1, 1, 1, 2}};
        vector<vector<int>> _out1 = {
                {1, 1, 1, 1},
                {1, 2, 2, 2},
                {1, 2, 3, 3}};
        vector<vector<int>> out1 = diagonalSort(input1);
        for (int i = 0; i < out1.size(); i++) {
            for (int j = 0; j < out1[0].size(); j++) {
                assert(out1[i][j] == _out1[i][j]);
            }
        }

    }
};
/*
Runtime: 20 ms,
Memory Usage: 10.8 MB,
100%,100%.
*/
#endif
