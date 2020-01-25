#pragma once
#ifndef _LEETCODE_26_H_
#define _LEETCODE_26_H_
#include <vector>
#include <algorithm>
using namespace std;
/*
Given a sorted array nums,
remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.
*/
class Solution26 {
public:
    int removeDuplicates(vector<int>& nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        int willreturn = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[willreturn] = nums[i];
                willreturn++;
            }
        }
        nums.resize(willreturn);
        return willreturn;
    }
    int removeDuplicates2(vector<int>& nums) {
        return distance(
            nums.begin(),
            unique(
                nums.begin(),
                nums.end()
            )
        );
    }
    void test() {
        vector<int> vec1 = { 1,2 };
        vector<int> vec2 = { 1,1,2};
        vector<int> vec3 = { 0,0,1,1,1,2,2,3,3,4 };
        cout << removeDuplicates(vec1) << endl;
        cout << removeDuplicates(vec2) << endl;
        cout << removeDuplicates(vec3) << endl;
        cout << "---------------------" << endl;
        vec1 = { 1,2 };
        vec2 = { 1,1,2 };
        vec3 = { 0,0,1,1,1,2,2,3,3,4 };
        cout << removeDuplicates2(vec1) << endl;
        cout << removeDuplicates2(vec2) << endl;
        cout << removeDuplicates2(vec3) << endl;
    }
};
/*
way one:
Runtime: 24 ms,
Memory Usage: 10.1 MB,
60%,20%.
my way:
Runtime: 16 ms,
Memory Usage: 10.1 MB,
99.31%,20%.
*/
#endif
