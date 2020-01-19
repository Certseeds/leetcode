#pragma once
#ifndef _LEETCODE_697_H
#define _LEETCODE_697_H
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
Given a non-empty array of non-negative integers nums, 
the degree of this array is defined 
as the maximum frequency of any one of its elements.

Your task is to find the smallest possible length 
of a (contiguous) subarray of nums, that has the same degree as nums.
*/
class Solution697 {
public:
    int findShortestSubArray(vector<int>& nums) {
        if (nums.size() == 1) {
            return 1;
        }
        unordered_map<int, int > times, begin;
        int max = INT16_MIN;
        int willreturn = 0;
        for (int i = 0; i < nums.size(); i++){
            if (times[nums[i]] == 0) {
                times[nums[i]] = 1;
                begin[nums[i]] = i;
            }else{
                times[nums[i]]++;
                if (times[nums[i]] >max) {
                    max = times[nums[i]];
                    willreturn = i - begin[nums[i]];
                }
                else if (times[nums[i]] == max) {
                    willreturn = min(willreturn, i - begin[nums[i]]);

                }
            }
        }
        return willreturn+1;
    }
    void test() {
        vector<int> vec1 = { 1, 2, 2, 3, 1 };
        vector<int> vec2 = { 1,2,2,3,1,4,2 };
        vector<int> vec3 = { 2,1 };
        cout << findShortestSubArray(vec1) << endl;
        cout << findShortestSubArray(vec2) << endl;
        cout << findShortestSubArray(vec3) << endl;
    }
};
/*
Runtime: 32 ms, 
Memory Usage: 13.2 MB,
96.34%,100%.
*/
#endif
