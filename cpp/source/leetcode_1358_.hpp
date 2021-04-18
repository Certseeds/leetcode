/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-22 23:10:46
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-23 01:10:24
 */
#ifndef _LEETCODE_1358_H_
#define _LEETCODE_1358_H_

#include <vector>
#include <string>
#include <algorithm>

using std::max;
using std::min;
using std::cout;
using std::endl;
using std::fill;
using std::vector;
using std::string;
/*
Given a string s consisting only of characters a, b and c.
Return the number of substrings containing at least
one occurrence of all these characters a, b and c.

Example 1:
Input: s = "abcabc"
Output: 10
Explanation: The substrings containing at least one
occurrence of the characters a, b and c
are "abc", "abca", "abcab", "abcabc", "bca", "bcab", "bcabc", "cab", "cabc" and "abc" (again).

Example 2:
Input: s = "aaacb"
Output: 3
Explanation: The substrings containing at least one
occurrence of the characters a, b and c
are "aaacb", "aacb" and "acb".

Example 3:
Input: s = "abc"
Output: 1

Constraints:
3 <= s.length <= 5 x 10^4
s only consists of a, b or c characters.
23:08-24:53
*/
//24:53
class Solution1358 {
public:
    int numberOfSubstrings(string s) {
        int count = 0;
        vector<int> temp(3, 0);
        vector<int> a(s.size(), 0);
        vector<int> b(s.size(), 0);
        vector<int> c(s.size(), 0);
        for (int32_t i{0}; i < s.size(); i++) {
            temp[s[i] - 'a']++;
        }
        if (temp[0] == 0 || temp[1] == 0 || temp[2] == 0) {
            return 0;
        }
        get_nexts('a', a, s);
        get_nexts('b', b, s);
        get_nexts('c', c, s);
        for (int32_t i{0}; i <= s.size() - 3; i++) {
            switch (s[i]) {
                case 'a': {
                    if (b[i] == 0 || c[i] == 0) {
                        return count;
                    }
                    count += (s.size() - max(b[i], c[i]));
                    break;
                }
                case 'b': {
                    if (a[i] == 0 || c[i] == 0) {
                        return count;
                    }
                    count += (s.size() - max(c[i], a[i]));
                    break;
                }
                case 'c': {
                    if (a[i] == 0 || b[i] == 0) {
                        return count;
                    }
                    count += (s.size() - max(b[i], a[i]));
                    break;
                }
            }
        }
        return count;
    }

    void get_nexts(const char &ch, vector<int> &vec, const string &s) {
        for (int32_t i{0}; i < s.size();) {
            //cout << i << endl;
            int find = 0;
            for (int j = i + 1; j < s.size(); j++) {
                //cout << s[i] << " " << s[j] << endl;
                if (ch == s[j]) {
                    std::fill(vec.begin() + i, vec.begin() + j, j);
                    find = 1;
                    i = j;
                    break;
                }
            }
            if (0 == find) {
                return;
            }
        }
    }

    void test() {
        cout << "effctive test" << endl;
        assert(11 == numberOfSubstrings("acbbcac"));
        cout << "normal test 1" << endl;
        assert(10 == numberOfSubstrings("abcabc"));
        cout << "normal test 2" << endl;
        assert(3 == numberOfSubstrings("aaacb"));
        cout << "normal test 3" << endl;
        assert(1 == numberOfSubstrings("abc"));
    }
};
/*
Runtime: 28 ms,
Memory Usage: 16.9 MB,
66.67%,100%.
*/
#endif
