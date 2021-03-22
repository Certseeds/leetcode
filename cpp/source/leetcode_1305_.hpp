#pragma once
#ifndef _LEETCODE_1305_H_
#define _LEETCODE_1305_H_

#ifdef __LOCAL__
#include "TreeNode.h"
#endif
#include <stack>
#include <vector>
#include <algorithm>

using namespace std;

/*
Merge two Binary Search Tree
iterate preorder visit and merge.
*/
class Solution1305 {
public:
    vector<int> getAllElements(TreeNode *root1, TreeNode *root2) {
        vector<int> vec1 = trans(root1);
        vector<int> vec2 = trans(root2);
        vector<int> willreturn;
        int x = 0;
        int y = 0;
        while (x != vec1.size() && y != vec2.size()) {
            if (vec1[x] < vec2[y]) {
                willreturn.push_back(vec1[x]);
                x++;
            } else {
                willreturn.push_back(vec2[y]);
                y++;
            }
        }
        if (x == vec1.size()) {
            while (y != vec2.size()) {
                willreturn.push_back(vec2[y]);
                y++;
            }
        } else {
            while (x != vec1.size()) {
                willreturn.push_back(vec1[x]);
                x++;
            }
        }
        return willreturn;
    }

    vector<int> trans(TreeNode *root) {
        vector<int> willreturn;
        if (root == nullptr) {
            return willreturn;
        }
        stack<TreeNode *> stk;
        TreeNode *head = root;
        while (!stk.empty() || head != nullptr) {
            while (head != nullptr) {
                stk.push(head);
                head = head->left;
            }
            if (!stk.empty()) {
                head = stk.top();
                willreturn.push_back(head->val);
                cout << head->val << endl;
                head = head->right;
                stk.pop();
            }
        }
        return willreturn;
    }

    void test() {
        vector<TreeNode *> tree;
        for (int i = 0; i <= 7; i++) {
            TreeNode *temp = new TreeNode(i);
            tree.push_back(temp);
        }
        tree[2]->left = tree[1];
        tree[2]->right = tree[4];

        tree[5]->val = 1;
        tree[5]->left = tree[0];
        tree[5]->right = tree[3];
        //bstToGst(tree[0]);
        vector<int> output = getAllElements(tree[2], tree[5]);
        for (int i = 0; i < output.size(); i++) {
            cout << output[i] << endl;
        }
        for (int i = 0; i <= 7; i++) {
            delete tree[i];
        }
    }
};
/*
Runtime: 320 ms,11.11%,
Memory Usage: 59.6 MB,100%.
*/
#endif
