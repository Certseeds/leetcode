#pragma once
#ifndef _LEETCODE_1222_H
#define _LEETCODE_1222_H
#include <vector>
#include <array>
#include <unordered_set>
#include <algorithm>
#include "leetcode_hash.h"
using namespace std;
/*
On an 8x8 chessboard, there can be multiple Black Queens and one White King.

Given an array of integer coordinates queens that 
represents the positions of the Black Queens, 
and a pair of coordinates king that represent the position of the White King, 
return the coordinates of all the queens (in any order) that can attack the King.
*/
class Solution1222 {
public:
    vector<vector<int>> queensAttacktheKing(vector<vector<int>>& queens, vector<int>& king) {
        vector<vector<int>> will_return;
        unordered_set<std::pair<int, int>> umap;
        for (auto i : queens) {
            umap.insert(std::make_pair(i[0], i[1]));
        }
        int x = king[0];
        int y = king[1];
        const int Chessboard = 8;
        for (int i = x - 1; i >= 0; i--) {
            if (umap.count(std::make_pair(i, y)) == 1) {
                will_return.push_back(vector<int>{i, y});
                umap.erase(std::make_pair(i, y));
                break;
            }
        }
        for (int i = x + 1; i < Chessboard; i++) {
            if (umap.count(std::make_pair(i, y)) == 1) {
                will_return.push_back(vector<int>{i, y});
                umap.erase(std::make_pair(i, y));
                break;
            }
        }
        for (int i = y - 1; i >= 0; i--) {
            if (umap.count(std::make_pair(x,i)) == 1) {
                will_return.push_back(vector<int>{x, i});
                umap.erase(std::make_pair(x, i));
                break;
            }
        }
        for (int i = y + 1; i < Chessboard; i++) {
            if (umap.count(std::make_pair(x, i)) == 1) {
                will_return.push_back(vector<int>{x, i});
                umap.erase(std::make_pair(x, i));
                break;
            }
        }
        for (int i = 1; i <= min(x,y); i++) {
            if (umap.count(std::make_pair(x-i,y-i)) == 1) {
                will_return.push_back(vector<int>{x - i, y - i});
                umap.erase(std::make_pair(x - i, y - i));
                break;
            }
        }
        for (int i = 1; i <= min(Chessboard-x, Chessboard -y); i++) {
            if (umap.count(std::make_pair(x + i, y + i)) == 1) {
                will_return.push_back(vector<int>{x + i, y + i});
                umap.erase(std::make_pair(x + i, y + i));
                break;
            }
        }
        for (int i = 1; i <= min(x, Chessboard -y); i++) {
            if (umap.count(std::make_pair(x - i, y + i)) == 1) {
                will_return.push_back(vector<int>{x - i, y+ i});
                umap.erase(std::make_pair(x - i, y + i));
                break;
            }
        }
        for (int i = 1; i <= min(Chessboard - x,y); i++) {
            if (umap.count(std::make_pair(x + i, y - i)) == 1) {
                will_return.push_back(vector<int>{x + i, y - i});
                umap.erase(std::make_pair(x + i, y - i));
                break;
            }
        }
        return will_return;
    }
    void test() {
        vector<vector<int>> vec1 = { {0,1},{1,0},{4,0},{0,4},{3,3},{2,4} };
        vector<int> vec1_1 = { 0,0 };
        vector<vector<int>> out1 = queensAttacktheKing(vec1,vec1_1);
        for (auto i : out1) {
            for (auto j : i) {
                cout << j << " ";
            }cout << endl;
        }

    }
};
/*
Runtime: 12 ms,
Memory Usage: 9.9 MB,
10.69%,100%.
*/
#endif
