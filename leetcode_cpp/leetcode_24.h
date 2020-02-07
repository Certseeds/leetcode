#pragma once
#ifndef _LEETCODE_24_H_
#define _LEETCODE_24_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-07 10:33:15
*/
#include <vector>
#include <algorithm>
#include "ListNode.h"
using std::cout;
using std::endl;
using std::swap;
using std::vector;
/*
Given a linked list, 
swap every two adjacent nodes and return its head.

You may not modify the values in the list's nodes, 
only nodes itself may be changed.

Example:

Given 1->2->3->4, 
you should return the list as 2->1->4->3.
*/
class Solution24 {
public:
    ListNode* swapPairs(ListNode* root) {
        ListNode will_return(0);
        ListNode* head = &will_return;
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
    void test() {
        cout << "do not have element"<<endl;
        assert(swapPairs(nullptr) == nullptr);
        cout << "one element";
        _test(1);
        cout << "even elements";
        _test(4);
        cout << "odd elements";
        _test(5);
    }
    void _test(int x) {
        vector<int> nums1;
        for (int i = 0; i < x; i++) {
            nums1.push_back(i+1);
        }
        vector<ListNode*> vec1 = ListNode::numToList(nums1);
        for (int i = 0; i < nums1.size() / 2; i++) {
            swap(nums1[2 * i], nums1[2 * i + 1]);
        }
        ListNode* node1 = swapPairs(vec1[0]);
        int begin = 0;
        while (node1 != nullptr) {
            assert(node1->val == nums1[begin]);
            begin++;
            node1 = node1->next;
        }
        cout << endl;
        for (auto& i : vec1) {
            delete i;
        }
    }
};

/*
Runtime: 4 ms,
Memory Usage: 8.9 MB,
72.17%,8.93%.
*/
#endif
