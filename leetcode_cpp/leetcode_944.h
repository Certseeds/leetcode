#pragma once
#ifndef _LEETCODE_944_H
#define _LEETCODE_944_H
#include <vector>
#include <string>
using namespace std;


class Solution944 {
public:
	int minDeletionSize(vector<string>& A) {
		int count = 0;
		bool notdeletex = true;
		for (int i = 0; i < A[0].length(); i++)
		{
			for (int j = 1; j < A.size(); j++)
			{
				notdeletex = notdeletex & (A[j][i] - A[j - 1][i] >= 0);
			}
			count += !notdeletex;
			notdeletex = true;
		}
		return count;
	}
};

#endif
