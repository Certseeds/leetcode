#pragma once
#ifndef _LEETCODE_1013_H_
#define _LEETCODE_1013_H_

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given an array A of integers, 
return true if and only if 
we can partition the array into three non-empty parts with equal sums.
Formally, 
we can partition the array if we can find indexes i+1 < j with 
(A[0] + A[1] + ... + A[i] ==
A[i+1] + A[i+2] + ... + A[j-1] ==
A[j] + A[j-1] + ... + A[A.length - 1])
can be improve
*/
class Solution1013 {
public:
    bool canThreePartsEqualSum(vector<int> &A) {
        int sums = std::accumulate(A.begin(), A.end(), 0);
        cout << sums << endl;
        if (sums % 3 != 0) {
            return false;
        }
        sums /= 3;
        int sum_x = sums;
        int sum_y = sums;
        int x = 0;
        int y = A.size() - 1;
        while (x < y) {
            if (sum_x != 0) {
                sum_x -= A[x];
                x++;
            }
            if (sum_y != 0) {
                sum_y -= A[y];
                y--;
            }
            if (sum_x == 0 && sum_y == 0) {
                return true;
            }
            cout << sum_x << " " << sum_y << endl;
        }
        return false;
    }

    void test() {
        vector<int> vec1 = {3, 3, 6, 5, -2, 2, 5, 1, -9, 4};
        cout << canThreePartsEqualSum(vec1) << endl;
    }
};
/*
Runtime: 20 ms, 
Memory Usage: 12.5 MB,
99.81%,90.91%.
*/
#endif
