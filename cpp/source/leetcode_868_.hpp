/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-23 12:37:24
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-23 12:43:55
 */
#ifndef _LEETCODE_868_H_
#define _LEETCODE_868_H_

#include <vector>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;
using std::vector;

/*
Given a positive integer N, 
find and return the longest distance 
between two consecutive 1's in the binary representation of N.
If there aren't two consecutive 1's, 
return 0.

Example 1:
Input: 22
Output: 2
Explanation:
22 in binary is 0b10110.
In the binary representation of 22, 
there are three ones, and two consecutive pairs of 1's.
The first consecutive pair of 1's have distance 2.
The second consecutive pair of 1's have distance 1.
The answer is the largest of these two distances, 
which is 2.

Example 2:
Input: 5
Output: 2
Explanation:
5 in binary is 0b101.

Example 3:
Input: 6
Output: 1
Explanation:
6 in binary is 0b110.

Example 4:
Input: 8
Output: 0
Explanation:
8 in binary is 0b1000.
There aren't any consecutive pairs of 1's in 
the binary representation of 8, so we return 0.

Note:
1 <= N <= 10^9
*/
class Solution868 {
public:
    int binaryGap(int N) {
        vector<int> ones;
        ones.reserve(32);
        while (N > 0) {
            ones.push_back(N % 2);
            N /= 2;
        }
        vector<int> pos;
        for (int i = 0; i < ones.size(); i++) {
            if (1 == ones[i]) {
                pos.push_back(i);
            }
        }
        int diff = 0;
        for (int i = 0; i < pos.size() - 1; i++) {
            diff = max(diff, pos[i + 1] - pos[i]);
        }
        return diff;
    }

    void test() {
        cout << "normal test 1" << endl;
        assert(2 == binaryGap(22));
        cout << "normal test 2" << endl;
        assert(2 == binaryGap(5));
        cout << "normal test 3" << endl;
        assert(1 == binaryGap(6));
        cout << "zero test 1" << endl;
        assert(0 == binaryGap(8));
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.6 MB,
100%,12.50%.
*/
#endif
