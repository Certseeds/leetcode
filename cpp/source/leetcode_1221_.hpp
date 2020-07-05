#pragma once
#ifndef _LEETCODE_1221_H
#define _LEETCODE_1221_H

#include <string>

using namespace std;

class Solution1221 {
public:
    int balancedStringSplit(string &s) {
        int left = 0;
        //int right = 0;
        int willreturn = 0;
        for (int i = 0; i < s.size(); i++) {
            left += (s[i] == 'R');
            //right += !(s[i] == 'R') ;
            //cout << left << " " << right << " " << i << endl;
            willreturn += (left << 1 == i + 1);
        }
        return willreturn;
    }
};

#endif
