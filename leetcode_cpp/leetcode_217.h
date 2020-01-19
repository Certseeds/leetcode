#pragma once
#ifndef _LEETCODE_217_H_
#define _LEETCODE_217_H
#include <vector>
#include < unordered_set>
#include <algorithm>
#include <numeric>
using namespace std;
/*
Given an array of integers, 
find if the array contains any duplicates.

Your function should return true if any value appears at least twice in the array, 
and it should return false if every element is distinct.
hashtable is O(n) but the constant is too big,
(bigger than log(n) now ) 
*/
class Solution217 {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> judges;
        for (int i = 0; i < nums.size(); i++) {
            if (judges.count(nums[i])) {
                return true;
            }
            else {
                judges.insert(nums[i]);
            }
        }
        return false;
    }
    void test() {
        vector<int> vec1 = { 1,2,3,1 };
        vector<int> vec2 = { 1,2,3,4 };
        vector<int> vec3 = { 1,1,1,3,3,4,3,2,4,2 };
        cout << containsDuplicate(vec1) << endl;
        cout << containsDuplicate(vec2) << endl;
        cout << containsDuplicate(vec3) << endl;
    }
};
/*
Runtime: 20 ms, 
Memory Usage: 16.5 MB,
99.48%,77.63%.
*/
#endif
