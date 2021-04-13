/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-13 09:41:59
 * @LastEditors: nanoseeds
 */
/*  leetcode
    Copyright (C) 2020-2021 nanoseeds

    leetcode is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    leetcode is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_783_H
#define LEETCODE_CPP_SOURCE_LEETCODE_783_H

#include <stack>
#include <vector>
#include "TreeNode.h"

// same with 530
namespace Solution783 {
using std::stack;
using std::vector;
class Solution783 {
public:
    int32_t minDiffInBST(TreeNode *root) {
        if (root == nullptr) {
            return std::numeric_limits<int32_t>::max();
        }
        auto *left = root->left;
        auto *right = root->right;
        while (left != nullptr && left->right != nullptr) {
            left = left->right;
        }
        while (right != nullptr && right->left != nullptr) {
            right = right->left;
        }
        int32_t left_son_diff{std::numeric_limits<int32_t>::max()}, right_son_diff{std::numeric_limits<int32_t>::max()};
        if (left != nullptr) {
            left_son_diff = root->val - left->val;
        }
        if (right != nullptr) {
            right_son_diff = right->val - root->val;
        }
        int32_t will_return = std::min(left_son_diff, right_son_diff);
        int32_t left_will_return = minDiffInBST(root->left);
        int32_t right_will_return = minDiffInBST(root->right);
        return std::min(will_return, std::min(left_will_return, right_will_return));
    }

    // come from CS203_DSAA_template/algorithm/tree/Traverse.cpp
    int32_t minDiffInBST2(TreeNode *root) {
        if (root == nullptr) {
            return std::numeric_limits<int32_t>::max();
        }
        stack<TreeNode *> sta;
        TreeNode *head = root;
        int32_t lastValue{-0x3f3f3f3f}, will_return{std::numeric_limits<int32_t>::max()};
        while (head != nullptr || !sta.empty()) {
            while (head != nullptr) {
                sta.push(head);
                head = head->left;
            }
            head = sta.top();
            sta.pop();
            will_return = std::min(will_return, head->val - lastValue);
            lastValue = head->val;
            head = head->right;
        }
        return will_return;
    }

};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_783_H