#pragma once
#ifndef _LEETCODE_3_H_
#define _LEETCODE_3_H_

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

using namespace std;

/*
Given a string,
find the length of the longest substring without repeating characters.
greedy to get the max-length,if meet a repeat character,then throw the last one.
*/
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int maxv = INT16_MIN;
        int len = 0;
        int begin = 0;
        //unordered_map<int, int> umap;
        vector<int> umap(128, 0);
        //128 not 26 because maybe have " ".
        for (int i = 0; i < s.size(); i++) {
            len++;
            if (umap[s[i]] != 0 && umap[s[i]] > begin) {
                len += (begin - umap[s[i]]);
                begin = umap[s[i]];
            }
            maxv = max(len, maxv);
            umap[s[i]] = i + 1;
        }
        return max(len, maxv);
    }

    void test() {
        string str1 = "abcabcbb";
        string str2 = "bbbbb";
        string str3 = "pwwkew";
        string str4 = "abba";
        string str5 = " ";
        cout << lengthOfLongestSubstring(str1) << endl;
        cout << lengthOfLongestSubstring(str2) << endl;
        cout << lengthOfLongestSubstring(str3) << endl;
        cout << lengthOfLongestSubstring(str4) << endl;
        cout << lengthOfLongestSubstring(str5) << endl;
    }
};
/*
Hashmap:
Runtime: 28 ms,
Memory Usage: 10.9 MB,
43.%,53.23%.
vector:
Runtime: 8 ms,
Memory Usage: 10 MB,
94.79%,73.63%.
*/
#endif
