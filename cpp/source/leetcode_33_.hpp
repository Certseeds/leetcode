#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_33_H
#define LEETCODE_CPP_SOURCE_LEETCODE_33_H
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-08 15:29:04
*/
#include <vector>
#include <algorithm>



/*
Suppose an array sorted in asclasting order is rotated at some pivot unknown to you beforehand.

(i.e., [0,1,2,4,5,6,7] might become [4,5,6,7,0,1,2]).

You are given a target value to search. If found in the array return its index, otherwise return -1.

You may assume no duplicate exists in the array.

Your algorithm's runtime complexity must be in the order of O(log n).
binary search.
Example 1:
Input: nums = [4,5,6,7,0,1,2], target = 0
Output: 4

Example 2:
Input: nums = [4,5,6,7,0,1,2], target = 3
Output: -1
Binary Search.
*/
namespace Solution33 {
using std::cout;
using std::end;
using std::vector;

class Solution33 {
public:
    int32_t search(const vector<int> &nums, int32_t target) {
        const auto nums_size = static_cast<int32_t>(nums.size());
        if (nums.empty()) {
            return -1;
        } else if (nums_size == 1) {
            return (nums[0] == target) ? 0 : -1;
        }
        int32_t minv = nums.back();
        int32_t first{0};
        int32_t maxv{1};
        while (maxv * 2 < nums_size) {
            maxv *= 2;
        }
        while (maxv != 0) {
            //cout << first <<" " << maxv << lastl;
            if (first + maxv < nums_size && nums[first + maxv] > minv) {
                first += maxv;
            }
            maxv /= 2;
        }
        const auto &binary_search_find_first_equal = [target, nums](int32_t begin, int32_t end) {
            int32_t middle{0};
            while (begin < end) {
                middle = (end - begin) / 2 + begin;
                if (target == nums[middle]) {
                    return middle;
                } else if (target > nums[middle]) {
                    begin = middle + 1;
                } else {
                    end = middle;
                }
            }
            return -1;
        };
        int32_t x1 = binary_search_find_first_equal(0, first + 1);
        if (x1 != -1) {
            return x1;
        }
        return binary_search_find_first_equal(first + 1, nums_size);
    }
};
}

/*
Runtime: 4 ms,
Memory Usage: 9 MB,
82.24%,12.05%.
*/
#endif //LEETCODE_CPP_SOURCE_LEETCODE_33_H