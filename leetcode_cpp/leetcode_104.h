#pragma once
#ifndef _LEETCODE_104_H
#define _LEETCODE_104_H
#include <stack>
#include "TreeNode.h"
using namespace std;
/*Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.
*/
class Solution104 {
public:
	int maxDepth(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		root->val = 1;
		int willreturn = 0;
		stack<TreeNode*> tree;
		tree.push(root);
		while (!tree.empty()) {
			TreeNode* begin = tree.top();
			tree.pop();
			if (begin->left == nullptr && begin->right == nullptr) {
				willreturn = max(willreturn, begin->val);
				continue;
			}
			if (begin->left != nullptr) {
				begin->left->val = begin->val + 1;
				tree.push(begin->left);
			}
			if (begin->right != nullptr) {
				begin->right->val = begin->val + 1;
				tree.push(begin->right);
			}
		}
		return willreturn;
	}
	void test() {
		vector<TreeNode*> tree;
		for (int i = 1; i <= 7; i++) {
			TreeNode* temp = new TreeNode(i % 2);
			tree.push_back(temp);
		}
		tree[0]->left = tree[1];
		tree[0]->right = tree[2];
		tree[1]->left = tree[3];
		tree[1]->right = tree[4];
		tree[2]->left = tree[5];
		tree[2]->right = tree[6];
		cout << maxDepth(tree[0]) << endl;
		for (int i = 0; i < 7; i++) {
			delete tree[i];
		}
	}
};

#endif
