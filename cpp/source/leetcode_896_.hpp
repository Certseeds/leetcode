#pragma once
#ifndef _LEETCODE_896_H_
#define _LEETCODE_896_H_

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
An array is monotonic
if it is either monotone increasing or monotone decreasing.

An array A is monotone increasing if for all i <= j,
A[i] <= A[j].  An array A is monotone decreasing if for all i <= j, A[i] >= A[j].

Return true if and only if the given array A is monotonic.
what the fuck,INT_FAST16_MIN has difference with INT16_MIN,
so do INT_FAST16_MAX.
*/
class Solution896 {
public:
    inline bool isMonotonic(vector<int> &A) {
        if (A.size() == 0 || A.size() == 1) {
            return true;
        }
        int counts;
        int maxv = INT16_MIN;
        int minv = INT16_MAX;
        for (int32_t i{1}; i < A.size(); i++) {
            counts = isMonotonic_judge(A[i] - A[i - 1]);
            maxv = max(maxv, counts);
            minv = min(minv, counts);
            //cout << maxv << " " << minv << endl;
            if (maxv == 1 && minv == -1) {
                return false;
            }
        }
        return true;
    }

    inline int isMonotonic_judge(int num) {
        if (num > 0) {
            return 1;
        } else if (num < 0) {
            return -1;
        } else {
            return 0;
        }
    }

    void test() {
        vector<int> vec1 = {11, 11, 9, 4, 3, 3, 3, 1, -1, -1, 3, 3, 3, 5, 5, 5};
        cout << isMonotonic(vec1) << endl;
        vector<int> vec2 = {6, 5, 4, 4};
        cout << isMonotonic(vec2) << endl;
        vector<int> vec3 = {1, 2, 2, 3};
        cout << isMonotonic(vec3) << endl;
    }
};
/*
Runtime: 24 ms,
Memory Usage: 14.2 MB,
99.87%,31.58%.
*/
#endif
