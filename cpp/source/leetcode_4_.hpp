#pragma once
#ifndef _LEETCODE_4_H
#define _LEETCODE_4_H

#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

class Solution4 {
public:
    double findMedianSortedArrays(vector<int> &nums1, vector<int> &nums2) {
        int begin = 0;
        int end = nums1.size() - 1;
        int middle = 0;
        int length_sum = (nums1.size() + nums2.size()) / 2;
        while (begin < end) {
            middle = (end - begin) / 2 + begin;
            if (middle + findMedianSortedArrays_2(nums2, nums1[middle]) < length_sum) {
                begin = middle + 1;
            } else {
                end = middle;
            }
        }
        return nums1[begin];
    }

    int findMedianSortedArrays_2(vector<int> &nums2, int num) {
        int begin = 0;
        int end = nums2.size() - 1;
        int middle = 0;
        int length_sum = (nums2.size() + nums2.size()) / 2;
        while (begin < end) {
            middle = (end - begin) / 2 + begin;
            if (nums2[middle] > num) {
                end = middle;
            } else {
                begin = middle + 1;
            }
        }
        return middle;
    }

    void test() {
    }
};

#endif
