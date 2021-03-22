#pragma once
#ifndef _LEETCODE_1315_H_
#define _LEETCODE_1315_H_

#include <stack>
#include <vector>
#ifdef __LOCAL__
#include "TreeNode.h"
#endif

using namespace std;

/*
Given a binary tree, 
return the sum of values of nodes with even-valued grandparent.  
(A grandparent of a node is the parent of its parent, if it exists.)
If there are no nodes with an even-valued grandparent, return 0.
*/
class Solution1315 {
public:
    int sumEvenGrandparent(TreeNode *root) {
        return rec(root, false, false);
    }

    int rec(TreeNode *root, bool grad, bool fath) {
        if (root == nullptr) {
            return 0;
        }
        if (grad) {
            cout << root->val << " node red" << endl;
            return root->val + rec(root->left, fath, root->val % 2 == 0) +
                   rec(root->right, fath, root->val % 2 == 0);;
        } else {
            cout << root->val << " node green" << endl;
            return rec(root->left, fath, root->val % 2 == 0) +
                   rec(root->right, fath, root->val % 2 == 0);
        }
    }

    void test() {
        vector<TreeNode *> tree;
        for (int i = 0; i <= 11; i++) {
            TreeNode *temp = new TreeNode(i);
            tree.push_back(temp);
        }
        tree[10] = new TreeNode(7);
        tree[11] = new TreeNode(1);
        tree[6]->left = tree[7];
        tree[6]->right = tree[8];

        tree[7]->left = tree[2];
        tree[7]->right = tree[10];

        tree[8]->left = tree[1];
        tree[8]->right = tree[3];


        tree[2]->left = tree[9];


        tree[10]->left = tree[11];
        tree[10]->right = tree[4];

        tree[3]->right = tree[5];
        cout << sumEvenGrandparent(tree[6]) << endl;
        for (int i = 0; i <= 11; i++) {
            delete tree[i];
        }
    }
};

#endif
