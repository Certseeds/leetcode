#pragma once
#ifndef _LEETCODE_1347_H_
#define _LEETCODE_1347_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-12 07:51:52
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-12 09:23:13
*/
#include <array>
#include <string>
#include <algorithm>

using std::abs;
using std::max;
using std::cout;
using std::endl;
using std::array;
using std::string;

/*
Given two equal-size strings s and t.
In one step you can choose any character of t
and replace it with another character.

Return the minimum number of steps to make t an anagram of s.

An Anagram of a string is a string that contains
the same characters with a different (or the same) ordering.

Example 1:
Input: s = "bab", t = "aba"
Output: 1
Explanation: Replace the first 'a' in t with b, t = "bba" which is anagram of s.

Example 2:
Input: s = "leetcode", t = "practice"
Output: 5
Explanation: Replace 'p', 'r', 'a', 'i' and 'c' from t with proper characters to make t anagram of s.

Example 3:
Input: s = "anagram", t = "mangaar"
Output: 0
Explanation: "anagram" and "mangaar" are anagrams.

Example 4:
Input: s = "xxyyzz", t = "xxyyzz"
Output: 0

Example 5:
Input: s = "friend", t = "family"
Output: 4
*/
class Solution1347 {
public:
    int minSteps(const string &s, const string &t) {
        if (s.size() != t.size()) {
            return false;
        }
        array<int, 26> str_s = {0};
        array<int, 26> str_t = {0};
        int sizes = s.size();
        int count = 0;
        for (int32_t i{0}; i < sizes; i++) {
            str_s[static_cast<int>(s[i] - 'a')]++;
            str_t[static_cast<int>(t[i] - 'a')]++;
        }
        for (int32_t i{0}; i < 26; i++) {
            count += max(0, str_s[i] - str_t[i]);
        }
        return count;
    }

    void test() {
        assert(1 == minSteps("bab", "aba"));
        assert(5 == minSteps("leetcode", "practice"));
        assert(0 == minSteps("anagram", "mangaar"));
        assert(0 == minSteps("xxyyzz", "xxyyzz"));
        assert(4 == minSteps("friend", "family"));
    }
};
/*
Runtime: 16 ms,
Memory Usage: 16.7 MB,
99.84%,100%.
*/
#endif
