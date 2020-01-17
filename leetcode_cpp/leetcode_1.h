#pragma once
#ifndef _LEETCODE_1_H
#define _LEETCODE_1_H
#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>
using namespace std;
/*
Given an array of integers, 
return indices of the two numbers such that they add up to a specific target.
You may assume that each input would have exactly one solution,
and you may not use the same element twice.
*/
class Solution1 {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int, int> umaps;
        vector<int> willreturn;
        for (int i = 0; i < nums.size(); i++) {
            if (umaps[target - nums[i]] != 0) {
                willreturn.push_back(i);
                willreturn.push_back(umaps[target - nums[i]] - 1);
                break;
            }
            umaps[nums[i]] = i + 1;
        }
        return willreturn;
    }
    void test() {
        vector<int> vec1 = { 2,7,11,15 };
        vector<int> out1 = twoSum(vec1,9);
        for (auto i : out1) {
            cout << i << endl;
        }

    }
};
/*
Runtime: 8 ms, 
Memory Usage: 10.9 MB,
92.85%,9.17%.
*/
#endif
