#pragma once
#ifndef _LEETCODE_941_H_
#define _LEETCODE_941_H_
#include <vector>
#include <array>
#include <algorithm>
#include <numeric>
using namespace std;
/*
Given an array A of integers, 
return true if and only if it is a valid mountain array.
A.size()>=3
*/
class Solution941 {
public:
    bool validMountainArray(vector<int>& A) {
        if (A.size() < 3) {
            return false;
        }
        int count = 0;
        for (int i = 1; i < A.size() - 1; i++) {
            if ((A[i] - A[i - 1]) == 0 || (A[i + 1] - A[i] == 0)) {
                return false;
            }
            count += ((A[i] - A[i - 1]) * (A[i + 1] - A[i]) < 0);
        }
        return count == 1 && (A[1] - A[0] > 0);
    }
    void test() {
        vector<int> vec1 = { 14, 82, 89, 84, 79, 70, 70, 68, 67, 66, 63,
            60, 58, 54, 44, 43, 32, 28, 26, 25, 22, 15,
            13, 12, 10, 8, 7, 5, 4, 3 };
        cout << validMountainArray(vec1) << endl;

    }
};
/*
Runtime: 12 ms,
Memory Usage: 10.5 MB,
99.54%,43.75%.
*/
#endif
