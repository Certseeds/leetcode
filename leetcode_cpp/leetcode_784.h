#pragma once
#ifndef _LEETCODE_784_H_
#define _LEETCODE_784_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-14 21:21:23
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-14 22:07:17
*/
#include <vector>
#include <algorithm>
using std::cout;
using std::endl;
using std::vector;
using std::string;
/*
Given a string S, we can transform every letter 
individually to be lowercase or uppercase to create another string.  
Return a list of all possible strings we could create.

Examples:
Input: S = "a1b2"
Output: ["a1b2", "a1B2", "A1b2", "A1B2"]

Input: S = "3z4"
Output: ["3z4", "3Z4"]

Input: S = "12345"
Output: ["12345"]
Note:
S will be a string with length between 1 and 12.
S will consist only of letters or digits.
*/
class Solution784 {
public:
    vector<string> letterCasePermutation(const string& S) {
        vector<int> pos;
        pos.reserve(S.size());
        for (int i = 0; i <= S.size(); i++) {
            if ((S[i] >= 'a' && S[i] <= 'z') || (S[i] >= 'A' && S[i] <= 'Z')) {
                pos.push_back(i);
            }
        }
        vector<string> will_return((1<<pos.size()),S);
        for (int i = 0; i < pos.size(); i++) {
            char low = up_to_low(S[pos[i]]);
            char up = low_to_up(S[pos[i]]);
            int divisor = (1 << (pos.size() - 1 - i));
            for (int j = 0; j < will_return.size(); j++) {
                will_return[j][pos[i]] = ((j /divisor ) % 2 == 0)?up:low;
            }
            //cout << " ? " << endl;
        }
        return will_return;
    }
    char low_to_up(const char& ch) {
        if (ch >= 'A' && ch <= 'Z') {
            return (ch - 'A' + 'a');
        }
        return ch;
    }
    char up_to_low(const char& ch) {
        if (ch >= 'a' && ch <= 'z') {
            return (ch - 'a' + 'A');
        }
        return ch;
    }
    void test() {
        string str1 = "a1b2";
        string str2 = "3z4";
        string str3 = "12345";
        vector<string> _out1 = { "a1b2", "a1B2", "A1b2", "A1B2" };
        vector<string> _out2 = { "3z4", "3Z4" };
        vector<string> _out3 = { "12345"};
        vector<string> out1 = letterCasePermutation(str1);
        vector<string> out2 = letterCasePermutation(str2);
        vector<string> out3 = letterCasePermutation(str3);
        for (int i = 0; i < out1.size(); i++) {
            assert(out1[i] == _out1[i]);
        }
        for (int i = 0; i < out2.size(); i++) {
            assert(out2[i] == _out2[i]);
        }
        for (int i = 0; i < out3.size(); i++) {
            assert(out3[i] == _out3[i]);
        }
    }
};
/*
Runtime: 4 ms,
Memory Usage: 11.1 MB,
99.36%,100%.
*/
#endif
