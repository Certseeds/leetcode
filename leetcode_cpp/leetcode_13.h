#pragma once
#ifndef _LEETCODE_13_H_
#define _LEETCODE_13_H_
#include <array>
#include <string>
#include <algorithm>
using namespace std;
/*
Roman numerals are represented by seven different symbols: I, V, X, L, C, D and M.

Symbol       Value
I             1
V             5
X             10
L             50
C             100
D             500
M             1000
For example, 
two is written as II in Roman numeral, 
just two one's added together. 
Twelve is written as, 
XII, which is simply X + II. 
The number twenty seven is written as XXVII,
which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, 
the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, 
which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given a roman numeral, convert it to an integer. 
Input is guaranteed to be within the range from 1 to 3999.
*/
class Solution13 {
public:
    int romanToInt(string s) {
        array<string, 10>  hundres = 
        {"","C","CC","CCC","CD","D","DC","DCC","DCCC","CM" };
        array<string, 10>  tens = 
        {"","X","XX","XXX","XL","L","LX","LXX","LXXX","XC" };
        array<string, 10>  ones = 
        {"","I","II","III","IV","V","VI","VII","VIII","IX" };
        int will_return = 0;
        int begin = 0;
        while (s[begin] == 'M') {
            will_return += 1000;
            begin++;
        }
        for (int i = 9; i >= 0; i--) {
            if (s.compare(
                begin, hundres[i].size(),hundres[i], 0,hundres[i].size()) == 0) {
                will_return += 100 * i;
                begin += hundres[i].size();
                break;
            }
        }
        for (int i = 9; i >= 0; i--) {
            if (s.compare(
                begin, tens[i].size(), tens[i], 0, tens[i].size()) == 0) {
                will_return += 10 * i;
                begin += tens[i].size();
                break;
            }
        }
        for (int i = 9; i >= 0;  i--) {
            //cout << ones[i] << " " << s.substr(begin) << endl;
            if (s.compare(
                begin, ones[i].size(), ones[i], 0, ones[i].size()) == 0) {
                will_return += i;
                begin += ones[i].size();
                break;
            }
        }
        return will_return;
    }
    void test() {
        cout << romanToInt("III") << endl;
        cout << romanToInt("IV") << endl;
        cout << romanToInt("IX") << endl;
        cout << romanToInt("LVIIII") << endl;
        cout << romanToInt("MCMXCIV") << endl;
    }
};
/*
Runtime: 16 ms,
Memory Usage: 8.6 MB,
60.66%,44.12%.
*/
#endif
