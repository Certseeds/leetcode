#pragma once
#ifndef _LEETCODE_700_H
#define _LEETCODE_700_H
#include <string>
using namespace std;


class Solution700 {
public:

   struct TreeNode700 {
       int val;
       TreeNode700 *left;
       TreeNode700 *right;
       TreeNode700(int x) : val(x), left(NULL), right(NULL) {}
 };
 
	TreeNode700* searchBST(TreeNode700* root, int val) {
		if (root == nullptr)
		{
			return nullptr;
		}
		else if (root->val == val)
		{
			return root;
		}
		else if (root->val > val)
		{
			return (searchBST(root->left, val));
		}
		return (searchBST(root->right, val));
	}
};

#endif
