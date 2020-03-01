#pragma once
#ifndef _ListNode_H_
#define _ListNode_H_
#include <vector>
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-02 21:01:26
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-06 09:30:22
 */
using std::vector;
const int No_list = -100000;
struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x);
    ListNode(const ListNode& obj);
    ~ListNode();
    static vector<ListNode*> numToList(vector<int> nums);
};
ListNode::ListNode(int x) {
    this->val = x;
    this->next = nullptr;
}
ListNode::ListNode(const ListNode& obj) {
    this->val = obj.val;
    this->next = obj.next;
}
ListNode::~ListNode() {
    this->val = 0;
    this->next = 0;
}
vector<ListNode*> ListNode::numToList(vector<int> nums) {
    vector<ListNode*> will_return(nums.size(), nullptr);
    for (int i = 0; i < nums.size(); i++) {
        will_return[i] =
            (nums[i] != No_list) ?
            new ListNode(nums[i]) : nullptr;
    }
    for(int i = 0; i < nums.size()-1; i++) {
        will_return[i]->next = will_return[i + 1];
    }
    return will_return;
}
#endif