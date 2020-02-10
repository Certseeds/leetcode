#pragma once
#ifndef _LEETCODE_42_H
#define _LEETCODE_42_H
#include <vector>
#include <algorithm>
using std::max;
using std::min; 
using std::cout;
using std::endl;
using std::swap;
using std::vector;
class Solution42 {
public:
    int trap(vector<int>& height) {
        int count = 0;
        int sizes = height.size();
        for (int i = 0; i < sizes - 1; i++) {
            if (height[i] == 0) {
                continue;
            }
            int right = i + 1;
            int length = 0;
            for (int j = i + 1; j < sizes - 1; j++) {
                if (height[j] >= height[i]&&height[) {
                    right = height[j];
                    length = j - 1;
                }
            }

        }
    }
    void test() {
        //vector<int> vec1 = { 0,1,0,2,1,0,1,3,2,1,2,1 };
        vector<int> vec2 = { 2,1,0,2 };
        //cout << trap(vec1) << endl;
        cout << trap(vec2) << endl;
    }
};

#endif
