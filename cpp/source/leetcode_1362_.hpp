/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-23 11:29:08
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-23 12:30:37
 */
#ifndef _LEETCODE_1362_H_
#define _LEETCODE_1362_H_

#include <vector>
#include <algorithm>

using std::max;
using std::min;
using std::cout;
using std::endl;
using std::vector;

/*
Given an integer num,
find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
Return the two integers in any order.

Example 1:
Input: num = 8
Output: [3,3]
Explanation: For num + 1 = 9,
the closest divisors are 3 & 3,
for num + 2 = 10,
the closest divisors are 2 & 5,
hence 3 & 3 is chosen.

Example 2:
Input: num = 123
Output: [5,25]

Example 3:
Input: num = 999
Output: [40,25]

Constraints:
1 <= num <= 10^9
11:21-11:39
*/
class Solution1362 {
public:
    vector<int> closestDivisors(int num) {
        int range = sqrt(num) + 1;
        vector<int> ranges1(range + 1, INT32_MAX);
        vector<int> ranges2(range + 1, INT32_MAX);
        for (int32_t i{1}; i < range + 1; i++) {
            ranges1[i] = (num + 1) / i;
            ranges2[i] = (num + 2) / i;
        }
        int diff1 = INT32_MAX;
        int pos1 = 0;
        for (int32_t i{1}; i < range + 1; i++) {
            if (num + 1 == ranges1[i] * i) {
                if (diff1 > (max(i, ranges1[i]) - min(i, ranges1[i]))) {
                    diff1 = (max(i, ranges1[i]) - min(i, ranges1[i]));
                    pos1 = i;
                }
            }
        }
        int diff2 = INT32_MAX;
        int pos2 = 0;
        for (int32_t i{1}; i < range + 1; i++) {
            if (num + 2 == ranges2[i] * i) {
                if (diff2 > (max(i, ranges2[i]) - min(i, ranges2[i]))) {
                    diff2 = (max(i, ranges2[i]) - min(i, ranges2[i]));
                    pos2 = i;
                }
            }
        }
        if (diff1 > diff2) {
            return vector<int>{pos2, ranges2[pos2]};
        }
        return vector<int>{pos1, ranges1[pos1]};
    }

    void test() {
        vector<int> out1 = closestDivisors(8);
        vector<int> out2 = closestDivisors(123);
        vector<int> out3 = closestDivisors(999);
        cout << "normal test 1" << endl;
        assert(3 == out1[0] && 3 == out1[1]);
        cout << "can it choose smaller test" << endl;
        assert(5 == out2[0] && 25 == out2[1]);
        cout << "smaller in 0 and bigger in 1 test" << endl;
        assert(25 == out3[0] && 40 == out3[1]);
    }
};
/*
Runtime: 28 ms,
Memory Usage: 27.9 MB,
66.67%,100%.
*/
#endif
