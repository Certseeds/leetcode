#pragma once
#ifndef _LEETCODE_39_H_
#define _LEETCODE_39_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-09 12:30:38
*/
#include <vector>
#include <algorithm>
#include <unordered_set>
#include "leetcode_hash.h"

using std::cout;
using std::endl;
using std::vector;
using std::lower_bound;
using std::unordered_set;
using std::int32_vector_hasher;

/*
Given a set of candidate numbers (candidates)
(without duplicates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

The same repeated number may be chosen from candidates unlimited number of times.

Note:
All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [2,3,6,7], target = 7,
A solution set is:
[
  [7],
  [2,2,3]
]

Example 2:
Input: candidates = [2,3,5], target = 8,
A solution set is:
[
  [2,2,2,2],
  [2,3,3],
  [3,5]
]
*/
class Solution39 {
public:
    vector<vector<int>> combinationSum(vector<int> &nums, int target) {
        //cout << "? " << target << endl;
        unordered_set<vector<int>, int32_vector_hasher> uset;
        vector<vector<int>> will_return;
        vector<vector<int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i]) {
                uset.insert(vector<int>{target});
            } else if (target > nums[i]) {
                temp = combinationSum(nums, target - nums[i]);
                for (auto &j : temp) {
                    auto loca = lower_bound(j.begin(), j.end(), nums[i]);
                    j.emplace(loca, nums[i]);
                    uset.insert(j);
                }
                temp.clear();
            }
        }
        for (auto i : uset) {
            will_return.push_back(i);
        }
        return will_return;
    }

    void test() {
        vector<int> vec1 = {2, 3, 6, 7};
        vector<int> vec2 = {2, 3, 5};
        vector<vector<int>> out1 = combinationSum(vec1, 7);
        vector<vector<int>> out2 = combinationSum(vec2, 8);
    }
};
/*
Runtime: 180 ms,
Memory Usage: 48.1 MB,
5.59%,5.55%.
*/
#endif
