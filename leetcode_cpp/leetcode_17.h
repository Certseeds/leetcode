#pragma once
#ifndef _LEETCODE_17_H_
#define _LEETCODE_17_H_
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
/*
Given a string containing digits from 2-9 inclusive, 
return all possible letter combinations that the number could represent.

A mapping of digit to letters (just like on the telephone buttons) is given below. 
Note that 1 does not map to any letters.
*/
class Solution17 {
public:
    vector<string> letterCombinations(string digits) {
        if(digits.size() == 0){
            return vector<string>();
        }
        vector<vector<char>> chars{
            {},
        {'a','b','c'},
        {'d','e','f'},
        {'g','h','i'},
        {'j','k','l'},
        {'m','n','o'},
        {'p','q','r','s'},
        {'t','u','v'},
        {'w','x','y','z'}
        };
        vector<string> will_return = {""};
        for (int i = 0; i < digits.size(); i++) {
            vector<string> temp;
            for (int j = 0; j < will_return.size(); j++) {
                string temp_str = will_return[j];
                for (int k = 0; k < chars[digits[i] - '1'].size(); k++) {
                    temp.push_back(temp_str+chars[digits[i] - '1'][k]);
                }
            }
            will_return = temp;
        }
        return will_return;
    }
    void test() {
        vector<string> vec1 = letterCombinations("23");
        for (auto i : vec1) {
            cout << i << endl;
        }
        vector<string> vec2 = letterCombinations("");
        for (auto i : vec2) {
            cout << i << endl;
        }
    }
};
/*
Runtime: 0 ms,
Memory Usage: 9.8 MB,
100%,5.71%.
*/
#endif
