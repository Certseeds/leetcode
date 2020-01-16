#pragma once
#ifndef _LEETCODE_1314_H_
#define _LEETCODE_1314_H_
#include <unordered_map>
#include <vector>
#include <array>
#include <algorithm>
using namespace std;
/*
Given a m * n matrix mat and an integer K, 
return a matrix answer where each answer[i][j] is the sum of 
all elements mat[r][c] for i - K <= r <= i + K, j - K <= c <= j + K, 
and (r, c) is a valid position in the matrix.
it need the prefix sum.
do more use 304 307 308
*/
class Solution1314{
public:
	
	vector<vector<int>> matrixBlockSum(vector<vector<int>>& mat, int f) {
		vector<vector<int>> willreturn(mat);
		unordered_map<unsigned long long, int> ordered;
		int sizes1 = willreturn.size();
		int sizes2 = willreturn[0].size();
		for (int i = 0; i < sizes1; i++) {
			for (int j = 0; j < sizes2; j++) {
				unsigned long long temp =
					(max(0, i - f) << 21) +
					(min(sizes1, i + f+1) << 14) +
					(max(0, j - f) << 7) +
					min(sizes2, j + f + 1);
				if (ordered[temp] == 0) {
					//cout << i << " " << j << " " << temp << endl;
					int count = 0;
					//cout << "k" << max(0, i - f - 1) << "~" << min(sizes, i + f + 1) << endl;
					//cout << "l" << max(0, j - f - 1) << "~" << min(sizes, j + f + 1) << endl;
					for (int k = max(0, i - f); k < min(sizes1, i + f + 1); k++) {
						for (int l = max(0, j - f); l < min(sizes2, j + f + 1); l++) {
							//cout << k << " " << l << endl;
							count += mat[k][l];
						}
					}
					ordered[temp] = count;
					willreturn[i][j] = ordered[temp];
					cout << count << endl;
				}
				else {
					willreturn[i][j] = ordered[temp];
					cout << willreturn[i][j] << endl;

				}
			}
		}
		return willreturn;
	}
	void test() {
		vector<vector<int>> input1 = { {1,2,3},{4,5,6},{7,8,9} };
		vector<vector<int>> input2 = { {67, 64, 78 }, { 99, 98, 38 },
		{82, 46, 46 }, { 6, 52, 55 }, { 55, 99, 45 } };
		vector<vector<int>> vec1 = matrixBlockSum(input1,1);
		vector<vector<int>> vec2 = matrixBlockSum(input1, 2);
		vector<vector<int>> vec3 = matrixBlockSum(input2, 1);
		for (int i = 0; i < vec1.size(); i++) {
			for (int j = 0; j < vec1[0].size(); j++) {
				cout << vec1[i][j] << " ";
			}
			cout <<endl;
		}
		for (int i = 0; i < vec2.size(); i++) {
			for (int j = 0; j < vec2[0].size(); j++) {
				cout << vec2[i][j] << " ";
			}
			cout << endl;
		}
		for (int i = 0; i < vec3.size(); i++) {
			for (int j = 0; j < vec3[0].size(); j++) {
				cout << vec3[i][j] << " ";
			}
			cout << endl;
		}
	}
};
/*
Runtime: 264 ms,
Memory Usage: 12.7 MB,
35.52%,100%.
*/
#endif
