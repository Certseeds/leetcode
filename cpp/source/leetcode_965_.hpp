#pragma once
#ifndef _LEETCODE_965_H
#define _LEETCODE_965_H

#include <string>

using namespace std;


class Solution965 {
public:

    struct TreeNode965 {
        int val;
        TreeNode965 *left;
        TreeNode965 *right;

        TreeNode965(int x) : val(x), left(NULL), right(NULL) {}
    };

    bool isUnivalTree(TreeNode965 *root) {
        return judgement(root, root->val);
    }

    bool judgement(TreeNode965 *root, int value) {
        if (root == nullptr) {
            return true;
        }
        return (
                (root->val == value) &&
                judgement(root->left, root->val) &&
                judgement(root->right, root->val));
    }
};

#endif
