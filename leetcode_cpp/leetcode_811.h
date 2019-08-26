#pragma once
#ifndef _LEETCODE_811_H
#define _LEETCODE_811_H
#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>
using namespace std;


class Solution811 {
public:
	vector<string> subdomainVisits(vector<string>& cpd) {
		vector<string>willreturn;
		unordered_map<string, int> umaps;
		for (int i = 0; i < cpd.size(); i++)
		{
			int number = getNumber(cpd[i]);
			vector<string> domain = getDomains(cpd[i]);
			for (int j = 0; j < domain.size(); j++)
			{
				if (umaps.count(domain[j]) == 0) {
					umaps.insert(make_pair(domain[j], number));
				}
				else {
					umaps[domain[j]] += number;
				}
			}
		}
		for (unordered_map<string, int>::iterator its = umaps.begin(); its != umaps.end(); its++) {
			willreturn.push_back(to_string(its->second) + " " + its->first);
		}
		return willreturn;
	}
	inline int getNumber(string & str) {
		return (std::stoi(str.substr(0, str.find(" "))));
	}
	vector<string> getDomains(string & str) {
		str = (str.substr(str.find(" ") + 1, str.size()));
		vector<string> willreturn;
		willreturn.push_back(str);
		while (count(str.begin(), str.end(), '.') != 0)
		{
			str = str.substr(str.find('.') + 1, str.size());
			willreturn.push_back(str);
		}
		return willreturn;
	}
	// can be use
};

#endif
