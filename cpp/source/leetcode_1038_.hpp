#pragma once
#ifndef _LEETCODE_1038_H
#define _LEETCODE_1038_H

#include <stack>
#include <vector>
#include "TreeNode.h"

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
/*
the real needed is make every nodes' value be (node->val + ��(*->val<node->val)(*->val))
*/
class Solution1038 {
public:
    TreeNode *bstToGst(TreeNode *root) {
        if (root == nullptr) {
            return root;
        }
        rec(root, 0);
        return root;
    }

    int rec(TreeNode *root, int sum) {
        if (root == nullptr) {
            return sum;
        } else if (root->right == nullptr && root->left == nullptr) {
            root->val += sum;
            cout << root->val << endl;
            return root->val;
        }
        sum = rec(root->right, sum);
        sum += root->val;
        root->val = sum;
        cout << root->val << endl;
        sum = rec(root->left, sum);
        return sum;
    }

    void test() {
        vector<TreeNode *> tree;
        for (int i = 0; i <= 9; i++) {
            TreeNode *temp = new TreeNode(i);
            tree.push_back(temp);
        }
        tree[4]->left = tree[1];
        tree[4]->right = tree[6];
        tree[1]->left = tree[0];
        tree[1]->right = tree[2];
        tree[6]->left = tree[5];
        tree[6]->right = tree[7];
        tree[2]->right = tree[3];
        tree[7]->right = tree[8];
        //bstToGst(tree[0]);
        cout << rec(tree[4], 0);
        for (int i = 0; i <= 9; i++) {
            delete tree[i];
        }
    }
};

#endif
