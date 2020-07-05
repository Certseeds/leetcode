/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-23 11:08:58
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-23 12:30:34
 */
#ifndef _LEETCODE_1361_H_
#define _LEETCODE_1361_H_

#include <queue>
#include <vector>
#include <algorithm>
#include "TreeNode.h"

using std::cout;
using std::endl;
using std::queue;
using std::vector;

/*
You have n binary tree nodes numbered from 0 to n - 1 
where node i has two children leftChild[i] and rightChild[i], 
return true if and only if all the given nodes form exactly one valid binary tree.

If node i has no left child then leftChild[i] will equal -1, 
similarly for the right child.

Note that the nodes have no values and 
that we only use the node numbers in this problem.

Example 1:
Input: n = 4, 
leftChild = [1,-1,3,-1], 
rightChild = [2,-1,-1,-1]
Output: true

Example 2:
Input: n = 4, 
leftChild = [1,-1,3,-1],
rightChild = [2,3,-1,-1]
Output: false

Example 3:
Input: n = 2,
leftChild = [1,0],
rightChild = [-1,-1]
Output: false

Example 4:
Input: n = 6, 
leftChild = [1,-1,-1,4,-1,-1],
rightChild = [2,-1,-1,5,-1,-1]
Output: false

Constraints:
1 <= n <= 10^4
leftChild.length == rightChild.length == n
-1 <= leftChild[i], rightChild[i] <= n - 1
11:09-11:20
*/
class Solution1361 {
public:
    bool validateBinaryTreeNodes(int n, vector<int> &leftChild, vector<int> &rightChild) {
        vector<TreeNode *> nodes(n, nullptr);
        for (int i = 0; i < n; i++) {
            nodes[i] = new TreeNode(i);
        }
        for (int i = 0; i < n; i++) {
            if (leftChild[i] != -1) {
                nodes[i]->left = nodes[leftChild[i]];
            }
            if (rightChild[i] != -1) {
                nodes[i]->right = nodes[rightChild[i]];
            }
        }
        bool will_return = false;
        if (true == binary_tree_judge(nodes[0], n)) {
            will_return = true;
        }
        for (auto &i : nodes) {
            delete i;
        }
        return will_return;
    }

    bool binary_tree_judge(TreeNode *root, int number) {
        //���ճ������һ��,���������нڵ�,����û��һ���ڵ㱻��������
        vector<int> nums(number, 0);
        int count = 0;
        queue<TreeNode *> que;
        que.push(root);
        while (!que.empty()) {
            //cout << count << " " << (count > number) <<endl;
            TreeNode *head = que.front();
            que.pop();
            if (count > number) {
                return false;
            }
            if (head == nullptr) {
                continue;
            }
            count++;
            nums[head->val]++;
            que.push(head->left);
            que.push(head->right);
        }
        for (auto i : nums) {
            if (0 == i) {
                return false;
            }
        }
        return true;
    }

    void test() {
        vector<int> left1 = {1, -1, 3, -1};
        vector<int> right1 = {2, -1, -1, -1};

        vector<int> right2 = {2, 3, -1, -1};

        vector<int> left3 = {1, 0};
        vector<int> right3 = {-1, -1};

        vector<int> left4 = {1, -1, -1, 4, -1, -1};
        vector<int> right4 = {2, -1, -1, 5, -1, -1};
        cout << "true binary tree test" << endl;
        assert(1 == validateBinaryTreeNodes(4, left1, right1));
        cout << "same son node test" << endl;
        assert(0 == validateBinaryTreeNodes(4, left1, right2));
        cout << "unlimited rec test" << endl;
        assert(0 == validateBinaryTreeNodes(2, left3, right3));
        cout << "broken tree test" << endl;
        assert(0 == validateBinaryTreeNodes(6, left4, right4));
    }
};
/*
Runtime: 24 ms,
Memory Usage: 22 MB,
100%,100%.
*/
#endif
