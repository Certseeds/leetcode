#pragma once
#ifndef _LEETCODE_11_H_
#define _LEETCODE_11_H_
#include <vector>
#include <algorithm>
using namespace std;
/*
Given n non-negative integers a1, a2, ..., an , 
where each represents a point at coordinate (i, ai). 
n vertical lines are drawn such that the two endpoints of line i 
is at (i, ai) and (i, 0). Find two lines, 
which together with x-axis forms a container, 
uch that the container contains the most water.

Note: You may not slant the container and n is at least 2.
*/
class Solution11 {
public:
    int maxArea_n2(vector<int>& height) {
        // O(n^2) unused
        int maxv = INT32_MIN;
        for (int i = 0; i < height.size(); i++) {
            for (int j = i+1; j < height.size(); j++) {
                maxv = max(maxv, min(height[i], height[j]) * (j - i));
            }
        }
        return maxv;
    }
    int maxArea(vector<int>& height) {
        int begin = 0;
        int end = height.size() - 1;
        int will_return = (end-begin)*min(height[begin], height[end]);
        while (begin < end) {
            if (height[begin] >= height[end]) {
                end--;
            }
            else {
                begin++;
            }
            will_return = max(will_return, 
                (end - begin) * min(height[begin],height[end]));
        }
        return will_return;
    }

    void test() {
        vector<int> vec1 = { 1,8,6,2,5,4,8,3,7 };
        cout << maxArea(vec1) << endl;
    }
};
/*
Brute Force:
Runtime: 1988 ms,
Memory Usage: 9.9 MB,
5%,50.00%.
two pointer:
Runtime: 4 ms,
Memory Usage: 9.8 MB,
99.99%,68.04%.
*/
#endif
