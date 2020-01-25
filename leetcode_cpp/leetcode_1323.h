#pragma once
#ifndef _LEETCODE_1323_H_
#define _LEETCODE_1323_H_
#include <vector>
#include <array>
#include <numeric>
#include <algorithm>
using namespace std;
/*
Given a positive integer num consisting only of digits 6 and 9.

Return the maximum number you can get by 
changing at most one digit (6 becomes 9, and 9 becomes 6).
*/
class Solution1323 {
public:
    int maximum69Number(int num) {
        array<int, 5> arr = { 0 };
        for (int i = 0; i < 5; i++) {
            arr[4 - i] = num % 10;
            num /= 10;
        }
        for (int i = 0; i < 5; i++) {
            if (arr[i] == 6) {
                arr[i] = 9;
                break;
            }
        }
        return (arr[0] * 10000 +
            arr[1] * 1000 + arr[2] * 100 + arr[3] * 10 + arr[4] * 1);
    }
    void test() {
        cout << maximum69Number(9969) << endl;
        cout << maximum69Number(9669) << endl;
        cout << maximum69Number(6969) << endl;
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.1 MB,
100%,100%.
*/
#endif
