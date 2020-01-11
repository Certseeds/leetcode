#pragma once
#ifndef _LEETCODE_1200_H
#define _LEETCODE_1200_H
#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;
class Solution1200 {
public:
	vector<vector<int>> minimumAbsDifference(vector<int>& arr) {
		vector<vector<int>> willreturn;
		std::sort(arr.begin(),arr.end(),std::less<int>());
		int Min_Value = 0x7FFFFFFF;
		for (int i = 0; i < arr.size() - 1; i++) {
			//cout << Min_Value << endl;
			if (arr[i + 1] - arr[i] == Min_Value) {
				willreturn.push_back(vector<int>{arr[i], arr[i + 1]});
			}
			else if (arr[i + 1] - arr[i] < Min_Value) {
				willreturn.clear();
				Min_Value = arr[i + 1] - arr[i];
				willreturn.push_back(vector<int>{arr[i], arr[i + 1]});

			}
		}
		return willreturn;

	}
	void test() {
		vector<int> arr1 = { 4,2,1,3 };
		for (auto vec_out : minimumAbsDifference(arr1)) {
			for (auto vec_int : vec_out) {
				cout << vec_int << endl;
			}
		}
		cout << "1 finish" << endl;
		vector<int> arr2 = { 1,3,6,10,15 };
		for (auto vec_out : minimumAbsDifference(arr2)) {
			for (auto vec_int : vec_out) {
				cout << vec_int << endl;
			}
		}
		cout << "2 finish" << endl;
		vector<int> arr3 = { 3,8,-10,23,19,-4,-14,27 };
		for (auto vec_out : minimumAbsDifference(arr3)) {
			for (auto vec_int : vec_out) {
				cout << vec_int << endl;
			}
		}

		cout << "3 finish" << endl;
	}
};

#endif
