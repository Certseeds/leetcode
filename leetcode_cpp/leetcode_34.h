#pragma once
#ifndef _LEETCODE_34_H_
#define _LEETCODE_34_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-09 10:11:47
*/
#include <vector>
#include <algorithm>
using std::vector;
using std::lower_bound;
using std::upper_bound;
/*
Given an array of integers nums sorted in ascending order, 
find the starting and ending position of a given target value.

Your algorithm's runtime complexity must be in the order of O(log n).

If the target is not found in the array, return [-1, -1].

Example 1:
Input: nums = [5,7,7,8,8,10], target = 8
Output: [3,4]

Example 2:
Input: nums = [5,7,7,8,8,10], target = 6
Output: [-1,-1]
*/
class Solution34 {
public:
    vector<int> searchRange(const vector<int>& nums,const int& target) {
        if (nums.size() == 0) {
            return vector<int> {-1, -1};
        }
        if (binary_search_pos(nums, target, 0, nums.size()) == -1) {
            return vector<int> {-1, -1};
        }
        int minv = lower_bound(nums.begin(), nums.end(), target) - nums.begin();
        int maxv = upper_bound(nums.begin(), nums.end(), target) - nums.begin();
        return  vector<int> {minv,maxv-1};
    }
    void test() {
        vector<int> vec0 = {};
        vector<int> vec1 = { 5,7,7,8,8,10 };
        assert(searchRange(vec1, 8)[0] == 3 && searchRange(vec1, 8)[1] == 4);
        assert(searchRange(vec1, 6)[0] == -1 && searchRange(vec1, 6)[1] == -1);
        assert(searchRange(vec0, 115)[0] == -1 && searchRange(vec0, 6)[1] == -1);
    }
}; 
/*
Runtime: 4 ms,
Memory Usage: 10.6 MB,
99.43%,5.49%.
*/
#endif
