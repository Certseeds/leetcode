#pragma once
#ifndef _LEETCODE_TEST_H_
#define _LEETCODE_TEST_H_
#include <vector>
#include <algorithm>
#include <array>
#define test_NUM(EXP) test_##EXP()
using namespace std;
/*

*/
class Solutiontest {
public:
    void test() {
        test_NUM(100);
    }
    void test_100() {
        cout << "100 is running" << endl;
    }
    void test_999() {
        cout << "999 is running" << endl;
    }
};
/*
Runtime: 8 ms,
Memory Usage: 11.7 MB,
100%,84.62%.
*/
#endif
