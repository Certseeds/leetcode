/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-07 23:13:11
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-08 00:31:14
 */
#ifndef _LEETCODE_1372_H_
#define _LEETCODE_1372_H_

#include <vector>
#include <algorithm>
#include "TreeNode.h"

using std::max;
using std::vector;

/*
Given a binary tree root, a ZigZag path for a binary tree is defined as follow:
Choose any node in the binary tree and a direction (right or left).
If the current direction is right then move to the right child of 
the current node otherwise move to the left child.
Change the direction from right to left or right to left.
Repeat the second and third step until you can't move in the tree.
Zigzag length is defined as the number of nodes visited - 1. 
(A single node has a length of 0).
Return the longest ZigZag path contained in that tree.

Example 1:
Input: root = [1,null,1,1,1,null,null,1,1,null,1,null,null,null,1,null,1]
Output: 3
Explanation: Longest ZigZag path in blue nodes (right -> left -> right).

Example 2:
Input: root = [1,1,1,null,1,null,null,1,1,null,1]
Output: 4
Explanation: Longest ZigZag path in blue nodes (left -> right -> left -> right).

Example 3:
Input: root = [1]
Output: 0

Constraints:
Each tree has at most 50000 nodes..
Each node's value is between [1, 100].
10:54-12:18
*/
class Solution1372 {
public:
    int longestZigZag(TreeNode *root) {
        int maxv_n = INT16_MIN;
        int *maxv = &maxv_n;
        if (nullptr == root) {
            return -1;
        }
        (*maxv) = max(*maxv, 1 + std::max(
                longestZigZag_dirc(root->left, false, maxv),
                longestZigZag_dirc(root->right, true, maxv)
        ));
        return (*maxv);
    }

    int longestZigZag_dirc(TreeNode *root, bool b, int *maxv) {
        if (root == nullptr) {
            return -1;
        }
        if (b) {
            (*maxv) = max((*maxv), 1 + longestZigZag_dirc(root->right, b, maxv));
            return (1 + longestZigZag_dirc(root->left, !b, maxv));
        }
        (*maxv) = max((*maxv), 1 + longestZigZag_dirc(root->left, b, maxv));
        return (1 + longestZigZag_dirc(root->right, !b, maxv));
    }
    /*
    int maxv = INT16_MIN;
    int longestZigZag(TreeNode* root) {
        if (nullptr == root) {
            return -1;
        }
        maxv = max(maxv, 1 + std::max(
            longestZigZag_dirc(root->left, false),
            longestZigZag_dirc(root->right, true)
        ));
        return maxv;
    }
    int longestZigZag_dirc(TreeNode* root,bool b) {
        if (root == nullptr) {
            return -1;
        }
        if (b) {
            maxv = max(maxv, 1 + longestZigZag_dirc(root->right, b));
            return (1 + longestZigZag_dirc(root->left, !b));
        }
        maxv = max(maxv, 1 + longestZigZag_dirc(root->left, b));
        return (1 + longestZigZag_dirc(root->right, !b));
    }*/
    // also can run.
    void test() {
        vector<int> nums_1 = {
                1,
                No, 1,
                No, No, 1, 1,
                No, No, No, No, No, No, 1, 1,
                No, No, No, No, No, No, No, No, No, No, No, No,
                No, 1, No, No, No, No, No, No, No, No, No, No, No, No, No, No, No, No, No, No, No, No, No, No,
                No, No, No, No, No, No, No, 1, No, No, No, No
        };
        vector<int> nums_2 = {
                1,
                1, 1,
                No, 1, No, No,
                No, No, 1, 1, No, No, No, No,
                No, No, No, No, No, 1, No, No, No, No, No, No, No, No, No, No
        };
        vector<int> nums_3 = {1};
        vector<TreeNode *> node_1 = TreeNode::numToTree(nums_1);
        vector<TreeNode *> node_2 = TreeNode::numToTree(nums_2);
        vector<TreeNode *> node_3 = TreeNode::numToTree(nums_3);
        assert(3 == longestZigZag(node_1[0]));
        assert(4 == longestZigZag(node_2[0]));
        assert(0 == longestZigZag(node_3[0]));
        for (auto &i : node_1) {
            delete i;
        }
        for (auto &i : node_2) {
            delete i;
        }
        for (auto &i : node_3) {
            delete i;
        }
    }
};
/*
Runtime: 116 ms,
Memory Usage: 63.2 MB,
100%,100%.
*/
#endif