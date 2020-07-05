#pragma once
#ifndef _LEETCODE_1287_H_
#define _LEETCODE_1287_H_

#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
Given an integer array sorted in non-decreasing order, 
there is exactly one integer in the array that occurs more than 25% of the time.
Return that integer.
it looks like it should be a ergodic question using unordered_map,
but because it is a sorted array, so it should use 0-n/4,n/4-n/2,n/2-3*n/4,3*n/4-n.
four part to reaseach it there exist a part all numbers is the same number.
*/
class Solution1287 {
public:
    int findSpecialInteger(vector<int> &arr) {
        int willreturn = -1;
        int tfpt = arr.size() / 4 + 1;
        unordered_map<int, int> umaps;
        for (int i = 0; i < arr.size(); i++) {
            umaps[arr[i]]++;
            if (umaps[arr[i]] > tfpt) {
                return arr[i];
            }
        }
    }

    int findSpecialInteger2(vector<int> &arr) {
        int tfpt = arr.size() / 4;
        for (int i = 0; i < 4; i++) {
            int value = arr[i * tfpt];
            auto dist = equal_range(begin(arr), end(arr), value);
            if (distance(dist.first, dist.second) > tfpt) {
                return value;
            }
        }
    }

    void test() {
        vector<int> vec1 = {1, 2, 2, 6, 6, 6, 6, 7, 10};
        cout << findSpecialInteger2(vec1) << endl;
        vector<int> vec2 = {1, 1};
        cout << findSpecialInteger2(vec2) << endl;

    }
};
/*
Runtime: 16 ms, 
Memory Usage: 10.3 MB, 
85.84%,100%.
new way:
Runtime: 4 ms, 
Memory Usage: 9.7 MB, 
the complex do not improve,however,
a magic part
'''
[[maybe_unused]] static auto const fast = []{return ios_base::sync_with_stdio(false);}();
'''
seems can speed up.
*/
#endif
