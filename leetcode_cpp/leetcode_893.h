#pragma once
#ifndef _LEETCODE_893_H
#define _LEETCODE_893_H
#include <string>
#include <queue>
#include <set>
using namespace std;


class Solution893 {
public:
    int numSpecialEquivGroups(vector<string>& A) {
        vector < vector<array<int, 27>> >maps;
        for (int i = 0; i < A.size(); i++) {
            vector<array<int, 27>> map_in;
            array<int, 27> single = {0};
            array<int, 27> doub = { 0 };
            map_in.push_back(single);
            map_in.push_back(doub);
            for (int j = 0; j < A[i].size(); j++) {
                map_in[j % 2][A[i][j] -96]++;
            }
            maps.push_back(map_in);
        }
        set<array<int, 52>> willreturn;

        for (int i = 0; i < A.size(); i++) {
            array<int, 52> temp = { 0 };
            for (int j = 1; j <= 26; j++) {
                temp[j-1] = maps[i][0][j];
                temp[j+25] = maps[i][1][j];

            }
            willreturn.insert(temp);
        }
        return willreturn.size();

       
    }int numSpecialEquivGroups2(vector<string>& A) {
        set < array<int, 52> >maps;
        for (int i = 0; i < A.size(); i++) {
            array<int, 52> nums = { 0 };
            for (int j = 0; j < A[i].size(); j++) {
               nums[A[i][j] - 97+ (j % 2) * 26]++;
            }
            maps.insert(nums);
        }
        return maps.size();
    }
    void test() {
        vector<string> str1 = { "abcd", "cdab", "cbad", "xyzz", "zzxy", "zzyx" };
        cout << numSpecialEquivGroups2(str1) << endl;
        cout << (int)str1[0][0] -96 << endl;
    }
};

#endif
