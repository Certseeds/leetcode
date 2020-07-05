#pragma once
#ifndef _LEETCODE_1207_H
#define _LEETCODE_1207_H

#include <vector>
#include <array>
#include <string>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

class Solution1207 {
public:
    bool uniqueOccurrences(vector<int> &arr) {
        unordered_map<int, int> maps;
        unordered_set<int> maps_value;
        for (int i = 0; i < arr.size(); i++) {
            maps[arr[i]]++;
        }
        for (auto it = maps.begin(); it != maps.end(); it++) {
            maps_value.insert(it->second);
        }
        return maps.size() == maps_value.size();
    }

    void test() {
        vector<int> input = {1, 2, 2, 1, 1, 3};
        cout << (uniqueOccurrences(input) ? "true" : "false") << endl;
        vector<int> input2 = {1, 2};
        cout << (uniqueOccurrences(input2) ? "true" : "false") << endl;
        vector<int> input3 = {-3, 0, 1, -3, 1, 1, 1, -3, 10, 0};
        cout << (uniqueOccurrences(input3) ? "true" : "false") << endl;
        vector<int> input4 = {-1, 4, -5, 11, -3, 4, -1, 5, 0, 11, 3};
        cout << (uniqueOccurrences(input4) ? "true" : "false") << endl;
    }
};

#endif
