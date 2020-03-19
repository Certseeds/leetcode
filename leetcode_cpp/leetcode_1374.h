/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-14 19:21:20
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-14 20:01:20
 */
#ifndef _LEETCODE_1374_H_
#define _LEETCODE_1374_H_
#include <vector>
#include <string>
#include <algorithm>
using std::max; 
using std::cout;
using std::endl;
using std::vector;
using std::string;
/*
Given an integer n, 
return a string with n characters such that each character in such string occurs an odd number of times.

The returned string must contain only lowercase English letters. 
If there are multiples valid strings, return any of them.  
*/
class Solution1374 {
public:
    string generateTheString(int n) {
        char* str = new char[n + 1];
        memset(str, 'b', sizeof(char) * n);
        str[n] = '\0';
        if (1 == n % 2) {
            str[n - 1] = 'z';
            n--;
        }
        if (0 != n) {
            str[0] = 'a';
        }
        string will_return = string(str);
        delete[] str;
        return will_return;
    }
    void test() {
        assert("" == generateTheString(0));
        assert("z" == generateTheString(1));
        assert("ab" == generateTheString(2));
        assert("abz" == generateTheString(3));
        assert("abbb" == generateTheString(4));
    }
};
/*
Runtime:0 ms,
Memory Usage: 7.8 MB,
100%,100%.
*/
#endif