#pragma once
#ifndef _LEETCODE_HELPER_
#define _LEETCODE_HELPER_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-07 20:19:19
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-07 20:28:11
*/
const double eps = 0.00000001;
const double neps = -0.00000001;
inline int sign(int x) {
    return ((x > 0) - (x < 0));
}
inline int sign(double x) {
    return ((x<neps) ? -1 : (x>neps));
}
#endif
