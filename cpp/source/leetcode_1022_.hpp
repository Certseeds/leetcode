#pragma once
#ifndef _LEETCODE_1022_H
#define _LEETCODE_1022_H

#include <stack>
#ifdef __LOCAL__
#include "TreeNode.h"
#endif

using namespace std;

/*
Given a binary tree, each node has value 0 or 1.
Each root-to-leaf path represents a binary number starting with the most significant bit.
For example, if the path is 0 -> 1 -> 1 -> 0 -> 1,
then this could represent 01101 in binary, which is 13.
For all leaves in the tree,
consider the numbers represented by the path from the root to that leaf.
hese numbers.
*/
class Solution1022 {
public:
    int sumRootToLeaf(TreeNode *root) {
        if (root == nullptr) {
            return 0;
        }
        int willreturn = 0;
        stack<TreeNode *> tree;
        tree.push(root);
        while (!tree.empty()) {
            TreeNode *begin = tree.top();
            tree.pop();
            if (begin->left == nullptr && begin->right == nullptr) {
                willreturn += begin->val;
                continue;
            }
            if (begin->left != nullptr) {
                begin->left->val += begin->val << 1;
                tree.push(begin->left);
            }
            if (begin->right != nullptr) {
                begin->right->val += begin->val << 1;
                tree.push(begin->right);
            }
        }
        return willreturn;
    }

    void test() {
        vector<TreeNode *> tree;
        for (int32_t i{1}; i <= 7; i++) {
            TreeNode *temp = new TreeNode(i % 2);
            tree.push_back(temp);
        }
        tree[0]->left = tree[1];
        tree[0]->right = tree[2];
        tree[1]->left = tree[3];
        tree[1]->right = tree[4];
        tree[2]->left = tree[5];
        tree[2]->right = tree[6];
        cout << sumRootToLeaf(tree[0]) << endl;
        for (int32_t i{0}; i < 7; i++) {
            delete tree[i];
        }
    }
};

#endif
