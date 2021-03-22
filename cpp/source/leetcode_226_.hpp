#pragma once
#ifndef _LEETCODE_226_H_
#define _LEETCODE_226_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-12 12:49:28
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-12 12:56:15
*/
#include <vector>
#include <algorithm>
#ifdef __LOCAL__
#include "TreeNode.h"
#endif

using std::vector;

/*
Invert Binary Tree.
*/
class Solution226 {
public:
    TreeNode *invertTree(TreeNode *root) {
        if (root == nullptr) {
            return nullptr;
        }
        TreeNode *temp = root->left;
        root->left = invertTree(root->right);
        root->right = invertTree(temp);
        return root;
    }

    void test() {
        vector<int> nums1 = {4, 2, 7, 1, 3, 6, 9, No, No, No, No, No, No, No, No};
        vector<int> _nums1 = {4, 7, 2, 9, 6, 3, 1, No, No, No, No, No, No, No, No};
        vector<TreeNode *> vec1 = TreeNode::numToTree(nums1);
        TreeNode *node1 = invertTree(vec1[0]);
        TreeNode::judge_equal(vec1[0], _nums1);
        for (auto &i : vec1) {
            delete i;
        }
    }
};
/*
Runtime: 4 ms,
Memory Usage: 10.1 MB,
65.05%,5.45%.
*/
#endif
