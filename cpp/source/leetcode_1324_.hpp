#pragma once
#ifndef _LEETCODE_1324_H_
#define _LEETCODE_1324_H_

#include <vector>
#include <string>
#include <numeric>
#include <algorithm>
#include <iostream>
#include <sstream>

using namespace std;

/*
Given a string s. 
Return all the words vertically in the same order in which they appear in s.
Words are returned as a list of strings, 
complete with spaces when is necessary. 
(Trailing spaces are not allowed).
Each word would be put on only one column and 
that in one column there will be only one word.
*/
class Solution1324 {
public:
    vector<string> printVertically(string str) {
        istringstream in(str);
        vector<string> strs;
        string t;
        int max_length = INT16_MIN;
        char block = ' ';
        while (in >> t) {
            max_length = max(max_length, int(t.size()));
            strs.push_back(t);
        }
        vector<string> willreturn(max_length, string(" ", strs.size()));
        for (int i = 0; i < max_length; i++) {
            for (int j = 0; j < strs.size(); j++) {
                willreturn[i][j] =
                        (i >= strs[j].size()) ? block : strs[j][i];
            }
            willreturn[i].resize(willreturn[i].find_last_not_of(' ') + 1);
        }
        return willreturn;
    }

    vector<string> printVertically2(string str) {
        string temp = string(10, ' ');
        int max_length = INT16_MIN;
        vector<string> strs;
        string str2 = str;
        while (str2.find(" ") != string::npos) {
            int found = str2.find(" ");
            strs.push_back(str2.substr(0, found));
            max_length = max(max_length, found);
            str2 = str2.substr(found + 1);
        }
        max_length = max(max_length, int(str2.size()));
        strs.push_back(str2);
        vector<string> willreturn(max_length, string(strs.size(), ' '));
        for (int i = 0; i < max_length; i++) {
            for (int j = 0; j < strs.size(); j++) {
                willreturn[i][j] =
                        (i >= strs[j].size()) ? ' ' : strs[j][i];
            }
            willreturn[i].resize(willreturn[i].find_last_not_of(' ') + 1);
        }
        return willreturn;
    }

    string &trim(string &s) {
        if (s.empty()) {
            return s;
        }
        s.erase(0, s.find_first_not_of(" "));
        s.erase(s.find_last_not_of(" ") + 1);
        return s;
    }

    void test() {
        string str1 = "HOW ARE YOU";
        vector<string> out1 = printVertically2(str1);
        for (auto i : out1) {
            cout << i << " ";
        }
        cout << endl;
        string str2 = "TO BE OR NOT TO BE";
        vector<string> out2 = printVertically2(str2);
        for (auto i : out2) {
            cout << i << " ";
        }
        cout << endl;
        string str3 = "CONTEST IS COMING";
        vector<string> out3 = printVertically2(str3);
        for (auto i : out3) {
            cout << i << " ";
        }
        cout << endl;
    }
};
/*
Runtime: 4 ms,
Memory Usage: 8.7 MB,
60.32%,100%.
*/
#endif
