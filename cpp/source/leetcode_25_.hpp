#pragma once
#ifndef _LEETCODE_25_H_
#define _LEETCODE_25_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-07 13:26:45
*/
#include <vector>
#include <queue>
#include <algorithm>
#include "ListNode.h"

using std::cout;
using std::endl;
using std::swap;
using std::queue;
using std::vector;

/*
Given a linked list, 
reverse the nodes of a linked list k at a time and return its modified list.

k is a positive integer and 
is less than or equal to the length of the linked list. 
If the number of nodes is not a multiple of k then left-out nodes 
in the end should remain as it is.

Example:
Given this linked list: 1->2->3->4->5
For k = 2, you should return: 2->1->4->3->5
For k = 3, you should return: 3->2->1->4->5

Note:

Only constant extra memory is allowed.
You may not alter the values in the list's nodes, 
only nodes itself may be changed.
Reverse Linkedlist.
*/
class Solution25 {
public:
    ListNode *reverseKGroup(ListNode *root, int k) {
        ListNode will_return(0);
        ListNode *head = &will_return;
        head->next = root;
        queue<ListNode *> que;
        vector<ListNode *> vec;
        vec.reserve(sizeof(ListNode *) * k);
        while (root != nullptr) {
            que.push(root);
            root = root->next;
        }
        while (que.size() >= k) {
            for (int i = 0; i < k; i++) {
                vec.push_back(que.front());
                que.pop();
            }
            head->next = vec.back();
            for (int i = k - 1; i > 0; i--) {
                vec[i]->next = vec[i - 1];
                head = head->next;
            }
            head = head->next;
            vec.clear();
        }
        head->next = (que.empty()) ? nullptr : que.front();
        return will_return.next;
    }

    ListNode *reverseKGroup2(ListNode *root, int k) {
        ListNode will_return(0);
        ListNode *head = &will_return;
        head->next = root;
        vector<ListNode *> vec;
        vec.reserve(sizeof(ListNode *) * k);
        while (reverseKGroup_help(root, k)) {
            for (int i = 0; i < k; i++) {
                vec.push_back(root);
                root = root->next;
            }
            head->next = vec.back();
            for (int i = k - 1; i > 0; i--) {
                vec[i]->next = vec[i - 1];
                head = head->next;
            }
            head = head->next;
            vec.clear();
        }
        head->next = root;
        return will_return.next;
    }

    bool reverseKGroup_help(ListNode *root, int k) {
        ListNode *temp = root;
        for (int i = 0; i < k; i++) {
            if (temp == nullptr) {
                return false;
            }
            temp = temp->next;
        }
        return true;
    }

    ListNode *reverseKGroup3(ListNode *root, int k) {
        ListNode will_return(0);
        ListNode *head = &will_return;
        head->next = root;
        while (reverseKGroup_help(head->next, k)) {
            head->next = reverseKGroup_help2(head->next, k);
            for (int i = 0; i < k; i++) {
                head = head->next;
            }
        }
        return will_return.next;
    }

    ListNode *reverseKGroup_help2(ListNode *root, int k) {
        if (k == 1) {
            return root;
        }
        ListNode *fir = root;
        ListNode *sec = root->next;
        ListNode *temp = root->next->next;
        for (int i = 0; i < k - 1; i++) {
            temp = sec->next;
            sec->next = fir;
            fir = sec;
            sec = temp;
        }
        root->next = temp;
        return fir;
    }

    void transfer(vector<int> &vec, int k) {
        if (k == 1) {
            return;
        }
        auto iter = vec.begin();
        auto iter2 = vec.begin() + k;
        for (int i = 0; i < vec.size() / k - 1; i++) {
            //cout << i << endl;
            std::reverse(iter, iter2);
            iter += k;
            iter2 += k;
        }
        std::reverse(iter, iter2);
    }

    void test() {
        cout << " test k is 1" << endl;
        _test(10, 1);
        cout << " test even odd" << endl;
        _test(5, 2);
        cout << " test odd odd" << endl;
        _test(6, 2);
        cout << " test odd even" << endl;
        _test(6, 3);
        cout << " test equal" << endl;
        _test(3, 3);
        cout << " test can be divide" << endl;
        _test(9, 3);
    }

    void _test(int x, int y) {
        vector<int> nums1;
        for (int i = 0; i < x; i++) {
            nums1.push_back(i + 1);
        }
        vector<ListNode *> vec1 = ListNode::numToList(nums1);
        transfer(nums1, y);
        ListNode *node1 = reverseKGroup3(vec1[0], y);
        int begin = 0;
        while (node1 != nullptr) {
            assert(node1->val == nums1[begin]);
            //cout << node1->val << " " << nums1[begin] << " ";
            node1 = node1->next;
            begin++;
        }
        //cout << endl;
        for (auto &i : vec1) {
            delete i;
        }
    }
};
/*
Runtime: 20 ms,
Memory Usage: 11.3 MB,
85.22%,6.45%.
*/
#endif
