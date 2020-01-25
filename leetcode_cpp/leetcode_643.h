#pragma once
#ifndef _LEETCODE_643_H_
#define _LEETCODE_643_H_
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
/*
Given an array consisting of n integers, 
find the contiguous subarray of given length k 
that has the maximum average value.
And you need to output the maximum average value.
*/
class Solution643 {
public:
    double findMaxAverage(vector<int>& nums, int k) {
        if (nums.size() <= k) {
            return double(std::accumulate(nums.begin(), nums.end(), 0)) / nums.size();
        }
        vector<int> DP(nums.size() - k+1);
        DP[0] = std::accumulate(nums.begin(), nums.begin()+k,0);
        int willreturn = DP[0];
        for (int i = 1; i <= nums.size() - k; i++) {
            DP[i] = DP[i-1] - nums[i-1] + nums[k + i-1];
            willreturn = max(willreturn, DP[i]);
        }
        return willreturn / double(k);
    }
    void test() {
        vector<int> vec1 = { 1,12,-5,-6,50,3 };
        vector<int> vec2 = { -1 };
        cout << findMaxAverage(vec1, 4) << endl;
        cout << findMaxAverage(vec2, 1) << endl;
    }
};
/*
Runtime: 64 ms,
Memory Usage: 19.2 MB,
97.78%,33.33%.
*/
#endif
