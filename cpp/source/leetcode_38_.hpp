#pragma once
#ifndef _LEETCODE_38_H_
#define _LEETCODE_38_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:47
 * @LastEditors  : nanoseeds
 * @LastEditTime : 2020-02-09 11:31:56
*/
#include <string>
#include <algorithm>

using std::cout;
using std::endl;
using std::string;

/*
The count-and-say sequence is 
the sequence of integers with the first five terms as following:

1.     1
2.     11
3.     21
4.     1211
5.     111221
1 is read off as "one 1" or 11.
11 is read off as "two 1s" or 21.
21 is read off as "one 2, then one 1" or 1211.

Given an integer n where 1 �� n �� 30, generate the nth term of the count-and-say sequence. You can do so recursively, in other words from the previous member read off the digits, counting the number of digits in groups of the same digit.

Note: Each term of the sequence of integers will be represented as a string.
it is simple,get the same numbers into one and then read it one by one.
do not need to consider if double different number connect will happen what.
*/
class Solution38 {
public:
    string countAndSay(const int n) {
        if (n == 1) {
            return "1";
        }
        string str1 = countAndSay(n - 1);
        string will_return = "";
        for (int i = 0; i < str1.size();) {
            int length = 0;
            while (str1[i + length] == str1[i]) {
                length++;
            }
            will_return.append(1, length + '0');
            will_return.append(1, str1[i]);
            i += length;
        }
        return will_return;
    }

    void test() {
        /*  
          cout << countAndSay(1) << endl;
          cout << countAndSay(2) << endl;
          cout << countAndSay(3) << endl;
          cout << countAndSay(4) << endl;
          cout << countAndSay(5) << endl;
          cout << countAndSay(6) << endl;
          cout << countAndSay(7) << endl;
          */
        assert(countAndSay(1) == "1");
        assert(countAndSay(2) == "11");
        assert(countAndSay(3) == "21");
        assert(countAndSay(4) == "1211");
        assert(countAndSay(5) == "111221");
        assert(countAndSay(6) == "312211");
        assert(countAndSay(7) == "13112221");
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.8 MB,
100%,87.50%.
*/
#endif
