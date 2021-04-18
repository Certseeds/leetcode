#pragma once
#ifndef _LEETCODE_661_H_
#define _LEETCODE_661_H_

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given a 2D integer matrix M representing the gray scale of an image,
you need to design a smoother to make the gray scale of each cell becomes
the average gray scale (rounding down) of all the 8 surrounding cells and itself.
If a cell has less than 8 surrounding cells, then use as many as you can.
*/
class Solution661 {
public:
    vector<vector<int>> imageSmoother(vector<vector<int>> &M) {
        int sizes = M.size();
        int sizes_in = M[0].size();
        cout << "sizes " << sizes << " " << sizes_in << endl;
        vector<vector<int>> willreturn(sizes, vector<int>(sizes_in, 0));
        if (sizes == 1) {
            if (sizes_in == 1) {
                return M;
            } else if (sizes_in == 2) {
                M[0][0] = (M[0][0] + M[0][1]) / 2;
                M[0][1] = M[0][0];
                return M;
            } else {
                willreturn[0][0] = (M[0][0] + M[0][1]) / 2;
                willreturn[0][sizes_in - 1] = (M[0][sizes_in - 2] + M[0][sizes_in - 1]) / 2;
                for (int32_t i{1}; i < sizes_in - 1; i++) {
                    willreturn[0][i] = (
                                               M[0][i - 1] + M[0][i] + M[0][i + 1]) / 3;
                }
                return willreturn;
            }
        } else if (sizes_in == 1) {
            if (sizes == 2) {
                willreturn[0][0] = (M[0][0] + M[1][0]) / 2;
                willreturn[1][0] = willreturn[0][0];
                return willreturn;
            } else {
                willreturn[0][0] = (M[0][0] + M[1][0]) / 2;
                willreturn[sizes - 1][0] = (M[sizes - 1][0]
                                            + M[sizes - 2][0]) / 2;
                for (int32_t i{1}; i < sizes - 1; i++) {
                    willreturn[i][0] = (
                                               M[i - 1][0] + M[i][0] + M[i + 1][0]) / 3;
                }
                return willreturn;
            }
        }
        willreturn[0][0] =
                (M[0][0] + M[0][1] +
                 M[1][0] + M[1][1]) / 4;
        willreturn[sizes - 1][0] =
                (M[sizes - 1][0] + M[sizes - 2][0] +
                 M[sizes - 2][1] + M[sizes - 1][1]) / 4;
        willreturn[0][sizes_in - 1] = (
                                              M[0][sizes_in - 1] + M[1][sizes_in - 1] +
                                              M[1][sizes_in - 2] + M[0][sizes_in - 2]
                                      ) / 4;
        willreturn[sizes - 1][sizes_in - 1] = (
                                                      M[sizes - 1][sizes_in - 1] + M[sizes - 1][sizes_in - 2] +
                                                      M[sizes - 2][sizes_in - 1] + M[sizes - 2][sizes_in - 2]
                                              ) / 4;
        for (int32_t i{1}; i < sizes_in - 1; i++) {
            willreturn[0][i] = (
                                       M[0][i - 1] + M[0][i] + M[0][i + 1] +
                                       M[1][i - 1] + M[1][i] + M[1][i + 1]) / 6;
            willreturn[sizes - 1][i] = (
                                               M[sizes - 2][i - 1] + M[sizes - 2][i] + M[sizes - 2][i + 1] +
                                               M[sizes - 1][i - 1] + M[sizes - 1][i] + M[sizes - 1][i + 1]) / 6;
        }
        for (int32_t i{1}; i < sizes - 1; i++) {
            willreturn[i][0] = (
                                       M[i - 1][0] + M[i][0] + M[i + 1][0] +
                                       M[i - 1][1] + M[i][1] + M[i + 1][1]
                               ) / 6;
            willreturn[i][sizes_in - 1] = (
                                                  M[i - 1][sizes_in - 1] + M[i][sizes_in - 1] + M[i + 1][sizes_in - 1] +
                                                  M[i - 1][sizes_in - 2] + M[i][sizes_in - 2] + M[i + 1][sizes_in - 2]
                                          ) / 6;
            for (int j = 1; j < sizes_in - 1; j++) {
                willreturn[i][j] = (
                                           M[i - 1][j - 1] + M[i][j - 1] + M[i + 1][j - 1] +
                                           M[i - 1][j] + M[i][j] + M[i + 1][j] +
                                           M[i - 1][j + 1] + M[i][j + 1] + M[i + 1][j + 1]
                                   ) / 9;
            }
        }
        return willreturn;
    }

    void test() {
        vector<vector<int>> vec1 = {
                {1, 1, 1},
                {1, 0, 1},
                {1, 1, 1}
        };
        vector<vector<int>> out1 = imageSmoother(vec1);
        for (auto i : out1) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        vector<vector<int>> vec2 = {
                {2,  3,  4},
                {5,  6,  7},
                {8,  9,  10},
                {11, 12, 13},
                {14, 15, 16}
        };
        vector<vector<int>> out2 = imageSmoother(vec2);
        for (auto i : out2) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        vector<vector<int>> vec3 = {
                {6, 9, 7}
        };
        vector<vector<int>> out3 = imageSmoother(vec3);
        for (auto i : out3) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
        vector<vector<int>> vec4 = {
                {7},
                {9},
                {6}
        };
        vector<vector<int>> out4 = imageSmoother(vec4);
        for (auto i : out4) {
            for (auto j : i) {
                cout << j << " ";
            }
            cout << endl;
        }
    }
};
/*
Runtime: 132 ms,
Memory Usage: 17.8 MB,
99.54%,50.00%.
*/
#endif