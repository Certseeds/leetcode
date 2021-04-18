#pragma once
#ifndef _LEETCODE_665_H_
#define _LEETCODE_665_H_

#include <vector>
#include <array>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Given an array with n integers,
your task is to check if it could become non-decreasing
by modifying at most 1 element.

We define an array is non-decreasing if array[i] <= array[i + 1]
holds for every i (1 <= i < n).
*/
class Solution665 {
public:
    bool checkPossibility(vector<int> &nums) {
        int count = 0;
        int position = 0;
        for (int32_t i{0}; i < nums.size() - 1; i++) {
            if (nums[i] - nums[i + 1] > 0) {
                count++;
                position = i;
            }
        }
        if (count > 1) {
            return false;
        }
        if (position == 0 || position == nums.size() - 1) {
            return true;
        } else {
            bool first = true;
            bool second = true;
            if (nums[position - 1] > nums[position + 1]) {
                first = false;
            }
            for (int i = position + 1; i < nums.size() - 1; i++) {
                if (nums[i] > nums[i + 1]) {
                    first = false;
                }
            }
            if (position < nums.size() - 2) {
                if (nums[position] > nums[position + 2]) {
                    second = false;
                }
                for (int i = position + 1; i < nums.size() - 1; i++) {
                    if (nums[i] > nums[i + 1]) {
                        second = false;
                    }
                }
            }

            return first || second;
        }
    }

    void test() {
        vector<int> vec1 = {3, 4, 2, 3};
        cout << checkPossibility(vec1) << endl;

        vector<int> vec2 = {4, 2, 3};
        cout << checkPossibility(vec2) << endl;

        vector<int> vec3 = {2, 3, 3, 2, 4};
        cout << checkPossibility(vec3) << endl;

        vector<int> vec4 = {4, 2, 1};
        cout << checkPossibility(vec4) << endl;

        vector<int> vec5 = {1, 5, 4, 6, 7, 8, 9};
        cout << checkPossibility(vec5) << endl;


        vector<int> vec6 = {1, 3, 2};
        cout << checkPossibility(vec6) << endl;
    }
};
/*
Runtime: 16 ms,
Memory Usage: 10.5 MB,
97.60%,45.00%.
*/
#endif
