#pragma once
#ifndef _LEETCODE_806_H
#define _LEETCODE_806_H

#include <array>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;


class Solution806 {
public:
    vector<int> numberOfLines(vector<int> &widths, string S) {
        int number_of_a = 97;
        int line = 1;
        int number = 0;
        for (int32_t i{0}; i < S.size(); i++) {
            if (number + widths[S[i] - number_of_a] <= 100) {
                number += widths[S[i] - number_of_a];
            } else {
                number = widths[S[i] - number_of_a];
                line += 1;
            }

        }
        return vector<int>{line, number};

    }

    void test() {
        vector<int> vec1 = {10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                            10, 10, 10};
        string str1 = "abcdefghijklmnopqrstuvwxyz";
        cout << numberOfLines(vec1, str1)[0] << " " << numberOfLines(vec1, str1)[1] << endl;
        vector<int> vec2 = {4, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10, 10,
                            10, 10, 10};
        string str2 = "bbbcccdddaaa";
        cout << numberOfLines(vec2, str2)[0] << " " << numberOfLines(vec2, str2)[1] << endl;

    }
};

#endif
