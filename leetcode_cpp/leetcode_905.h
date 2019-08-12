#pragma once
#ifndef _LEETCODE_905_H
#define _LEETCODE_905_H
#include<unordered_map>
using namespace std;
class Solution905 {
public:
	vector<int>& sortArrayByParity(vector<int>& A) {
		if (A.size() == 0 or A.size() == 1)
		{
			return A;
		}
		int begin = 0;
		int ends = A.size()-1; 
		int temp = 0;
		while (begin < ends) 
		{
		    while ( ((A[begin] &1) == 0 ) && (begin < ends) ) 
				begin++;
			while ( ((A[ends] &1) == 1 ) && (begin < ends) ) 
				ends--;
			temp = A[begin];
			A[begin] = A[ends];
			A[ends] = temp;
		}
		return A;
	} 
};
#endif 