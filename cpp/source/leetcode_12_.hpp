#pragma once
#ifndef _LEETCODE_12_H_
#define _LEETCODE_12_H_

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
For example, two is written as II in Roman numeral, 
just two one's added together. 
Twelve is written as, XII, which is simply X + II. 
The number twenty seven is written as XXVII, which is XX + V + II.

Roman numerals are usually written largest to smallest from left to right. 
However, the numeral for four is not IIII. Instead, 
the number four is written as IV. 
Because the one is before the five we subtract it making four. 
The same principle applies to the number nine, which is written as IX. 
There are six instances where subtraction is used:

I can be placed before V (5) and X (10) to make 4 and 9.
X can be placed before L (50) and C (100) to make 40 and 90.
C can be placed before D (500) and M (1000) to make 400 and 900.
Given an integer, 
convert it to a roman numeral. 
Input is guaranteed to be within the range from 1 to 3999.
finish it step by step, reserve space before use.
*/
class Solution12 {
public:
    string intToRoman_2(int num) {
        if (num > 1000) {
            return "M" + intToRoman(num - 1000);
        } else if (num > 100) {
            array<string, 11> hundres = {
                    "", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
            return hundres[num / 100] + intToRoman(num % 100);
        } else if (num > 10) {
            array<string, 11> tens = {
                    "", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
            return tens[num / 10] + intToRoman(num % 10);
        } else if (num <= 10) {
            array<string, 11> ones = {
                    "", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
            return ones[num];
        }
        return "should reach there";
    }

    string intToRoman(int num) {
        array<string, 11> hundres =
                {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM", "M"};
        array<string, 11> tens =
                {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC", "C"};
        array<string, 11> ones =
                {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX", "X"};
        string will_return = string((num / 1000), 'M');
        will_return.reserve(sizeof(char) * 16);
        num = num % 1000;
        will_return += hundres[num / 100];
        num = num % 100;
        will_return += tens[num / 10];
        num = num % 10;
        will_return += ones[num];
        return will_return;
    }

    void test() {
        cout << intToRoman(3) << endl;
        cout << intToRoman(4) << endl;
        cout << intToRoman(9) << endl;
        cout << intToRoman(58) << endl;
        cout << intToRoman(1994) << endl;
    }
};
/*
way one:
Runtime:4 ms,
Memory Usage: 8.6 MB,
94.51%,57.89%.
way two:
Runtime: 4 ms,
Memory Usage: 8.9 MB,
94.51%,42.10%.
*/
#endif
