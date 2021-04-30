#pragma once
#ifndef _LEETCODE_19_H
#define _LEETCODE_19_H
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:46
 * @LastEditors: nanoseeds
 * @LastEditTime: 2021-04-30 12:16:20
 */
#include <vector>
#include <string>
#include <algorithm>

#ifdef __LOCAL__

#include "ListNode.h"

#endif
/*
Given a linked list,
remove the n-th node from the end of list and return its head.
*/
namespace Solution19 {
using namespace LISTNODE;

using namespace std;

class Solution19 {
#ifndef __LOCAL__
    static size_t alloc_delete_count{0};
#endif
public:
    ListNode *removeNthFromEnd(ListNode *head, int n) {
        // auto *will_return = new ListNode(0);
        ListNode will_return_o{0};
        auto *const will_return = &will_return_o;
        will_return->next = head;
        ListNode *first = will_return;
        ListNode *second = will_return;
        if (n == 0) {
            second = second->next;
            while (second->next != nullptr) {
                first = first->next;
                second = second->next;
            }
            first->next = nullptr;
            return head;
        }
        for (int32_t i{0}; i <= n; i++) {
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
    ~Solution19(){
        assert(alloc_delete_count==0);
    }
};
}
/*
Runtime: 4 ms,
Memory Usage: 8.9 MB,
90.40%,5.26%.
*/
#endif
