#pragma once
#ifndef _LEETCODE_1277_H_
#define _LEETCODE_1277_H_

#include <vector>
#include <array>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given a m * n matrix of ones and zeros,
return how many square submatrices have all ones.
*/
// DP
class Solution1277 {
public:
    int countSquares_old(vector<vector<int>> &matrix) {
        int xmax = matrix.size();
        int ymax = matrix[0].size();
        vector<vector<int>> row(matrix);
        vector<vector<int>> column(matrix);
        for (int32_t i{0}; i < xmax; i++) {
            for (int j = 1; j < ymax; j++) {
                row[i][j] += row[i][j - 1];
            }
        }
        for (int32_t i{1}; i < xmax; i++) {
            for (int j = 0; j < ymax; j++) {
                column[i][j] += column[i - 1][j];
            }
        }
        int count = std::accumulate(column[xmax - 1].begin(), column[xmax - 1].end(), 0);
        //cout << count << " begin" << endl;
        for (int32_t i{0}; i < xmax; i++) {
            for (int j = 0; j < ymax; j++) {
                // cout << i << " " << j << endl;
                if (!matrix[i][j]) {
                    continue;
                }
                for (int k = 1; k < min(xmax - i, ymax - j); k++) {
                    // cout << k << " ";
                    //cout << (matrix[i + k][j + k]) << " ";
                    // cout << (row[i+k][j + k] - row[i+k][j]) << " ";
                    // cout << (column[i + k][j+k] - column[i][j+k]) << endl;
                    if (matrix[i + k][j + k] &&
                        (row[i + k][j + k] - row[i + k][j] == k) &&
                        (column[i + k][j + k] - column[i][j + k] == k) &&
                        (matrix[i + k][j]) &&
                        (matrix[i][j + k])
                            ) {
                        count++;
                    } else {
                        break;
                    }
                }
                //cout << count << endl;
            }
        }
        return count;
    }

    int countSquares_N_2(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        int32_t will_return = 0;
        int32_t row = matrix.size();
        int32_t col = matrix.front().size();
        vector<vector<int32_t>> dp(row + 1, vector<int32_t>(col + 1));
        for (int32_t i{0}; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                dp[i + 1][j + 1] = dp[i][j + 1] + dp[i + 1][j] - dp[i][j] + matrix[i][j];
            }
        }
        will_return += dp.back().back();
        for (int32_t i{0}; i < row; ++i) {
            for (int j = 0; j < col; ++j) {
                for (int k = 1; k < min(row - i, col - j); ++k) {
                    if (dp[i + k + 1][j + k + 1] - dp[i][j + k + 1] - dp[i + k + 1][j] + dp[i][j] ==
                        (k + 1) * (k + 1)) {
                        will_return++;
                    } else {
                        break;
                    }
                }
            }
        }
        return will_return;
    }

    int countSquares(vector<vector<int>> &matrix) {
        if (matrix.empty() || matrix.front().empty()) {
            return 0;
        }
        int32_t will_return = 0;
        int32_t row = matrix.size();
        int32_t col = matrix.front().size();
        will_return -= matrix[0][0];
        for (int32_t i{0}; i < col; ++i) {
            will_return += matrix[0][i];
        }
        for (int32_t i{0}; i < row; ++i) {
            will_return += matrix[i][0];
        }
        for (int32_t i{1}; i < row; ++i) {
            for (int j = 1; j < col; ++j) {
                if (matrix[i][j] == 1) {
                    matrix[i][j] = 1 + min(min(matrix[i - 1][j], matrix[i][j - 1]), matrix[i - 1][j - 1]);
                    will_return += matrix[i][j];
                }
            }
        }
        return will_return;
    }

    void test() {
        vector<vector<int>> vec1 = {
                {0, 1, 1, 1},
                {1, 1, 1, 1},
                {0, 1, 1, 1}};
        cout << countSquares(vec1) << endl;
        vector<vector<int>> vec2 = {
                {1, 1, 0, 0, 1},
                {1, 0, 1, 1, 1},
                {1, 1, 1, 1, 1},
                {1, 0, 1, 0, 1},
                {0, 0, 1, 0, 1}};
        cout << countSquares(vec2) << endl;
    }
};
/*
Runtime: 56 ms,
Memory Usage: 21.3 MB,
97.25%,100%.
*/
#endif
