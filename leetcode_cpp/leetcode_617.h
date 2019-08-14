#pragma once
#ifndef _LEETCODE_617_H
#define _LEETCODE_617_H
#include <string>
using namespace std;
 
 
class Solution617 {
public:
	struct TreeNode617 {
		int val;
		TreeNode617 *left;
		TreeNode617 *right;
		TreeNode617(int x) : val(x), left(NULL), right(NULL) {}
	};
	TreeNode617* mergeTrees(TreeNode617* t1, TreeNode617* t2) {
		if (t1 == nullptr && t2 == nullptr)
		{
			return nullptr;
		}
		else if (t1 != nullptr && t2 == nullptr) {
			return t1;
		}
		else if (t1 == nullptr && t2 != nullptr) {
			return t2;
		}
		TreeNode617 * willreturn = new TreeNode617(0);
		willreturn->left = nullptr;
		willreturn->right = nullptr;
		willreturn->val = returnValueOfNode(t1, t2);
		//cout << willreturn->val << endl;
		willreturn->left = mergeTrees(t1->left, t2->left);
		willreturn->right = mergeTrees(t1->right, t2->right);
		
		return willreturn;
	}
	int returnValueOfNode(TreeNode617* t1, TreeNode617* t2) {
		int willreturn = 0;
		if (t1 != nullptr)
		{
			willreturn += t1->val;
		}
		if (t2 != nullptr)
		{
			willreturn += t2->val;
		}
		return willreturn;
	}
};

#endif
