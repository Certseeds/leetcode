#pragma once
#ifndef _LEETCODE_894_H_
#define _LEETCODE_894_H_

#include <set>
#include <vector>
#include "TreeNode.h"

using namespace std;

/*
A full binary tree 
is a binary tree where each node has exactly 0 or 2 children.

Return a list of all possible full binary trees with N nodes.  
Each element of the answer is the root node of one possible tree.

Each node of each tree in the answer must have node.val = 0.

You may return the final list of trees in any order.

rec,clone
*/
class Solution894 {
public:
    vector<TreeNode *> allPossibleFBT(int n) {
        vector<TreeNode *> willreturn;
        if (n == 1) {
            willreturn.push_back(new TreeNode(0));
        }
        for (int i = 1; i <= n - 2; i += 2) {
            vector<TreeNode *> left = allPossibleFBT(i);
            vector<TreeNode *> right = allPossibleFBT(n - i - 1);
            for (auto j : left) {
                for (auto k : right) {
                    TreeNode *root = new TreeNode(0);
                    root->left = j;
                    root->right = k;
                    willreturn.push_back(root);
                }
            }
        }
        return willreturn;
    }

    void test() {
    }
};
/*
Runtime: 180 ms, 
Memory Usage: 45.8 MB
11.16%,7.14%.
*/
#endif
