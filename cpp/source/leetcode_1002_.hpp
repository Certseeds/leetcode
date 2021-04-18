#pragma once
#ifndef _LEETCODE_1002_H
#define _LEETCODE_1002_H

#include <vector>
#include <array>
#include <string>

using namespace std;


class Solution1002 {
public:
    vector<string> commonChars(vector<string> &A) {
        vector<array<int, 26>> numbers;
        vector<string> willreturn;
        array<string, 26> filling = {
                "a", "b", "c", "d", "e", "f", "g", "h",
                "i", "j", "k", "l", "m", "n", "o", "p",
                "q", "r", "s", "t", "u", "v", "w", "x",
                "y", "z"};
        array<int, 26> max;
        max.fill(0);
        for (int32_t i{0}; i < A.size(); i++) {
            std::array<int, 26> temp;
            temp.fill(0);
            for (int j = 0; j < A[i].size(); j++) {
                temp[A[i][j] - 97] += 1;
            }
            numbers.push_back(temp);
        }

        for (int32_t i{0}; i < 26; i++) {
            int x = 0x3f3f3f3f;
            for (int j = 0; j < A.size(); j++) {
                x = x > numbers[j][i] ? numbers[j][i] : x;
            }
            max[i] = x;
        }
        for (int32_t i{0}; i < 26; i++) {
            int numbers = max[i];
            for (int j = 0; j < numbers; j++) {
                willreturn.push_back(filling[i]);
            }
        }
        return willreturn;
    }
};

#endif
