#pragma once
#ifndef _LEETCODE_1047_H
#define _LEETCODE_1047_H

#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution1047 {
public:

    string removeDuplicates(string &S) {
        bool judge = true;
        while (judge) {
            judge = false;
            for (int i = 0; i < S.size(); i++) {
                if (S[i] == S[i + 1]) {
                    S.erase(i, 2);
                    judge = true;
                    break;
                }
            }
        }
        return S;
    }

    string removeDuplicates2(string &S) {
        int count = S.size();
        for (int i = 0; i < count; i++) {
            if (S[i] == S[i + 1]) {
                S.erase(i, 2);
                i = min(0, i - 1);
                count = min(0, count - 2);
            }
        }
        return S;
    }

    string removeDuplicates3(string &S) {
        string willreturn = "0";
        for (int i = 0; i < S.size(); i++) {
            if (willreturn.back() == S[i]) {
                willreturn.pop_back();
            } else {
                willreturn.push_back(S[i]);
            }
        }
        return willreturn.substr(1);
    }

    void test() {
        string abbaca = "abbaca";
        cout << removeDuplicates3(abbaca) << endl;
        string a8 = "aaaaaaaa";
        cout << removeDuplicates3(a8) << endl;
    }
};

#endif
