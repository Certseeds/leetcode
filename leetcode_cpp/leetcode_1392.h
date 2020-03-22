/*
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-22 23:13:11
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-23 00:32:42
 */
#ifndef _LEETCODE_1392_H_
#define _LEETCODE_1392_H_
#include <string>
#include <algorithm>
using std::max;
using std::cout;
using std::endl;
using std::string;
/*
A string is called a happy prefix if is a non-empty prefix which is also a suffix (excluding itself).
Given a string s. Return the longest happy prefix of s .
Return an empty string if no such prefix exists.

Example 1:
Input: s = "level"
Output: "l"
Explanation: s contains 4 prefix excluding itself ("l", "le", "lev", "leve"), and suffix ("l", "el", "vel", "evel"). The largest prefix which is also suffix is given by "l".

Example 2:
Input: s = "ababab"
Output: "abab"
Explanation: "abab" is the largest prefix which is also suffix. They can overlap in the original string.

Example 3:
Input: s = "leetcodeleet"
Output: "leet"

Example 4:
Input: s = "a"
Output: ""

Constraints:
1 <= s.length <= 10^5
s contains only lowercase English letters.
78min->120min.
infact it is get it's max common prefix and suffix.
*/
class Solution1392 {
public:
    string longestPrefix(const string& s) {
        int32_t count = 0;
        for (int32_t i = 0; i < s.size()-1; i++) {
            if ( 0 == memcmp(&s[0], &s[s.size() - 1 - i], (i + 1))) {
                count = i + 1;
            }
        }
        return s.substr(0, count);
    }
    void test() {
        assert("l" == longestPrefix("level"));
        assert("leet" == longestPrefix("leetcodeleet"));
        assert("" == longestPrefix("a"));
        assert("abab" == longestPrefix("ababab"));
    }
};
/*
Runtime: 452 ms,
Memory Usage: 14.3 MB,
14.29%,100%.
*/
#endif
