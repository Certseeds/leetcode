#pragma once
#ifndef _LEETCODE_344_H
#define _LEETCODE_344_H

#include <string>
#include <vector>
#include <algorithm>

using namespace std;


class Solution344 {
public:
    void reverseString(vector<char> &s) {
        char temp;
        for (int32_t i{0}; i < s.size() / 2; i++) {
            swap(s[i], s[s.size() - 1 - i]);
        }
    }

    void test() {

    }
};

#endif
