#pragma once
#ifndef _LEETCODE_876_H
#define _LEETCODE_876_H

#include <vector>

using namespace std;

struct ListNode876 {
    int val;
    ListNode876 *next;

    ListNode876(int x) : val(x), next(NULL) {}
};

class Solution876 {
public:
    ListNode876 *middleNode(ListNode876 *head) {
        ListNode876 *one = head;
        ListNode876 *two = head;
        while (two != nullptr) {
            if (two->next != nullptr) {
                two = two->next;
            } else {
                return one;
            }
            two = two->next;
            one = one->next;
        }
        return one;
    }
};

#endif
