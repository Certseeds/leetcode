#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_88_H
#define LEETCODE_CPP_SOURCE_LEETCODE_88_H

#include <vector>
#include <algorithm>


/*
Given two sorted integer arrays nums1 and nums2,
merge nums2 into nums1 as one sorted array.
*/
namespace Solution88 {
using namespace std;

class Solution88 {
public:
    void merge(vector<int32_t> &nums1, int32_t m, const vector<int32_t> &nums2, int32_t n) {
        int32_t begin_x{m - 1}, begin_y{n - 1}, count{m + n - 1};
        while (count >= 0) {
            if (begin_x < 0) {
                nums1[count] = nums2[begin_y];
                begin_y--;
                count--;
            } else if (begin_y < 0 || nums1[begin_x] > nums2[begin_y]) {
                nums1[count] = nums1[begin_x];
                begin_x--;
                count--;
            } else {
                nums1[count] = nums2[begin_y];
                begin_y--;
                count--;
            }
        }
    }
};
}
/*
Runtime: 0 ms,
Memory Usage: 8.9 MB,
100%,21.74%.
*/
#endif //LEETCODE_CPP_SOURCE_LEETCODE_88_H