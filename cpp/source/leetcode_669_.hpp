#pragma once
#ifndef _LEETCODE_669_H_
#define _LEETCODE_669_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-10 15:56:59
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-10 16:24:14
*/
#include <vector>
#include <algorithm>
#include "TreeNode.h"

using std::vector;

/*
Given a binary search tree and the lowest and 
highest boundaries as L and R, 
trim the tree so that all its elements lies in [L, R] (R >= L). 
You might need to change the root of the tree, 
so the result should return the 
new root of the trimmed binary search tree.
*/
class Solution669 {
public:
    TreeNode *trimBST(TreeNode *root, int L, int R) {
        if (root == nullptr) {
            return nullptr;
        }
        if (root->val < L) {
            root->left = nullptr;
            return trimBST(root->right, L, R);
        } else if (root->val > R) {
            root->right = nullptr;
            return trimBST(root->left, L, R);
        }
        root->left = trimBST(root->left, L, R);
        root->right = trimBST(root->right, L, R);
        return root;
    }

    void test() {
        vector<int> nums1 = {1, 0, 2};
        vector<int> _nums1 = {1, No, 2, No, No};
        vector<int> nums2 = {3, 0, 4, No, 2, No, No, No, No, 1, No};
        vector<int> _nums2 = {3, 2, No, 1, No, No, No};
        vector<TreeNode *> vec1 = TreeNode::numToTree(nums1);
        vector<TreeNode *> vec2 = TreeNode::numToTree(nums2);
        TreeNode *head1 = trimBST(vec1[0], 1, 2);
        TreeNode *head2 = trimBST(vec2[0], 1, 3);
        assert(head1->val == 1);
        assert(head1->left == nullptr);
        assert(head1->right->val == 2);
        assert(head2->val == 3);
        assert(head2->left->val == 2);
        assert(head2->right == nullptr);
        assert(head2->left->left->val == 1);
        assert(head2->left->right == nullptr);
        TreeNode::judge_equal(vec1[0], _nums1);
        TreeNode::judge_equal(vec2[0], _nums2);
        for (auto &i : vec1) {
            delete i;
        }
        for (auto &i : vec2) {
            delete i;
        }
    }
};
/*
Runtime: 8 ms,
Memory Usage: 15.3 MB,
100%,100%.
*/
#endif
