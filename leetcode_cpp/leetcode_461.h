#pragma once
#ifndef _LEETCODE_461_H
#define _LEETCODE_461_H
#include <string>
using namespace std;


class Solution461 {
public:
	int hammingDistance(const int & x, const int &  y) {
		int count = 0;
		int temp = x ^ y;
		while (temp)
		{
			count += (temp & 1);
			temp = temp >> 1;
		}
		return count;
	}
};

#endif
