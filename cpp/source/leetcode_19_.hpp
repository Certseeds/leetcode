#pragma once
#ifndef _LEETCODE_19_H
#define _LEETCODE_19_H
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:46
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-06 10:14:54
 */
#include <vector>
#include <string>
#include <algorithm>
#ifdef __LOCAL__
#include "ListNode.h"
#endif

using namespace std;

/*
Given a linked list,
remove the n-th node from the end of list and return its head.
*/
class Solution19 {
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        ListNode *will_return = new ListNode(0);
        will_return->next = head;
        ListNode *first = will_return;
        ListNode *second = will_return;
        for (int i = 0; i <= n; i++) {
            cout << second->val << endl;
            second = second->next;
        }
        while (second != nullptr) {
            first = first->next;
            second = second->next;
        }
        if (first == nullptr || first->next == nullptr) {
            return head;
        }
        first->next = (first->next)->next;
        return will_return->next;
    }

    void test() {
        vector<int> nums = {1, 2, 3, 4, 5};
        vector<ListNode *> vec1 = ListNode::numToList(nums);
        ListNode *temp = removeNthFromEnd(vec1[0], 2);
        while (temp != nullptr) {
            cout << temp->val << " ";
            temp = temp->next;
        }
        cout << endl;
        for (int i = 0; i < vec1.size(); i++) {
            delete vec1[i];
        }
    }
};
/*
Runtime: 4 ms,
Memory Usage: 8.9 MB,
90.40%,5.26%.
*/
#endif
