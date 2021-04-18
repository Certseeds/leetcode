#pragma once
#ifndef _LEETCODE_590_H
#define _LEETCODE_590_H

#include <vector>

using namespace std;

class Node590 {
public:
    int val;
    vector<Node590 *> children;

    Node590() {}

    Node590(int _val, vector<Node590 *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution590 {
public:
    vector<int> postorder(Node590 *root) {
        vector<int> vec;
        real_action(root, vec);
        return vec;
    }

    void real_action(Node590 *root, vector<int> &vec) {
        if (root == nullptr) {
            return;
        }
        for (int32_t i{0}; i < root->children.size(); i++) {
            real_action(root->children[i], vec);
        }
        vec.push_back(root->val);
    }
};

#endif
