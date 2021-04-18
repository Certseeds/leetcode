#pragma once
#ifndef _LEETCODE_1030_H
#define _LEETCODE_1030_H

#include <vector>
#include <algorithm>

using namespace std;


class Solution1030 {
public:
    struct point1030 {
        int x;
        int y;

        point1030(int x1, int y1) : x(x1), y(y1) {}

        bool operator<(const point1030 &right) const {
            return (abs(x) + abs(y)) < (abs(right.x) + abs(right.y));
        }

        bool operator>(const point1030 &right) const {
            return (abs(x) + abs(y)) > (abs(right.x) + abs(right.y));
        }

        bool operator==(const point1030 &right) const {
            return (abs(x) + abs(y)) == (abs(right.x) + abs(right.y));
        }
    };

    vector<vector<int>> allCellsDistOrder(int R, int C, int r0, int c0) {
        vector<point1030> pois;
        vector<vector<int>> willreturn;
        for (int32_t i{0}; i < R; i++) {
            for (int j = 0; j < C; j++) {
                pois.push_back(point1030(i - r0, j - c0));
            }
        }
        sort(pois.begin(), pois.end(), less<point1030>());
        for (int32_t i{0}; i < pois.size(); i++) {
            vector<int> temp = {pois[i].x + r0, pois[i].y + c0};
            willreturn.push_back(temp);
        }
        return willreturn;
    }

    void test() {
        vector<vector<int>> vec1 = allCellsDistOrder(2, 3, 1, 2);
        for (int32_t i{0}; i < vec1.size(); i++) {
            cout << vec1[i][0] << " " << vec1[i][1] << endl;
        }
    }
};

#endif
