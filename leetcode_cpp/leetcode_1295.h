#pragma once
#ifndef _LEETCODE_1295_H
#define _LEETCODE_1295_H
#include <vector>
using namespace std;

class Solution1295 {
public:
	int findNumbers(vector<int>& nums) {
		int count = 0;
		for (int i = 0; i < nums.size(); i++) {
			bool temp = true;
			//cout << nums[i] << " ";
			while (nums[i] > 0) {
				temp = !temp;
				nums[i] = nums[i] / 10;
			}
			count += temp;
			//cout << temp << " ";
			//cout << count << endl;
		}
		return count;
	}
};

#endif
