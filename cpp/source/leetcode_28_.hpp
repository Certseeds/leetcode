#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_28_H
#define LEETCODE_CPP_SOURCE_LEETCODE_28_H
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-07 17:51:19
*/
#include <vector>
#include <string>
#include <algorithm>



/*
Implement strStr().

Return the index of the first occurrence of needle in haystack,
or -1 if needle is not part of haystack.

Example 1:

Input: haystack = "hello", needle = "ll"
Output: 2
Example 2:

Input: haystack = "aaaaa", needle = "bba"
Output: -1
Clarification:

What should we return when needle is an empty string?
This is a great question to ask during an interview.

For the purpose of this problem,
we will return 0 when needle is an empty string.
This is consistent to C's strstr() and Java's indexOf().
*/
namespace Solution28 {
using std::cout;
using std::endl;
using std::vector;
using std::string;

class Solution28 {
public:
    int strStr(string haystack, string needle) {
        if (needle.empty()) {
            return 0;
        }
        for (size_t i = 0; i < haystack.size();) {
            size_t temp = i;
            for (size_t j = 0; j < needle.size();) {
                cout << i << " " << j << endl;
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                } else {
                    i++;
                    break;
                }
                if (j == needle.size()) {
                    return i - j;
                }
            }
            i = temp + 1;
        }
        return -1;
    }

    int strStr_kmp(const string &h, const string &n) {
        if (n.empty()) {
            return 0;
        }
        int x = 0;
        int y = 0;
        int hsize = h.size();
        int nsize = n.size();
        vector<int> next = get_next(n);
        while ((x < hsize) && (y < nsize)) {
            if (y == -1 || h[x] == n[y]) {
                x++;
                y++;
            } else {
                y = next[y];
            }
        }
        if (y == nsize) {
            return x - y;
        }
        return -1;
    }

    vector<int> get_next(const string &h) {
        vector<int> will_return(h.size(), -1);
        int64_t x = -1;
        size_t y = 0;
        while (y < h.size() - 1) {
            if (x == -1 || h[x] == h[y]) {
                x++;
                y++;
                will_return[y] = x;
            } else {
                x = will_return[x];
            }
        }
        return will_return;
    }
};
}
/*
brute force:
Runtime: 1284 ms,
Memory Usage: 9.2 MB,
10%,41.43%.
kmp:
Runtime: 4 ms,
Memory Usage: 9.3 MB,
91.88%,21.43%.
*/
#endif //LEETCODE_CPP_SOURCE_LEETCODE_28_H