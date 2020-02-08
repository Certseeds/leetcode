#pragma once
#ifndef _LEETCODE_33_H_
#define _LEETCODE_33_H_ 
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
using std::cout;
using std::endl;
using std::vector;
/*
Suppose an array sorted in ascending order is rotated at some pivot unknown to you beforehand.

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
class Solution33 {
public:
    int search(vector<int>& nums, int target) {
        if (nums.size() == 0) {
            return -1;
        }
        else if (nums.size() == 1) {
            return (nums[0] == target) ? 0 : -1;
        }
        int minv = nums.back();
        int begin = 0;
        int maxv = 1;
        while (maxv*2 < nums.size()) {
            maxv *= 2;
        }
        while (true) {
            //cout << begin <<" " << maxv << endl;
            if (begin+maxv < nums.size() && nums[begin + maxv] > minv) {
                begin += maxv;
            }
            maxv /= 2;
            if (maxv == 0) {
                break;
            }
        }
        //cout << begin << endl;
        int x1 = binary_search_pos(nums, target, 0, begin + 1);
        //cout << x1 << endl;
        if (x1 != -1) {
            return x1;
        }
        return binary_search_pos(nums, target, begin + 1, nums.size());
    }
    void test() {
        vector<int>vec1 = { 4, 5, 6, 7, 8, 0, 1, 2 };
        vector<int>vec2 = { 4, 5, 6, 7, 8, 9, 0, 1, 2 };
        vector<int>vec3 = { 4, 5, 6, 7, 8, 9, 10, 0, 1, 2 };
        vector<int>vec4 = { 4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2 };
        vector<int>vec5 = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2 };
        vector<int>vec6 = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, 1, 2 };
        vector<int>vec7 = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 1, 2 };
        vector<int>vec8 = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2 };
        vector<int>vec9 = { 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0, 1, 2 };
        //cout << binary_search_pos(vec1, 8, 0, 4) << endl;
        vector<int>vec10 = { 
            49, 64, 66, 67, 68, 69, 71, 74, 76, 78, 83, 86, 91, 93, 94, 96, 97, 106, 113, 11,
            6, 118, 119, 120, 121, 122, 123, 125, 126, 129, 131, 132, 141, 142, 144, 146, 14,
            7, 156, 157, 167, 170, 171, 172, 178, 183, 185, 188, 191, 192, 196, 209, 210, 211,
            213, 221, 226, 228, 230, 233, 235, 236, 237, 242, 243, 246, 247, 250, 251, 252,
            256, 261, 266, 267, 272, 275, 286, 289, 291, 296, 299,
            0, 7, 8, 9, 14, 16, 21, 35, 37, 41, 44, 45, 47, 48};
        assert(search(vec1, 8) == 4);
        assert(search(vec2, 9) == 5);
        assert(search(vec3, 3) == -1);
        assert(search(vec4, 2) == 10);
        assert(search(vec5, 7) == 3);
        assert(search(vec6, 24) == -1);
        assert(search(vec7, 13) == 9);
        assert(search(vec8, 1) == 13);
        assert(search(vec9, 0) == 13);
        assert(search(vec10, 35) == 88);
        assert(binary_search_pos(vec1, 0, 0, 5) == -1);
        assert(binary_search_pos(vec2, 4, 0, 5) == 0);
        assert(binary_search_pos(vec3, 5, 0, 5) == 1);
        assert(binary_search_pos(vec4, 6, 0, 5) == 2);
        assert(binary_search_pos(vec5, 7, 0, 5) == 3);
        assert(binary_search_pos(vec6, 8, 0, 5) == 4);
    }
};
/*
Runtime: 4 ms,
Memory Usage: 9 MB,
82.24%,12.05%.
*/
#endif
