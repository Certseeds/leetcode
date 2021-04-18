#pragma once
#ifndef _LEETCODE_654_H_
#define _LEETCODE_654_H_

#include <vector>
#include <queue>
#ifdef __LOCAL__
#include "TreeNode.h"
#endif

using namespace std;

/*
Given the root node of a binary search tree (BST)
and a value to be inserted into the tree,
insert the value into the BST.
Return the root node of the BST after the insertion.
It is guaranteed that the new value does not exist in the original BST.
Note that there may exist multiple valid ways for the insertion,
as long as the tree remains a BST after insertion. You can return any of them.
*/
class Solution654 {
public:
    TreeNode *constructMaximumBinaryTree(vector<int> &nums) {
        return rec(nums, 0, nums.size());
    }

    TreeNode *rec(vector<int> &nums, int begin, int end) {
        //cout << begin << " " << end << endl;
        if (begin == end) {
            return nullptr;
        }
        int posi = get_max(nums, begin, end);
        cout << nums[posi] << ":" << posi << endl;
        TreeNode *willreturn = new TreeNode(nums[posi]);
        //if (begin != posi) {
        willreturn->left = rec(nums, begin, posi);
        //}
        //if (posi + 1 != end) {
        willreturn->right = rec(nums, posi + 1, end);
        //}
        return willreturn;
    }

    inline int get_max(vector<int> &nums, int begin, int end) {
        int maxv = INT16_MIN;
        int posi = 0;
        for (int i = begin; i < end; i++) {
            if (maxv < nums[i]) {
                maxv = nums[i];
                posi = i;
            }
        }
        return posi;
    }

    TreeNode *constructMaximumBinaryTree2(vector<int> &nums) {
        stack < TreeNode * > nodes;
        for (int32_t i{0}; i < nums.size(); i++) {
            TreeNode *temp = new TreeNode(nums[i]);
            while (!nodes.empty() && nums[i] > nodes.top()->val) {
                temp->left = nodes.top();
                nodes.pop();
            }
            if (!nodes.empty()) {
                nodes.top()->right = temp;
            }
            nodes.push(temp);
        }
        while (nodes.size() != 1) {
            nodes.pop();
        }
        return nodes.top();
    }

    void test() {
        vector<int> vec1 = {3, 2, 1, 6, 0, 5};

        constructMaximumBinaryTree(vec1);
    }
};

#endif
