#pragma once
#ifndef _LEETCODE_1078_H_
#define _LEETCODE_1078_H_
#include <array>
#include <string>
#include <vector>
#include <map>
#include <algorithm>
using namespace std;
/*
You have a set of tiles, 
where each tile has one letter tiles[i] printed on it.
Return the number of possible non-empty sequences of letters you can make.
EX:
"AAB" ->"A", "B", "AA", "AB", "BA", "AAB", "ABA", "BAA".
PS:
tiles.size()<=7
if it is unlimited, it should get a ! function
*/
class Solution1078 {
public:
	int numTilePossibilities(string tiles) {
		array<int, 10> fact = { 1,1,2,6,24,120,720,5040,40320,362880 };
		array<int, 27> chars = { 0 };
		vector<int> nums;
		map<vector<int>,vector<int>> items;
		for (int i = 0; i < tiles.size(); i++) {
			chars[tiles[i] - 'A' +1]++;
			cout << i << endl;
		}
		//small ===> big
		sort(chars.begin(), chars.end(),less<int>());
		for (int i = 1; i < 27; i++) {
			if (chars[i] > 0) {
				nums.push_back(chars[i]);
				cout << chars[i] << endl;
			}
		}

		for (int i = 0; i < nums.size(); i++) {
			cout << i << " "<< nums.size()<<endl;
			vector<int> first(nums);
			vector<int> second(nums.size());
			first[i] -= 1;
			second[i] = 1;
			items.insert(make_pair(first, second));
			cout << i << " " << nums.size() << endl;
		}
		int willreturn = nums.size();
		cout << "willreturn is : " << willreturn << endl;
		for (int i = 1; i < tiles.size(); i++) {
			cout << i << endl;
			map<vector<int>, vector<int>> items2;
			for (auto itor = items.begin(); itor != items.end(); itor++) {
				for (int j = 0; j < nums.size(); j++) {
					if (itor->first[j] != 0) {
						vector<int> first(itor->first);
						vector<int> second(itor->second);
						first[j] -= 1;
						second[j] += 1;
						items2.insert(make_pair(first, second));
					}
				}
			}
			for (auto itor = items2.begin(); itor != items2.end(); itor++) {
				int temp = fact[i + 1];
				for (int j = 0; j < itor->second.size(); j++) {
					if (itor->second[j] != 0) {
						temp /= fact[itor->second[j]];
					}
				}
				willreturn += temp;
			}
			items = items2;
		}
		return willreturn;
	}
	int countTiles(vector<int> tiles,int num) {
		vector<vector<int>> items;
		if (tiles.size() >= num) {
		}
	}
	void test() {
		string str1 = "AAB";
		string str2 = "AAABBC";

		cout <<"result is: " << numTilePossibilities(str1) << endl;
		cout <<"result is: " << numTilePossibilities(str2) << endl;
	}
};
/*
Runtime: 4 ms, faster than 95.72%.
Memory Usage: 10.9 MB, less than 100.00%.
*/
#endif
