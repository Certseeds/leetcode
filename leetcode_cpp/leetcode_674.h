#pragma once
#ifndef _LEETCODE_674_H_
#define _LEETCODE_674_H_
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
Given an unsorted array of integers,
find the length of longest continuous increasing subsequence (subarray).
*/
class Solution674 {
public:
    int findLengthOfLCIS(vector<int>& nums) {
        int will_Return = (nums.size() >= 1);
        int maxv = 1;
        for (int i = 1; i < nums.size(); i++) {
            maxv = (nums[i] > nums[i - 1]) ? (maxv + 1) : 1;
            will_Return = max(will_Return,maxv);
        }
        return will_Return;
    }
   
    void test() {
        vector<int> vec1 = { 1,3,5,4,7 };
        vector<int> vec2 = { 2,2,2,2,2 };
        vector<int> vec3 = { 1 };
        vector<int> vec4 = { };
        cout << findLengthOfLCIS(vec1) << endl;// 3
        cout << findLengthOfLCIS(vec2) << endl;// 1
        cout << findLengthOfLCIS(vec3) << endl;// 1
        cout << findLengthOfLCIS(vec4) << endl;// 0

    }
};
/*
Runtime: 4 ms, 
Memory Usage: 9.4 MB,
99.62%,83.33%.
*/
#endif
