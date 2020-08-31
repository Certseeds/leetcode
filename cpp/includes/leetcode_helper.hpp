/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-07 20:19:19
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-05 11:46:28
*/
#pragma once
#ifndef _LEETCODE_HELPER_
#define _LEETCODE_HELPER_
#include <vector>
constexpr double eps = 0.00000001;
constexpr double neps = -0.00000001;
inline int32_t sign(int32_t x) {
    return ((x > 0) - (x < 0));
}
inline int32_t sign(double x) {
    return ((x<neps) ? -1 : (x>neps));
}
int32_t binary_search_pos(std::vector<int32_t> vec, int32_t target, int32_t begin, int32_t end) {
    // it is [begin,end),length is end-begin
    int32_t vec_size = vec.size();
    assert(begin <= end);
    assert(begin <= vec_size);
    assert(end <= vec_size);
    int32_t middle = 0;
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
