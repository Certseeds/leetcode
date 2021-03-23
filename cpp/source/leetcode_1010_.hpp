#pragma once
#ifndef _LEETCODE_1010_H_
#define _LEETCODE_1010_H_

#include <vector>
#include <array>

using std::vector;
using std::array;

/*
In a list of songs, the i-th song has a duration of time[i] seconds.

Return the number of pairs of songs 
for which their total duration in seconds is divisible by 60.

Formally, 
we want the number of indices i < j with (time[i] + time[j]) % 60 == 0.
*/
class Solution1010 {
public:
    int numPairsDivisibleBy60(const vector<int> &time) {
        array<int32_t, 60> uses = {0};
        int32_t willreturn = 0;
        for (const int32_t i : time) {
            uses[i % 60]++;
            willreturn += uses[(60 - i % 60) % 60];
        }
        return willreturn - uses[30] - uses[0];
    }
};
/*
Runtime: 8 ms,
Memory Usage: 11.7 MB,
100%,84.62%.
*/
#endif
