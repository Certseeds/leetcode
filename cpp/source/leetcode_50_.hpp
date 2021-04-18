/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:48
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-07 21:53:29
 */
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_50_H
#define LEETCODE_CPP_SOURCE_LEETCODE_50_H

#include <vector>
#include <algorithm>
#include <numeric>

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
namespace Solution50 {
using std::cout;
using std::endl;
using std::less;
using std::vector;

class Solution50 {
public:
    double myPow(double x, int32_t n) {
        assert(-100.0f < x && x < 100.0f);
        assert(std::numeric_limits<int32_t>::min() <= n && n <= std::numeric_limits<int32_t>::max());
        if (0 == n) {
            return 1;
        } else if (1 == x || 0 == x) {
            return x;
        } else if (n < 0 && n != std::numeric_limits<int32_t>::min()) {
            return 1 / myPow(x, -n);
        } else if (std::numeric_limits<int32_t>::min() == n) {
            return 1 / (myPow(x, std::numeric_limits<int32_t>::max()) * x);
        }
        vector<double> pows(32, 0);
        pows[0] = x;
        pows[1] = x * x;
        vector<short> nums{};
        nums.reserve(32);
        for (int32_t i{1}; i <= 32; i++) {
            if ((n & (1 << (i - 1))) > 0) {
                nums.push_back(i);
                // 拆解成2^i次方之积
            }
        }
        std::sort(nums.begin(), nums.end(), less<>());
        for (const auto &i : nums) {
            quick_pow(pows, x, i);
        }
        double will_return{1.0f};
        for (const auto &i : nums) {
            will_return *= pows[i - 1];
        }
        return will_return;
    }

    double quick_pow(vector<double> &pows, double num, int32_t n) {
        assert(0 <= n && n < 32);
        assert(pows.size() == 32);
        if (pows[n] != 0) {
            return pows[n];
        }
        pows[n - 1] = quick_pow(pows, num, n - 1);
        return pows[n - 1] * pows[n - 1];
    }
};
}
/*
Runtime: 0 ms,
Memory Usage: 7.8 MB,
100%,100%.
*/
#endif //LEETCODE_CPP_SOURCE_LEETCODE_50_H