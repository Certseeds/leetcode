#pragma once
#ifndef _LEETCODE_15_H_
#define _LEETCODE_15_H_
#include <vector>
#include <unordered_set>
#include <string>
#include <algorithm>
#include "leetcode_hash.h"
using namespace std;
/*
Given an array nums of n integers,
are there elements a, b, c in nums such that a + b + c = 0? 
Find all unique triplets in the array which gives the sum of zero.

Note:The solution set must not contain duplicate triplets.
*/
class Solution15 {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>> will_return;
        if (nums.size() < 3) {
            return will_return;
        }
        std::sort(nums.begin(), nums.end(),less<int>());
        if (std::count_if(nums.begin(), nums.end(), [](int i) {return i == 0; }) >= 3) {
            will_return.push_back(vector<int>{0, 0, 0});
        }
        if (nums[0] >= 0 || nums.back() <= 0) {
            return will_return;
        }
        int order =
            distance(begin(nums),find_if(begin(nums), end(nums), [](auto x) { return x > 0; }));
        unordered_set<int> negative;
        unordered_set<int> positive;
        for (int i = 0; i<order; i++) {
            negative.insert(nums[i]);
        }
        for (int i = order; i < nums.size(); i++) {
            positive.insert(nums[i]);
        }
        unordered_set<vector<int>, int32_vector_hasher> uset;
        // two - one +
        for (int i = 0; i < order; i++) {
            for (int j = i + 1; j < order; j++) {
                if (positive.count(0 - nums[i] - nums[j]) > 0) {
                    uset.insert(
                        vector<int> {nums[i], nums[j], 0 - nums[i] - nums[j]});
                }
            }
        }
        // two + one -
        for (int i = order; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                if (negative.count(0 - nums[i] - nums[j]) > 0) {
                    uset.insert(
                        vector<int> {nums[i], nums[j], 0 - nums[i] - nums[j]});
                }
            }
        }
        for (auto i : uset) {
            will_return.push_back(i);
        }
        return will_return;
    }
    void test() {
        vector<int> nums = { -4,-1,-1,0,1,2};
        cout << distance(begin(nums), find_if(begin(nums), end(nums), [](auto x) { return x > 0; })) << endl;
        vector<vector<int>> out1 = threeSum(nums);
        for (auto i : out1) {
            for (auto j : i) {
                cout << j << " ";
            }cout << endl;
        }
    }
};
/*
Runtime: 224 ms,
Memory Usage: 34.5 MB,
16.98%,5.30%.
*/
#endif
