#pragma once
#ifndef _LEETCODE_21_H_
#define _LEETCODE_21_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:46
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-06 17:16:50
 */
#include <vector>
#include <string>
#include <algorithm>
#ifdef __LOCAL__
#include "ListNode.h"
#endif

using namespace std;

/*
Merge two sorted linked lists and 
return it as a new list. 
The new list should be made 
by splicing together the nodes of the first two lists.
*/
class Solution21 {
public:
    ListNode *mergeTwoLists(ListNode *l1, ListNode *l2) {
        if (l1 == nullptr) {
            return l2;
        } else if (l2 == nullptr) {
            return l1;
        }
        if (l1->val > l2->val) {
            l2->next = mergeTwoLists(l1, l2->next);
            return l2;
        }
        l1->next = mergeTwoLists(l1->next, l2);
        return l1;
    }

    ListNode *mergeTwoLists2(ListNode *l1, ListNode *l2) {
        ListNode will_return(0);
        ListNode *head = &will_return;
        while (l1 != nullptr && l2 != nullptr) {
            if (l1->val < l2->val) {
                head->next = l1;
                l1 = l1->next;
            } else {
                head->next = l2;
                l2 = l2->next;
            }
            head = head->next;
        }
        head->next = (l1 == nullptr) ? l2 : l1;
        return will_return.next;
    }

    void test() {
        vector<ListNode *> vec1 = ListNode::numToList(vector<int>{1, 2, 4});
        vector<ListNode *> vec2 = ListNode::numToList(vector<int>{1, 3, 4});
        ListNode *node1 = mergeTwoLists2(vec1[0], vec2[0]);
        while (node1 != nullptr) {
            cout << node1->val << " ";
            node1 = node1->next;
        }
        cout << endl;
        for (auto &i : vec1) {
            delete i;
        }
        for (auto &i : vec2) {
            delete i;
        }
    }
};
/*
Runtime: 8 ms,
Memory Usage: 9.5 MB,
85.27%,5.74%.
*/
#endif
