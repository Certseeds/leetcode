#pragma once
#ifndef _LEETCODE_581_H_
#define _LEETCODE_581_H_

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given an integer array,
you need to find one continuous subarray that if you only
sort this subarray in ascending order,
then the whole array will be sorted in ascending order, too.

You need to find the shortest such subarray and output its length.
*/
class Solution581 {
public:
    int findUnsortedSubarray(vector<int> &nums) {
        vector<int> nums2(nums);
        sort(nums2.begin(), nums2.end());
        int left = 0;
        int right = nums.size();
        for (int32_t i{0}; i < nums2.size(); i++) {
            if (nums2[i] == nums[i]) {
                left++;
            } else {
                break;
            }
        }
        for (int i = nums2.size() - 1; i >= 0; i--) {
            if (nums2[i] == nums[i]) {
                right--;
            } else {
                break;
            }
        }
        return max(0, right - left);
    }

    void test() {
        vector<int> vec1 = {2, 6, 4, 8, 10, 9, 15};
        vector<int> vec2 = {1, 2, 3, 4};
        vector<int> vec3 = {1};
        cout << findUnsortedSubarray(vec1) << endl;
        cout << findUnsortedSubarray(vec2) << endl;
        cout << findUnsortedSubarray(vec3) << endl;
    }
};
/*
Runtime: 24 ms,
Memory Usage: 11.4 MB,
98.61%,38.10%.
*/
#endif
