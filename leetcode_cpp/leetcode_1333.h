#pragma once
#ifndef _LEETCODE_1333_H_
#define _LEETCODE_1333_H_
#include <vector>
#include <algorithm>
#include <numeric>
using namespace std;
/*
Given the array restaurants where  restaurants[i] = [idi, ratingi, veganFriendlyi, pricei, distancei]. 
You have to filter the restaurants using three filters.

The veganFriendly filter will be either true 
(meaning you should only include restaurants with veganFriendlyi set to true) 
or false (meaning you can include any restaurant). 
In addition, you have the filters maxPrice and maxDistance 
which are the maximum value for price and distance of restaurants you should consider respectively.

Return the array of restaurant IDs after filtering, 
ordered by rating from highest to lowest. For restaurants with the same rating, 
order them by id from highest to lowest. 
For simplicity veganFriendlyi and veganFriendly take value 1 when it is true, and 0 when it is false.
single week 173-1
*/
class Solution1333 {
public:
    vector<int> filterRestaurants(vector<vector<int>>& restaurants, 
        int veganFriendly,int maxPrice, int maxDistance) {
        std::sort(restaurants.begin(), restaurants.end(), less_1333);
        vector<int> willreturn;
        willreturn.reserve(restaurants.size());
        for (int i = 0; i < restaurants.size(); i++) {
            if (
                (restaurants[i][2] || !veganFriendly) &&
                (maxPrice >= restaurants[i][3]) &&
                (maxDistance >= restaurants[i][4])) {
                willreturn.push_back(restaurants[i][0]);
            }
        }
        return willreturn;
    }
    static bool less_1333(const vector<int>& vec1,const vector<int>& vec2) {
        return (vec1[1] > vec2[1]) ||(vec1[1] == vec2[1] && vec1[0] > vec2[0]);
    }
    
    void test() {
        vector<vector<int>> vec1 = { {1, 4, 1, 40, 10}, {2, 8, 0, 50, 5},
        {3, 8, 1, 30, 4}, {4, 10, 0, 10, 3}, {5, 1, 1, 15, 1} };
        vector<int> out1 = filterRestaurants(vec1,0,50,10);
        for (auto i : out1) {
            cout << i << " ";
        }cout << endl;
        vector<int> out2 = filterRestaurants(vec1, 1, 50, 10);
        for (auto i : out2) {
            cout << i << " ";
        }cout << endl;
    }
};
/*
Runtime: 48 ms,
Memory Usage: 20.5 MB,
100%,100%.
*/
#endif
