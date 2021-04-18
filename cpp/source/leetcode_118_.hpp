#pragma once
#ifndef _LEETCODE_118_H_
#define _LEETCODE_118_H_

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given a non-negative integer numRows,
generate the first numRows of Pascal's triangle.
*/
class Solution118 {
public:
    inline vector<vector<int>> generate(int numRows) {
        vector<vector<int>> willreturn;
        vector<int> temp = {};
        for (int32_t i{1}; i <= numRows; i++) {
            temp = generate_help(temp);
            willreturn.push_back(temp);
        }
        return willreturn;
    }

    inline vector<int> generate_help(vector<int> vec) {
        vector<int> willreturn(vec);
        willreturn.push_back(1);
        for (int32_t i{1}; i < vec.size(); i++) {
            willreturn[i] = vec[i - 1] + vec[i];
        }
        return willreturn;
    }

    void test() {
        vector<vector<int>> out1 = generate(0);
        for (auto i : out1) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        vector<vector<int>> out2 = generate(5);
        for (auto i : out2) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
/*
Runtime: 4 ms,
Memory Usage: 8.9 MB,
61.92%,44.44%.
*/
#endif
