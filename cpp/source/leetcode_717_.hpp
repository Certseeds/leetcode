#pragma once
#ifndef _LEETCODE_717_H_
#define _LEETCODE_717_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
We have two special characters.
The first character can be represented by one bit 0. 
The second character can be represented by two bits (10 or 11).

Now given a string represented by several bits. 
Return whether the last character must be a one-bit character or not. 
The given string will always end with a zero.
*/
class Solution717 {
public:
    bool isOneBitCharacter(vector<int> &bits) {
        const int sizes = bits.size();
        if (sizes < 2 || bits[sizes - 2] == 0) {
            return true;
        }
            // sizes == 2 is the same with sizes >2
            // it means, test the string before the last one is over or not
        else {
            int i = 0;
            for (; i < sizes - 1; i++) {
                i += bits[i];
            }
            return (i == sizes - 1);
        }
    }

    void test() {
        vector<int> vec1 = {1, 0, 0};
        vector<int> vec2 = {1, 1, 1, 0};
        vector<int> vec3 = {0, 0};
        vector<int> vec4 = {1, 0};
        cout << isOneBitCharacter(vec1) << endl;
        cout << isOneBitCharacter(vec2) << endl;
        cout << isOneBitCharacter(vec3) << endl;
        cout << isOneBitCharacter(vec4) << endl;
    }
};
/*
Runtime: 4 ms, 
Memory Usage: 8.8 MB,
77.44%,66.67%.
*/
#endif
