#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_26_H
#define LEETCODE_CPP_SOURCE_LEETCODE_26_H

#include <vector>
#include <algorithm>
/*
Given a sorted array nums,
remove the duplicates in-place such that each element appear only once and return the new length.

Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.
*/
namespace Solution26 {
using namespace std;

class Solution26 {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.size() <= 1) {
            return nums.size();
        }
        size_t will_return{1};
        for (size_t i = 1; i < nums.size(); i++) {
            if (nums[i] != nums[i - 1]) {
                nums[will_return] = nums[i];
                will_return++;
            }
        }
        nums.resize(will_return);
        return will_return;
    }

    int removeDuplicates2(vector<int> &nums) {
        auto result = unique(std::begin(nums), std::end(nums));
        const auto length = std::distance(std::begin(nums), result);
        nums.resize(length);
        return length;
    }
};
}
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
#endif //LEETCODE_CPP_SOURCE_LEETCODE_26_H
