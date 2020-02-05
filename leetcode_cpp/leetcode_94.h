/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:51
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-05 11:49:55
 */
#pragma once
#ifndef _LEETCODE_94_H_
#define _LEETCODE_94_H_
#include <vector>
#include <stack>
#include <algorithm>
#include "TreeNode.h"
using namespace std;
/*
recusive && iterative way for inorder traversal.
*/
class Solution94 {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector<int> will_return;
        //recursion_94(root, will_return);
        iteration_94(root, will_return);
        return will_return;
    }
    void recursion_94(TreeNode* root,vector<int> & vec) {
        if (root == nullptr) {
            return;
        }
        recursion_94(root->left,vec);
        vec.push_back(root->val);
        recursion_94(root->right,vec);
        return;
    }
    void iteration_94(TreeNode* root, vector<int>& vec) {
        stack<TreeNode*> stk;
        stk.push(root);
        while (!stk.empty()) {
            TreeNode* head = stk.top(); stk.pop();
            if (head == nullptr) {
                continue;
            }
            else if (head->left == nullptr && head->right == nullptr){
                vec.push_back(head->val);
            }
            else {
                TreeNode* right = head->right;
                TreeNode* left = head->left;
                head->left = nullptr;
                head->right = nullptr;
                stk.push(right);
                stk.push(head);
                stk.push(left);
            }
        }
    }
    void test() {
        vector<int> nums = { 1,2,3,No,No,4,5 };
        vector<TreeNode*> vec1 = TreeNode::numToTree(nums);
        vector<int> out1 = inorderTraversal(vec1[0]);
        for (auto i : out1) {
            cout << i << " ";
        }cout << endl;
        
    }
};
/*
recursion:
Runtime: 4 ms,
Memory Usage: 10.4 MB,
60.93%,6.00%.
iteration:
Runtime: 0 ms,
Memory Usage: 8.6 MB,
100%,100%.
*/
#endif
