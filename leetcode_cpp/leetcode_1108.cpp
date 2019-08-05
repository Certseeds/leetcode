#include <string>
#include <fstream>
#include <iostream>
#include "leetcode_1108.h"
#include "leetcode_771.h"
using namespace std;
void main_1108();
void main_771();
string defangIPaddr(string address);
int main() {
	main_1108();
	main_771();
}
void main_1108() {
	string  temp = "1.1.1.1";
	Solution1108 sol1108 = Solution1108();
	cout << sol1108.defangIPaddr(temp);
	cin.get();
	cin.get();
}
void main_771() {
	unordered_map<char, bool> map;
	map.insert(make_pair('a', true));
	bool b = map.at('a');
	cout << b << endl;
	map.erase('a');
	map.insert(make_pair('a', false));
	cout << map.at('a') << endl;
	string j;
	string s;
	cin >> j;
	cin >> s;
	Solution771 sol771 = Solution771();
	cout << sol771
		.numJewelsInStones(j, s);
	cin.get();
	cin.get();
}