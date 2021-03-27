#pragma once
#ifndef _LEETCODE_22_H_
#define _LEETCODE_22_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-06 17:46:56
*/
#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>
/*
Given n pairs of parentheses, 
write a function to generate all combinations of well-formed parentheses.

For example, given n = 3, a solution set is:
[
  "((()))",
  "(()())",
  "(())()",
  "()(())",
  "()()()"
]
*/
namespace Solution22 {
using std::vector;
using std::string;
using std::unordered_set;
using std::cout;
using std::endl;
using std::endl;

class Solution22 {
public:
    vector<string> generateParenthesis(int32_t n) {
        assert(n >= 0);
        if (n == 1) {
            return vector<string>{"()"};
        }
        vector<string> temp = generateParenthesis(n - 1);
        unordered_set<string> uset;
        for (const auto &i : temp) {
            for (int32_t j = 0; j < n; j++) {
                uset.insert(string(i).insert(j, "()"));
            }
        }
        temp.clear();
        temp.reserve(uset.size());
        temp.insert(temp.end(), uset.begin(), uset.end());
        return temp;
    }

    vector<string> generateParenthesis2(int32_t n) {
        assert(n >= 0);
        vector<string> will_return = {"()"};
        unordered_set<string> uset;
        for (int32_t i = 2; i <= n; i++) {
            for (const auto &j : will_return) {
                for (int32_t k = 0; k < i; k++) {
                    uset.insert(string(j).insert(k, "()"));
                }
            }
            will_return.clear();
            will_return.reserve(uset.size());
            will_return.insert(will_return.end(), uset.begin(), uset.end());
            uset.clear();
        }
        return will_return;
    }
};
}

/*
recursion:
Runtime: 4 ms,
Memory Usage: 10.1 MB,
87.80%,96.69%.
iteration:
Runtime: 0 ms,
Memory Usage: 10.2 MB,
100%,96.69%.
*/
#endif
