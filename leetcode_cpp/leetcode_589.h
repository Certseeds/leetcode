#pragma once
#ifndef _LEETCODE_589_H
#define _LEETCODE_589_H
#include <vector>
using namespace std;

class Node589 {
public:
	int val;
	vector<Node589*> children;
	Node589() {}
	Node589(int _val, vector<Node589*> _children) {
		val = _val;
		children = _children;
	}
};
class Solution589 {
public:
	vector<int> preorder(Node589* root) {
		vector <int> vec;
		real_action(root, vec);
		return vec;
	}
	void real_action(Node589 * root, vector<int> & vec) {
		if (root == nullptr)
		{
			return;
		}
		vec.push_back(root->val);
		for (int i = 0; i < root->children.size(); i++)
		{
			real_action(root->children[i], vec);
		}
	}
};

#endif

