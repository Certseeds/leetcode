/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-01 10:28:03
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-01 13:36:53
 */
#ifndef _LEETCODE_1365_H_
#define _LEETCODE_1365_H_

#include <vector>
#include <algorithm>

using std::vector;

/*
Given the array nums,
for each nums[i] find out
how many numbers in the array are smaller than it.
That is,
for each nums[i] you have to count
the number of valid j's such that j != i and nums[j] < nums[i].
Return the answer in an array.

Example 1:
Input: nums = [8,1,2,2,3]
Output: [4,0,1,1,3]
Explanation:
For nums[0]=8 there exist four smaller numbers than it (1, 2, 2 and 3).
For nums[1]=1 does not exist any smaller number than it.
For nums[2]=2 there exist one smaller number than it (1).
For nums[3]=2 there exist one smaller number than it (1).
For nums[4]=3 there exist three smaller numbers than it (1, 2 and 2).

Example 2:
Input: nums = [6,5,4,8]
Output: [2,1,0,3]

Example 3:
Input: nums = [7,7,7,7]
Output: [0,0,0,0]

Constraints:
2 <= nums.length <= 500
0 <= nums[i] <= 100
10:30-10:36
*/
class Solution1365 {
public:
    vector<int> smallerNumbersThanCurrent(vector<int> &nums) {
        vector<int> sorted_nums(nums);
        std::sort(sorted_nums.begin(), sorted_nums.end());
        for (int32_t i{0}; i < nums.size(); i++) {
            nums[i] = std::lower_bound(
                    sorted_nums.begin(), sorted_nums.end(), nums[i])
                      - sorted_nums.begin();
        }
        return nums;
    }

    void test() {
    }
};
/*
Runtime: 8 ms,
Memory Usage: 9.7 MB,
100%,100%.
*/
#endif
