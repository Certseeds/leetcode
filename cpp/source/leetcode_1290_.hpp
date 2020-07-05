#pragma once
#ifndef _LEETCODE_1290_H
#define _LEETCODE_1290_H

#include <vector>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(nullptr) {}
};

class Solution1290 {
public:
    int getDecimalValue(ListNode *head) {
        int willreturn = 0;
        while (head != nullptr) {
            willreturn = willreturn << 1;
            willreturn += head->val;
            head = head->next;
        }
        return willreturn;
    }
};

#endif
