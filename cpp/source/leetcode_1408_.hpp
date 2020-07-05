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
/**
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-04-15 09:45:52 
 * @LastEditors  : nanoseeds
 */
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_1408_H
#define LEETCODE_CPP_SOURCE_LEETCODE_1408_H

#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using std::max;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::unordered_set;


bool cmp_length(const string &s1, const string &s2) {
    return s1.length() > s2.length();
}

class Solution1408 {
    vector<string> stringMatching(vector<string> &words) {
        vector<string> will_return;
        std::sort(words.begin(), words.end(), cmp_length);
        if (words.empty()) {
            return will_return;
        }
        unordered_set<string> temp;
        for (const auto &i:words) {
            cout << i << endl;
            cout << i.size() << endl;
        }
        for (int i = words.size() - 1; i >= 0; i--) {
            for (int j = 0; j < i; ++j) {
                if (words[j].find(words[i]) != string::npos) {
                    temp.insert(words[i]);
                }
            }
        }
        for (const auto &i:temp) {
            will_return.push_back(i);
        }
        return will_return;
    }

public:
    void test() {
        vector<string> vec1 = {"leetcoder", "leetcode", "od", "hamlet", "am"};
        vector<string> output1 = stringMatching(vec1);
        for (const auto &i:output1) {
            cout << i << endl;
        }
    }
};

#endif //LEETCODE_CPP_SOURCE_LEETCODE_1408_H
