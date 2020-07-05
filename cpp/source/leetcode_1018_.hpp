#pragma once
#ifndef _LEETCODE_1018_H_
#define _LEETCODE_1018_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array A of 0s and 1s, consider N_i:
the i-th subarray from A[0] to A[i] interpreted as a binary number
(from most-significant-bit to least-significant-bit.)

Return a list of booleans answer, 
where answer[i] is true if and only if N_i is divisible by 5.
*/
class Solution1018 {
public:
    vector<bool> prefixesDivBy5(vector<int> &A) {
        vector<bool> willreturn(A.size());
        int num = 0;
        for (int i = 0; i < A.size(); i++) {
            num = (2 * num + A[i]) % 5;
            willreturn[i] = (num == 0);
        }
        return willreturn;
    }

    void test() {
        vector<int> vec1 = {0, 1, 1};
        vector<int> vec2 = {1, 1, 1};
        vector<int> vec3 = {0, 1, 1, 1, 1, 1};
        vector<int> vec4 = {1, 1, 1, 0, 1};
        vector<bool> out1 = prefixesDivBy5(vec1);
        vector<bool> out2 = prefixesDivBy5(vec2);
        vector<bool> out3 = prefixesDivBy5(vec3);
        vector<bool> out4 = prefixesDivBy5(vec4);
        for (auto j : out1) {
            cout << (j ? "true" : "false") << " ";
        }
        cout << endl;
        for (auto j : out2) {
            cout << (j ? "true" : "false") << " ";
        }
        cout << endl;
        for (auto j : out3) {
            cout << (j ? "true" : "false") << " ";
        }
        cout << endl;
        for (auto j : out4) {
            cout << (j ? "true" : "false") << " ";
        }
        cout << endl;
    }
};
/*
Runtime: 12 ms,
Memory Usage: 11 MB,
89.28%,28.57%.
*/
#endif
