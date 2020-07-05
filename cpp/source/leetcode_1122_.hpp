#pragma once
#ifndef _LEETCODE_1122_H
#define _LEETCODE_1122_H

#include <vector>
#include <algorithm>
#include <unordered_map>

using namespace std;


class Solution1122 {
public:
    vector<int> relativeSortArray(vector<int> &arr1, vector<int> &arr2) {
        int count = 1;
        int number = 0;
        unordered_map<int, int> map;
        sort(arr1.begin(), arr1.end());
        for (int i = 1; i < arr1.size(); i++) {
            if (arr1[i] - arr1[i - 1]) {
                count++;
            }
        }
        vector<int> numbers(count);
        vector<int> times(count);
        numbers[number] = arr1[0];
        times[number] = 1;
        for (int i = 1; i < arr1.size(); i++) {
            if (arr1[i] - arr1[i - 1]) {
                number++;
                numbers[number] = arr1[i];
                times[number] = 1;
            } else {
                times[number] += 1;
            }
        }
        for (int i = 0; i < count; i++) {
            cout << numbers[i] << " " << times[i] << endl;
            map.insert(make_pair(numbers[i], times[i]));
        }
        arr1.clear();
        for (int i = 0; i < arr2.size(); i++) {
            for (int j = 0; j < map.at(arr2[i]); j++) {
                arr1.push_back(arr2[i]);
            }
            map.erase(arr2[i]);
        }
        for (int i = 0; i < count; i++) {
            if (map.count(numbers[i])) {
                for (int j = 0; j < times[i]; j++) {
                    arr1.push_back(numbers[i]);
                }
            }
        }
        return arr1;
    }
};

#endif
