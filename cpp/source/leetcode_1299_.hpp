#pragma once
#ifndef _LEETCODE_1299_H
#define _LEETCODE_1299_H

#include <vector>
#include <algorithm>

using namespace std;

class Solution1299 {
public:
    vector<int> replaceElements(vector<int> &arr) {
        int max_value = -1;
        int temp = 0;
        for (int i = arr.size() - 1; i >= 0; i--) {
            temp = arr[i];
            arr[i] = max_value;
            max_value = max(max_value, temp);
        }
        return arr;
    }

    void test() {
        vector<int> array_in_1 = {17, 18, 5, 4, 6, 1};
        vector<int> array_out_2 = {18, 6, 6, 6, 1, -1};
        vector<int> array_out = replaceElements(array_in_1);
        for (int32_t i{0}; i < array_out.size(); i++) {
            cout << array_out[i] << " " << array_out_2[i] << endl;
            assert(array_out[i] == array_out_2[i]);
        }
    }
};

#endif
