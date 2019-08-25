#pragma once
#ifndef _LEETCODE_1160_H
#define _LEETCODE_1160_H
#include <string>
#include <vector>
#include <array>
using namespace std;
class Solution1160 {
public:
	const int & countCharacters(vector<string>& words, string & chars) {
		//printf("%s\n","begin");
		vector<array<int,27>> orders;
		int count_value[27];
		int willreturn = 0;
		for (int i = 0; i < words.size(); i++)
		{
			array<int, 27> temparray;
			for (int i = 0; i < 27; i++)
			{
				temparray[i] = 0;
			}
			for (int j = 0; j < words[i].size();j++) {
				temparray[(int)words[i][j] - 96] += 1;
			}
			orders.push_back(temparray);
		}
		for (int i = 0; i < 27; i++)
		{
			count_value[i] = 0;
		}
		for (int i = 0; i < chars.size(); i++)
		{
			count_value[(int)chars[i] - 96] += 1;
		}
		for (int i = 0; i < words.size(); i++)
		{
			bool tempjudge = true;
			for (int j = 1; j < 27 ; j++)
			{
				tempjudge = tempjudge & (count_value[j] >= orders[i][j]);
			}
			if (tempjudge)
			{
				willreturn += words[i].size();
			}
		}
		/*for (size_t i = 0; i < words.size(); i++)
		{
			for (int j = 0; j < 27;j++) {
				printf("%d ",orders[i][j]);
			}
			printf("\n");
		}
		for (int j = 0; j < 27; j++) {
			printf("%d ", count_value[j]);
		}
		printf("%s", "finish");
		*/
		return willreturn;

	}
};

#endif
