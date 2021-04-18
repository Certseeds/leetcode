#pragma once
#ifndef _LEETCODE_561_H
#define _LEETCODE_561_H

#include <vector>
#include <algorithm>

using namespace std;


class Solution561 {
public:
    int arrayPairSum(vector<int> &nums) {
        sort(nums.begin(), nums.end());
        int temp = 0;
        for (int32_t i{0}; i < nums.size(); i += 2) {
            temp += nums[i];
        }
        return temp;
    }
};

#endif
