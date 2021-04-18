#pragma once
#ifndef _LEETCODE_559_H
#define _LEETCODE_559_H

#include <vector>

using namespace std;

class Node559 {
public:
    int val;
    vector<Node559 *> children;

    Node559() {}

    Node559(int _val, vector<Node559 *> _children) {
        val = _val;
        children = _children;
    }
};

class Solution559 {
public:
    // choose 1 or 2(use 3);
    int maxDepth(Node559 *root) {
        if (root == nullptr)
            return 0;
        int maxvalue = 0;
        for (int32_t i{0}; i < root->children.size(); i++) {
            maxvalue = max(maxvalue, maxDepth(root->children[i]));
        }
        return maxvalue + 1;
    }

    int maxDepth2(Node559 *root) {
        if (root == nullptr)
            return 0;
        return maxDepth3(root, 1);
    }

    int maxDepth3(Node559 *root, int depth) {
        if (!(root->children.size()))
            return depth;
        int x = depth;
        for (int32_t i{0}; i < root->children.size(); i++) {
            int nextDepth = maxDepth3(root->children[i], depth + 1);
            x = x > nextDepth ? x : nextDepth;
            x = max(x, nextDepth);
        }
        return x;
    }
};

#endif

