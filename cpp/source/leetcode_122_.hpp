#pragma once
#ifndef _LEETCODE_122_H
#define _LEETCODE_122_H

#include <vector>
#include <algorithm>
#include <numeric>

using namespace std;

/*
Say you have an array for 
which the ith element is the price of a given stock on day i.

Design an algorithm to find the maximum profit. 
You may complete as many transactions as you like 
(i.e., buy one and sell one share of the stock multiple times).

Note: You may not engage in multiple transactions at the same time 
(i.e., you must sell the stock before you buy again).
just greedy.
*/
class Solution122 {
public:
    int maxProfit(vector<int> &prices) {
        if (prices.size() < 2) {
            return 0;
        }
        int willreturn = 0;
        int temp = 0;
        for (int i = 1; i < prices.size(); i++) {
            temp = prices[i] - prices[i - 1];
            if (temp > 0) {
                willreturn += temp;
            }
        }
        return willreturn;
    }

    void test() {
        vector<int> vec1 = {7, 1, 5, 3, 6, 4};
        vector<int> vec2 = {1, 2, 3, 4, 5};
        vector<int> vec3 = {7, 6, 4, 3, 1};
        cout << maxProfit(vec1) << endl;
        cout << maxProfit(vec2) << endl;
        cout << maxProfit(vec3) << endl;
    }
};
/*
Runtime: 0 ms, 
Memory Usage: 9.6 MB,
100%,80.95%.
*/
#endif
