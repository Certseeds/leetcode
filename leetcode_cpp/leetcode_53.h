#pragma once
#ifndef _LEETCODE_53_H_
#define _LEETCODE_53_H_
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
Given a non-negative index k where k ¡Ü 33,
return the kth index row of the Pascal's triangle.

Note that the row index starts from 0.
*/
class Solution53 {
public:
    int maxSubArray(vector<int>& nums) {
        int begin = 0;
        int begin_max = INT16_MIN;
        int end = nums.size() - 1;
        int end_max = nums[0] - nums[1];
        for (int i = 1; i < nums.size()-1; i++) {
            if (nums[i] - nums[i - 1] > begin_max) {
                begin_max = nums[i] - nums[i - 1];
                begin = i;
            }
            if (nums[i] - nums[i+1] > end_max) {
                end_max = nums[i] - nums[i + 1];
                end = i;
            }
        }
        if (nums[nums.size() - 1] - nums[nums.size() - 2] > begin_max) {
            begin_max = nums[nums.size() - 1] - nums[nums.size() - 2];
            begin = nums.size() - 1;
        }
        return std::accumulate(nums.begin() + begin, nums.end() - end, 0);
    }
    void test() {
        vector<int> out1 = getRow(3);
        for (int i : out1) {
            cout << i << " ";
        }cout << endl;
    }
};
/*
Runtime: 8 ms,
Memory Usage: 8.4 MB,
61.00%,90.32%.
*/
#endif
