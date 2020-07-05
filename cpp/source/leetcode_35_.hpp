#pragma once
#ifndef _LEETCODE_35_H_
#define _LEETCODE_35_H_

#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

/*
Given a sorted array and a target value,
return the index if the target is found.
If not,
return the index where it would be if it were inserted in order.
*/
class Solution35 {
public:
    int searchInsert(vector<int> &nums, int target) {
        auto diff = std::lower_bound(nums.begin(), nums.end(), target);
        return distance(nums.begin(), diff);
    }

    void test() {
        vector<int> vec1 = {1, 3, 5, 6};
        cout << searchInsert(vec1, 5) << endl;
        cout << searchInsert(vec1, 2) << endl;
        cout << searchInsert(vec1, 7) << endl;
        cout << searchInsert(vec1, 0) << endl;
    }
};
/*
Runtime: 8 ms,
Memory Usage: 8.8 MB,
59.37%,100%.
*/
#endif
