#pragma once
#ifndef _LEETCODE_814_H_
#define _LEETCODE_814_H_

#include <vector>
#ifdef __LOCAL__
#include "TreeNode.h"
#endif
#include <algorithm>

using namespace std;

/*
We are given the head node root of a binary tree,
where additionally every node's value is either a 0 or a 1.
Return the same tree where every subtree
(of the given tree) not containing a 1 has been removed.
(Recall that the subtree of a node X is X,
plus every node that is a descendant of X.)
*/
class Solution814 {
public:
    TreeNode *pruneTree(TreeNode *root) {
        return pruneTree_rec(root);
    }

    TreeNode *pruneTree_rec(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        root->left = pruneTree_rec(root->left);
        root->right = pruneTree_rec(root->right);
        if (root->left == nullptr && root->right == nullptr && root->val == 0) {
            return nullptr;
        }
        return root;
    }

    void test() {
        vector<TreeNode *> tree;
        for (int32_t i{0}; i <= 8; i++) {
            TreeNode *temp = new TreeNode(i % 2);
            tree.push_back(temp);
        }
        tree[1]->right = tree[2];
        tree[2]->left = tree[4];
        tree[2]->right = tree[3];
        tree[1] = pruneTree_rec(tree[1]);
        cout << tree[1]->val << " " << tree[1]->right->val << " " << tree[1]->right->right->val << endl;
        cout << (tree[1]->left == nullptr) << " " << (tree[1]->right->left == nullptr) << endl;
        for (int32_t i{0}; i <= 8; i++) { ;
            delete tree[i];
        }
    }
};
/*
Runtime: 0 ms,
Memory Usage: 11.3 MB,
100%,7.14%.
*/
#endif
