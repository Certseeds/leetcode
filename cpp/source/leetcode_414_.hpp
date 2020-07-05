#pragma once
#ifndef _LEETCODE_414_H_
#define _LEETCODE_414_H_

#include <vector>
#include <unordered_set>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Given a non-empty array of integers, 
return the third maximum number in this array. 
If it does not exist, 
return the maximum number. 
The time complexity must be in O(n).
*/
class Solution414 {
public:
    int thirdMax(vector<int> &nums) {
        unordered_set<int> uset;
        for (auto i : nums) {
            uset.insert(i);
        }
        if (uset.size() < 3) {
            return *(std::max_element(uset.begin(), uset.end()));
        }
        vector<int> fst(3, INT32_MIN);
        for (auto i : uset) {
            if (i > fst[2] && i != fst[1] && i != fst[0]) {
                fst[2] = i;
            }
            if (fst[2] > fst[1]) {
                swap(fst[1], fst[2]);
            }
            if (fst[1] > fst[0]) {
                swap(fst[0], fst[1]);
            }
        }

        return fst[2];
    }

    void test() {
        vector<int> vec1 = {3, 2, 1};
        vector<int> vec2 = {1, 2};
        vector<int> vec3 = {2, 2, 3, 1};
        vector<int> vec4 = {1, 1, 2};
        cout << thirdMax(vec1) << endl;
        cout << thirdMax(vec2) << endl;
        cout << thirdMax(vec3) << endl;
        cout << thirdMax(vec4) << endl;
    }
};
/*
Runtime: 8 ms,
Memory Usage: 10.6 MB,
77.72%,46.15%.
*/
#endif
