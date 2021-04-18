#pragma once
#ifndef _LEETCODE_448_H_
#define _LEETCODE_448_H_

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given an array of integers where 1 �� a[i] �� n (n = size of array),
some elements appear twice and others appear once.

Find all the elements of [1, n] inclusive that do not appear in this array.

Could you do it without extra space and in O(n) runtime?
You may assume the returned list does not count as extra space.
*/
class Solution448 {
public:
    vector<int> findDisappearedNumbers(vector<int> &nums) {
        vector<int> res;
        int len = nums.size();
        for (int32_t i{0}; i < len; i++) {
            int m = abs(nums[i]) - 1; // index start from 0
            nums[m] = nums[m] > 0 ? -nums[m] : nums[m];
        }
        for (int32_t i{0}; i < len; i++) {
            if (nums[i] > 0) {
                res.push_back(i + 1);
            }
        }
        return res;
    }

    void test() {
        vector<int> vec1 = {4, 3, 2, 7, 8, 2, 3, 1};
        vector<int> out1 = findDisappearedNumbers(vec1);
        for (auto i : out1) {
            cout << i << " ";
        }
        cout << endl;
    }
};
/*
Runtime: 72 ms,
Memory Usage: 15 MB,
99.63%,66.67%.
*/
#endif
