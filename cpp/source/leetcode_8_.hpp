#pragma once
#ifndef _LEETCODE_8_H
#define _LEETCODE_8_H

#include <string>
#include <algorithm>

using namespace std;

/*
Implement atoi which converts a string to an integer.

The function first discards as many whitespace characters as necessary 
until the first non-whitespace character is found. 
Then, starting from this character, 
takes an optional initial plus or minus sign followed by as many numerical digits 
as possible, and interprets them as a numerical value.

The string can contain additional characters after 
those that form the integral number, 
which are ignored and have no effect on the behavior of this function.

If the first sequence of non-whitespace characters 
in str is not a valid integral number, 
or if no such sequence exists because either str is empty or 
it contains only whitespace characters, no conversion is performed.

If no valid conversion could be performed, a zero value is returned.

Note:

Only the space character ' ' is considered as whitespace character.
Assume we are dealing with an environment which could only store integers 
within the 32-bit signed integer range: [−231,  231 − 1]. 
If the numerical value is out of the range of representable values, 
INT_MAX (231 − 1) or INT_MIN (−231) is returned.
*/
class Solution8 {
public:
    int myAtoi(string str) {
        int begin = 0;
        while (str[begin] == ' ') {
            begin++;
        }
        int sign = 1;
        long long will_return = 0;
        if (str[begin] >= 'a' && str[begin] <= 'z') {
            return 0;
        } else if (str[begin] == '+') {
            begin++;
        } else if (str[begin] == '-') {
            sign = -1;
            begin++;
        }
        while (str[begin] >= '0' && str[begin] <= '9') {
            will_return = will_return * 10 + (str[begin] - '0');
            begin++;
            if (will_return > INT32_MAX) {
                return sign == 1 ? INT32_MAX : INT32_MIN;
            }
        }
        return will_return * sign;
    }

    void test() {
        cout << myAtoi("42") << endl;
        cout << myAtoi("   -42") << endl;
        cout << myAtoi("114514 with words") << endl;
        cout << myAtoi("words and 1919810") << endl;
        cout << myAtoi("-91283472332") << endl;
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.6 MB,
100%,25.37%.
*/
#endif
