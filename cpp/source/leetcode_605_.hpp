#pragma once
#ifndef _LEETCODE_605_H_
#define _LEETCODE_605_H_

#include <vector>
#include <unordered_map>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Suppose you have a long flowerbed in which some of 
the plots are planted and some are not. However, 
flowers cannot be planted in adjacent plots - they would compete for water and both would die.

Given a flowerbed (represented as an array containing 0 and 1, 
where 0 means empty and 1 means not empty), and a number n, 
return if n new flowers can be planted in it 
without violating the no-adjacent-flowers rule.
urinal problems in O(n).
*/
class Solution605 {
public:
    bool canPlaceFlowers(vector<int> &urinal, int n) {
        if (n == 0) {
            return true;
        }
        //return no need to consider
        if ((urinal.size() + 1) / 2 < n) {
            return false;
        }
        //return impossible cases
        if (urinal.size() == 1) {
            return urinal[0] != 1;
        } else if (urinal.size() == 2) {
            return urinal[0] != 1 && urinal[1] != 1;
        }
        if (urinal[0] == 0 && urinal[1] == 0) {
            urinal[0] = 1;
            n--;
        }
        if (urinal[urinal.size() - 1] == 0 && urinal[urinal.size() - 2] == 0) {
            urinal[urinal.size() - 1] = 1;
            n--;
        }
        int i = 1;
        int temp = 0;
        while (n > 0) {
            temp = i;
            for (; i < urinal.size(); i++) {
                if (urinal[i - 1] == 0 && urinal[i] == 0 && urinal[i + 1] == 0) {
                    urinal[i] = 1;
                    i += 2;
                    n--;
                    break;
                }
            }
            if (temp == i) {
                return false;
            }
        }
        return true;
    }

    void test() {
        vector<int> vec1 = {1, 0, 0, 0, 1};
        vector<int> vec2 = {1};
        vector<int> vec3 = {0, 0};
        cout << canPlaceFlowers(vec1, 1) << endl;
        cout << canPlaceFlowers(vec1, 2) << endl;
        cout << canPlaceFlowers(vec2, 0) << endl;
        cout << canPlaceFlowers(vec3, 2) << endl;
    }
};
/*
Runtime: 12 ms,
Memory Usage: 10.1 MB,
96.93%,100%.
*/
#endif
