#pragma once
#ifndef _TreeNode_H_
#define _TreeNode_H_
struct TreeNode {
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
#endif