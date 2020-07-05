/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-07 22:54:29
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-08 00:56:00
 */
#ifndef _LEETCODE_1370_H_
#define _LEETCODE_1370_H_

#include <array>
#include <string>
#include <algorithm>

using std::string;
using std::array;

/*
Given a string s. You should re-order the string using the following algorithm:
Pick the smallest character from s and append it to the result.
Pick the smallest character from s which is greater 
than the last appended character to the result and append it.
Repeat step 2 until you cannot pick more characters.
Pick the largest character from s and append it to the result.
Pick the largest character from s which is smaller 
than the last appended character to the result and append it.
Repeat step 5 until you cannot pick more characters.
Repeat the steps from 1 to 6 until you pick all characters from s.
In each step, If the smallest or the largest character appears 
more than once you can choose any occurrence and append it to the result.
Return the result string after sorting s with this algorithm.

Example 1:
Input: s = "aaaabbbbcccc"
Output: "abccbaabccba"
Explanation: After steps 1, 2 and 3 of the first iteration, result = "abc"
After steps 4, 5 and 6 of the first iteration, result = "abccba"
First iteration is done. Now s = "aabbcc" and we go back to step 1
After steps 1, 2 and 3 of the second iteration, result = "abccbaabc"
After steps 4, 5 and 6 of the second iteration, result = "abccbaabccba"

Example 2:
Input: s = "rat"
Output: "art"
Explanation: The word "rat" becomes "art" after re-ordering it 
with the mentioned algorithm.

Example 3:
Input: s = "leetcode"
Output: "cdelotee"

Example 4:
Input: s = "ggggggg"
Output: "ggggggg"

Example 5:
Input: s = "spo"
Output: "ops"

Constraints:
1 <= s.length <= 500
s contains only lower-case English letters.
10:36-10:54
*/
class Solution1370 {
public:
    string sortString(string s) {
        array<int, 26> charset = {0};
        for (auto i : s) {
            charset[i - static_cast<int>('a')]++;
        }
        string will_return = "";
        string added = "null";
        while (added != "") {
            added = pos_charset(charset);
            will_return += added;
            added = neg_charset(charset);
            will_return += added;
        }
        return will_return;
    }

    string pos_charset(array<int, 26> &charset) {
        string will_return = "";
        for (int i = 0; i < charset.size(); i++) {
            if (charset[i] > 0) {
                will_return += static_cast<char>(i + 'a');
                charset[i]--;
            }
        }
        return will_return;
    }

    string neg_charset(array<int, 26> &charset) {
        string will_return = "";
        for (int i = 25; i >= 0; i--) {
            if (charset[i] > 0) {
                will_return += static_cast<char>(i + 'a');
                charset[i]--;

            }
        }
        return will_return;
    }

    void test() {
        assert("abccbaabccba" == sortString("aaaabbbbcccc"));
        assert("art" == sortString("rat"));
        assert("cdelotee" == sortString("leetcode"));
        assert("ggggggg" == sortString("ggggggg"));
        assert("ops" == sortString("spo"));
    }
};
/*
Runtime: 0 ms,
Memory Usage: 9.5 MB,
100%,100%.
*/
#endif