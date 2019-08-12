#include <string>
#include <fstream>
#include <iostream>
#include "leetcode_1108.h"
#include "leetcode_771.h"
#include "leetcode_938.h"
#include "leetcode_709.h"
#include "leetcode_1021.h"
#include "leetcode_804.h"
#include "leetcode_832.h"
#include "leetcode_905.h"
using namespace std;
void main_1108();
void main_771();
void main_938();
void main_709();
void main_1021();
void main_804();
void main_832();
void main_905();
int main() {
	//main_1108();
	//main_771();
	//main_938();
	//main_709();
	//main_1021();
	//main_804();
	//main_832();
	main_905();
	cin.get();
	cin.get();
	
return 0;
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
	cout << sol771.numJewelsInStones(j, s);
	cin.get();
	cin.get();
}
void main_938() {
	TreeNode * root = new TreeNode(10);
	root->left = new TreeNode(5);
	root->right = new TreeNode(15);
	root->left->left = new TreeNode(3);
	root->left->right = new TreeNode(7);
	root->right->left = nullptr;
	root->right->right= new TreeNode(18);
	Solution938 sol938;
	cout << sol938.rangeSumBST(root, 7, 15) << endl;
	cout << (int)'A' << " " << (int)'a' << endl;
	cin.get();
	cin.get();

}
void main_709() {
	Solution709 sol709;
	string hello = "HEllo";
	cout << sol709.toLowerCase(hello) << endl;
}
void main_1021() {
	Solution1021 sol1021;
	string s = "(()())(())(()(()))";
	cout << sol1021.removeOuterParentheses(s);

}
void main_804() {
	Solution804 sol804;
	vector<string> words = {"gin", "zen", "gig", "msg"};
	cout << sol804.uniqueMorseRepresentations(words);
}
void main_832() {
	Solution832 sol832;
	vector<vector<int>> matrixs = { {1, 1, 0 }, { 1, 0, 1 }, { 0, 0, 0 }};
	sol832.flipAndInvertImage_1(matrixs);
	sol832.flipAndInvertImage_2(matrixs);
	for (int i = 0; i < matrixs.size(); i++)
	{
		for (int j = 0; j < matrixs[0].size(); j++)
		{
			cout << matrixs[i][j] << " ";
		}
		cout << endl;
	}

}
void main_905() {
	Solution905 sol905;
	vector<int> parity = { 3,1,2,4 };
	for (int i = 0; i < parity.size(); i++)
	{
		cout << parity[i] << " ";
	}
	sol905.sortArrayByParity(parity);
	cout << "?" << endl;
	for (int i = 0; i < parity.size(); i++)
	{
		cout << parity[i] << " ";
	}

}