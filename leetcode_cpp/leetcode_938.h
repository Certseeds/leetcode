#pragma once
#ifndef LEETCODE_938_H
#define LEETCODE_938_H

using namespace std;
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};
class Solution938 {
public:
	int rangeSumBST(TreeNode* root, int L, int R) {
		if (root == nullptr)
			return 0;
		int willreturn = 0;
		willreturn += ((root->val >= L) && (root->val <= R)) ? root->val : 0;
		if (root->val >= R)
		{
			willreturn += rangeSumBST(root->left, L, R);
		}
		else if (root->val > L && root->val < R) {
			willreturn += rangeSumBST(root->left, L, R);
			willreturn += rangeSumBST(root->right, L, R);
		}
		else {
			willreturn += rangeSumBST(root->right, L, R);
		}
		//out << root->val << " " << willreturn << endl;
		return willreturn;
	}
};


#endif