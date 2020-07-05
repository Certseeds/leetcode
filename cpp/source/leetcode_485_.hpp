#pragma once
#ifndef _LEETCODE_485_H_
#define _LEETCODE_485_H_

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given a binary array, 
find the maximum number of consecutive 1s in this array.
*/
class Solution485 {
public:
    int findMaxConsecutiveOnes(vector<int> &nums) {
        int val = 0;
        int willreturn = INT16_MIN;
        for (auto i : nums) {
            if (i) {
                val++;
            } else {
                willreturn = max(val, willreturn);
                //if (willreturn > nums.size() / 2) {
                //	return willreturn;
                //}
                val = 0;
            }
        }
        return max(val, willreturn);;
    }

    void test() {
        vector<int> vec1 = {1, 0, 1, 1, 0, 1};
        cout << findMaxConsecutiveOnes(vec1) << endl;// 2
        vector<int> vec2 = {1, 1, 0, 1, 1, 1};
        cout << findMaxConsecutiveOnes(vec2) << endl;// 3
        vector<int> vec3 = {1};
        cout << findMaxConsecutiveOnes(vec3) << endl;// 1
    }
};
/*
Runtime: 16ms, 
Memory Usage: 11.7 MB,
99.87%,60.34%.
*/
#endif
