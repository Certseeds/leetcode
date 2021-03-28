#ifndef _LEETCODE_8_H
#define _LEETCODE_8_H
/*  leetcode
    Copyright (C) 2020  nanoseeds

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
/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @LastEditors  : nanoseeds
 */
#include <string>
#include <algorithm>

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
within the 32-bit signed integer range: [−2^31,  2^31 − 1].
If the numerical value is out of the range of representable values,
INT_MAX (2^31 − 1) or INT_MIN (−2^31) is returned.
*/
namespace Solution8 {
using namespace std;

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
            if (will_return > std::numeric_limits<int32_t>::max()) {
                return sign == 1 ? std::numeric_limits<int32_t>::max() :
                       std::numeric_limits<int32_t>::min();
            }
        }
        return static_cast<int32_t>(will_return * sign);
    }
};
}
/*
Runtime: 0 ms,
Memory Usage: 8.6 MB,
100%,25.37%.
*/
#endif
