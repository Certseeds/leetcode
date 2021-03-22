/*
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-27 11:59:53
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-13 22:17:00
 */
/*  leetcode_cpp
   Copyright (C) 2020  nanoseeds

   leetcode_cpp is free software: you can redistribute it and/or modify
   it under the terms of the GNU Affero General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   leetcode_cpp is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
   */
#pragma once
#ifndef _LEETCODE_2_H
#define _LEETCODE_2_H

#include <vector>
#include <array>
#ifdef __LOCAL__
#include "ListNode.h"
#endif
#include <algorithm>

using namespace std;

/*
You are given two non-empty linked lists representing two non-negative integers. 
The digits are stored in reverse order and 
each of their nodes contain a single digit. 
Add the two numbers and return it as a linked list.

You may assume the two numbers do not contain any leading zero, 
except the number 0 itself.
*/
class Solution2 {
public:
    ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {
        vector<int> nums;
        int carry = 0;
        while (l1 != nullptr && l2 != nullptr) {
            nums.push_back((l1->val + l2->val + carry) % 10);
            carry = (l1->val + l2->val + carry) / 10;
            l1 = l1->next;
            l2 = l2->next;
        }
        if (l1 == nullptr) {
            l1 = l2;
        }
        while (l1 != nullptr) {
            nums.push_back((l1->val + carry) % 10);
            carry = (l1->val + carry) / 10;
            l1 = l1->next;
        }
        if (carry == 1) {
            nums.push_back(1);
        }
        ListNode *head = new ListNode(nums[0]);
        ListNode *willreturn = head;
        for (int i = 1; i < nums.size(); i++) {
            head->next = new ListNode(nums[i]);
            head = head->next;
        }
        return willreturn;
    }

    void test() {
    }
};
/*
Runtime: 24 ms,
Memory Usage: 12.4 MB,
76.66%,5.14%.
*/
#endif
