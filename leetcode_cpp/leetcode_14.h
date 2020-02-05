#pragma once
#ifndef _LEETCODE_14_H_
#define _LEETCODE_14_H_
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Write a function to find the longest common prefix string amongst an array of strings.

If there is no common prefix, 
return an empty string "".
*/
class Solution14 {
public:
    string longestCommonPrefix(vector<string>& strs) {
        if (strs.empty()) {
            return "";
        }
        size_t length = INT32_MAX;
        for (auto i : strs) {
            length = min(length, i.size());
        }
        string will_return = "";
        for (int i = 0; i < length; i++) {
            char judge = strs[0][i];
            bool equal = true;
            for (int j = 0; j < strs.size(); j++) {
                if (strs[j][i] != judge) {
                    return will_return;
                }
            }
            will_return += judge;
        }
        return will_return;
    }
    void test() {
        vector<string> str1 = { "flower","flow","flight" };
        vector<string> str2 = { "dog", "racecar", "car" };
        vector<string> str3 = { };
        cout << longestCommonPrefix(str1) << endl;
        cout << longestCommonPrefix(str2) << endl;
        cout << longestCommonPrefix(str3) << endl;
    }
};
/*
Runtime: 4 ms,
Memory Usage: 9.2 MB,
96.09%,6.45%.
*/
#endif
