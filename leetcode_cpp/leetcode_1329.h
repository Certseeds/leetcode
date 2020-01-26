#pragma once
#ifndef _LEETCODE_1329_H_
#define _LEETCODE_1329_H_
#include <vector>
#include <algorithm>
#include <numeric>
#include <string>
using namespace std;
/*

*/
class Solution1329 {
public:
    string breakPalindrome(string pal) {
        if (pal.size() < 2) {
            return "";
        }
        char maxv = 0;
        for (int i = 0; i < (pal.size()+1)/2; i++) {
            maxv = max(maxv, pal[i]);
        }
        if (maxv == 'a') {
            for (int i = pal.size()-1; i > 0; i--) {
                if (pal[i] == 'a') {
                    pal[i] == 'b';
                    return pal;
                }
            }
        }
        cout << maxv << endl;
        for (int i = 0; i < (pal.size()) / 2; i++) {
            if (pal[i] != 'a') {
                pal[i] = 'a';
                return pal;
            }
        }
        return "";
    }
    void test() {
        cout << breakPalindrome("abccba") << endl;
        cout << breakPalindrome("aba") << endl;
    }
};
/*

*/
#endif
