#pragma once
#ifndef _LEETCODE_307_H_
#define _LEETCODE_307_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
Given an integer array nums,
find the sum of the elements between indices i and j (i �� j),
inclusive.
The update(i, val) function modifies nums by updating the element at index i to val.
*/
class Solution307 {
public:
    vector<int> sums;
    vector<int> nums;
    int num;

    void NumArray(vector<int> &nums) {
        if (nums.size() == 0) {
            this->num = 0;
            return;
        }
        this->nums = nums;
        this->num = floor(sqrt(nums.size()));
        for (int32_t i{0}; i < (nums.size()) / this->num; i++) {
            int temp = 0;
            for (int j = 0; j < this->num; j++) {
                temp += nums[i * this->num + j];
            }
            sums.push_back(temp);
        }
        int temp = 0;
        for (int i = this->num * this->num; i < nums.size(); i++) {
            temp += nums[i];
        }
        sums.push_back(temp);
    }

    void update(int i, int val) {
        if (this->num == 0) {
            return;
        }
        int diff = val - nums[i];
        sums[i / this->num] += diff;
        nums[i] = val;
    }

    int sumRange(int i, int j) {
        if (this->num == 0) {
            return 0;
        }
        int willreturn = 0;
        if (j - i + 1 < this->num) {
            for (int k = i; k <= j; k++) {
                willreturn += nums[k];
            }
            return willreturn;
        } else {
            for (int k = i; k < (i / this->num + 1) * this->num; k++) {
                cout << nums[k] << "a ";
                willreturn += nums[k];
            }
            for (int k = (i / this->num + 1); k < (j / this->num); k++) {
                cout << sums[k] << "b ";
                willreturn += sums[k];
            }
            for (int k = j; k >= (j / this->num) * this->num; k--) {
                cout << nums[k] << "c " << endl;
                willreturn += nums[k];
            }
            return willreturn;
        }
    }

    void test() {
        vector<int> vec1{1, 3, 5};
        NumArray(vec1);
        cout << sumRange(0, 2) << endl;
        update(1, 2);
        cout << sumRange(0, 2) << endl;
        vector<int> vec3{0, 9, 5, 7, 3};
        NumArray(vec3);
        cout << sumRange(4, 4) << endl;
        cout << sumRange(2, 4) << endl;
        cout << sumRange(3, 3) << endl;
        update(4, 5);
        update(1, 7);
        update(0, 8);
        cout << sumRange(1, 2) << endl; // ?
        update(1, 9);
        cout << sumRange(4, 4) << endl;
        update(3, 4);
        vector<int> vec4{7, 2, 7, 2, 0};
        NumArray(vec4);
        cout << sumRange(0, 4) << endl;
        update(4, 6);
        cout << sumRange(0, 4) << endl;
        update(0, 2);
        cout << sumRange(0, 4) << endl;
        update(0, 9);
        cout << sumRange(4, 4) << endl;
        cout << sumRange(0, 4) << endl;
        update(3, 8);
        cout << "? " << endl;

        cout << "? " << endl;

        cout << sumRange(0, 4) << endl;
        update(4, 1);
        cout << sumRange(0, 3) << endl;
        cout << sumRange(0, 4) << endl;
        update(0, 4);


    }
};
/*
Runtime: 24 ms,
Memory Usage: 16.8 MB,
79.68%,66.67%.
*/
#endif
