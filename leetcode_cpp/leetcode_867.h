#pragma once
#ifndef _LEETCODE_867_H
#define _LEETCODE_867_H
#include <array>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution867 {
public:
	vector<vector<int>> transpose(vector<vector<int>>& A) {
		vector<vector<int>> willreturn;
		for (int i = 0; i < A[0].size(); i++) {
			vector<int> temp;
			for (int j = 0; j < A.size(); j++) {
				temp.push_back(A[j][i]);
			}
			willreturn.push_back(temp);
		}
		return willreturn;
	}
	void test() {
		vector<vector<int>> vec1 = { {1,2,3},{4,5,6},{7,8,9} };
		auto return1 = transpose(vec1);
		for (int i = 0; i < return1.size(); i++) {
			for (int j = 0; j < return1[i].size();j++) {
				cout << return1[i][j] <<" " ;
			}
			cout << endl;
 		}
		vector<vector<int>> vec2 = { {1,2,3},{4,5,6} };
		auto return2= transpose(vec2);
		for (int i = 0; i < return2.size(); i++) {
			for (int j = 0; j < return2[i].size(); j++) {
				cout << return2[i][j] << " ";
			}
			cout << endl;
		}
	}
};

#endif
