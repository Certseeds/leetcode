#pragma once
#ifndef _LEETCODE_914_H_
#define _LEETCODE_914_H_
#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>
using namespace std;
/*
In a deck of cards, each card has an integer written on it.

Return true if and only if you can choose X >= 2 such that 
it is possible to split the entire deck into 1 or more groups of cards, where:
*/
class Solution914 {
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (deck.size() < 2) {
            return false;
        }
        int maxv = INT16_MIN;
        unordered_map<int, int> umap;
        for (auto i : deck) {
            umap[i] ++;
            maxv = max(umap[i], maxv);
        }
        for (int i = 2; i <= maxv; i++) {
            int count = 0;
            for (auto j = umap.begin(); j != umap.end(); j++) {
                if (j->second % i != 0) {
                    break;
                }
                count += umap[j->first];

            }
            if (count == deck.size()) {
                return true;
            }
        }
        return false;
    }
    void test() {
        vector<int> vec1 = { 1,1,1,2,2,2,3,3 };
        cout << hasGroupsSizeX(vec1) << endl;
        vector<int> vec2 = { 1,1 };
        cout << hasGroupsSizeX(vec2) << endl;
    }
};
/*
Runtime: 12 ms,
Memory Usage: 9.9 MB,
98.24%,75.00%.
*/
#endif
