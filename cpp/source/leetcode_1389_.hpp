/*
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-22 21:54:48
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-23 00:32:33
 */
#ifndef _LEETCODE_1389_H_
#define _LEETCODE_1389_H_

#include <vector>
#include <algorithm>

using std::cout;
using std::endl;
using std::vector;

/*
Given two arrays of integers nums and index. 
Your task is to create target array under the following rules:
Initially target array is empty.
From left to right read nums[i] and index[i], 
insert at index index[i] the value nums[i] in target array.
Repeat the previous step until there are no elements to read in nums and index.
Return the target array.
It is guaranteed that the insertion operations will be valid.

Example 1:
Input: nums = [0,1,2,3,4], index = [0,1,2,2,1]
Output: [0,4,1,3,2]
Explanation:
nums       index     target
0            0        [0]
1            1        [0,1]
2            2        [0,1,2]
3            2        [0,1,3,2]
4            1        [0,4,1,3,2]

Example 2:
Input: nums = [1,2,3,4,0], index = [0,1,2,3,0]
Output: [0,1,2,3,4]
Explanation:
nums       index     target
1            0        [1]
2            1        [1,2]
3            2        [1,2,3]
4            3        [1,2,3,4]
0            0        [0,1,2,3,4]

Example 3:
Input: nums = [1], index = [0]
Output: [1]

Constraints:
1 <= nums.length, index.length <= 100
nums.length == index.length
0 <= nums[i] <= 100
0 <= index[i] <= i
vector insert.
begin to 7.5min
*/
class Solution1389 {
public:
    vector<int32_t> createTargetArray(vector<int32_t> &nums, vector<int32_t> &index) {
        vector<int32_t> will_return;
        will_return.reserve(nums.size());
        for (int i = 0; i < index.size(); i++) {
            will_return.insert(will_return.begin() + index[i], nums[i]);
        }
        return will_return;
    }

    void test() {
        vector<int32_t> nums1 = {0, 1, 2, 3, 4};
        vector<int32_t> index1 = {0, 1, 2, 2, 1};
        vector<int32_t> output1 = {0, 4, 1, 3, 2};
        vector<int32_t> vec1 = createTargetArray(nums1, index1);
        assert(output1.size() == vec1.size());
        for (int32_t i = 0; i < output1.size(); i++) {
            assert(output1[i] == vec1[i]);
        }
    }
};
/*
Runtime: 4 ms,
Memory Usage: 8.4 MB,
55.56%,100%.
*/
#endif
