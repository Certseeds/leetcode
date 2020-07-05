#pragma once
#ifndef _LEETCODE_1184_H_
#define _LEETCODE_1184_H_

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

/*
A bus has n stops numbered from 0 to n - 1 that form a circle. 
We know the distance between all pairs of neighboring stops 
where distance[i] is the distance between the stops number i and (i + 1) % n.

The bus goes along both directions i.e.
clockwise and counterclockwise.

Return the shortest distance between the given start and destination stops.
justy quicker get sum from vector;
*/
class Solution1184 {
public:
    int distanceBetweenBusStops(vector<int> &distance, int start, int destination) {
        if (start > destination) {
            swap(start, destination);
        }
        int begin = std::accumulate(
                std::begin(distance), std::begin(distance) + start, 0);
        int middle = std::accumulate(
                std::begin(distance) + start, std::begin(distance) + destination, 0);
        int reserve = std::accumulate(
                std::begin(distance) + destination, std::end(distance), 0);
        return min(middle, begin + reserve);
    }

    void test() {
        cout << "1184 begin" << endl;
        vector<int> vec1 = {1, 2, 3, 4};
        cout << distanceBetweenBusStops(vec1, 0, 1) << endl;
        cout << distanceBetweenBusStops(vec1, 0, 3) << endl;
        vector<int> vec2 = {7, 10, 1, 12, 11, 14, 5, 0};
        cout << distanceBetweenBusStops(vec2, 7, 2) << endl;
        cout << "1184 end" << endl;
    }
};
/*
Runtime: 4 ms, 
Memory Usage: 9.2 MB,
95.8%,100%.
*/
#endif
