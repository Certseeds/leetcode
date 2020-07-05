/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-22 09:55:06
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-22 10:34:48
 */
#ifndef _LEETCODE_993_H_
#define _LEETCODE_993_H_

#include <vector>
#include <queue>
#include <algorithm>
#include "TreeNode.h"

using std::max;
using std::queue;
using std::vector;

/*
In a binary tree, 
the root node is at depth 0, 
and children of each depth k node are at depth k+1.

Two nodes of a binary tree are cousins if they have the same depth, 
but have different parents.

We are given the root of a binary tree with unique values, 
and the values x and y of two different nodes in the tree.

Return true if and only if the nodes 
corresponding to the values x and y are cousins.

EX1:
Input: root = [1,2,3,4], x = 4, y = 3
Output: false

Example 2:
Input: root = [1,2,3,null,4,null,5], x = 5, y = 4
Output: true

Example 3:
Input: root = [1,2,3,null,4], x = 2, y = 3
Output: false
*/
class Solution993 {
public:
    bool isCousins(TreeNode *root, int x, int y) {
        if (x == y) {
            return true;
        } else if (root->val == x || root->val == y) {
            return false;
        } else if ((get_depth(root, x) == get_depth(root, y)) &&
                   (get_father(root, x) != get_father(root, y))) {
            return true;
        }
        return false;
    }

    int get_depth(TreeNode *root, int x) {
        if (root == nullptr) {
            return 0;
        }
        if (root->val == x) {
            return 1;
        }
        int ln = get_depth(root->left, x);
        int rn = get_depth(root->right, x);
        if (ln > 0 || rn > 0) {
            return 1 + max(ln, rn);
        } else {
            return 0;
        }
    }

    TreeNode *get_father(TreeNode *root, int x) {
        queue<TreeNode *> ques;
        ques.push(root);
        while (!ques.empty()) {
            TreeNode *head = ques.front();
            ques.pop();
            if (head->left != nullptr) {
                if (head->left->val == x) {
                    return head;
                } else {
                    ques.push(head->left);
                }
            }
            if (head->right != nullptr) {
                if (head->right->val == x) {
                    return head;
                } else {
                    ques.push(head->right);
                }
            }
        }
        return nullptr;
    }

    void test() {
        vector<int> nums1 = {1, 2, 3, 4, No, No, No, No, No};
        vector<int> nums2 = {1, 2, 3, No, 4, No, 5, No, No, No, No, No, No, No, No};
        vector<TreeNode *> vec1 = TreeNode::numToTree(nums1);
        vector<TreeNode *> vec2 = TreeNode::numToTree(nums2);
        assert(3 == get_depth(vec1[0], 4));
        assert(2 == get_depth(vec1[0], 3));
        assert(2 == get_depth(vec1[0], 2));
        assert(1 == get_depth(vec1[0], 1));

        assert(3 == get_depth(vec2[0], 5));
        assert(3 == get_depth(vec2[0], 4));
        assert(2 == get_depth(vec2[0], 3));
        assert(2 == get_depth(vec2[0], 2));
        assert(1 == get_depth(vec2[0], 1));

        assert(0 == isCousins(vec1[0], 4, 3));
        assert(1 == isCousins(vec2[0], 4, 5));

        for (auto &i : vec1) {
            delete i;
        }
        for (auto &i : vec2) {
            delete i;
        }
    }
};
/*
Runtime: 0 ms
Memory Usage: 11.2 MB,
100%,86.67%.
*/
#endif
