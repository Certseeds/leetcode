#pragma once
#ifndef _LEETCODE_1010_H_
#define _LEETCODE_1010_H_

#include <vector>
#include <algorithm>
#include <array>

using namespace std;

/*
In a list of songs, the i-th song has a duration of time[i] seconds.

Return the number of pairs of songs 
for which their total duration in seconds is divisible by 60.

Formally, 
we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.
*/
class Solution1010 {
public:
    int numPairsDivisibleBy60(vector<int> &time) {
        array<int, 60> uses = {0};
        int willreturn = 0;
        for (int i = 0; i < time.size(); i++) {
            uses[(time[i] % 60)]++;
            willreturn += uses[(60 - time[i] % 60) % 60];
        }
        return willreturn - uses[30] - uses[0];
    }

    void test() {
        vector<int> vec1 = {30, 20, 150, 100, 40};
        vector<int> vec2 = {60, 60, 60};
        vector<int> vec3 =
                {54, 8, 17, 437, 54, 498, 455, 239, 183, 347, 59, 199, 52, 488, 147, 82};
        vector<int> vec4 =
                {418, 204, 77, 278, 239, 457, 284, 263, 372, 279, 476, 416, 360, 18};
        cout << numPairsDivisibleBy60(vec1) << endl;
        cout << numPairsDivisibleBy60(vec2) << endl;
        cout << numPairsDivisibleBy60(vec3) << endl;
        cout << numPairsDivisibleBy60(vec4) << endl;
    }
};
/*
Runtime: 8 ms,
Memory Usage: 11.7 MB,
100%,84.62%.
*/
#endif
