#pragma once
#ifndef _LEETCODE_1261_H
#define _LEETCODE_1261_H

#include <set>
#include <vector>
#ifdef __LOCAL__
#include "TreeNode.h"
#endif

using namespace std;

/*
Given a binary tree with the following rules:
root.val == 0
If treeNode.val == x and treeNode.left != null, 
then treeNode.left.val == 2 * x + 1
If treeNode.val == x and treeNode.right != null, 
then treeNode.right.val == 2 * x + 2
Now the binary tree is contaminated,
which means all treeNode.val have been changed to -1.
You need to first recover the binary tree and 
then implement the FindElements class:
FindElements(TreeNode* root) 
Initializes the object with a contamined binary tree, 
you need to recover it first.
bool find(int target) 
Return if the target value exists in the recovered binary tree.
*/
class Solution1261 {
public:
    set<int> numbers;

    void FindElements(TreeNode *root) {
        FindElements_rec(root, 0, 0);
    }

    void FindElements_rec(TreeNode *root, int val, int added) {
        if (root == nullptr) {
            return;
        }
        root->val = 2 * val + added;
        numbers.insert(root->val);
        FindElements_rec(root->left, root->val, 1);
        FindElements_rec(root->right, root->val, 2);
        return;
    }

    bool find(int target) {
        return numbers.count(target);
    }

    void test() {
    }
};
/*
Runtime: 40 ms,
Memory Usage: 30.2 MB,
75.12%,100%.
*/
#endif
