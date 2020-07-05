#pragma once
#ifndef _LEETCODE_999_H
#define _LEETCODE_999_H

#include <vector>

using namespace std;

class Solution999 {
public:
    int numRookCaptures(vector<vector<char>> &board) {
        int x = 0;
        int y = 0;
        for (short i = 0; i < 8; i++) {
            for (short j = 0; j < 8; j++) {
                if (board[i][j] == 'R') {
                    x = i;
                    y = j;
                }
            }
        }
        bool judge1 = false;
        for (int i = x + 1; i < 8; i++) {
            //cout << board[i][y] << endl;
            switch (board[i][y]) {
                case 'B': {
                    i = 8;
                    break;
                }
                case '.': {
                    break;
                }

                case 'p': {
                    i = 8;
                    judge1 = true;
                    break;
                }

            }
        }
        //cout << judge1 << " 1 " << endl;
        bool judge2 = false;
        for (short i = x - 1; i >= 0; i--) {
            //cout << board[i][y] << endl;
            switch (board[i][y]) {
                case 'B': {
                    i = 0;
                    break;
                }

                case '.': {
                    break;
                }

                case 'p': {
                    judge2 = true;
                    i = 0;
                    break;
                }
            }
        }

        //cout << judge2 << " 2 " << endl;
        bool judge3 = false;
        for (short i = y - 1; i >= 0; i--) {
            //cout << board[x][i] << endl;
            switch (board[x][i]) {
                case 'B': {
                    i = 0;
                    break;
                }

                case '.': {
                    break;
                }

                case 'p': {
                    judge3 = true;
                    i = 0;
                    break;
                }
            }
        }
        //cout << judge3 << " 3 " << endl;
        bool judge4 = false;
        for (int i = y + 1; i < 8; i++) {
            //cout << board[x][i] << endl;
            switch (board[x][i]) {
                case 'B': {
                    i = 8;
                    break;
                }

                case '.': {
                    break;
                }

                case 'p': {
                    judge4 = true;
                    i = 8;
                    break;
                }

            }
        }
        //cout << judge4 << " 4 " << endl;
        return (judge1 + judge2 + judge3 + judge4);
    }

};

#endif
