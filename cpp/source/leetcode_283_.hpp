#pragma once
#ifndef _LEETCODE_283_H_
#define _LEETCODE_283_H_

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given an array nums,
write a function to move all 0's to the end of it
while maintaining the relative order of the non-zero elements.
the fastest way is the slow and fast ptr.
*/
class Solution283 {
public:
    void moveZeroes(vector<int> &nums) {
        if (nums.size() < 2) {
            return;
        }
        int count = 0;
        for (auto iter = nums.begin(); iter != nums.end();) {
            cout << *iter << endl;
            if (*iter == 0) {
                iter = nums.erase(iter);
                count++;
            } else {
                iter++;
            }
        }
        for (int32_t i{0}; i < count; i++) {
            nums.push_back(0);
        }
    }

    void moveZeroes2(vector<int> &nums) {
        if (nums.size() < 2) {
            return;
        }
        vector<int> willreturn(nums.size());
        int count = 0;
        for (auto iter = nums.begin(); iter != nums.end(); iter++) {
            if (*iter != 0) {
                willreturn[count] = *iter;
                count++;
            }
        }
        nums = willreturn;
    }

    void test() {
        vector<int> vec1 = {0, 1, 0, 3, 12};
        moveZeroes2(vec1);
        for (auto i : vec1) {
            cout << i << " ";
        }
        cout << endl;
        vector<int> vec2 = {0};
        moveZeroes2(vec2);
        for (auto i : vec2) {
            cout << i << " ";
        }
        cout << endl;
        vector<int> vec3 = {1, 0};
        moveZeroes2(vec3);
        for (auto i : vec3) {
            cout << i << " ";
        }
        cout << endl;
    }
};
/*
way 1:
Runtime: 16 ms,
Memory Usage: 9.6 MB,
63.06%,45.83%.
way 2:
Runtime: 12 ms,
Memory Usage: 9.8 MB,
97.11%,5.55%.
*/
#endif
