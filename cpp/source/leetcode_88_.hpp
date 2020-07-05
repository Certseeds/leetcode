#pragma once
#ifndef _LEETCODE_88_H
#define _LEETCODE_88_H

#include <vector>
#include <algorithm>

using namespace std;

/*
Given two sorted integer arrays nums1 and nums2, 
merge nums2 into nums1 as one sorted array.
*/
class Solution88 {
public:
    void merge(vector<int> &nums1, int m, vector<int> &nums2, int n) {
        vector<int> willreturn;
        int begin_x = 0;
        int begin_y = 0;
        while (begin_x < m && begin_y < n) {
            if (nums1[begin_x] < nums2[begin_y]) {
                willreturn.push_back(nums1[begin_x]);
                begin_x++;
            } else {
                willreturn.push_back(nums2[begin_y]);
                begin_y++;
            }
        }
        for (int i = begin_x; i < m; i++) {
            willreturn.push_back(nums1[i]);
        }
        for (int i = begin_y; i < n; i++) {
            willreturn.push_back(nums2[i]);
        }
        nums1 = willreturn;
        return;
    }

    void test() {
        vector<int> vec1 = {1, 2, 3, 0, 0, 0};
        vector<int> vec2 = {2, 5, 6};
        merge(vec1, 3, vec2, 3);
        for (auto i : vec1) {
            cout << i << " ";
        }
        cout << endl;
        vector<int> vec3 = {2, 0};
        vector<int> vec4 = {1};
        merge(vec3, 1, vec4, 1);
        for (auto i : vec3) {
            cout << i << " ";
        }
        cout << endl;
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.9 MB,
100%,21.74%.
*/
#endif
