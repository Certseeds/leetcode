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
	    unordered_map<int, vector<int>> nums;
	    vector < vector<int>> willreturn;
	    for (int i = 0; i < groupSizes.size(); i++) {
		    nums[groupSizes[i]].push_back(i);
	    }
	    for (auto iter = nums.begin(); iter != nums.end(); iter++) {
		    for (int i = 0; i < (*iter).second.size() / (*iter).first; i++) {
		    	vector<int> temp;
			    for (int j = 0; j < (*iter).first; j++) {
				    temp.push_back((*iter).second[i * (*iter).first + j]);
			    }
			    willreturn.push_back(temp);
		    }
	    }
	    return willreturn;
    }
	vector<vector<int>> groupThePeople2(vector<int>& groupSizes) {
		unordered_map<int,vector<int>> nums;
		vector <vector<int>> willreturn;
		for (int i = 0; i < groupSizes.size(); i++) {
			nums[groupSizes[i]].push_back(i);
			if (nums[groupSizes[i]].size() == groupSizes[i]) {
				willreturn.push_back(nums[groupSizes[i]]);
				nums[groupSizes[i]].clear();
			}
		}
		return willreturn;
	}

	void test() {
		vector<int> vec1 = { 3,3,3,3,3,1,3 };
		vector<int> vec2 = { 2,1,3,3,3,2 };
		vector<vector<int>> return1 = groupThePeople(vec1);
		for (auto i : return1){
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
		vector<vector<int>> return2 = groupThePeople(vec2);
		for (auto i : return2) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
		vector<vector<int>> return3 = groupThePeople2(vec1);
		for (auto i : return3) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}
		vector<vector<int>> return4 = groupThePeople2(vec2);
		for (auto i : return4) {
			for (auto j : i) {
				cout << j << " ";
			}
			cout << endl;
		}

	}
};

#endif
