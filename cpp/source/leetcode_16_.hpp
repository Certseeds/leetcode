#pragma once
#ifndef _LEETCODE_16_H_
#define _LEETCODE_16_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
Given an array nums of n integers and an integer target, 
find three integers in nums such that the sum is closest to target. 
Return the sum of the three integers.
You may assume that each input would have exactly one solution.
*/
class Solution16 {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        std::sort(nums.begin(), nums.end());
        int minv = INT32_MAX;
        int will_return = 0;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                for (int k = j + 1; k < nums.size(); k++) {
                    if (minv > abs(nums[i] + nums[j] + nums[k] - target)) {
                        minv = abs(nums[i] + nums[j] + nums[k] - target);
                        will_return = nums[i] + nums[j] + nums[k];
                    }
                }
            }
        }
        return will_return;
    }

    void test() {
        vector<int> vec1 = {-4, -1, 1, 2};
        cout << threeSumClosest(vec1, 1) << endl;
    }
};
/*
Runtime: 252 ms,
Memory Usage: 8.8 MB,
5.68%,47.17%.
*/
#endif
