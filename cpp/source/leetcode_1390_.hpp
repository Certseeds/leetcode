/*
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-22 22:03:19
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-23 00:32:35
 */
#ifndef _LEETCODE_1390_H_
#define _LEETCODE_1390_H_

#include <vector>
#include <numeric>
#include <algorithm>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

/*
Given an integer array nums, 
return the sum of divisors of the integers in that array that have exactly four divisors.
If there is no such integer in the array, return 0.

Example 1:
Input: nums = [21,4,7]
Output: 32
Explanation:
21 has 4 divisors: 1, 3, 7, 21
4 has 3 divisors: 1, 2, 4
7 has 2 divisors: 1, 7
The answer is the sum of divisors of 21 only.

Constraints:
1 <= nums.length <= 10^4
1 <= nums[i] <= 10^5
7.5 min to 30min.
unordered_set
sqrt
*/
class Solution1390 {
public:
    int32_t sumFourDivisors(vector<int32_t> &nums) {
        int32_t will_return = 0;
        for (auto i : nums) {
            will_return += get_four_divisors(i);
        }
        return will_return;
    }

    int32_t get_four_divisors(int32_t value) {
        unordered_set<int32_t> uset;
        int32_t max_range = static_cast<int>(std::sqrt(value) + 1);
        for (int32_t i = 1; i < max_range; i++) {
            if (0 == value % i) {
                uset.insert(i);
                uset.insert(value / i);
                if (uset.size() > 4) {
                    return 0;
                }
            }
        }
        return uset.size() == 4 ? std::accumulate(uset.begin(), uset.end(), 0) : 0;
    }

    void test() {
        assert(32 == get_four_divisors(21));
        assert(0 == get_four_divisors(4));
        assert(0 == get_four_divisors(7));
    }
};
/*
Runtime: 180 ms,
Memory Usage: 33.3 MB,
66.67%,100%.
*/
#endif
