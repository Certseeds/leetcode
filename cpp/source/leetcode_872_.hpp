#pragma once
#ifndef _LEETCODE_872_H
#define _LEETCODE_872_H

#include <vector>
#include <algorithm>
#include <stack>

using namespace std;

struct TreeNode872 {
    int val;
    TreeNode872 *left;
    TreeNode872 *right;

    TreeNode872(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution872 {
public:
    bool leafSimilar(TreeNode872 *root1, TreeNode872 *root2) {
        if (root1 == nullptr && root2 == nullptr) {
            return true;
        } else if (root1 == nullptr || root2 == nullptr) {
            return false;
        }
        vector<int> val1 = getNode(root1);
        vector<int> val2 = getNode(root2);
        if (val1.size() != val2.size()) {
            return false;
        }
        for (int32_t i{0}; i < val1.size(); i++) {
            if (val1[i] != val2[i]) {
                return false;
            }
        }
        return true;
    }

    vector<int> getNode(TreeNode872 *root) {
        vector<int> willreturn;
        stack<TreeNode872 *> ques;
        ques.push(root);
        while (!ques.empty()) {

            TreeNode872 *rootnode = ques.top();
            ques.pop();
            //cout << rootnode->val << "?" << endl;
            if (rootnode->left != nullptr) {
                ques.push(rootnode->left);
            }
            if (rootnode->right != nullptr) {
                ques.push(rootnode->right);
            }
            if (rootnode->left == nullptr && rootnode->right == nullptr) {
                willreturn.push_back(rootnode->val);
            }
        }
        return willreturn;
    }

    void test() {
        cout << "test begin" << endl;
        vector<TreeNode872 *> arr1;
        vector<TreeNode872 *> arr2;
        for (int32_t i{0}; i < 10; i++) {
            TreeNode872 *temp = new TreeNode872(i);
            TreeNode872 *temp2 = new TreeNode872(i);
            arr1.push_back(temp);
            arr2.push_back(temp2);
        }
        arr1[3]->left = arr1[5];
        arr1[3]->right = arr1[1];
        arr1[5]->left = arr1[6];
        arr1[5]->right = arr1[2];
        arr1[1]->left = arr1[9];
        arr1[1]->right = arr1[8];
        arr1[2]->left = arr1[7];
        arr1[2]->right = arr1[4];

        arr2[3]->left = arr2[5];
        arr2[3]->right = arr2[1];
        arr2[5]->left = arr2[6];
        arr2[5]->right = arr2[7];
        arr2[1]->left = arr2[4];
        arr2[1]->right = arr2[2];
        arr2[2]->left = arr2[9];
        arr2[2]->right = arr2[8];
        vector<int> val1 = getNode(arr1[3]);
        vector<int> val2 = getNode(arr2[3]);
        for (auto i : val1) {
            cout << i << endl;
        }
        cout << "middle" << endl;
        for (auto i : val2) {
            cout << i << endl;
        }
        bool judge = true;
        for (int32_t i{0}; i < val1.size(); i++) {
            judge = judge & (val1[i] == val2[i]);
        }
        cout << ((judge == 1) ? "true" : "false") << endl;
        for (int32_t i{0}; i < 10; i++) {
            delete arr1[i];
            delete arr2[i];
        }
    }

};

#endif
