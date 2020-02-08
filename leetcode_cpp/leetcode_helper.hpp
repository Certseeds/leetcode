#pragma once
#ifndef _LEETCODE_HELPER_
#define _LEETCODE_HELPER_
#include <vector>
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-07 20:19:19
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-08 15:27:41
*/
const double eps = 0.00000001;
const double neps = -0.00000001;
inline int sign(int x) {
    return ((x > 0) - (x < 0));
}
inline int sign(double x) {
    return ((x<neps) ? -1 : (x>neps));
}
int binary_search_pos(std::vector<int> vec, int target, int begin, int end) {
    // it is [begin,end),length is end-begin
    assert(begin <= end);
    assert(begin <= vec.size());
    assert(end <= vec.size());
    int middle = 0;
    while (begin < end) {
        middle = (end - begin) / 2 + begin;
        if (vec[middle] < target) {
            begin = middle + 1;
        }
        else if (target == vec[middle]) {
            return middle;
        }
        else {
            end = middle;
        }
    }
    return -1;
}
#endif
