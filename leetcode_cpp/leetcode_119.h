#pragma once
#ifndef _LEETCODE_119_H_
#define _LEETCODE_119_H_
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a non-negative index k where k ¡Ü 33, 
return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.
*/
class Solution119 {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> willreturn(rowIndex + 1, 1);
        for (int i = 1; i <= rowIndex; i++) {
            for (int j = i-1; j > 0; j--) {
                willreturn[j] += willreturn[j - 1];
            }
        }
        return willreturn;
    }
    void test() {
        vector<int> out1 = getRow(3);
        for (int i : out1) {
            cout << i << " ";
        }cout << endl;
    }
};
/*
Runtime: 8 ms,
Memory Usage: 8.4 MB,
61.00%,90.32%.
*/
#endif
