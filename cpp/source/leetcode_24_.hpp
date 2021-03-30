/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-07 10:33:15
*/
#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_24_H
#define LEETCODE_CPP_SOURCE_LEETCODE_24_H

#include <vector>
#include <algorithm>

#ifdef __LOCAL__

#include "ListNode.h"

#endif

/*
Given a linked list,
swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes,
only nodes itself may be changed.

Example:

Given 1->2->3->4,
you should return the list as 2->1->4->3.
*/
namespace Solution24 {
using std::cout;
using std::endl;
using std::swap;
using std::vector;

class Solution24 {
public:
    ListNode *swapPairs(ListNode *root) {
        ListNode will_return{0};
        ListNode *head = &will_return;
        head->next = root;
        while (root != nullptr && root->next != nullptr) {
            head->next = root->next;
            root->next = head->next->next;
            head->next->next = root;
            root = root->next;
            head = head->next->next;
        }
        return will_return.next;
    }
};
}
/*
Runtime: 4 ms,
Memory Usage: 8.9 MB,
72.17%,8.93%.
*/
#endif //LEETCODE_CPP_SOURCE_LEETCODE_24_H