/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-01 11:35:22
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-01 13:37:02
 */
#ifndef _LEETCODE_1367_H_
#define _LEETCODE_1367_H_

#include <queue>
#include <vector>
#include <algorithm>
#include "TreeNode.h"
#include "ListNode.h"

using std::queue;
using std::vector;

/*
Given a binary tree root and a linked list with head as the first node.
Return True if all the elements in the linked list starting from
the head correspond to some downward path connected in the binary tree otherwise return False.
In this context downward path means a path that starts at some node and goes downwards.

Example 1:
Input:
head = [4,2,8],
root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true
Explanation: Nodes in blue form a subpath in the binary Tree.

Example 2:
Input:
head = [1,4,2,6],
root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: true

Example 3:
Input:
head = [1,4,2,6,8],
root = [1,4,4,null,2,2,null,1,null,6,8,null,null,null,null,1,3]
Output: false
Explanation: There is no path in the binary tree that contains all the elements of the linked list from head.

Constraints:
1 <= node.val <= 100 for each node in the linked list and binary tree.
The given linked list will contain between 1 and 100 nodes.
The given binary tree will contain between 1 and 2500 nodes.
11:35-12:15
*/
class Solution1367 {
public:
    bool isSubPath(ListNode *listnode, TreeNode *root) {
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            TreeNode *head = que.front();
            que.pop();
            if (head == nullptr) {
                continue;
            }
            que.push(head->left);
            que.push(head->right);
            if (listnode->val == head->val && judge_isSubPath(listnode, head)) {
                return true;
            }
        }
        return false;
    }

    bool judge_isSubPath(ListNode *head, TreeNode *root) {
        if (nullptr == head) {
            return true;
        } else if (nullptr == root && nullptr != head) {
            return false;
        }
        return (head->val == root->val) && (
                judge_isSubPath(head->next, root->left) ||
                judge_isSubPath(head->next, root->right));
    }

    void test() {
        vector<int> list_num1 = {4, 2, 8};
        vector<int> tree_num1_2_3 = {1, 4, 4, No, 2, 2, No, 1, No, 6, 8, No, No, No, No, 1, 3};
        vector<int> list_num2 = {1, 4, 2, 6};
        vector<int> list_num3 = {1, 4, 2, 6, 8};
        vector<int> list_num4 = {1, 10, 3, 7, 10, 8, 9, 5, 3, 9, 6, 8, 7, 6, 6, 3, 5, 4, 4, 9, 6, 7, 9, 6, 9, 4, 9, 9,
                                 7, 1, 5, 5, 10, 4, 4, 10, 7, 7, 2, 4, 5, 5, 2, 7, 5, 8, 6, 10, 2, 10, 1, 1, 6, 1, 8, 4,
                                 7, 10, 9, 7, 9, 9, 7, 7, 7, 1, 5, 9, 8, 10, 5, 1, 7, 6, 1, 2, 10, 5, 7, 7, 2, 4, 10, 1,
                                 7, 10, 9, 1, 9, 10, 4, 4, 1, 2, 1, 1, 3, 2, 6, 9};
        vector<int> tree_num4 = {4, No, 8, No, 5, No, 7, No, 5, No, 2, 1, 3, No, No, No, 6, 8, 9, No, No, No, 3, No, 2,
                                 No, 10, No, 7, No, 8, 3, 4, No, No, No, 3, 5, 1, No, No, No, 3, 1, 7, No, No, No, 4, 7,
                                 7, No, No, 8, 3, No, No, No, 6, 3, 1, No, No, No, 1, No, 8, No, 2, 5, 5, No, No, 1, 3,
                                 No, No, No, 5, No, 3, 3, 5, No, No, No, 7, No, 10, No, 7, No, 6, No, 8, No, 4, No, 10,
                                 No, 6, No, 6, 9, 3, No, No, 6, 5, No, No, No, 5, No, 2, No, 7, No, 5, No, 4, 8, 2, No,
                                 No, No, 2, No, 10, 10, 8, No, No, No, 7, No, 2, No, 5, 8, 6, No, No, No, 5, No, 7, No,
                                 3, 4, 5, No, No, No, 4, No, 8, No, 8, No, 8, No, 2, No, 5, 2, 9, No, No, No, 2, No, 3,
                                 7, 1, No, No, 10, 1, No, No, No, 7, No, 6, No, 6, No, 7, No, 7, No, 4, 4, 2, No, No, 7,
                                 4, No, No, No, 7, No, 3, 7, 5, No, No, No, 5, No, 4, No, 9, 5, 2, No, No, No, 4, No, 9,
                                 No, 5, No, 5, No, 5, No, 2, No, 5, No, 2, No, 5, No, 7, 5, 5, No, No, No, 6, No, 1, No,
                                 7, No, 3, 9, 8, No, No, No, 4, No, 7, 4, 8, No, No, 4, 2, No, No, No, 3, 10, 2, No, No,
                                 No, 7, No, 10, No, 3, No, 1, No, 2, No, 5, No, 9, No, 8, No, 5, No, 9, No, 3, No, 7,
                                 No, 10, 5, 2, No, No, No, 2, 8, 10, No, No, No, 4, 4, 7, No, No, No, 5, 1, 4, No, No,
                                 No, 10, No, 9, No, 4, No, 9, 6, 5, No, No, No, 7, 5, 4, No, No, No, 8, No, 8, 4, 9, No,
                                 No, No, 6, 9, 1, No, No, No, 3, 3, 6, No, No, No, 6, No, 7, No, 2, No, 1, No, 8, 2, 9,
                                 No, No, No, 8, No, 3, No, 1, 9, 1, No, No, No, 2, No, 6, No, 1, No, 6, 3, 9, No, No,
                                 No, 10, No, 1, No, 9, No, 9, No, 10, No, 2, No, 6, No, 3, No, 7, No, 2, No, 2, No, 2,
                                 9, 5, No, No, No, 5, No, 6, No, 6, No, 2, No, 5, 7, 9, No, No, No, 6, 10, 4, No, No, 8,
                                 4, No, No, 4, 2, No, No, 4, 7, No, No, 2, 5, No, No, No, 4, 5, 1, No, No, No, 3, No, 1,
                                 10, 6, No, No, 3, 2, No, No, No, 6, No, 9, No, 7, No, 5, 8, 5, No, No, No, 5, No, 5,
                                 10, 6, No, No, No, 7, No, 1, No, 6, 3, 7, No, No, No, 9, 7, 1, No, No, No, 7, No, 4,
                                 No, 4, No, 9, No, 4, No, 1, No, 10, No, 1, 10, 10, No, No, No, 6, No, 3, No, 1, No, 9,
                                 No, 7, No, 6, 6, 1, No, No, No, 9, 4, 7, No, No, No, 3, No, 10, No, 4, 3, 3, No, No,
                                 No, 4, 5, 10, No, No, No, 1, 8, 10, No, No, No, 6, No, 9, No, 10, No, 4, 4, 9, No, No,
                                 No, 3, No, 3, No, 3, No, 10, No, 10, No, 6, 8, 1, No, No, No, 9, 7, 1, No, No, No, 5,
                                 No, 3, No, 10, No, 5, No, 9, No, 5, No, 8, No, 6, 3, 2, No, No, No, 8, No, 8, 3, 9, No,
                                 No, No, 9, No, 10, 3, 8, No, No, 6, 6, No, No, No, 6, No, 8, No, 2, No, 9, No, 4, No,
                                 6, No, 4, No, 4, No, 6, No, 9, No, 7, No, 10, No, 1, No, 3, No, 6, No, 7, No, 4, No, 9,
                                 No, 1, No, 3, 8, 10, No, No, No, 2, No, 10, No, 4, No, 8, No, 10, No, 7, No, 8, 5, 1,
                                 No, No, 9, 3, No, No, 7, 8, No, No, No, 1, No, 1, 5, 4, No, No, No, 1, No, 4, 5, 7, No,
                                 No, No, 3, No, 6, No, 6, No, 9, No, 4, No, 1, 5, 10, No, No, No, 3, No, 7, No, 10, No,
                                 8, No, 9, 2, 5, No, No, No, 3, No, 9, 10, 6, No, No, No, 8, No, 7, 8, 6, No, No, No, 6,
                                 No, 3, No, 5, No, 4, No, 4, No, 9, No, 6, 2, 7, No, No, No, 9, No, 6, 1, 9, No, No, No,
                                 4, No, 9, 9, 9, No, No, No, 7, 7, 1, No, No, No, 5, No, 5, 6, 10, No, No, No, 4, No, 4,
                                 10, 10, No, No, No, 7, 2, 7, No, No, No, 2, No, 4, No, 5, No, 5, 10, 2, No, No, No, 7,
                                 9, 5, No, No, No, 8, No, 6, No, 10, 8, 2, No, No, 8, 10, No, No, No, 1, No, 1, No, 6,
                                 5, 1, No, No, 8, 8, No, No, 8, 4, No, No, No, 7, No, 10, 4, 9, No, No, No, 7, No, 9,
                                 No, 9, 1, 7, No, No, 4, 7, No, No, No, 7, No, 1, No, 5, 8, 9, No, No, 9, 8, No, No, 9,
                                 10, No, No, 4, 5, No, No, 1, 1, No, No, No, 7, No, 6, No, 1, No, 2, 1, 10, No, No, 2,
                                 5, No, No, 7, 7, No, No, No, 7, No, 2, No, 4, 3, 10, No, No, No, 1, No, 7, No, 10, 7,
                                 9, No, No, No, 5, 4, 9, No, No, No, 10, 6, 4, No, No, 8, 4, No, No, No, 1, No, 2, No,
                                 1, 8, 1, No, No, No, 3, No, 2, No, 6, No, 9, No, 2, 1, 10, No, No, No, 5, No, 8, 2, 1,
                                 No, No, No, 2, 3, 10, No, No, No, 8, No, 9, No, 5, No, 4, No, 1, 9, 10, No, No, 4, 9,
                                 No, No, 3, 5, No, No, No, 6, No, 6, 9, 1, No, No, No, 5, No, 2, No, 2, No, 6, No, 1, 7,
                                 9, No, No, No, 6, No, 8, 4, 4, No, No, No, 2, No, 10, No, 1, No, 2, No, 9, No, 8, No,
                                 2, No, 1, 10, 4, No, No, No, 10, No, 8, 3, 2, No, No, No, 10, No, 3, 8, 1, No, No, 5,
                                 3, No, No, No, 6, No, 8, No, 7, 2, 5, No, No, 1, 6, No, No, No, 8, No, 6, No, 3, No, 8,
                                 No, 9, No, 5, No, 2, No, 9, No, 2, 6, 10, No, No, 7, 10, No, No, No, 6, No, 8, No, 7,
                                 7, 4, No, No, No, 3, 5, 2, No, No, 10, 4, No, No, No, 4, 4, 3, No, No, No, 5, No, 1,
                                 No, 10, No, 10, No, 5, No, 9, No, 3, No, 8, No, 3, No, 2, No, 4, 1, 1, No, No, No, 7,
                                 10, 8, No, No, No, 9, 4, 8, No, No, 1, 2, No, No, 9, 7, No, No, 5, 8, No, No, No, 9,
                                 No, 7, No, 4, No, 4, 5, 3, No, No, No, 2, No, 4, 3, 10, No, No, 7, 7, No, No, No, 2,
                                 No, 2, 8, 8, No, No, No, 2, No, 4, No, 5, 8, 4, No, No, No, 9, No, 4, No, 10, No, 4,
                                 No, 5, No, 5, No, 1, No, 5, No, 8, No, 5, No, 5, No, 1, No, 10, No, 9, No, 10, No, 2,
                                 No, 7, 5, 9, No, No, No, 6, 4, 6, No, No, No, 2, No, 10, No, 1, 4, 3, No, No, 7, 8, No,
                                 No, No, 3, No, 3, No, 8, No, 10, No, 6, 6, 10, No, No, No, 1, 8, 5, No, No, 1, 3, No,
                                 No, No, 8, No, 9, No, 10, No, 8, 4, 9, No, No, 10, 1, No, No, No, 2, No, 8, 5, 2, No,
                                 No, 8, 6, No, No, No, 4, No, 7, 10, 1, No, No, No, 3, 3, 3, No, No, No, 3, No, 5, 7, 3,
                                 No, No, 10, 9, No, No, No, 2, No, 8, No, 10, No, 7, No, 10, No, 3, 9, 10, No, No, No,
                                 6, 4, 9, No, No, 9, 3, No, No, No, 7, No, 2, No, 10, No, 10, No, 7, No, 4, 5, 7, No,
                                 No, 9, 8, No, No, No, 6, 3, 1, No, No, No, 9, No, 7, 4, 4, No, No, No, 6, No, 1, No, 9,
                                 No, 9, No, 3, 1, 1, No, No, 1, 8, No, No, No, 1, No, 2, No, 7, 4, 6, No, No, No, 1, No,
                                 3, No, 8, No, 10, No, 3, No, 10, No, 10, No, 10, No, 10, No, 10, No, 6, No, 7, No, 3,
                                 No, 9, No, 7, 5, 4, No, No, No, 5, No, 5, 1, 3, No, No, No, 6, 3, 4, No, No, No, 3, 2,
                                 10, No, No, 10, 5, No, No, No, 5, 9, 1, No, No, No, 8, No, 7, No, 9, 5, 3, No, No, No,
                                 2, No, 7, No, 10, No, 2, 9, 4, No, No, No, 4, 10, 10, No, No, No, 6, 2, 6, No, No, No,
                                 4, No, 5, No, 7, No, 7, No, 2, 4, 1, No, No, No, 7, No, 5, 8, 8, No, No, 3, 6, No, No,
                                 No, 1, No, 5, No, 8, 4, 6, No, No, No, 6, No, 9, No, 4, No, 4, No, 3, No, 2, 6, 9, No,
                                 No, No, 6, 6, 8, No, No, No, 7, No, 5, No, 5, No, 9, 4, 3, No, No, No, 10, 4, 6, No,
                                 No, No, 9, No, 3, No, 10, No, 9, No, 1, No, 6, No, 1, No, 4, No, 5, 5, 3, No, No, 7, 8,
                                 No, No, No, 6, No, 6, No, 5, 9, 4, No, No, No, 9, No, 7, No, 7, 7, 5, No, No, No, 7,
                                 No, 3, 8, 3, No, No, No, 1, 5, 4, No, No, No, 2, No, 3, No, 4, No, 5, 5, 6, No, No, No,
                                 2, No, 2, 7, 9, No, No, 9, 5, No, No, No, 9, No, 9, No, 8, 7, 6, No, No, No, 2, No, 9,
                                 No, 2, No, 7, 6, 4, No, No, No, 1, No, 7, No, 2, No, 7, No, 3, 9, 2, No, No, 4, 5, No,
                                 No, No, 3, No, 2, No, 8, 7, 8, No, No, 7, 7, No, No, No, 10, No, 9, 2, 7, No, No, 6, 3,
                                 No, No, No, 10, No, 5, No, 7, No, 9, No, 3, No, 1, No, 9, No, 2, 5, 2, No, No, No, 4,
                                 No, 8, No, 6, 10, 10, No, No, 10, 3, No, No, No, 3, No, 1, No, 3, No, 8, 3, 2, No, No,
                                 No, 5, 2, 8, No, No, 7, 5, No, No, 7, 7, No, No, No, 1, 6, 5, No, No, No, 2, No, 4, No,
                                 7, No, 5, No, 3, No, 7, No, 10, No, 10, No, 7, No, 9, No, 5, 5, 5, No, No, No, 9, No,
                                 4, No, 7, No, 6, No, 2, No, 3, No, 3, 8, 10, No, No, No, 1, No, 3, No, 6, No, 10, No,
                                 8, No, 6, 4, 5, No, No, No, 6, No, 3, No, 3, No, 8, 1, 3, No, No, 2, 3, No, No, No, 7,
                                 No, 10, No, 2, No, 10, No, 2, No, 7, No, 10, 6, 7, No, No, 3, 4, No, No, 6, 2, No, No,
                                 No, 9, No, 8, No, 7, No, 10, No, 9, 10, 1, No, No, No, 5, 1, 10, No, No, 10, 2, No, No,
                                 No, 2, 5, 8, No, No, No, 9, 8, 8, No, No, No, 8, No, 4, 1, 3, No, No, No, 4, No, 4, No,
                                 9, No, 4, 10, 7, No, No, 10, 4, No, No, 4, 5, No, No, 9, 2, No, No, 3, 7, No, No, 8, 7,
                                 No, No, No, 5, No, 10, No, 3, No, 8, No, 3, No, 5, 2, 9, No, No, No, 10, No, 3, No, 10,
                                 No, 7, 5, 1, No, No, 2, 4, No, No, No, 5, No, 2, No, 6, No, 8, No, 9, No, 10, No, 9,
                                 No, 6, No, 2, 6, 7, No, No, 2, 7, No, No, No, 3, No, 6, 9, 5, No, No, 2, 6, No, No, No,
                                 8, No, 4, No, 8, No, 2, 4, 9, No, No, 4, 7, No, No, No, 9, No, 5, No, 3, No, 8, No, 6,
                                 No, 5, 7, 4, No, No, 8, 7, No, No, No, 9, 1, 2, No, No, No, 9, 6, 7, No, No, No, 8, No,
                                 6, No, 6, 4, 6, No, No, No, 3, No, 5, 10, 4, No, No, No, 5, No, 8, No, 8, No, 7, No,
                                 10, 5, 10, No, No, No, 10, No, 10, No, 10, 8, 2, No, No, 5, 3, No, No, No, 8, 6, 6, No,
                                 No, 10, 8, No, No, 1, 8, No, No, No, 9, 1, 6, No, No, 7, 6, No, No, No, 10, 5, 4, No,
                                 No, No, 10, 5, 4, No, No, 2, 5, No, No, No, 4, 2, 5, No, No, No, 3, No, 4, 2, 8, No,
                                 No, No, 5, No, 9, No, 3, 9, 3, No, No, No, 5, No, 7, No, 7, No, 5, No, 10, No, 3, 2, 7,
                                 No, No, 3, 8, No, No, No, 10, 2, 3, No, No, No, 7, 3, 3, No, No, No, 6, No, 4, No, 8,
                                 No, 3, No, 3, No, 1, No, 9, 10, 1, No, No, No, 1, No, 6, 6, 5, No, No, 6, 3, No, No,
                                 No, 6, No, 4, No, 2, No, 10, No, 9, 2, 5, No, No, No, 10, No, 10, 3, 5, No, No, 10, 6,
                                 No, No, 1, 9, No, No, 6, 7, No, No, 6, 5, No, No, No, 8, No, 8, 5, 6, No, No, No, 6,
                                 No, 8, No, 8, No, 4, No, 6, No, 9, No, 2, No, 1, No, 10, No, 9, No, 9, No, 4, 1, 6, No,
                                 No, No, 1, No, 3, No, 4, 10, 8, No, No, No, 7, No, 5, No, 10, No, 1, No, 9, No, 9, No,
                                 9, 1, 8, No, No, No, 1, No, 9, 5, 1, No, No, 7, 1, No, No, No, 8, No, 1, 8, 6, No, No,
                                 2, 9, No, No, 10, 5, No, No, No, 2, No, 10, No, 10, No, 9, No, 10, No, 7, No, 7, No, 5,
                                 No, 8, 8, 2, No, No, No, 9, No, 10, No, 1, No, 1, No, 1, No, 10, 6, 1, No, No, No, 9,
                                 No, 2, 9, 9, No, No, No, 9, 3, 8, No, No, No, 1, No, 10, 1, 10, No, No, No, 8, No, 7,
                                 No, 8, No, 8, 6, 5, No, No, 2, 5, No, No, No, 7, No, 1, No, 10, No, 4, 8, 5, No, No, 5,
                                 2, No, No, 2, 3, No, No, No, 6, 3, 10, No, No, 1, 8, No, No, No, 9, No, 8, 7, 10, No,
                                 No, No, 10, No, 5, 10, 6, No, No, No, 5, No, 6, No, 5, 6, 6, No, No, 5, 8, No, No, No,
                                 7, No, 8, No, 10, 1, 1, No, No, No, 10, 1, 2, No, No, 9, 5, No, No, No, 7, 4, 5, No,
                                 No, No, 10, No, 3, No, 5, No, 8, No, 2, No, 9, No, 9, 6, 7, No, No, 7, 1, No, No, No,
                                 5, No, 2, No, 8, 5, 3, No, No, No, 7, No, 6, No, 6, No, 7, No, 5, No, 1, 6, 7, No, No,
                                 No, 6, No, 8, No, 8, No, 5, 10, 10, No, No, No, 10, 5, 2, No, No, 6, 5, No, No, 8, 1,
                                 No, No, 2, 3, No, No, 9, 3, No, No, 10, 7, No, No, 1, 4, No, No, 5, 10, No, No, No, 7,
                                 No, 6, No, 1, No, 9, No, 8, No, 2, 10, 7, No, No, No, 5, 3, 9, No, No, No, 2, No, 7,
                                 No, 3, No, 7, No, 7, 9, 2, No, No, No, 5, No, 6, 1, 2, No, No, 5, 10, No, No, 6, 9, No,
                                 No, No, 10, 9, 8, No, No, 5, 9, No, No, No, 10, 5, 6, No, No, No, 10, 10, 1, No, No,
                                 No, 7, No, 10, No, 3, No, 2, No, 6, 9, 9, No, No, 2, 5, No, No, No, 1, No, 8, No, 2,
                                 No, 4, 2, 9, No, No, No, 10, No, 6, No, 5, 2, 3, No, No, No, 1, No, 7, No, 10, 6, 10,
                                 No, No, No, 2, 5, 9, No, No, 4, 7, No, No, No, 2, 1, 1, No, No, No, 9, No, 5, 7, 7, No,
                                 No, No, 3, No, 4, No, 10, 2, 6, No, No, 8, 6, No, No, 1, 10, No, No, No, 10, 4, 4, No,
                                 No, No, 7, No, 8, 7, 5, No, No, No, 2, 10, 6, No, No, 3, 6, No, No, No, 10, No, 8, No,
                                 8, 8, 9, No, No, No, 7, No, 8, No, 1, No, 5, No, 8, No, 7, 10, 6, No, No, No, 3, No, 5,
                                 No, 6, 9, 10, No, No, No, 10, No, 6, No, 2, No, 2, No, 2, No, 9, No, 7, No, 4, 5, 9,
                                 No, No, No, 4, No, 4, No, 3, No, 10, No, 3, 10, 3, No, No, 5, 7, No, No, No, 6, No, 3,
                                 3, 4, No, No, No, 7, No, 6, No, 10, No, 5, 8, 8, No, No, No, 4, 5, 5, No, No, No, 2,
                                 No, 10, No, 2, No, 1, 2, 8, No, No, No, 5, No, 8, No, 3, No, 4, No, 8, No, 1, No, 5, 8,
                                 1, No, No, 3, 9, No, No, No, 3, 1, 1, No, No, 5, 9, No, No, No, 6, No, 9, 5, 6, No, No,
                                 No, 5, 3, 5, No, No, No, 9, 3, 1, No, No, 3, 5, No, No, 3, 10, No, No, No, 10, No, 8,
                                 No, 1, No, 7, No, 4, No, 1, No, 7, No, 1, No, 3, 7, 9, No, No, 1, 2, No, No, No, 8, 3,
                                 7, No, No, No, 8, No, 1, 6, 6, No, No, No, 9, 7, 4, No, No, 6, 10, No, No, 4, 5, No,
                                 No, No, 1, No, 7, No, 6, 7, 3, No, No, No, 6, No, 9, No, 8, 2, 6, No, No, 6, 8, No, No,
                                 2, 7, No, No, No, 8, No, 8, 7, 5, No, No, No, 4, No, 9, 5, 3, No, No, 9, 5, No, No, No,
                                 5, No, 1, No, 5, No, 6, 8, 6, No, No, No, 5, No, 4, No, 2, 8, 5, No, No, No, 9, No, 5,
                                 No, 9, No, 3, No, 5, 9, 3, No, No, No, 2, No, 7, No, 8, No, 8, No, 8, No, 10, 7, 2, No,
                                 No, No, 6, No, 2, 1, 10, No, No, No, 6, No, 8, No, 4, No, 6, 8, 5, No, No, No, 3, No,
                                 1, No, 6, No, 6, No, 2, No, 9, 1, 9, No, No, No, 3, No, 7, 4, 7, No, No, 9, 6, No, No,
                                 7, 8, No, No, No, 1, 5, 1, No, No, 7, 10, No, No, No, 6, No, 8, 3, 2, No, No, 1, 5, No,
                                 No, No, 8, No, 3, No, 3, 9, 1, No, No, No, 8, No, 1, 3, 5, No, No, No, 9, No, 8, 3, 4,
                                 No, No, No, 9, No, 1, No, 3, No, 7, No, 3, 5, 1, No, No, No, 4, No, 1, No, 5, No, 1,
                                 No, 3, 4, 8, No, No, No, 1, 10, 7, No, No, No, 1, No, 9, No, 7, No, 3, No, 10, 6, 9,
                                 No, No, No, 3, 6, 8, No, No, No, 8, No, 3, No, 4, No, 10, No, 2, 10, 7, No, No, 5, 4,
                                 No, No, No, 4, 2, 6, No, No, 1, 10, No, No, No, 4, 3, 7, No, No, No, 4, No, 1, No, 6,
                                 No, 10, No, 7, 4, 9, No, No, No, 10, 9, 4, No, No, No, 6, 5, 9, No, No, No, 7, 1, 7,
                                 No, No, No, 4, No, 4, No, 4, No, 6, 4, 3, No, No, No, 4, No, 5, No, 10, No, 2, No, 1,
                                 No, 1, No, 2, No, 2, 9, 4, No, No, No, 9, No, 9, 9, 4, No, No, No, 5, No, 6, No, 2, No,
                                 3, No, 10, 9, 10, No, No, 10, 2, No, No, 3, 9, No, No, No, 9, No, 10, No, 9, No, 3, No,
                                 1, 5, 6, No, No, No, 6, No, 2, No, 9, No, 3, No, 9, 9, 3, No, No, 5, 3, No, No, No, 2,
                                 No, 3, No, 8, No, 2, No, 9, No, 3, No, 4, No, 3, No, 4, No, 8, 6, 7, No, No, No, 6, No,
                                 3, No, 1, No, 9, 5, 1, No, No, No, 2, No, 7, 4, 7, No, No, No, 2, No, 9, No, 7, No, 10,
                                 No, 6, No, 7, No, 1, No, 4, No, 5, No, 2, No, 7, No, 3, No, 7, No, 4, No, 5, No, 10,
                                 No, 1, No, 9, 9, 8, No, No, 10, 10, No, No, No, 6, 6, 10, No, No, 10, 4, No, No, 4, 6,
                                 No, No, No, 4, No, 3, No, 5, 4, 8, No, No, No, 5, 6, 3, No, No, 1, 7, No, No, 9, 4, No,
                                 No, No, 9, 10, 2, No, No, No, 5, No, 6, 2, 5, No, No, No, 10, 5, 1, No, No, No, 8, 2,
                                 2, No, No, 7, 6, No, No, No, 9, No, 4, No, 4, No, 2, No, 4, No, 8, 1, 10, No, No, No,
                                 8, No, 3, No, 1, No, 5, No, 2, No, 9, 8, 5, No, No, 8, 6, No, No, No, 1, No, 6, No, 2,
                                 2, 9, No, No, No, 9, 5, 7, No, No, No, 4, No, 5, 4, 5, No, No, 1, 1, No, No, 8, 3, No,
                                 No, No, 10, 7, 10, No, No, 6, 5, No, No, 6, 3, No, No, 4, 1, No, No, 10, 1, No, No, 4,
                                 2, No, No, 6, 3, No, No, No, 2, No, 9, No, 10, 9, 9, No, No, No, 2, No, 8, No, 8, 6, 2,
                                 No, No, 10, 7, No, No, No, 10, 1, 3, No, No, 2, 3, No, No, No, 10, 3, 1, No, No, No, 9,
                                 No, 4, No, 3, No, 4, No, 7, No, 2, No, 1, No, 9, No, 1, No, 7, No, 9, No, 7, No, 6, 7,
                                 9, No, No, No, 10, No, 6, 3, 2, No, No, No, 4, No, 4, No, 5, 4, 1, No, No, No, 3, No,
                                 3, No, 6, No, 5, No, 4, 10, 5, No, No, 4, 6, No, No, 10, 4, No, No, No, 7, No, 10, No,
                                 1, No, 1, 5, 6, No, No, 9, 7, No, No, No, 3, No, 6, No, 8, No, 2, No, 4, No, 2, No, 7,
                                 No, 8, 3, 10, No, No, No, 6, No, 3, No, 7, No, 4, 2, 3, No, No, 1, 9, No, No, 5, 6, No,
                                 No, 6, 6, No, No, No, 7, No, 8, 9, 9, No, No, No, 9, No, 1, No, 9, No, 5, No, 1, No, 5,
                                 2, 6, No, No, No, 9, 2, 4, No, No, 3, 6, No, No, 4, 2, No, No, No, 9, No, 6, 3, 3, No,
                                 No, No, 7, No, 9, No, 6, 2, 9, No, No, No, 8, No, 5, No, 4, No, 7, No, 4, No, 8, No, 5,
                                 3, 2, No, No, No, 1, No, 1, No, 1, No, 1, No, 1, No, 1, No, 4, No, 6, 3, 7, No, No, 9,
                                 7, No, No, 9, 2, No, No, No, 4, No, 1, No, 5, No, 8, No, 2, 10, 1, No, No, No, 10, No,
                                 1, 2, 7, No, No, No, 5, No, 8, No, 7, 2, 6, No, No, No, 10, No, 3, No, 7, No, 3, No, 6,
                                 9, 4, No, No, No, 2, No, 8, No, 8, No, 1, No, 8, No, 8, No, 9, No, 7, No, 5, 10, 9, No,
                                 No, 4, 4, No, No, No, 7, No, 6, No, 8, 1, 3, No, No, 9, 3, No, No, 1, 10, No, No, No,
                                 9, 8, 2, No, No, No, 8, No, 4, No, 4, 4, 1, No, No, No, 7, No, 8, 1, 9, No, No, No, 10,
                                 No, 3, 6, 7, No, No, No, 5, 5, 2, No, No, No, 4, No, 5, 6, 6, No, No, 7, 7, No, No, 5,
                                 10, No, No, No, 6, 10, 6, No, No, No, 2, No, 5, 2, 5, No, No, No, 7, No, 7, No, 7, No,
                                 4, No, 9, No, 4, No, 8, No, 1, No, 5, No, 9, 6, 4, No, No, No, 8, 9, 2, No, No, 10, 2,
                                 No, No, No, 3, No, 4, No, 10, No, 6, No, 10, 2, 9, No, No, 6, 1, No, No, No, 7, 6, 6,
                                 No, No, No, 2, No, 4, No, 10, 8, 9, No, No, No, 7, 3, 9, No, No, 10, 4, No, No, No, 10,
                                 No, 6, No, 2, No, 5, No, 1, No, 8, 8, 3, No, No, No, 2, 5, 10, No, No, 5, 8, No, No, 3,
                                 10, No, No, No, 5, No, 8, No, 5, No, 4, No, 5, 6, 2, No, No, No, 7, No, 5, No, 10, No,
                                 8, 1, 5, No, No, No, 1, No, 1, No, 5, No, 9, No, 6, No, 1, No, 5};
        vector<ListNode *> list1 = ListNode::numToList(list_num1);
        vector<TreeNode *> tree1 = TreeNode::numToTree(tree_num1_2_3);
        vector<ListNode *> list2 = ListNode::numToList(list_num2);
        vector<TreeNode *> tree2 = TreeNode::numToTree(tree_num1_2_3);
        vector<ListNode *> list3 = ListNode::numToList(list_num3);
        vector<TreeNode *> tree3 = TreeNode::numToTree(tree_num1_2_3);
        vector<ListNode *> list4 = ListNode::numToList(list_num4);
        vector<TreeNode *> tree4 = TreeNode::numToTree(tree_num4);
        std::cout << "normal test 1" << std::endl;
        assert(1 == isSubPath(list1[0], tree1[0]));
        std::cout << "normal test 2" << std::endl;
        assert(1 == isSubPath(list2[0], tree2[0]));
        std::cout << "normal test 3" << std::endl;
        assert(0 == isSubPath(list3[0], tree3[0]));
        std::cout << "complex test 1" << std::endl;
        assert(0 == isSubPath(list4[0], tree4[0]));
        for (auto &i : list1) {
            delete i;
        }
        for (auto &i : tree1) {
            delete i;
        }
        for (auto &i : list2) {
            delete i;
        }
        for (auto &i : tree2) {
            delete i;
        }
        for (auto &i : list3) {
            delete i;
        }
        for (auto &i : tree3) {
            delete i;
        }
        for (auto &i : list4) {
            delete i;
        }
        for (auto &i : tree4) {
            delete i;
        }
    }
};
/*
Runtime: 24 ms,
Memory Usage: 23.9 MB,
100%,100%.
*/
#endif