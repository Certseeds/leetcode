#pragma once
#ifndef _LEETCODE_32_H_
#define _LEETCODE_32_H_
#include <stack>
#include <vector>
#include <string>
#include <algorithm>
using std::max;
using std::swap;
using std::cout;
using std::endl;
using std::stack;
using std::vector;
using std::string;
using std::reverse; 
class Solution32 {
public:
    int longestValidParentheses(string s) {
        if (s.size() <= 1) {
            return 0;
        }
        
    }
    void test() {
        cout << longestValidParentheses("") << endl;
        cout << longestValidParentheses("(()") << endl;
        cout << longestValidParentheses(")()())") << endl;
        cout << longestValidParentheses("()(())") << endl;
        cout << longestValidParentheses("()(()") << endl;

    }
};

#endif
