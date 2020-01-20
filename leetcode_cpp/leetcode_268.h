#pragma once
#ifndef _LEETCODE_268_H_
#define _LEETCODE_268_H_
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;
/*
Given an array containing n 
distinct numbers taken from 0, 1, 2, ..., n, 
find the one that is missing from the array.
*/
class Solution268 {
public:
	int missingNumber(vector<int>& nums) {
		return (nums.size() * (nums.size() + 1) / 2 -
			std::accumulate(nums.begin(), nums.end(), 0));
	}
	void test() {
		vector<int> vec1 = { 3,0,1 }; // 2
		cout << missingNumber(vec1) << endl;
		vector<int> vec2 = { 9,6,4,2,3,5,7,0,1 }; // 8
		cout << missingNumber(vec2) << endl;
	}
};
/*
Runtime: 8 ms, 
Memory Usage: 10.1 MB, 
99.90%,23.53%.
*/
#endif