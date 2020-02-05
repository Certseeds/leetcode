#pragma once
#ifndef _LEETCODE_94_H_
#define _LEETCODE_94_H_
#include <vector>
#include <algorithm>
#include "TreeNode.h"
using namespace std;
class Solution94 {
public:
    void test() {
        vector<int> nums = { 1,2,3,No,No,4,5 };
        vector<TreeNode*> vec1 = TreeNode::numToTree(nums);
        cout << vec1[0]->val << endl;
        cout << vec1[0]->left->val << endl;
        cout << vec1[0]->right->val << endl;
        cout << vec1[0]->right->left->val << endl;
        cout << vec1[0]->right->right->val << endl;
    }
};

#endif
