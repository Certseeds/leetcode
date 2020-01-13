#pragma once
#ifndef _LEETCODE_1302_H
#define _LEETCODE_1302_H
#include "TreeNode.h"
#include <vector>
//#include <set>
using namespace std;
/*Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.
*/
class Solution1302 {
public:
	int deepestLeavesSum(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		int maxv = INT16_MIN;
		int willreturn = 0;
		root->val = root->val << 14;
		//vector<TreeNode*> trees;
		stack<TreeNode*> tree;
		tree.push(root);
		while (!tree.empty()) {
			TreeNode* begin = tree.top();
			tree.pop();
			cout << begin->val << " " << maxv  << " "<<((begin->val) & 0x00003FFF )<<endl;
			//trees.push_back(begin);
			if (maxv < ((begin->val) & 0x00003FFF) && maxv>0) {
				willreturn = (begin->val)>>14;
			}
			else if (maxv == ((begin->val) & 0x00003FFF) && maxv > 0) {
				willreturn += (begin->val)>>14;
			}
			maxv = max(maxv, ((begin->val)&0x00003FFF) );

			if (begin->left != nullptr) {
				begin->left->val = begin->left->val << 14;
				begin->left->val += (((begin->val) & 0x00003FFF) +1);
				tree.push(begin->left);
			}
			if (begin->right != nullptr) {
				begin->right->val = begin->right->val << 14;
				begin->right->val += (((begin->val) & 0x00003FFF) + 1);
				tree.push(begin->right);
			}
		}
		return willreturn;
	}
	int deepestLeavesSum2(TreeNode* root) {
		if (root == nullptr) {
			return 0;
		}
		return get_sum(root, get_depth(root), 1);
	}
	int get_depth(TreeNode* root) {
		if (root == nullptr ) {
			return 0;
		}
		return 1 + max(get_depth(root->left), get_depth(root->right));
	}
	int get_sum(TreeNode* root, int depth,int highth) {
		if (root == nullptr) {
			return 0;
		}
		else if (depth == highth) {
			return root->val;
		}
		return (get_sum(root->left, depth, highth + 1) +
			get_sum(root->right, depth, highth + 1));
	}
	void test() {
		vector<TreeNode*> tree;
		for (int i = 1; i <= 8; i++) {
			TreeNode* temp = new TreeNode(i);
			tree.push_back(temp);
		}
		tree[0]->left = tree[1];
		tree[0]->right = tree[2];
		tree[1]->left = tree[3];
		tree[1]->right = tree[4];
		tree[3]->left = tree[6];
		tree[2]->right = tree[5];
		tree[5]->right = tree[7];
		cout << deepestLeavesSum2(tree[0]) << endl;
		for (int i = 0; i < 8; i++) {
			delete tree[i];
		}
	}
};

#endif
