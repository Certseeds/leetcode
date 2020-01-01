#pragma once
#ifndef _LEETCODE_1252_H
#define _LEETCODE_1252_H
#include <vector>
using namespace std;

class Solution1252 {
public:
	int oddCells1(int n, int m, vector<vector<int>>& indices) {
		vector<vector<int>> matrix(m, vector<int>(n, 0));
		int willreturn = 0;
		for (int i = 0; i < indices.size(); i++) {
			for (int j = 0; j < m; j++) {
				matrix[j][indices[i][0]] += 1; 
			}
			for (int j = 0; j < n; j++) {
				matrix[indices[i][1]][j] += 1;
			}
		}
		for (int i = 0; i <m; i++) {
			for (int j = 0; j <n; j++) {
				willreturn += matrix[i][j] & 1;
			}
		}
		return willreturn;
	}
	int oddCells(int n, int m, vector<vector<int>>& indices) {
		vector<bool> rows(n, true);
		vector<bool> columns(m, true);
		int n2 = 0; 
		int m2 = 0;
		for (int i = 0; i < indices.size(); i++) {
			rows[indices[i][0]] = !rows[indices[i][0]];
			columns[indices[i][1]] = !columns[indices[i][1]];
		}
		for (int i = 0; i < m; i++) {
			m2 += !columns[i];
		}
		for (int j = 0; j < n; j++) {
			n2 += !rows[j];
		}
		//cout << m2 << " " << n2 << endl;
		//cout << (m - n2) << " " << (n - m2) << endl;
		return (n - n2)*m2 + (m - m2)*n2;
	}
	void test() {
		vector<vector<int>> indices1 = { {0,1},{1,1} };
		vector<vector<int>> indices2 = { {1,1},{0,0} };
		vector<vector<int>> indices3 = { {40, 5} };
		cout << oddCells(2, 3, indices1) << endl;
		cout << oddCells(2, 2, indices2) << endl;
		cout << oddCells(48, 37, indices3) << endl;
		assert(oddCells(2, 3, indices1) == 6);
		assert(oddCells(2, 2, indices2) == 0);
		assert(oddCells(48, 37, indices3) == 83);
	}
};

#endif
