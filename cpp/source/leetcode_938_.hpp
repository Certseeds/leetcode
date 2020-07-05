#pragma once
#ifndef _LEETCODE_938_H
#define _LEETCODE_938_H

using namespace std;

struct TreeNode938 {
    int val;
    TreeNode938 *left;
    TreeNode938 *right;

    TreeNode938(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution938 {
public:
    int rangeSumBST(TreeNode938 *root, int L, int R) {
        if (root == nullptr)
            return 0;
        int willreturn = 0;
        willreturn += ((root->val >= L) && (root->val <= R)) ? root->val : 0;
        if (root->val >= R) {
            willreturn += rangeSumBST(root->left, L, R);
        } else if (root->val > L && root->val < R) {
            willreturn += rangeSumBST(root->left, L, R);
            willreturn += rangeSumBST(root->right, L, R);
        } else {
            willreturn += rangeSumBST(root->right, L, R);
        }
        //out << root->val << " " << willreturn << endl;
        return willreturn;
    }
};


#endif