#pragma once
#ifndef _LEETCODE_41_H_
#define _LEETCODE_41_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:48
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-10 10:45:41
*/
#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::swap;
using std::vector;

/*
Given an unsorted integer array,
find the smallest missing positive integer.
*/
class Solution41 {
public:
    int firstMissingPositive(vector<int> &nums) {
        int maxv = nums.size();
        vector<int> num(nums.size() + 1, 0);
        for (int32_t i{0}; i < nums.size(); i++) {
            if (nums[i] > 0 && nums[i] <= maxv) {
                num[nums[i] - 1] = nums[i];
            }
        }
        for (int32_t i{0}; i < num.size(); i++) {
            if (num[i] == 0) {
                return (i + 1);
            }
        }
    }

    void test() {
        vector<int> vec1 = {7, 8, 9, 11, 12};
        vector<int> vec2 = {1, 2, 0};
        vector<int> vec3 = {1, 1};
        assert(firstMissingPositive(vec1) == 1);
        assert(firstMissingPositive(vec2) == 3);
        assert(firstMissingPositive(vec3) == 2);
    }
};
/*
Runtime: 0 ms,
Memory Usage : 8.7 MB,
100%,80.0%.
*/
#endif
