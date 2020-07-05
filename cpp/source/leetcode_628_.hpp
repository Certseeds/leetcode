#pragma once
#ifndef _LEETCODE_628_H_
#define _LEETCODE_628_H_

#include <vector>
#include <string>
#include <queue>
#include <algorithm>

using namespace std;

/*
In a string S of lowercase letters,
these letters form consecutive groups of the same character.

For example, a string like S = "abbxxxxzyy"
has the groups "a", "bb", "xxxx", "z" and "yy".

Call a group large if it has 3 or more characters.
We would like the starting and ending positions of every large group.

The final answer should be in lexicographic order.
*/
class Solution628 {
public:
    vector<vector<int>> largeGroupPositions(string S) {
        int end = 1;
        int length = 1;
        vector<vector<int>> willreturn;
        for (int i = 1; i < S.size(); i++) {
            end = i;
            if (S[i] == S[i - 1]) {
                length++;
            } else {
                if (length >= 3) {
                    willreturn.push_back(vector<int>{end - length, end - 1});
                }
                length = 1;
            }
        }
        if (length >= 3) {
            willreturn.push_back(vector<int>{end - length + 1, end});
        }
        return willreturn;
    }

    void test() {
        string str1 = "abbxxxxzzy";
        string str2 = "abcdddeeeeaabbbcd";
        string str3 = "aaa";
        vector<vector<int>> out1 = largeGroupPositions(str1);
        vector<vector<int>> out2 = largeGroupPositions(str2);
        vector<vector<int>> out3 = largeGroupPositions(str3);
        for (auto i : out1) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        for (auto i : out2) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        for (auto i : out3) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }

    }
};
/*
Runtime: 8 ms,
Memory Usage: 9.5 MB,
74.47%,20.00%.
*/
#endif
