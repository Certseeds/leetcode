#pragma once
#ifndef _LEETCODE_724_H_
#define _LEETCODE_724_H_
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
/*
Given an array of integers nums, 
write a method that returns the "pivot" index of this array.

We define the pivot index as the index 
where the sum of the numbers to the left of the index is equal to 
the sum of the numbers to the right of the index.

If no such index exists, we should return -1. 
If there are multiple pivot indexes, 
you should return the left-most pivot index.
*/
class Solution724 {
public:
    int pivotIndex(vector<int>& nums) {
        int sums = std::accumulate(
            std::begin(nums),
            std::end(nums),
            0
        );
        int sum = 0;
        for (int i = 0; i < nums.size(); i++) {
            sums -= nums[i];
            if (sum == sums) {
                return i;
            }
            sum += nums[i];
        }
        return -1;
    }
    void test() {
        vector<int> vec1 = { 1,7,3,6,5,6};
        vector<int> vec2 = { 1,2,3 };
        cout << pivotIndex(vec1) << endl;
        cout << pivotIndex(vec2) << endl;
    }
};
/*
Runtime: 20 ms,
Memory Usage: 9.8 MB,
97.49%,95.24%.
*/
#endif
