/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-22 22:32:12
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-23 01:00:36
 */
#ifndef _LEETCODE_1356_H_
#define _LEETCODE_1356_H_
#include <vector>
#include <algorithm>
using std::vector;
/*
Given an integer array arr. 
You have to sort the integers in the array in ascending order by the number of 1's 
in their binary representation and in case of two or more 
integers have the same number of 1's you have to sort them in ascending order.

Return the sorted array.

Example 1:
Input: arr = [0,1,2,3,4,5,6,7,8]
Output: [0,1,2,4,8,3,5,6,7]
Explantion: [0] is the only integer with 0 bits.
[1,2,4,8] all have 1 bit.
[3,5,6] have 2 bits.
[7] has 3 bits.
The sorted array by bits is [0,1,2,4,8,3,5,6,7]

Example 2:
Input: arr = [1024,512,256,128,64,32,16,8,4,2,1]
Output: [1,2,4,8,16,32,64,128,256,512,1024]
Explantion: All integers have 1 bit in the binary representation, 
you should just sort them in ascending order.

Example 3:
Input: arr = [10000,10000]
Output: [10000,10000]

Example 4:
Input: arr = [2,3,5,7,11,13,17,19]
Output: [2,3,5,17,7,11,13,19]

Example 5:
Input: arr = [10,100,1000,10000]
Output: [10,100,10000,1000]

Constraints:
1 <= arr.length <= 500
0 <= arr[i] <= 10^4
10:30-10:49.
self-defined cmp function.
*/
class Solution1356 {
public:
    static bool cmp(const int& x, const int& y) {
        int fir = count_binary_one(x);
        int sec = count_binary_one(y);
        if (fir == sec) {
            return x < y;
        }
        return fir > sec;
    }
    static int count_binary_one(int x) {
        int will_return = 0;
        while (x > 0) {
            will_return += (x % 2);
            x /= 2;
        }
        return will_return;
    }
    vector<int> sortByBits(vector<int>& arr) {
        std::sort(arr.begin(), arr.end(), cmp);
        return arr;
    }
    void test() {
        vector<int> vec1 = { 1024,512,256,128,64,32,16,8,4,2,1 };
        vector<int> vec2 = { 0,1,2,3,4,5,6,7,8 };
        vector<int> out1 = sortByBits(vec1);
        vector<int> out2 = sortByBits(vec2);
    }
};
/*
Runtime: 20 ms,
Memory Usage: 9.4 MB,
85.71%,100%.
*/
#endif
