#pragma once
#ifndef _LEETCODE_804_H
#define _LEETCODE_804_H
#include <string>
#include<unordered_map>
#include <array>
using namespace std;
class Solution804 {
public:
	int uniqueMorseRepresentations(vector<string>& words) {
		array<string, 26> asks = { ".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---", "-.-",
		".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-", "..-", "...-", ".--", "-..-", "-.--", "--.." };
		unordered_map<string, int> maps;
		for (int i = 0; i < words.size(); i++){
			string temp = "";
			for (int j = 0; j < words[i].size(); j++)
			{
				temp += asks[(int)words[i][j] - 97];
			}
			if (maps.count(temp) == 0 ) 
			{
				maps.insert(make_pair(temp,i));
			}
			
		}
		return maps.size();
	}
};
#endif 