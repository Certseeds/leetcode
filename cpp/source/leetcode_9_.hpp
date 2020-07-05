#pragma once
#ifndef _LEETCODE_9_H_
#define _LEETCODE_9_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
Determine whether an integer is a palindrome. 
An integer is a palindrome when it reads the same backward as forward.
*/
class Solution9 {
public:
    bool isPalindrome(int x) {
        vector<int> nums;
        if (x < 0) {
            return false;
        }
        while (x > 0) {
            nums.push_back(x % 10);
            x /= 10;
        }
        for (int i = 0; i < (nums.size()) / 2; i++) {
            if (nums[i] != nums[nums.size() - 1 - i]) {
                return false;
            }
        }
        return true;
    }

    void test() {
        cout << isPalindrome(121) << endl;
        cout << isPalindrome(-121) << endl;
        cout << isPalindrome(120) << endl;
    }
};
/*
Runtime: 28 ms,
Memory Usage: 12 MB,
13.43%,5.45%.
*/
#endif
