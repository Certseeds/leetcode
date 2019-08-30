#pragma once
#ifndef _LEETCODE_897_H
#define _LEETCODE_897_H
#include <string>
#include <queue>
using namespace std;

struct TreeNode897 {
	int val;
	TreeNode897 *left;
	TreeNode897 *right;
	TreeNode897(int x) : val(x), left(NULL), right(NULL) {}

};

class Solution897 {
public:
	 TreeNode897* increasingBST(TreeNode897* root) {
		queue <int> pq;
		rev(root, pq);
		TreeNode897 * rooted = new TreeNode897(pq.front());
		pq.pop();
		getSon(rooted,pq);
		return rooted;
	}
	void  rev(TreeNode897* root, queue <int> & pq) {
		if (root  == nullptr)
			return;
		rev(root->left, pq);
        pq.push(root->val);
		rev(root->right, pq);
	}
	void getSon(TreeNode897 * root, queue <int>& pq) {
		if (!pq.size())
			return;
		root->right = new TreeNode897(pq.front());
		pq.pop();
		getSon(root->right, pq);
	}
};

#endif
