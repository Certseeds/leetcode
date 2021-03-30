#ifndef _LEETCODE_20_H
#define _LEETCODE_20_H
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:46
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-06 10:40:03
 */
/*  leetcode
    Copyright (C) 2020-2021  nanoseeds

    leetcode is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    leetcode is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
#include <stack>
#include <string>
#include <algorithm>
#include <unordered_map>


/*
Given a string containing just the characters
'(', ')', '{', '}', '[' and ']',
determine if the input string is valid.

An input string is valid if:

Open brackets must be closed by the same type of brackets.
Open brackets must be closed in the correct order.
Note that an empty string is also considered valid.
*/
namespace Solution20 {
using std::string;

class Solution20 {
public:
    bool isValid(const string &s) {
        std::stack<uint8_t> stk;
        std::unordered_map<uint8_t, uint8_t> umap;
        umap['('] = ')';
        umap['['] = ']';
        umap['{'] = '}';
        stk.push('?');
        for (const auto i : s) {
            if (umap[stk.top()] == i) {
                stk.pop();
            } else {
                stk.push(i);
            }
        }
        stk.pop();
        return stk.empty();
    }
};
}
/*
Runtime: 0 ms,
Memory Usage: 8.7 MB,
100%,40.31%.
*/
#endif
