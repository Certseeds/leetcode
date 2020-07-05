#pragma once
#ifndef _LEETCODE_1021_H
#define _LEETCODE_1021_H

#include <string>
#include <stack>

using namespace std;

class Solution1021 {
public:
    string &removeOuterParentheses(string &S) {
        stack<short> clean;
        stack<int> order;
        stack<int> level;
        int now = 0;
        for (int i = 0; i < S.size(); i++) {
            if (clean.empty()) {
                clean.push(S[i]);
                order.push(i);
                level.push(1);
            } else {
                now = clean.top();
                clean.push(S[i]);
                order.push(i);
                level.push(level.top() + 1);
                if (now == (int) '(' && clean.top() == (int) ')' && level.top() != 2) {
                    clean.pop();
                    clean.pop();
                    order.pop();
                    order.pop();
                    level.pop();
                    level.pop();
                } else if (now == (int) '(' && clean.top() == (int) ')' && level.top() == 2) {
                    level.pop();
                    level.push(0);
                }
            }
        }
        for (int i = 0; i < level.size(); i++) {
            S.erase(order.top(), 1);
            order.pop();
        }
        return S;
    }
};

#endif
