#pragma once
#ifndef _LEETCODE_1237_H
#define _LEETCODE_1237_H
#include <vector>
#include <algorithm>
using namespace std;

class CustomFunction {
public:
	int f(int x, int y)
	{
		return x+y;
	}
};
class Solution1237 {
public:
	vector<vector<int>> findSolution(CustomFunction & customfunction, int z) {
		vector<vector<int>> willreturn;
		int MIN_1237 = 1;
		int MAX_1237 = 1000;
		int x_min = 0;
		int x_max = 0;
		int x_begin = MIN_1237;
		int x_end = MAX_1237;
		int x_middle = 0; 
		while (x_begin < x_end) {
			x_middle = x_begin +(x_end - x_begin) / 2 ;
			if (customfunction.f(x_middle, MAX_1237) < z) {
				x_begin = x_middle + 1;
			}
			else {
				x_end = x_middle;
			}
		}
		x_min = x_begin;
		x_begin = MIN_1237;
		x_end = MAX_1237;
		while (x_begin < x_end) {
			x_middle = x_begin + (x_end - x_begin) / 2;
			if (customfunction.f(x_middle, MIN_1237) < z) {
				x_begin = x_middle + 1;
			}
			else {
				x_end = x_middle;
			}
		}
		x_max = x_end;
		for (int x = x_min; x <= x_max; x++) {
			int y_begin = MIN_1237;
			int y_end = MAX_1237;
			int y_middle = 0;
			while (y_begin < y_end) {
				y_middle = y_begin + (y_end - y_begin) / 2;
				if (customfunction.f(x, y_middle) == z) {
					vector<int> temp;
					temp.push_back(x);
					temp.push_back(y_middle);
					willreturn.push_back(temp);
					break;
				}
				else if (customfunction.f(x, y_middle) < z) {
					y_begin = y_middle + 1;
				}
				else {
					y_end = y_middle;
				}
			}
		}
		return willreturn;
	}

	void test() {
		CustomFunction temp;
		vector<vector<int>> test1 = findSolution(temp, 6);
		for (int i = 0; i < test1.size(); i++) {
				cout << test1[i][0] << " " << test1[i][1] << endl;
			
		}
	}
};
#endif
