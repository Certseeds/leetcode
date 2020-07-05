#pragma once
#ifndef _LEETCODE_532_H_
#define _LEETCODE_532_H_

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given an array of integers and an integer k, 
you need to find the number of unique k-diff pairs in the array. 
Here a k-diff pair is defined as an integer pair (i, j), 
where i and j are both numbers in the array and their absolute difference is k.
*/
class Solution532 {
public:
    int findPairs(vector<int> &nums, int k) {
        if (k < 0) {
            return 0;
        }
        unordered_map<int, int> umap;
        int count = 0;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }
        if (k == 0) {
            for (auto i : umap) {
                count += (umap[i.first] > 1);
            }
            return count;
        }
        for (auto i : umap) {
            count += (umap.count(i.first + k) > 0);
        }
        return count;
    }

    void test() {
        vector<int> vec1 = {3, 1, 4, 1, 5};
        vector<int> vec2 = {1, 2, 3, 4, 5};
        vector<int> vec3 = {1, 3, 1, 5, 4};
        cout << findPairs(vec1, 2) << endl;
        cout << findPairs(vec2, 1) << endl;
        cout << findPairs(vec3, 0) << endl;
    }
};
/*
Runtime: 16 ms,
Memory Usage: 11.9 MB,
99.44%,72.73%.
*/
#endif
