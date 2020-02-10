#pragma once
#ifndef _LEETCODE_43_H_
#define _LEETCODE_43_H_
#include <string>
#include <vector>
#include <algorithm>
using std::max;
using std::min; 
using std::cout;
using std::endl;
using std::find;
using std::swap;
using std::string;
using std::vector;
/*
Given two non-negative integers num1 and num2 represented as strings, 
return the product of num1 and num2, also represented as a string.
*/
class Solution43 {
public:
    string multiply(string num1, string num2) {
        if (num1 == "0" || num2 == "0") {
            return "0";
        }
        vector<int> sum(num1.size()+num2.size(), 0);
        for (int i = num2.size()-1; i >= 0; i--) {
            for (int j = num1.size() - 1; j >= 0; j--) {
                int mul = 
                    (static_cast<int>(num2[i]) - static_cast<int>('0')) * 
                    (static_cast<int>(num1[j])- static_cast<int>('0'));
                //cout << i << " " << j << " " << mul << endl;
                sum[i + j] += (mul + sum[i + j + 1]) / 10;
                sum[i + j + 1] = (mul + sum[i + j + 1]) % 10;
            }
        }
        string will_return = "";
        int i = std::find_if(sum.begin(), sum.end(), [](int x) {return x != 0; })-sum.begin();
        for (; i < sum.size(); i++) {
            will_return += static_cast<char>(sum[i] + static_cast<int>('0'));
        }
        return will_return;
    }
    void test() {
        cout << multiply("9", "9") << endl;
        cout << multiply("123","456") << endl;
    }
};
/*
Runtime: 0 ms, faster than 100.00% of C++ online submissions for Multiply Strings.
Memory Usage: 9 MB, less than 30.77%
*/
#endif
