#pragma once
#ifndef _LEETCODE_1128_H_
#define _LEETCODE_1128_H_
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
/*
Given a list of dominoes,
dominoes[i] = [a, b] is equivalent to dominoes[j] = [c, d] 
if and only if either (a==c and b==d), or (a==d and b==c) - that is, 
one domino can be rotated to be equal to another domino.

Return the number of pairs (i, j) for which 0 <= i < j < dominoes.length,
and dominoes[i] is equivalent to dominoes[j].
*/
class Solution1128 {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        const int MAX_VALUE = 9;
        array<int, MAX_VALUE * (1 << 4 + 1) + 1> arr = { 0 };
        int maxv = 0;
        int minv = 0;
        for (int i = 0; i < dominoes.size(); i++) {
            maxv = max(dominoes[i][0], dominoes[i][1]);
            minv = min(dominoes[i][0], dominoes[i][1]);
            arr[(maxv << 4) + minv]++;
        }
        maxv = 0;
        for (auto i : arr) {
            maxv += i * (i - 1) / 2;
        }
        return maxv;
    }
    void test() {
        vector<vector<int>> vec1 = {
        {1,2},
        {2,1},
        {3,4},
        {5,6} };
        cout << numEquivDominoPairs(vec1) << endl; // 1

        vector<vector<int>> vec2 =
        { {2, 1},{5, 4},{3, 7},{6, 2},{4, 4},{1, 8},
       {9, 6},{5, 3},{7, 4},{1, 9},{1, 1},{6, 6},
       {9, 6}, {1, 3}, {9, 7}, {4, 7},  {5, 1}, {6, 5},
       {1, 6}, {6, 1}, {1, 8}, {7, 2}, {2, 4}, {1, 6},
       {3, 1}, {3, 9}, {3, 7}, {9, 1}, {1, 9}, {8, 9} };
        cout << numEquivDominoPairs(vec2) << endl; // 11
    }
};
/*
Runtime: 28 ms,
Memory Usage: 21.3 MB,
99.67%,100%.
*/
#endif
