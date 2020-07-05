#pragma once
#ifndef _LEETCODE_169_H_
#define _LEETCODE_169_H_

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given an array of size n, 
find the majority element. 
The majority element is the element that appears more than ⌊ n/2 ⌋ times.

You may assume that the array is non-empty 
and the majority element always exist in the array.
*/
class Solution169 {
public:
    int majorityElement(vector<int> &nums) {
        if (nums.size() == 1) {
            return nums[0];
        }
        unordered_map<int, int> umaps;
        int val = INT16_MIN;
        int count = 0;
        for (auto i : nums) {
            umaps[i]++;
            if (umaps[i] > count) {
                count = umaps[i];
                val = i;
            }
        }
        return val;
    }

    int majorityElement2(vector<int> &nums) {
        if (nums.empty()) {
            return -1;
        } else if (nums.size() == 1) {
            return nums[0];
        }
        int val = INT16_MIN;
        int count = 0;
        for (auto i : nums) {
            if (count > 0) {
                if (val == i) {
                    count++;
                } else {
                    count--;
                }
            } else {
                count = 1;
                val = i;
            }
        }
        return val;
    }

    void test() {
        vector<int> vec1 = {1, 0, 1, 1, 0, 1};
        cout << majorityElement(vec1) << endl;
        cout << majorityElement2(vec1) << endl;
        vector<int> vec2 = {1};
        cout << majorityElement(vec2) << endl;
        cout << majorityElement2(vec2) << endl;

    }
};
/*
my way
Runtime: 16 ms, 
Memory Usage: 11.2 MB,
96.41%,9.09%.
fastest way:
Runtime: 8 ms, 
Memory Usage: 11.3 MB,
99.85%,6.06%.
*/
#endif
