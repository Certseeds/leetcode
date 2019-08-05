#ifndef leetcode_771_H
#define leetcode_771_H
#include <string>
#include <fstream>
#include <iostream>
#include<unordered_map>
using  std::string;
using std::unordered_map;
using std::make_pair;
using std::cout;
using std::cin;
using std::endl;
int numJewelsInStones(string J, string S); 
class Solution771 {
public:
	int numJewelsInStones(string J, string S) {
		unordered_map<char, bool> map;
		int count = 0;
		for (int i = 0; i < 26; i++) {
			map.insert(make_pair('a' + i, false));
			map.insert(make_pair('A' + i, false));
		}
		for (int i = 0; i < J.length(); i++) {
			if (!map.at(J.at(i))) {
				map.erase(J.at(i));
				map.insert(make_pair(J.at(i), true));
			}
		}
		for (int i = 0; i < S.length(); i++) {
			if (map.at(S.at(i))) {
				count++;
			}
		}
		return count;
	}
};
#endif 