#pragma once
#ifndef _LEETCODE_121_H_
#define _LEETCODE_121_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
Say you have an array for which the ith element is the price of a given stock on day i.

If you were only permitted to complete at most one transaction
(i.e., buy one and sell one share of the stock),
design an algorithm to find the maximum profit.

Note that you cannot sell a stock before you buy one.
*/
class Solution121 {
public:
    int maxProfit(vector<int> &prices) {
        int min = INT16_MAX;
        int willreturn = 0;
        for (int32_t i{0}; i < prices.size(); i++) {
            if (min > prices[i]) {
                min = prices[i];
            } else {
                willreturn = max(willreturn, prices[i] - min);
            }
        }
        return willreturn;
    }

    void test() {
        vector<int> vec1 = {7, 1, 5, 3, 6, 4};
        cout << maxProfit(vec1) << endl;
        vector<int> vec2 = {7, 6, 4, 3, 1};
        cout << maxProfit(vec2) << endl;
    }
};
/*
Runtime: 4 ms,
Memory Usage: 9.6 MB,
98.49%,58.88%.
*/
#endif
