#pragma once
#ifndef _LEETCODE_219_H
#define _LEETCODE_219_H

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
Given an array of integers and an integer k,
find out whether there are two distinct indices i and j
in the array such that nums[i] = nums[j] and
the absolute difference between i and j is at most k.
*/
class Solution219 {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> umap;
        for (int32_t i{0}; i < nums.size(); i++) {
            if (umap[nums[i]] != 0 && (i - umap[nums[i]]) < k) {
                return true;
            }
            umap[nums[i]] = i + 1;
        }
        return false;
    }

    void test() {
        vector<int> vec1 = {1, 2, 3, 1};
        vector<int> vec2 = {1, 0, 1, 1};
        vector<int> vec3 = {1, 2, 3, 1, 2, 3};
        vector<int> vec4 = {99, 99};
        cout << containsNearbyDuplicate(vec1, 3) << endl;//1
        cout << containsNearbyDuplicate(vec2, 1) << endl;//1
        cout << containsNearbyDuplicate(vec3, 2) << endl;//0
        cout << containsNearbyDuplicate(vec4, 2) << endl;//1
    }
};
/*
Runtime: 12 ms,
Memory Usage: 15.4 MB,
99.67%,70.59%.
*/
#endif
