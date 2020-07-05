#pragma once
#ifndef _LEETCODE_69_H
#define _LEETCODE_69_H

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
the same with leetcode 989,
it is just change the number to 1.
*/
class Solution69 {
public:
    vector<int> plusOne(vector<int> &A) {
        int last = 0;
        int K = 1;
        for (int i = A.size() - 1; i >= 0; i--) {
            last += K % 10;
            K = K / 10;
            A[i] += last;
            last = (A[i] >= 10);
            A[i] = A[i] % 10;
        }
        while (K > 0 || last > 0) {
            last += K % 10;
            K /= 10;
            A.emplace(A.begin(), last % 10);
            last = last / 10;
        }
        return A;
    }

    void test() {
    }
};
/*
Runtime: 16 ms,
Memory Usage: 8.6 MB,
6.49%,77.05%.
*/
#endif
