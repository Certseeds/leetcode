#pragma once
#ifndef _LEETCODE_15_H_
#define _LEETCODE_15_H_

#include <vector>
#include <unordered_map>
#include <unordered_set>
#include <algorithm>
#include "leetcode_hash.h"


/*
Given an array nums of n integers,
are there elements a, b, c in nums such that a + b + c = 0?
Find all unique triplets in the array which gives the sum of zero.

Note:The solution set must not contain duplicate triplets.
*/
namespace Solution15 {
using namespace std;

class Solution15 {
public:
    vector<vector<int32_t>> threeSum(vector<int32_t> &nums) {
        vector<vector<int32_t>> will_return;
        if (nums.size() < 3) {
            return will_return;
        }
        std::sort(nums.begin(), nums.end(), less<>());
        if (std::count_if(nums.begin(), nums.end(), [](int32_t i) { return i == 0; }) >= 3) {
            will_return.push_back(vector<int32_t>{0, 0, 0});
        }
        if (nums[0] >= 0 || nums.back() <= 0) {
            return will_return;
        }
        int32_t order =
                distance(begin(nums), find_if(begin(nums), end(nums), [](auto x) { return x > 0; }));
        unordered_set<int32_t> negative;
        unordered_set<int32_t> positive;
        for (int32_t i = 0; i < order; i++) {
            negative.insert(nums[i]);
        }
        for (size_t i = order; i < nums.size(); i++) {
            positive.insert(nums[i]);
        }
        unordered_set<vector<int32_t>, int32_vector_hasher> uset;
        // two - one +
        for (int32_t i = 0; i < order; i++) {
            for (int32_t j = i + 1; j < order; j++) {
                if (positive.count(0 - nums[i] - nums[j]) > 0) {
                    uset.insert(
                            vector<int32_t>{nums[i], nums[j], 0 - nums[i] - nums[j]});
                }
            }
        }
        // two + one -
        for (size_t i = order; i < nums.size(); i++) {
            for (size_t j = i + 1; j < nums.size(); j++) {
                if (negative.count(0 - nums[i] - nums[j]) > 0) {
                    uset.insert(
                            vector<int32_t>{nums[i], nums[j], 0 - nums[i] - nums[j]});
                }
            }
        }
        for (const auto &i : uset) {
            will_return.push_back(i);
        }
        return will_return;
    }

    vector<vector<int32_t>> threeSum2(vector<int32_t> &nums) {
        vector<vector<int32_t>> will_return{};
        if (nums.size() < 3) {
            return will_return;
        }
        int32_t zero_nums{0};
        unordered_map<int32_t, int32_t> umap;
        for (const auto &i: nums) {
            umap[i] += (umap[i] <= 1);
            zero_nums += (i == 0);
        }
        size_t count{0};
        for (const auto &key  :umap) {
            nums[count] = key.first;
            count++;
        }
        nums.resize(count);
        std::sort(std::begin(nums), std::end(nums), less<>());
        if (nums[0] > 0 || nums[count - 1] < 0) {
            return will_return;
        }
        size_t first_bigger_than_zero{0};
        for (size_t i = 0; i < count; i++) {
            if (nums[i] > 0) {
                first_bigger_than_zero = i;
                break;
            }
        }
        for (size_t begin_t{0}; begin_t < first_bigger_than_zero; begin_t++) {
            for (size_t end_t{count - 1}; end_t >= first_bigger_than_zero; end_t--) {
                auto sum2 = nums[begin_t] + nums[end_t];
                auto iter = umap.find(-sum2);
                if (
                        (iter != std::end(umap)) &&
                        ((-sum2 > nums[begin_t] && -sum2 < nums[end_t]) ||
                         (iter->second == 2 && (-sum2 == nums[begin_t] || -sum2 == nums[end_t])))
                        ) {
                    will_return.emplace_back(std::initializer_list<int32_t>{nums[begin_t], -sum2, nums[end_t]});
                }
            }
        }
        if (zero_nums >= 3) {
            will_return.push_back(vector<int32_t>{0, 0, 0});
        }
        return will_return;
    }
};
}
/*
Runtime: 224 ms,
Memory Usage: 34.5 MB,
16.98%,5.30%.
*/
#endif