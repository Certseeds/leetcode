#pragma once
#ifndef _LEETCODE_888_H_
#define _LEETCODE_888_H_

#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

/*
Alice and Bob have candy bars of different sizes: 
A[i] is the size of the i-th bar of candy that Alice has, 
and B[j] is the size of the j-th bar of candy that Bob has.

Since they are friends, 
they would like to exchange one candy bar each so that after the exchange, 
they both have the same total amount of candy.  
(The total amount of candy a person has is the sum of the sizes of candy bars they have.)

Return an integer array ans where ans[0] 
is the size of the candy bar that Alice must exchange,
and ans[1] is the size of the candy bar that Bob must exchange.

If there are multiple answers, you may return any one of them.  
It is guaranteed an answer exists.
std::accumulate();quickest get sum;
set.
*/
class Solution888 {
public:
    vector<int> fairCandySwap(vector<int> &A, vector<int> &B) {
        int sum1 = std::accumulate(A.begin(), A.end(), 0);
        int sum2 = std::accumulate(B.begin(), B.end(), 0);
        int diff = (sum1 - sum2);
        vector<int> willreturn(2);
        if (diff % 2 == 1) {
            return willreturn;
        }
        diff /= 2;
        set<int> s2;
        for (auto i : B) {
            s2.insert(i);
        }
        for (int i = 0; i < A.size(); i++) {
            if (s2.count(A[i] - diff) == 1) {
                willreturn[0] = A[i];
                willreturn[1] = A[i] - diff;
                return willreturn;
            }
        }
        return willreturn;
    }

    void test() {
        vector<int> vec1 = {1, 1};
        vector<int> vec2 = {2, 2};
        vector<int> out1 = fairCandySwap(vec1, vec2);
        for (auto i : out1) {
            cout << i << " ";
        }
        cout << endl;
        vector<int> vec3 = {1, 2};
        vector<int> vec4 = {2, 3};
        vector<int> out2 = fairCandySwap(vec3, vec4);
        for (auto i : out2) {
            cout << i << " ";
        }
        cout << endl;
        vector<int> vec5 = {2};
        vector<int> vec6 = {1, 3};
        vector<int> out3 = fairCandySwap(vec5, vec6);
        for (auto i : out3) {
            cout << i << " ";
        }
        cout << endl;
        vector<int> vec7 = {1, 2, 5};
        vector<int> vec8 = {2, 4};
        vector<int> out4 = fairCandySwap(vec7, vec8);
        for (auto i : out4) {
            cout << i << " ";
        }
        cout << endl;
    }
};
/*
Runtime: 72 ms, 
Memory Usage: 23.5 MB,
99.28%,10%.
*/
#endif
