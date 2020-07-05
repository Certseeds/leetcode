#pragma once
#ifndef _LEETCODE_31_H_
#define _LEETCODE_31_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-08 12:35:32
*/
#include <vector>
#include <string>
#include <algorithm>

using std::swap;
using std::cout;
using std::endl;
using std::vector;
using std::reverse;

/*
Implement next permutation, 
which rearranges numbers into 
the lexicographically next greater permutation of numbers.

If such arrangement is not possible, 
it must rearrange it as the lowest possible order (ie, sorted in ascending order).

The replacement must be in-place and use only constant extra memory.

Here are some examples.
Inputs are in the left-hand column and 
its corresponding outputs are in the right-hand column.
*/
class Solution31 {
public:
    void nextPermutation(vector<int> &nums) {
        if (nums.size() <= 1) {
            return;
        }
        int j = nums.size() - 1;
        for (; j > 0; j--) {
            if (nums[j - 1] < nums[j]) {
                break;
            }
        }
        if (j == 0) {
            reverse(nums.begin(), nums.end());
            return;
        }
        for (int k = nums.size() - 1; k >= j; k--) {
            ////cout << k << " " << (j - 1) << endl;
            if (nums[k] > nums[j - 1]) {
                swap(nums[k], nums[j - 1]);
                break;
            }
        }
        reverse(nums.begin() + j, nums.end());

        //cout << j << endl;
        return;
    }

    void test() {
        vector<int> vec1 = {1, 2, 3};
        vector<int> vec2 = {3, 2, 1};
        vector<int> vec3 = {1, 1, 5};
        vector<int> vec4 = {1, 2, 1, 5, 4, 3, 3, 2, 1};
        vector<int> vec5 = {1, 1};
        vector<int> vec6 = {1};
        vector<int> _vec1 = {1, 3, 2};
        vector<int> _vec2 = {1, 2, 3};
        vector<int> _vec3 = {1, 5, 1};
        vector<int> _vec4 = {1, 2, 2, 1, 1, 3, 3, 4, 5};
        vector<int> _vec5 = {1, 1};
        vector<int> _vec6 = {1};
        cout << "basic test " << endl;
        _test(vec1, _vec1);
        cout << "test reverse " << endl;
        _test(vec2, _vec2);
        cout << "basic test 2 " << endl;
        _test(vec3, _vec3);
        cout << "complext test 1 " << endl;
        _test(vec4, _vec4);
        cout << "test same elemtes " << endl;
        _test(vec5, _vec5);
        cout << "test just one element " << endl;
        _test(vec6, _vec6);
    }

    void _test(vector<int> &vec1, const vector<int> &vec2) {
        nextPermutation(vec1);
        for (int i = 0; i < vec1.size(); i++) {
            assert(vec1[i] == vec2[i]);
        }
    }
};
/*
Runtime: 8 ms,
Memory Usage: 8.8 MB,
78.80%,76.46%.
*/
#endif
