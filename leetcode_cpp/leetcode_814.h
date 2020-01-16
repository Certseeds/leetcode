#pragma once
#ifndef _LEETCODE_814_H_
#define _LEETCODE_814_H_
#include <vector>
#include "TreeNode.h"
#include <algorithm>
using namespace std;
/*
Given a directed, acyclic graph of N nodes.
Find all possible paths from node 0 to node N-1,
and return them in any order.
The graph is given as follows:
the nodes are 0, 1, ..., graph.length - 1.
graph[i] is a list of all nodes j for which the edge (i, j) exists.
-->
find all paths in directed, acyclic graph from A to B.
*/
class Solution814 {
public:
	TreeNode* pruneTree(TreeNode* root) {
		return pruneTree_rec(root);
	}
	TreeNode* pruneTree_rec(TreeNode* root) {
		if (root == nullptr) {
			return nullptr;
		}
		root->left = pruneTree_rec(root->left);
		root->right = pruneTree_rec(root->right);
		if (root->left == nullptr && root->right == nullptr&&root->val == 0) {
			return nullptr;
		}
		return root;
	}
	void test() {
		vector<TreeNode*> tree;
		for (int i = 0; i <= 8; i++) {
			TreeNode* temp = new TreeNode(i%2);
			tree.push_back(temp);
		}
		tree[1]->right = tree[2];
		tree[2]->left = tree[4];
		tree[2]->right = tree[3];
		tree[1] = pruneTree_rec(tree[1]);
		cout << tree[1]->val << " " << tree[1]->right->val << " " << tree[1]->right->right->val << endl;
		cout << (tree[1]->left == nullptr) << " " << (tree[1]->right->left == nullptr) << endl;
		for (int i = 0; i <= 8; i++) {;
			delete tree[i];
		}
	}
};
/*
Runtime: 0 ms,
Memory Usage: 11.3 MB,
100%,7.14%.
*/
#endif
