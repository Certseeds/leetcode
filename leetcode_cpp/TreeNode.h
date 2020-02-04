#pragma once
#ifndef _TreeNode_H_
#define _TreeNode_H_
#include <vector>
using std::vector;
const int No = -100000;
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x);
    TreeNode(const TreeNode& obj);
    ~TreeNode();
    static vector<TreeNode*> numToTreeNode(vector<int> nums);
    static void organize(vector<TreeNode*> Tree);
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

vector<TreeNode*> TreeNode::numToTreeNode(vector<int> nums){
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
#endif