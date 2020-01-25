#pragma once
#ifndef _LEETCODE_747_H_
#define _LEETCODE_747_H_
#include <vector>
#include <numeric>
#include <algorithm>
using namespace std;
/*
In a given integer array nums,
there is always exactly one largest element.

Find whether the largest element in the array 
is at least twice as much as every other number in the array.

If it is, return the index of the largest element,
otherwise return -1.
*/
class Solution747 {
public:
    int dominantIndex(vector<int>& nums) {
        auto max = std::max_element(nums.begin(), nums.end());
        int willreturn = distance(nums.begin(),max);
        for (int i = 0; i < willreturn; i++) {
            if (nums[i] * 2 > *max) {
                return -1;
            }
        }
        for (int i = willreturn+1; i < nums.size(); i++) {
            if (nums[i] * 2 > * max) {
                return -1;
            }
        }
        return willreturn;
    }
    void test() {
        vector<int> vec1 = { 3,6,1,0 };
        vector<int> vec2 = { 1,2,3,4 };
        vector<int> vec3 = { 0,0,0,1 };
        cout << dominantIndex(vec1) << endl;
        cout << dominantIndex(vec2) << endl;
        cout << dominantIndex(vec3) << endl;
    }
};
/*
Runtime: 4 ms,
Memory Usage: 8.5 MB,
67.29%,50.00%.
*/
#endif
