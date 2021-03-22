#pragma once
#ifndef _LEETCODE_701_H_
#define _LEETCODE_701_H_

#include <vector>
#include <string>
#ifdef __LOCAL__
#include "TreeNode.h"
#endif

using namespace std;

/*
Given the root node of a binary search tree (BST)
and a value to be inserted into the tree,
insert the value into the BST.
Return the root node of the BST after the insertion. 
It is guaranteed that the new value does not exist in the original BST.
Note that there may exist multiple valid ways for the insertion,
as long as the tree remains a BST after insertion. You can return any of them.
*/
class Solution701 {
public:
    TreeNode *insertIntoBST(TreeNode *root, int val) {
        TreeNode *willreturn = root;
        TreeNode *newnode = new TreeNode(val);
        while (root->val != val) {
            if (root->val > val) {
                if (root->left == nullptr) {
                    root->left = newnode;
                }
                root = root->left;
            } else {
                if (root->right == nullptr) {
                    root->right = newnode;
                }
                root = root->right;
            }
        }
        return willreturn;
    }

    void rec(TreeNode *root, int val) {
        if (root == nullptr) {

        } else if (root->val > val) {
            if (root->left != nullptr) {
                rec(root->left, val);
            } else {
                root->left = new TreeNode(val);
            }
        } else {
            if (root->right != nullptr) {
                rec(root->right, val);
            } else {
                root->right = new TreeNode(val);
            }
        }
    }

    void test() {
    }
};

#endif
