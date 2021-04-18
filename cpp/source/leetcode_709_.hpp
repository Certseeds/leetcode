#pragma once
#ifndef _LEETCODE_709_H
#define _LEETCODE_709_H

#include <string>

using namespace std;

class Solution709 {
public:
    string &toLowerCase(string &str) {
        for (int32_t i{0}; i < str.size(); i++) {
            str[i] += ((str[i] <= (int) 'Z') && (str[i] >= (int) 'A') ? 32 : 0);
        }
        return str;
    }
};

#endif
