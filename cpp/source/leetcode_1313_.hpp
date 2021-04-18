#pragma once
#ifndef _LEETCODE_1313_H_
#define _LEETCODE_1313_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
We are given a list nums of integers
representing a list compressed with run-length encoding.
Consider each adjacent pair of elements
[a, b] = [nums[2*i], nums[2*i+1]] (with i >= 0).
For each such pair, there are a elements with value b in the decompressed list.
Return the decompressed list.
vector.insert()?
*/
class Solution1313 {
public:
    vector<int> decompressRLElist(vector<int> &nums) {
        vector<int> willreturn;
        for (int32_t i{0}; i < nums.size(); i += 2) {
            willreturn.insert(willreturn.end(), nums[i], nums[i + 1]);
        }
        return willreturn;
    }

    void test() {
        vector<int> vec1 = {1, 2, 3, 4};
        vector<int> out1 = decompressRLElist(vec1);
        for (auto i : out1) {
            cout << i << endl;
        }
    }
};
/*
Runtime: 44 ms,
Memory Usage: 10.7 MB,
89.16%,100%.
*/
#endif
