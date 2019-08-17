#pragma once
#ifndef _LEETCODE_852_H
#define _LEETCODE_852_H
#include <vector>
using namespace std;
class Solution852 {
public:
	int peakIndexInMountainArray(vector<int>& A) {
		int x1 = 0;
		int x4 = A.size() -1 ;
		int x2 = x1 + (x4 - x1) / 3;
		int x3 = x1 + (x4 - x1) * 2 / 3;
		while (x1 < x4)
		{
			int temp1 = A[x2];
			int temp2 = A[x3];
			if (temp1 > temp2)
			{
				x4 = x3;
			}
			else {
				x1 = x2 + 1;
			}
			x2 = x1 + (x4 - x1) / 3;
			x3 = x1 + (x4 - x1) * 2 / 3;		
		}
		return x1 -1;
		//what the fuck, i can not understand why it's true
	}
};

#endif
