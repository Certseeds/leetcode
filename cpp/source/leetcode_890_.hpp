#pragma once
#ifndef _LEETCODE_890_H
#define _LEETCODE_890_H

#include <string>
#include <vector>
#include <array>
#include <unordered_map>

using namespace std;

/*
You have a list of words and a pattern,
and you want to know which words in words matches the pattern.

A word matches the pattern
if there exists a permutation of letters p
so that after replacing every letter x in the pattern with p(x),
we get the desired word.

(Recall that a permutation of letters is a bijection
from letters to letters: every letter maps to another letter,
and no two letters map to the same letter.)

Return a list of the words in words that match the given pattern.
You may return the answer in any order.

double linked array, quickly fill vector/array zero.
*/
class Solution890 {
public:
    vector<string> findAndReplacePattern(vector<string> &words, string pattern) {
        // word -> pattern
        vector<int> one(26, 0);
        vector<int> two(26, 0);
        /*
        array<int,26> one={0};
        array<int,26> two={0};
        */
        // pattern -> word
        vector<string> willreturn;
        for (int32_t i{0}; i < words.size(); i++) {
            bool judge_bool = true;
            //cout << words[i] << endl;
            for (int j = 0; j < pattern.size(); j++) {
                //cout << one[pattern[j]] << " " << two[words[i][j]] << endl;
                if ((one[pattern[j] - 'a'] != 0 ||
                     two[words[i][j] - 'a'] != 0) &&
                    (one[pattern[j] - 'a'] != words[i][j] ||
                     two[words[i][j] - 'a'] != pattern[j])) {
                    judge_bool = false;
                    break;
                } else {
                    one[pattern[j] - 'a'] = words[i][j];
                    two[words[i][j] - 'a'] = pattern[j];
                }
                //cout << one[pattern[j]] << " " << two[words[i][j]] << endl;
                //cout << endl;
            }
            //std::fill(one.begin(), one.end(), 0);
            //std::fill(two.begin(), two.end(), 0);
            memset(&one[0], 0, one.size() * sizeof one[0]);
            memset(&two[0], 0, two.size() * sizeof two[0]);
            if (judge_bool) {
                willreturn.push_back(words[i]);
            }
        }
        return willreturn;
    }

    void test() {
        vector<string> input1 = {"abc", "deq", "mee", "aqq", "dkd", "ccc"};
        string str1 = "abb";
        vector<string> output1 = findAndReplacePattern(input1, str1);
        for (auto i : output1) {
            cout << i << endl;
        }
    }
};
/*
Memset():
Runtime: 0 ms,
Memory Usage: 8.9 MB,
100%,100%.
unordered_map() || std::fill() to vector<int>:
Runtime: 8 ms,
Memory Usage: 9.3 MB,
39.50%,81.82%.
*/
#endif
