#pragma once
#ifndef _LEETCODE_1051_H
#define _LEETCODE_1051_H
#include <vector>
#include <algorithm>
using namespace std;


class Solution105 {
public:
	int heightChecker(vector<int>& heights) {
		vector<int> compareWith(heights);
		sort(heights.begin(),heights.end());
		short count = 0;
		for (short i = 0; i < heights.size(); i++)
		{
			if (!(compareWith[i] - heights[i]))
			{
				count++;
			}
		}
		return (int)count; // because the size smaller than 100
	}
};

#endif
