#pragma once
#ifndef _LEETCODE_20_H
#define _LEETCODE_20_H
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:46
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-06 10:40:03
 */
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>
using namespace std;
/*
Given a string containing just the characters 
'(', ')', '{', '}', '[' and ']', 
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/
class Solution20 {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<int, int> umap;
        umap['('] = ')';
        umap['['] = ']';
        umap['{'] = '}';
        stk.push('?');
        for (int i = 0; i < s.size(); i++) {
            if(umap[stk.top()] == s[i]){
                stk.pop();
            }
            else {
                stk.push(s[i]);
            }
        }
        stk.pop();
        return stk.empty();
    }
    void test() {
        assert(isValid("()") == 1);
        assert(isValid("()[]{}") == 1);
        assert(isValid("(]") == 0);
        assert(isValid("([)]") == 0);
        assert(isValid("{[]}") == 1);
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.7 MB,
100%,40.31%.
*/
#endif
