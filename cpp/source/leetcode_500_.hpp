#pragma once
#ifndef _LEETCODE_500_H
#define _LEETCODE_500_H

#include <string>
#include <vector>
#include <array>
//#include <set>
using namespace std;

/*Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
Note: A leaf is a node with no children.
*/
class Solution500 {
public:
    vector<string> findWords(vector<string> &words) {
        //set<char> line1 = { 'q','w','e','r','t','y','u','i','o','p' };
        //set<char> line2 = { 'a','s','d','f','g','h','j','k','l' };
        //set<char> line2 = { 'z','x','c','v','b','n','m'};
        array<int, 58> chars = {
                2, 3, 3, 2, 1, 2, 2, 2, 1, 2,
                2, 2, 3, 3, 1, 1, 1, 1, 2, 1,
                1, 3, 1, 3, 1, 3,
                0, 0, 0, 0, 0, 0,
                2, 3, 3, 2, 1, 2, 2, 2, 1, 2,
                2, 2, 3, 3, 1, 1, 1, 1, 2, 1,
                1, 3, 1, 3, 1, 3};
        vector<string> willreturn;
        for (int i = 0; i < words.size(); i++) {
            bool judge = true;
            for (int j = 0; j < words[i].size() - 1; j++) {
                //cout << words[i][j] << endl;
                //cout << words[i][j] - 97 << " " << words[i][j + 1] - 97 << endl;
                if (chars[words[i][j] - 65] != chars[words[i][j + 1] - 65]) {
                    judge = false;
                    break;
                }
            }
            if (judge) {
                willreturn.push_back(words[i]);
            }
            //cout << "succ" << endl;
        }
        return willreturn;
    }

    void test() {
        vector<string> words1 = {"Hello", "Alaska", "Dad", "Peace"};
        vector<string> return1 = findWords(words1);
        for (auto i : return1) {
            cout << i << endl;
        }
        vector<string> words2 = {"Aasdfghjkl", "Qwertyuiop", "zZxcvbnm"};
        vector<string> return2 = findWords(words2);
        for (auto i : return2) {
            cout << i << endl;
        }
    }
};

#endif
