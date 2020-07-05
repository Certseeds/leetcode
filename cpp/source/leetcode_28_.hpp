#pragma once
#ifndef _LEETCODE_28_H_
#define _LEETCODE_28_H_
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

using std::cout;
using std::endl;
using std::vector;
using std::string;

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
class Solution28 {
public:
    int strStr(string haystack, string needle) {
        if (needle == "") {
            return 0;
        }
        int will_return = -1;
        for (int i = 0; i < haystack.size();) {
            int temp = i;
            for (int j = 0; j < needle.size();) {
                cout << i << " " << j << endl;
                if (haystack[i] == needle[j]) {
                    i++;
                    j++;
                } else {
                    i++;
                    break;
                }
                if (j == needle.size()) {
                    return (i - j);
                }
            }
            i = temp + 1;
        }
        return -1;
    }

    int strStr_kmp(const string &h, const string &n) {
        if (n == "") {
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
        int x = -1;
        int y = 0;
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

    void test() {
        cout << "normal test 1" << endl;
        assert(strStr_kmp("hello", "ll") == 2);
        cout << "normal test 2" << endl;
        assert(strStr_kmp("aaaaa", "bba") == -1);
        cout << "for null pattern" << endl;
        assert(strStr_kmp("aaaaa", "") == 0);
        cout << "single one and single one" << endl;
        assert(strStr_kmp("a", "a") == 0);
        cout << "long stirng" << endl;
        assert(strStr_kmp("mississippi", "issi") == 1);
        cout << "repeats" << endl;
        assert(strStr_kmp("mississippi", "issip") == 4);
    }
};
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
#endif
