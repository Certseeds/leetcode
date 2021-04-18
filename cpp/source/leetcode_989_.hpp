#pragma once
#ifndef _LEETCODE_989_H_
#define _LEETCODE_989_H_

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
For a non-negative integer X,
the array-form of X is an array of its digits in left to right order.
For example, if X = 1231, then the array form is [1,2,3,1].

Given the array-form A of a non-negative integer X,
return the array-form of the integer X+K.
*/
class Solution989 {
public:
    vector<int> addToArrayForm(vector<int> &A, int K) {
        int last = 0;
        for (int i = A.size() - 1; i >= 0; i--) {
            last += K % 10;
            K = K / 10;
            A[i] += last;
            last = (A[i] >= 10);
            A[i] = A[i] % 10;
            cout << A[i] << endl;
        }
        while (K > 0 || last > 0) {
            cout << K << " " << last << endl;
            last += K % 10;
            K /= 10;
            A.emplace(A.begin(), last % 10);
            last = last / 10;
        }
        return A;
    }

    vector<int> addToArrayForm2(vector<int> &A, int K) {
        unsigned long long counts = 0;
        for (int32_t i{0}; i < A.size(); i++) {
            counts *= 10;
            counts += A[i];
            cout << counts << endl;
        }
        A.clear();
        cout << counts << endl;
        counts += K;
        A.insert(A.begin(), counts % 10);
        counts /= 10;
        while (counts > 0) {
            A.insert(A.begin(), counts % 10);
            counts /= 10;
        }
        return A;
    } // can not deal with long vectors
    void test() {
        vector<int> vec1 = {1, 2, 0, 0};
        vector<int> vec2 = {2, 7, 4};
        vector<int> vec3 = {2, 1, 5};
        vector<int> vec4 = {9, 9, 9, 9, 9, 9, 9, 9, 9, 9};
        vector<int> vec5 = {0};
        vector<int> vec6 = {0};

        vector<int> out1 = addToArrayForm(vec1, 34);// 1234
        vector<int> out2 = addToArrayForm(vec2, 181);// 455
        vector<int> out3 = addToArrayForm(vec3, 806);//1021
        vector<int> out4 = addToArrayForm(vec4, 1);//10 000 000 000
        vector<int> out5 = addToArrayForm(vec5, 12300);// 12300
        vector<int> out6 = addToArrayForm(vec6, 0);// 12300

        for (auto i : out1) {
            cout << i << " ";
        }
        cout << endl;
        for (auto i : out2) {
            cout << i << " ";
        }
        cout << endl;
        for (auto i : out3) {
            cout << i << " ";
        }
        cout << endl;
        for (auto i : out4) {
            cout << i << " ";
        }
        cout << endl;
        for (auto i : out5) {
            cout << i << " ";
        }
        cout << endl;
        for (auto i : out6) {
            cout << i << " ";
        }
        cout << endl;
    }
};
/*
use insert:
Runtime: 152 ms,
Memory Usage: 12.4 MB,
11.51%,88.89%.
use emplace:
Runtime: 112 ms,
Memory Usage: 12.4 MB,
87.05%,100%.
*/
#endif
