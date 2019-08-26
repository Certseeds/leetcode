#pragma once
#ifndef _LEETCODE_961_H
#define _LEETCODE_961_H
#include <vector>
#include <unordered_map>
using namespace std;


class Solution961 {
public:
	int repeatedNTimes(vector<int>& A) {
		unordered_map<int, int> umaps;
		for (int i = 0; i < A.size(); i++)
		{
			if (umaps.count(A[i]) == 1) {
				return A[i];
			}
			else {
				umaps.insert(make_pair(A[i], 1));
			}
		}
		return 0;
	}
};

#endif
