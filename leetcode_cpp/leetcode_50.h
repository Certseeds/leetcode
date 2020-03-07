/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:48
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-07 21:53:29
 */
#ifndef _LEETCODE_50_H_
#define _LEETCODE_50_H_
#include <vector>
#include <algorithm>
#include <numeric>
using std::cout;
using std::endl;
using std::less;
using std::vector;
/*
Implement pow(x, n),
which calculates x raised to the power x^n.

Example 1:
Input: 2.00000, 10
Output: 1024.00000

Example 2:
Input: 2.10000, 3
Output: 9.26100

Example 3:
Input: 2.00000, -2
Output: 0.25000
Explanation: 2^-2 = 1/(2^2) = 1/4 = 0.25

Note:
-100.0 < x < 100.0
n is a 32-bit signed integer,
within the range [−2^31, 2^31 − 1]
*/
const int one = 1;
class Solution50 {
public:
    double myPow(double x,int n) {
        assert(x < 100);
        assert(x > -100);
        if (0 == n) {
            return 1;
        }else if (one == x) {
            return 1;
        }
        else if (0 == x) {
            return 0;
        }
        else if (n < 0 && n != -2147483648) {
            return one / myPow(x, -n);
        }
        else if (-2147483648 == n) {
            return one / (myPow(x, -n - one) * x);
        }
        vector<double> pows(32, 0);
        pows[0] = x;
        pows[1] = x * x;
        vector<short> nums = {};
        nums.reserve(32);
        for (int i = one; i <= 32; i++) {
            if ((n & (one <<(i-one) ) ) > 0) {
                nums.push_back(i);
            }
        }
        std::sort(nums.begin(), nums.end(), less<short>());
        for (auto i : nums) {
            quick_pow(pows, x, i);
        }
        double will_return = one;
        for (auto i : nums) {
            will_return *= pows[i-one];
        }
        return will_return; 
    }
    double quick_pow(vector<double>& pows,double num,int n) {
        assert(n >= 0);
        assert(n < 32);
        assert(pows.size() == 32);
        if (0 == n) {
            return num;
        }
        else if (one == n) {
            return num*num;
        }
        if (pows[n] != 0) {
            return pows[n];
        }
        pows[n - one] = quick_pow(pows, num, n - one);
        return pows[n - one] * pows[n - one];
    }
    void test() {
        assert(0.0f == myPow(2.00000, -2147483648));
        assert(1024.0f == myPow(2.00000,10));
        cout << myPow(2.1, 3) << endl;
        // assert(9.261f == myPow(2.1, 3));
        // double can not judge equal only by ==
        assert(0.25000f == myPow(2.00000, -2));
    }
};
/*
Runtime: 0 ms,
Memory Usage: 7.8 MB,
100%,100%.
*/
#endif
