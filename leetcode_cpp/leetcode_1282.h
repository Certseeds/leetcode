#pragma once
#ifndef _LEETCODE_1282_H
#define _LEETCODE_1282_H
#include <vector>
#include <unordered_map>
using namespace std;
/*There are n people 
whose IDs go from 0 to n - 1 and each person belongs exactly to one group.
Given the array groupSizes of length n telling the group size each person belongs to, 
return the groups there are and the people's IDs each group includes.
You can return any solution in any order and the same applies for IDs.
Also, it is guaranteed that there exists at least one solution. 
*/
class Solution1282 {
public:
	vector<vector<int>> groupThePeople(vector<int>& groupSizes) {
		unordered_map<int,vector<int>> nums;
		vector <vector<int>> willreturn;
		for (int i = 0; i < groupSizes.size(); i++) {
			if (nums[groupSizes[i]].size() > groupSizes[i]) {
			}
			nums[groupSizes[i]].push_back(i);
		}
		for (auto iter = nums.begin(); iter != nums.end(); iter++) {
			for (int i = 0; i < (*iter).second.size()/ (*iter).first; i++) {
				vector<int> temp;
				for (int j = 0; j <(*iter).first; j++) {
					temp.push_back((*iter).second[i * (*iter).first + j]);
				}
				willreturn.push_back(temp);
			}
		}
		return willreturn;
	}
	void test() {
		vector<int> vec1 = { 3,3,3,3,3,1,3 };
		vector<vector<int>> return1 = groupThePeople(vec1);
		for (auto i : return1){
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
	}
};

#endif
