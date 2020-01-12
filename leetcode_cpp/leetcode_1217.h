#pragma once
#ifndef _LEETCODE_1217_H
#define _LEETCODE_1217_H
#include <array>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;


class Solution1217 {
public:
	int minCostToMoveChips(vector<int>& chips) {
		//vector<int> chip = { 0 };
		int one = 0;
		int two = 0;
		for (auto num : chips){
			one += (num % 2);
			two += (num + 1) % 2;
		}
		return min(one, two);

	}
	void test() {
		vector<int> vec1 = { 1,2,3 };
		cout << minCostToMoveChips(vec1) << endl;
		vector<int> vec2 = { 2,2,2,3,3 };
		cout << minCostToMoveChips(vec2) << endl;
	}
};

#endif
