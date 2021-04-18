#pragma once
#ifndef _LEETCODE_1170_H_
#define _LEETCODE_1170_H_

#include <vector>
#include <string>
#include <algorithm>

using namespace std;

/*
Let's define a function f(s) over a non-empty string s,
which calculates the frequency of the smallest character in s. For example,
if s = "dcce" then f(s) = 2 because the smallest character is "c"
and its frequency is 2.

Now, given string arrays queries and words,
return an integer array answer, where each answer[i] is the number of words such that f(queries[i]) < f(W), where W is a word in words
upper_bound,distance(),a magic function.
*/
class Solution1170 {
public:
    vector<int> numSmallerByFrequency(vector<string> &queries, vector<string> &words) {
        vector<int> quer(queries.size());
        vector<int> wor(words.size());

        for (int32_t i{0}; i < queries.size(); i++) {
            quer[i] = numSmallerByFrequency_help(queries[i]);
        }
        for (int32_t i{0}; i < words.size(); i++) {
            wor[i] = numSmallerByFrequency_help(words[i]);
        }
        sort(wor.begin(), wor.end(), less<int>());
        for (int32_t i{0}; i < queries.size(); i++) {
            //cout << i << endl;
            auto diff = std::upper_bound(wor.begin(), wor.end(), quer[i]);
            quer[i] = distance(diff, std::end(wor));
        }
        return quer;
    }

    inline int numSmallerByFrequency_help(string &s) {
        int num = INT16_MAX;
        int val = 1;
        for (int32_t i{0}; i < s.size(); i++) {
            if (num > s[i]) {
                num = s[i];
                val = 1;
            } else if (num == s[i]) {
                val++;
            }
        }
        return val;
    }

    void test() {
        string str1 = "zaaaz";
        cout << numSmallerByFrequency_help(str1) << endl;
        vector<string> str2 = {"bbb", "cc"};
        vector<string> str3 = {"a", "aa", "aaa", "aaaa"};
        vector<int> out1 = numSmallerByFrequency(str2, str3);
        for (auto i : out1) {
            cout << i << endl;
        }
        vector<string> str4 = {"cbd"};
        vector<string> str5 = {"zaaaz"};
        vector<int> out2 = numSmallerByFrequency(str4, str5);
        for (auto i : out2) {
            cout << i << endl;
        }
    }
};
/*
Runtime: 16 ms,
Memory Usage: 11 MB,
97.16%,100%.
*/
#endif
