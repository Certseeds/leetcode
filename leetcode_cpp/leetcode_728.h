#pragma once
#ifndef _LEETCODE_728_H
#define _LEETCODE_728_H
#include <string>
#include <vector>
using namespace std;
class Solution728 {
public:
	vector<int> selfDividingNumbers(int left, int right) {
		vector <int> willreturn;
		vector <int> temp;
		for (int i = left; i <= right; i++)
		{
			if (judgement(i, temp)) {
				willreturn.push_back(i);
			}

		}
		return willreturn;
	}
	bool judgement(int x, vector<int> & temp) {
		int constX = x;
		int middle = x%10;
		temp.clear();
		while (x >= 10)
		{
			middle = x % 10;
			x = x / 10;
			if (!middle)
			{
				return false;
			}
			temp.push_back(middle);
		}
		middle = x % 10;
		if (!middle)
		{
			return false;
		}
		temp.push_back(middle);

			

		for (int i = 0; i < temp.size(); i++)
		{
			if (constX % temp[i] != 0) {
				return false;
			}
		}
		return true;
	}


};

#endif
