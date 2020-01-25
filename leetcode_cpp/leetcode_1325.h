#pragma once
#ifndef _LEETCODE_1325_H_
#define _LEETCODE_1325_H_
#include <vector>
#include <numeric>
#include <algorithm>
#include "TreeNode.h"
using namespace std;
/*
Given a binary tree root and an integer target, 
delete all the leaf nodes with value target.

Note that once you delete a leaf node with value target, 
if it's parent node becomes a leaf node and has the value target, 
it should also be deleted (you need to continue doing that until you can't).
*/

class Solution1325 {
public:
    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(root==nullptr){
            return nullptr;
        }
        root->left = removeLeafNodes(root->left, target);
        root->right = removeLeafNodes(root->right, target);
        if (root->left == nullptr && root->right == nullptr && (root->val == target)) {
            return nullptr;
        }
        return root;
    }
    void test() {
        
    }
};
/*
Runtime: 8 ms,
Memory Usage: 21.6 MB,
100%,100%.
*/
#endif
