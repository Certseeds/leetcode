#pragma once
#ifndef _LEETCODE_1328_H_
#define _LEETCODE_1328_H_

#include <vector>
#include <algorithm>
#include <numeric>
#include <unordered_map>

using namespace std;

/*

*/
class Solution1328 {
public:
    vector<int> arrayRankTransform(vector<int> &arr) {
        if (arr.size() == 0) {
            return arr;
        } else if (arr.size() == 1) {
            return {1};
        }
        int max = 1;
        unordered_map<int, int> umap;
        vector<int> willreturn(arr);
        std::sort(arr.begin(), arr.end(), less<int>());
        umap[arr[0]] = 1;
        for (int i = 1; i < arr.size(); i++) {
            if (arr[i] == arr[i - 1]) {
                umap[arr[i]] = max;
            } else {
                umap[arr[i]] = max + 1;
            }
            max += (arr[i] > arr[i - 1]);
        }
        for (int i = 0; i < arr.size(); i++) {
            willreturn[i] = umap[willreturn[i]];

        }
        return willreturn;
    }

    void test() {
    }
};
/*

*/
#endif
