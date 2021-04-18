#pragma once
#ifndef _LEETCODE_849_H_
#define _LEETCODE_849_H_

#include <vector>
#include <numeric>
#include <algorithm>

using namespace std;

/*
In a row of seats,
1 represents a person sitting in that seat,
and 0 represents that the seat is empty.

There is at least one empty seat,
and at least one person sitting.

Alex wants to sit in the seat such that the distance
between him and the closest person to him is maximized.

Return that maximum distance to closest person.
*/
class Solution849 {
public:
    int maxDistToClosest(vector<int> &seats) {
        vector<int> left(seats);
        vector<int> right(seats);
        int willreturn = INT16_MIN;
        left[0] = (seats[0] == 1) ? 0 : INT16_MAX;
        right[seats.size() - 1] = (seats[seats.size() - 1] == 1) ? 0 : INT16_MAX;
        for (int32_t i{1}; i < seats.size(); i++) {
            left[i] = (seats[i] == 1) ? 0 : left[i - 1] + 1;
        }
        for (int i = seats.size() - 2; i >= 0; i--) {
            right[i] = (seats[i] == 1) ? 0 : right[i + 1] + 1;
        }
        for (int32_t i{0}; i < seats.size(); i++) {
            willreturn = max(
                    willreturn,
                    min(left[i],
                        right[i]
                    )
            );
        }
        return willreturn;
    }

    void test() {
        vector<int> vec1 = {1, 0, 0, 0, 1, 0, 1};
        vector<int> vec2 = {1, 0, 0, 0};
        vector<int> vec3 = {0, 0, 0, 0, 1};
        cout << maxDistToClosest(vec1) << endl;
        cout << maxDistToClosest(vec2) << endl;
        cout << maxDistToClosest(vec3) << endl;
    }
};
/*
Runtime: 8 ms,
Memory Usage: 10.8 MB,
99.13%,17.65%.
*/
#endif
