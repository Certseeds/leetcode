#pragma once
#ifndef _LEETCODE_27_H_
#define _LEETCODE_27_H_
#include <vector>
#include <algorithm>
#include <array>
using namespace std;
/*
Given an array nums and a value val, 
remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed.
It doesn't matter what you leave beyond the new length.
standard vector delete should use that
standard vector find.
*/
class Solution27 {
public:
    //It's more easy to understand.
    int removeElement(vector<int>& vec, int val) {
        vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
        return vec.size();
    }
    int removeElement2(vector<int>& vec, int val) {
        int begin = 0;
        int count = vec.size() - 1;
        while (begin < count) {
            if (vec[begin] == val) {
                swap(vec[begin], vec[count]);
                count--;
            }
            begin += (vec[begin] != val);
        }
        return std::find(vec.begin(),vec.end(),val)-vec.begin();
    }
    void test() {
        vector<int> vec1 = { 0, 1, 2, 2, 3, 0, 4, 2 };
        cout << removeElement2(vec1,2) << endl; // 5

        vector<int> vec2 = { 3,2,2,3};
        cout << removeElement2(vec2, 2) << endl; // 3

        vector<int> vec3 = { 1 };
        cout << removeElement2(vec3, 1) << endl; // 0

        vector<int> vec4 = {};
        cout << removeElement2(vec4, 0) << endl; // 0

        vector<int> vec5 = {3,3};
        cout << removeElement2(vec5, 3) << endl; // 0
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.7 MB,
100%,61.76%.
*/
#endif
