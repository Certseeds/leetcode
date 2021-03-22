/*
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-27 11:59:55
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-21 20:34:42
 */
/*  leetcode
    Copyright (C) 2020  nanoseeds

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
#ifndef LEETCODE_SOURCE_LEETCODE_95_H
#define LEETCODE_SOURCE_LEETCODE_95_H

#include <vector>
#include <algorithm>

#ifdef __LOCAL__
#include "TreeNode.h"
#endif

using std::vector;

class Solution95 {
public:
    vector<TreeNode *> generateTrees(int n) {
        if (n == 0) {
            return vector<TreeNode *>{};
        }
        return generateTrees_rec(1, n);
    }

    vector<TreeNode *> generateTrees_rec(int32_t left, int32_t right) {
        if (left > right) {
            return vector<TreeNode *>{nullptr};
        } else if (left == right) {
            return vector<TreeNode *>{new TreeNode(left)};
        }
        vector<TreeNode *> will_return;
        for (int i = left; i <= right; i++) {
            for (auto const &j : generateTrees_rec(left, i - 1)) {
                for (auto const &k : generateTrees_rec(i + 1, right)) {
                    will_return.push_back(new TreeNode(i, j, k));
                    //will_return.emplace_back(i,j,k);
                }
            }
        }
        return will_return;
    }
};

#endif  //LEETCODE_CPP_SOURCE_LEETCODE_95_H