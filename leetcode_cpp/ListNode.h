#pragma once
#ifndef _ListNode_H_
#define _ListNode_H_
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};
#endif