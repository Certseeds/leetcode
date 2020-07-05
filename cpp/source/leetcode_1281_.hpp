#pragma once
#ifndef _LEETCODE_1281_H
#define _LEETCODE_1281_H
using namespace std;

class Solution1281 {
public:
    int subtractProductAndSum(int &n) {
        int sum = 0;
        int dot = 1;
        while (n > 0) {
            sum += n % 10;
            dot *= n % 10;
            n = n / 10;
        }
        return dot - sum;
    }
};

#endif
