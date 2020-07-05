#pragma once
#ifndef _LEETCODE_40_H_
#define _LEETCODE_40_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:48
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-10 09:48:28
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
Given a collection of candidate numbers (candidates) and a target number (target), 
find all unique combinations in candidates where the candidate numbers sums to target.

Each number in candidates may only be used once in the combination.

Note:

All numbers (including target) will be positive integers.
The solution set must not contain duplicate combinations.
Example 1:
Input: candidates = [10,1,2,7,6,1,5], target = 8,
A solution set is:
[
  [1, 7],
  [1, 2, 5],
  [2, 6],
  [1, 1, 6]
]

Example 2:
Input: candidates = [2,5,2,1,2], target = 5,
A solution set is:
[
  [1,2,2],
  [5]

*/
class Solution40 {
public:
    vector<vector<int>> combinationSum2(vector<int> &nums, int target) {
        //cout << "? " << target << endl;
        unordered_set<vector<int>, int32_vector_hasher> uset;
        vector<vector<int>> will_return;
        vector<vector<int>> temp;
        for (int i = 0; i < nums.size(); i++) {
            if (target == nums[i]) {
                uset.insert(vector<int>{target});
            } else if (target > nums[i]) {
                int temp_num = nums[i];
                nums[i] = (INT32_MAX >> 2);
                temp = combinationSum2(nums, target - temp_num);
                nums[i] = temp_num;
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
        vector<int> vec1 = {10, 1, 2, 7, 6, 1, 5};
        vector<vector<int>> out1 = combinationSum2(vec1, 8);
        cout << 1 << endl;
    }
};
/*
Runtime: 196 ms,
Memory Usage: 37.4 MB,
5.30%,5.26%.
*/
#endif
