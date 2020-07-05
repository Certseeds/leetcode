#pragma once
#ifndef _LEETCODE_1309_H
#define _LEETCODE_1309_H

#include <vector>
#include <array>
#include <algorithm>

using namespace std;

/*
Given a string s formed by digits ('0' - '9') and '#' . 
We want to map s to English lowercase characters as follows:

Characters ('a' to 'i') are represented by ('1' to '9') respectively.
Characters ('j' to 'z') are represented by ('10#' to '26#') respectively.
Return the string formed after mapping.

It's guaranteed that a unique mapping will always exist.
*/
class Solution1309 {
public:
    string freqAlphabets(string s) {
        vector<char> chars;
        int i = 0;
        for (; i < s.size() - 2; i++) {
            if (s[i + 2] == '#') {
                chars.push_back((s[i] - '0') * 10 + (s[i + 1] - '0') + 'a' - 1);
                i += 2;
            } else {
                chars.push_back(s[i] - '1' + 'a');
            }
        }
        for (; i < s.size(); i++) {
            chars.push_back(s[i] - '1' + 'a');
        }
        return std::string(chars.begin(), chars.end());
    }

    void test() {
        cout << freqAlphabets("10#11#12") << endl;
        cout << freqAlphabets("1326#") << endl;
        cout << freqAlphabets("25#") << endl;
        cout << freqAlphabets(
                "12345678910#11#12#13#14#15#16#17#18#19#20#21#22#23#24#25#26#") << endl;
        cout << freqAlphabets("26#11#418#5") << endl;
        cout << freqAlphabets("1326#") << endl;
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.6 MB,
100%,100%.
*/
#endif
