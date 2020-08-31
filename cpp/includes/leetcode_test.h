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
        //test_NUM(100);
        cout << test_UB_1(5) << endl;
    }
    int  test_UB_1(int i) {
        int j = -2;
        switch (i) {
        case 0:   do {
        case 1:   i++;
        case 2:  if (j += ++i < 11)
        case 3:  continue;
        case 4:  if (i % 4) {
        case 5:  j = i / 2;
        case 6:   break;
        case 7: ;}
        case 8:   i += j / 10;
        case 9:;} while (i < 10);
        default: j += i;
        }    
        return j;
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
