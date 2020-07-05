#pragma once
#ifndef _LEETCODE_1089_H_
#define _LEETCODE_1089_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
Given a fixed length array arr of integers, 
duplicate each occurrence of zero, shifting the remaining elements to the right.

Note that elements beyond the length of the original array are not written.

Do the above modifications to the input array in place,
do not return anything from your function.
*/
class Solution1089 {
public:
    void duplicateZeros(vector<int> &arr) {
        auto finish = arr.size();
        for (auto iter = arr.begin(); iter != arr.end(); iter++) {
            if (*iter == 0) {
                iter = arr.emplace(iter, 0);
                iter++;
            }
        }
        arr.resize(finish);
    }

    void test() {
        vector<int> vec1 = {1, 0, 2, 3, 0, 4, 5, 0};
        duplicateZeros(vec1);
        for (auto i : vec1) {
            cout << i << " " << endl;
        }
    }
};
/*
Runtime: 36 ms, 
Memory Usage: 9.6 MB,
34.75%,100%.
*/
#endif
