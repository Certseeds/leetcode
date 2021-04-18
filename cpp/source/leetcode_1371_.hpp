#ifndef _LEETCODE_1371_H_
#define _LEETCODE_1371_H_

#include <queue>
#include <string>
#include <vector>
#include <algorithm>

using std::queue;
using std::string;
using std::vector;

class Solution1371 {
//10:36-10:54
public:
    vector<char> aeiou = {'a', 'e', 'i', 'o', 'u'};

    int findTheLongestSubstring(string s) {
        vector<vector<int>> vowel(5, vector<int>(s.size(), 0));
        for (int32_t i{0}; i < 5; i++) {
            vowel[i][0] = (s[0] == aeiou[i]);
            for (int j = 1; j < s.size(); j++) {
                vowel[i][j] += (s[j] == aeiou[i]);
            }
        }
        int begin = 0;
        int end = s.size() - 1;
    }

    bool judgement(const vector<vector<int>> &vowel, int begin, int end) {
        for (int32_t i{0}; i < 5; i++) {
            if (1 == (vowel[i][end] - vowel[i][begin]) % 2) {
                return false;
            }
        }
        return true;
    }

    void test() {
    }
};

#endif