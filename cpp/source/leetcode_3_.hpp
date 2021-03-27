#pragma once
#ifndef _LEETCODE_3_H_
#define _LEETCODE_3_H_
/*
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-27 11:59:53
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-13 22:16:33
 */
/*  leetcode_cpp
   Copyright (C) 2020  nanoseeds

   leetcode_cpp is free software: you can redistribute it and/or modify
   it under the terms of the GNU Affero General Public License as
   published by the Free Software Foundation, either version 3 of the
   License, or (at your option) any later version.

   leetcode_cpp is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU Affero General Public License for more details.

   You should have received a copy of the GNU Affero General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.
   */
#include <vector>
#include <string>
#include <algorithm>
#include <unordered_map>

namespace Solution3 {
using namespace std;

/*
Given a string,
find the length of the longest substring without repeating characters.
greedy to get the max-length,if meet a repeat character,then throw the last one.
*/
class Solution3 {
public:
    int lengthOfLongestSubstring(string s) {
        int32_t maxv = std::numeric_limits<int16_t>::min();
        int32_t len = 0;
        int32_t begin = 0;
        int32_t s_size = s.size();
        //unordered_map<int, int> umap;
        vector<int> umap(128, 0);
        //128 not 26 because maybe have " ".
        for (int32_t i = 0; i < s_size; i++) {
            len++;
            if (umap[s[i]] != 0 && umap[s[i]] > begin) {
                len += (begin - umap[s[i]]);
                begin = umap[s[i]];
            }
            maxv = max(len, maxv);
            umap[s[i]] = i + 1;
        }
        return max(len, maxv);
    }

    int lengthOfLongestSubstring2(string s) {
        if (s.size() <= 1) {
            return s.size();
        }
        array<uint8_t, 256> uarray = {false};
        int32_t left = 0;
        int32_t right = 1;
        int32_t diff = 0;
        int32_t s_size = s.size();
        uarray[s[left]] = 1;
        while (right < s_size) {
            if (!uarray[s[right]]) {
                uarray[s[right]] = true;
                right++;
            } else {
                uarray[s[left]] = false;
                left++;
            }
            diff = std::max(diff, right - left);
        }
        return diff;
    }
};
}
/*
Hashmap:
Runtime: 28 ms,
Memory Usage: 10.9 MB,
43.%,53.23%.
vector:
Runtime: 8 ms,
Memory Usage: 10 MB,
94.79%,73.63%.
*/
#endif
