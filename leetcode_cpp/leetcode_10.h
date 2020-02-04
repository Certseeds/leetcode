#pragma once
#ifndef _LEETCODE_10_H_
#define _LEETCODE_10_H_
#include <regex>
#include <string>
#include <algorithm>
using namespace std;
/*
Given an input string (s) and a pattern (p), 
implement regular expression matching with support for '.' and '*'.

'.' Matches any single character.
'*' Matches zero or more of the preceding element.
The matching should cover the entire input string (not partial).
*/
class Solution10 {
public:
    bool isMatch(string s, string p) {
        return std::regex_match(s, std::regex(p));
    }
    void test() {
        cout << isMatch("aa", "a") << endl;
        cout << isMatch("aa", "a*") << endl;
        cout << isMatch("ab", ".*") << endl;
        cout << isMatch("mississippi", "mis*is*p*.") << endl;
    }
};
/*
Runtime: 148 ms,
Memory Usage: 12.1 MB,
22.29%,16.95%.
*/
#endif
