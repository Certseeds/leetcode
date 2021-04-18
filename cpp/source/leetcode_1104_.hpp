#pragma once
#ifndef _LEETCODE_1104_H_
#define _LEETCODE_1104_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-14 09:03:26
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-14 09:44:31
*/
#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::cout;
using std::endl;
using std::less;
using std::vector;
using std::reverse;

/*
In an infinite binary tree where every node has two children,
the nodes are labelled in row order.

In the odd numbered rows (ie., the first, third, fifth,...),
the labelling is left to right,
while in the even numbered rows (second, fourth, sixth,...),
the labelling is right to left.
Given the label of a node in this tree,
return the labels in the path from the root
of the tree to the node with that label.
Example 1:
Input: label = 14
Output: [1,3,4,14]

Example 2:
Input: label = 26
Output: [1,2,6,10,26]
*/
class Solution1104 {
public:
    vector<int> pathInZigZagTree(int label) {
        vector<int> paths;
        while (label > 0) {
            paths.push_back(label);
            label /= 2;
        }
        if (paths.size() % 2 == 0) {
            label = pathInZigZagTree_helper(paths.size() - 1, paths[0]);
            paths.clear();
            while (label > 0) {
                paths.push_back(label);
                label /= 2;
            }
        }
        reverse(paths.begin(), paths.end());
        for (int32_t i{1}; i < paths.size(); i += 2) {
            paths[i] = pathInZigZagTree_helper(i, paths[i]);
        }
        return paths;
    }

    inline int pathInZigZagTree_helper(const int lev, const int input) {
        return (1 << lev) * 3 - input - 1;
    }

    void test() {
        vector<int> _out1 = {1, 3, 4, 14};
        vector<int> _out2 = {1, 2, 6, 10, 26};
        vector<int> out1 = pathInZigZagTree(14);
        vector<int> out2 = pathInZigZagTree(26);
        for (int32_t i{0}; i < out1.size(); i++) {
            assert(out1[i] == _out1[i]);
        }
        for (int32_t i{0}; i < out2.size(); i++) {
            assert(out2[i] == _out2[i]);
        }
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.5 MB,
100%,100%.
*/
#endif
