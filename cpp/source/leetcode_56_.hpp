#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_56_H
#define LEETCODE_CPP_SOURCE_LEETCODE_56_H

#include <vector>
#include <algorithm>

namespace Solution56 {
using std::sort;
using std::string;
using std::vector;

class Solution56 {
public:
    vector<vector<int>> merge(vector<vector<int>> intervals) {
        size_t s{intervals.size()};
        if (s <= 1) {
            return intervals;
        }
        std::sort(std::begin(intervals), std::end(intervals), [](const auto &v1, const auto &v2) {
            return v1[0] < v2[0];
        });
        vector<vector<int32_t>> will_return;
        int32_t begin{intervals[0][0]}, end{intervals[0][1]};
        for (size_t order{1}; order < s; order++) {
            if (end >= intervals[order][0]) {
                end = std::max(end, intervals[order][1]);
            } else {
                will_return.push_back(vector<int32_t>{begin, end});
                begin = intervals[order][0];
                end = intervals[order][1];
            }
        }
        will_return.push_back(vector<int32_t>{begin, end});
        return will_return;
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_56_H