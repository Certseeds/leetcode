#pragma once
#ifndef _LEETCODE_1266_H
#define _LEETCODE_1266_H
#include <vector>
#include <algorithm>
using namespace std;

class Solution1266 {
public:
	int minTimeToVisitAllPoints(vector<vector<int>>& points) {
		int willreturn = 0;
		for (int i = 0; i < points.size()-1; i++)
		{
			willreturn += max(abs(points[i + 1][0] - points[i][0]),abs(points[i + 1][1] - points[i][1]));
		}
		return willreturn;
	}

};

#endif
