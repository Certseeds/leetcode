#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_31_H
#define LEETCODE_CPP_SOURCE_LEETCODE_31_H
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-08 12:35:32
*/
#include <vector>
#include <string>
#include <algorithm>


/*
Implement next permutation,
which rearranges numbers into
the lexicographically next greater permutation of numbers.

If such arrangement is not possible,
it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples.
Inputs are in the left-hand column and
its corresponding outputs are in the right-hand column.
*/
namespace Solution31 {
using std::swap;
using std::vector;

class Solution31 {
public:
    void nextPermutation(vector<int32_t> &nums) {
        if (nums.size() <= 1) {
            return;
        }
        size_t j = nums.size() - 1;
        for (; j > 0; j--) {
            if (nums[j - 1] < nums[j]) {
                break;
            }
        }
        if (j == 0) {
            std::reverse(nums.begin(), nums.end());
            return;
        }
        for (size_t k = nums.size() - 1; k >= j; k--) {
            if (nums[k] > nums[j - 1]) {
                swap(nums[k], nums[j - 1]);
                break;
            }
        }
        std::reverse(nums.begin() + j, nums.end());
    }
};
}
/*
Runtime: 8 ms,
Memory Usage: 8.8 MB,
78.80%,76.46%.
*/
#endif //LEETCODE_CPP_SOURCE_LEETCODE_31_H