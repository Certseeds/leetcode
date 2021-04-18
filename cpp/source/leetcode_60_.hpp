/*
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-01-17 13:18:49
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-19 08:51:53
 */
#ifndef _LEETCODE_60_H_
#define _LEETCODE_60_H_

#include <vector>
#include <array>
#include <string>
#include <algorithm>

using std::max;
using std::cout;
using std::endl;
using std::array;
using std::vector;
using std::string;

/*
The set [1,2,3,...,n] contains a total of n! unique permutations.
By listing and labeling all of the permutations in order, we get the following sequence for n = 3:
"123"
"132"
"213"
"231"
"312"
"321"
Given n and k, return the kth permutation sequence.
Note:
Given n will be between 1 and 9 inclusive.
Given k will be between 1 and n! inclusive.

Example 1:
Input: n = 3, k = 3
Output: "213"

Example 2:
Input: n = 4, k = 9
Output: "2314"
*/
class Solution60 {
public:
    constexpr uint32_t facts(uint32_t t) {
        uint32_t will_return = 1;
        for (uint32_t x = 1; x <= t; x++) {
            will_return *= x;
        }
        return will_return;
    }// c++ 14 constexpr, count facts in complier time.
    string getPermutation(int32_t n, int32_t k) {
        vector<uint32_t> fact(10, 1);
        for (int32_t i{0}; i < 10; i++) {
            fact[i] = facts(i);
        }
        assert(fact[n] >= k && k >= 1);
        assert(n >= 1 && n <= 9);
        vector<uint32_t> nums;
        char will_return[10];
        memset(will_return, '\0', sizeof(char) * 10);
        uint32_t k_count = k - 1;
        vector<uint32_t> ordres;
        for (uint32_t i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        for (uint32_t i = 0; i < n; i++) {
            uint32_t temp = k_count / fact[n - 1 - i];
            ordres.push_back(temp);
            k_count = k_count % fact[n - 1 - i];
            will_return[i] = '0' + nums[ordres[i]];
            nums.erase(std::remove(nums.begin(), nums.end(), nums[ordres[i]]), nums.end());
        }
        return will_return;
    }

    string getPermutation_rec_out(int32_t n, int32_t k) {
        vector<uint32_t> fact(10, 1);
        for (int32_t i{0}; i < 10; i++) {
            fact[i] = facts(i);
        }
        assert(fact[n] >= k && k >= 1);
        assert(n >= 1 && n <= 9);
        vector<uint32_t> nums;
        for (uint32_t i = 1; i <= n; i++) {
            nums.push_back(i);
        }
        return getPermutation_rec_in(n, k - 1, nums);
    }

    string getPermutation_rec_in(int32_t n, int32_t k, vector<uint32_t> nums) {
        vector<uint32_t> fact(10, 1);
        for (int32_t i{0}; i < 10; i++) {
            fact[i] = facts(i);
        }
        assert(fact[n] >= k && k >= 0);
        assert(n >= 1 && n <= 9);
        char will_return[2];
        memset(will_return, '\0', sizeof(char) * 2);
        if (1 == n) {
            will_return[0] = '0' + nums[0];
            return will_return;
        }
        will_return[0] = '0' + nums[k / fact[n - 1]];
        nums.erase(std::remove(nums.begin(), nums.end(), will_return[0] - '0'), nums.end());
        return will_return + getPermutation_rec_in(n - 1, k % fact[n - 1], nums);
    }

    void test() {
        assert("2314" == getPermutation(4, 9));
        assert("2314" == getPermutation_rec_out(4, 9));
        assert("132" == getPermutation(3, 2));
        assert("132" == getPermutation_rec_out(3, 2));
        assert("213" == getPermutation(3, 3));
        assert("213" == getPermutation_rec_out(3, 3));
        assert(getPermutation_rec_out(9, 114514) == getPermutation(9, 114514));
    }
};
/*
iteration way:
Runtime: 0 ms,
Memory Usage: 7.7 MB,
100%,100%.
recursion way:
Runtime: 0 ms,
Memory Usage: 8 MB,
100%,100%.
*/
#endif
