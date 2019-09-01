#pragma once
#ifndef _LEETCODE_908_H
#define _LEETCODE_908_H
#include <vector>
using namespace std;


class Solution908 {
public:
	int smallestRangeI(vector<int>& A, int K) {
		int min = 0x3f3f3f3f;
		int max = 0;
		for (int i = 0; i < A.size(); i++) {
			min = min > A[i] ? A[i] : min;
			max = max > A[i] ? min : A[i];
		}
		return(max - min >= 2 * K ? max - min - 2 * K : 0);
	}
};

#endif
