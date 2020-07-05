#pragma once
#ifndef _LEETCODE_986_H_
#define _LEETCODE_986_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-13 09:13:16
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-13 10:02:36
*/
#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::cout;
using std::endl;
using std::vector;

/*
Given two lists of closed intervals
each list of intervals is pairwise disjoint and in sorted order.

Return the intersection of these two interval lists.

(Formally, a closed interval [a, b] (with a <= b) 
denotes the set of real numbers x with a <= x <= b.  
The intersection of two closed intervals is a set of 
real numbers that is either empty, 
or can be represented as a closed interval.  
For example, the intersection of [1, 3] and [2, 4] is [2, 3].)
*/
class Solution986 {
public:
    vector<vector<int>> intervalIntersection(
            const vector<vector<int>> &A, const vector<vector<int>> &B) {
        int x = 0;
        int y = 0;
        int judge = 0;
        vector<vector<int>> will_return;
        while (x < A.size() && y < B.size()) {
            if (A[x][1] < B[y][0]) {
                x++;
                continue;
            } else if (A[x][0] > B[y][1]) {
                y++;
                continue;
            }
            vector<int> temp = intervalIntersection_helper(A[x], B[y]);
            if (!temp.empty()) {
                will_return.push_back(temp);
            }
            judge = ((temp[1] >= A[x][1]) == 1 ? 1 : 0);
            x += judge;
            y += (1 - judge);
        }
        return will_return;
    }

    vector<int> intervalIntersection_helper(
            const vector<int> &A, const vector<int> &B) {
        if (A[1] - A[0] < B[1] - B[0]) {
            return intervalIntersection_helper(B, A);
        } else {
            return vector<int>{
                    max(A[0], B[0]), min(A[1], B[1])};
        }
    }

    void test() {
        vector<vector<int>> vec1 = {{0,  2},
                                    {5,  10},
                                    {13, 23},
                                    {24, 25}};
        vector<vector<int>> vec2 = {{1,  5},
                                    {8,  12},
                                    {15, 24},
                                    {25, 26}};
        vector<vector<int>> _out1 = {{1,  2},
                                     {5,  5},
                                     {8,  10},
                                     {15, 23},
                                     {24, 24},
                                     {25, 25}};
        vector<vector<int>> out1 = intervalIntersection(vec1, vec2);
        for (int i = 0; i < _out1.size(); i++) {
            assert(out1[i][0] == _out1[i][0]);
            assert(out1[i][1] == _out1[i][1]);
        }
        vector<int> vec3 = {0, 2};
        vector<int> vec4 = {1, 5};
        vector<int> test = intervalIntersection_helper(vec3, vec4);
    }
};
/*
Runtime: 40 ms,
Memory Usage: 25.8 MB,
99.14%,8.00%.
*/
#endif
