#pragma once
#ifndef _LEETCODE_1008_H_
#define _LEETCODE_1008_H_

#include "TreeNode.h"

using namespace std;

/*
using vector to construct a Binary search tree
*/
class Solution1008 {
public:
    TreeNode *bstFromPreorder(vector<int> &preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        TreeNode *path = root;
        for (int i = 1; i < preorder.size(); i++) {
            TreeNode *Node = new TreeNode(preorder[i]);
            path = root;
            while (true) {
                if (path->val > preorder[i]) {
                    if (path->left == nullptr) {
                        path->left = Node;
                        break;
                    } else {
                        path = path->left;
                    }
                } else {
                    if (path->right == nullptr) {
                        path->right = Node;
                        break;
                    } else {
                        path = path->right;
                    }
                }
            }
        }
        return root;
    }

    TreeNode *bstFromPreorder2(vector<int> &preorder) {
        TreeNode *root = new TreeNode(preorder[0]);
        for (int i = 1; i < preorder.size(); i++) {
            rec(root, preorder[i]);
        }
        return root;
    }

    void rec(TreeNode *root, int val) {
        if (root->val > val) {
            if (root->left == nullptr) {
                root->left = new TreeNode(val);
                return;
            } else {
                rec(root->left, val);
            }
        } else {
            if (root->right == nullptr) {
                root->right = new TreeNode(val);
                return;
            } else {
                rec(root->right, val);
            }
        }
    }

    void test() {
        vector<int> vec1 = {8, 5, 1, 7, 10, 12};
        TreeNode *root1 = bstFromPreorder(vec1);
        TreeNode *root2 = bstFromPreorder2(vec1);
        cout << root1->val << endl;
        cout << root1->left->val << endl;
        cout << root1->right->val << endl;
        cout << root1->left->left->val << endl;
        cout << root1->left->right->val << endl;
        cout << root1->right->right->val << endl;
        cout << "1 finish " << endl;
        cout << root2->val << endl;
        cout << root2->left->val << endl;
        cout << root2->right->val << endl;
        cout << root2->left->left->val << endl;
        cout << root2->left->right->val << endl;
        cout << root2->right->right->val << endl;
    }
};
/*
circulate
Runtime: 0 ms, faster than 100.00% 
Memory Usage: 12.6 MB, less than 9.52% 
recurrence
Runtime: 8 ms, faster than 40.37% 
Memory Usage: 14.1 MB, less than 9.52% 
*/
#endif
