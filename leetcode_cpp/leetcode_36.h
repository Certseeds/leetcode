#pragma once
#ifndef _LEETCODE_36_H_
#define _LEETCODE_36_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-09 10:51:08
*/
#include <vector>
#include <algorithm>
#include <unordered_set>
using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;
/*
Determine if a 9x9 Sudoku board is valid.
Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the 9 3x3 sub-boxes of the grid must contain the digits 1-9 without repetition.

A partially filled sudoku which is valid.

The Sudoku board could be partially filled, 
where empty cells are filled with the character '.'.
*/
class Solution36 {
public:
    const int sizes_36 = 9;
    const int block_36 = 3;
    bool isValidSudoku(const vector<vector<char>>& board) {
        for (int i = 0; i < sizes_36; i++) {
            //cout << i << endl;
            if (!isValidSudoku_corss_line(board, i) ||
                !isValidSudoku_block(board, (i / block_36)* block_36, (i % block_36)* block_36)) {
                return false;
            }
        }
        return true;
    }
    bool isValidSudoku_block(const vector<vector<char>>& board,
        const int left, const int up) {
        unordered_set<int> uset;
        for (int i = 0; i < sizes_36; i++) {
            if (uset.count(board[left + i / block_36][up + i % block_36]) == 1) {
                return false;
            }
            if (board[left + i / block_36][up + i % block_36] != '.') {
                uset.insert(board[left + i / block_36][up + i % block_36]);
            }
        }
        return true;
    }
    bool isValidSudoku_corss_line(const vector<vector<char>>& board,const int number) {
        unordered_set<int> uset1;
        unordered_set<int> uset2;
        for (int i = 0; i < sizes_36; i++) {
            if (uset1.count(board[number][i]) == 1 ||
               (uset2.count(board[i][number]) == 1)
                    ) {
                return false;
            }
            if (board[number][i] != '.') {
                uset1.insert(board[number][i]);

            }
            if (board[i][number] != '.') {
                uset2.insert(board[i][number]);
            }
        }
        return true;
    }
    void test() {
        vector<vector<char>> vec1 = {
          {'5','3','.','.','7','.','.','.','.'},
          {'6','.','.','1','9','5','.','.','.'},
          {'.','9','8','.','.','.','.','6','.'},
          {'8','.','.','.','6','.','.','.','3'},
          {'4','.','.','8','.','3','.','.','1'},
          {'7','.','.','.','2','.','.','.','6'},
          {'.','6','.','.','.','.','2','8','.'},
          {'.','.','.','4','1','9','.','.','5'},
          {'.','.','.','.','8','.','.','7','9'} };
        assert(isValidSudoku(vec1) == true);
        vec1[0][0] = '8';
        assert(isValidSudoku(vec1) == false);
    }
};
/*
Runtime: 16 ms,
Memory Usage: 11 MB,
67.93%,28.81%.
*/
#endif
