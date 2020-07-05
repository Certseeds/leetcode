#pragma once
#ifndef _TreeNode_H_
#define _TreeNode_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-12 20:27:58
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-10 16:24:40
*/
#include <vector>
#include <queue>
using std::queue;
using std::vector;
const int No = -100000;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x);
    TreeNode(const TreeNode& obj);
    ~TreeNode();
    static vector<TreeNode*> numToTree(vector<int> nums);
    static void organize(vector<TreeNode*> Tree);
    static void judge_equal(TreeNode* root, vector<int> vec);
};
TreeNode::TreeNode(int x) {
    this->val = x;
    this->left = nullptr;
    this->right = nullptr;
}
TreeNode::TreeNode(const TreeNode& obj) {
    this->val = obj.val;
    this->left = obj.left;
    this->right = obj.right;
}
inline TreeNode::~TreeNode(){
    this->val = 0;
    this->left = nullptr;
    this->right = nullptr;
}

vector<TreeNode*> TreeNode::numToTree(vector<int> nums){
    vector<TreeNode*> will_return(nums.size(), nullptr);
    for (int i = 0; i < nums.size(); i++) {
        will_return[i] =
            (nums[i] != No)? 
            new TreeNode(nums[i]) : nullptr;
    }
    TreeNode::organize(will_return);
    return will_return;
}
void TreeNode::organize(vector<TreeNode*> Tree) {
    for (int i = 0; i < Tree.size(); i++) {
        if (Tree[i] != nullptr) {
            Tree[i]->left =
                (2 * i + 1 < Tree.size()) ? Tree[2 * i + 1] : nullptr;
            Tree[i]->right =
                (2 * i + 2 < Tree.size()) ? Tree[2 * i + 2] : nullptr;
        }
    }
}
void TreeNode::judge_equal(TreeNode* root, vector<int> vec) {
    queue<TreeNode*> que;
    vector<int> nums;
    que.push(root);
    while (!que.empty()) {
        TreeNode* head = que.front(); que.pop();
        if (head == nullptr) {
            nums.push_back(No);
            continue;
        }
        nums.push_back(head->val);
        que.push(head->left);
        que.push(head->right);
    }
    for (int i = 0; i < nums.size(); i++) {
        assert(nums[i] == vec[i]);
    }
}
#endif