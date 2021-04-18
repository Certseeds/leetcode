#pragma once
#ifndef _LEETCODE_985_H_
#define _LEETCODE_985_H_

#include <vector>
#include <algorithm>

using namespace std;

/*
We have an array A of integers, and an array queries of queries.
For the i-th query val = queries[i][0],
index = queries[i][1], we add val to A[index].
Then, the answer to the i-th query is the sum of the even values of A.
(Here, the given index = queries[i][1] is a 0-based index,
and each query permanently modifies the array A.)
Return the answer to all queries.
Your answer array should have answer[i] as the answer to the i-th query.
In Most case,complier is smaster than human.
*/
class Solution985 {
public:
    vector<int> sumEvenAfterQueries(vector<int> &ints, vector<vector<int>> &queries) {
        vector<int> willreturn;
        int sums = 0;
        for (int32_t i{0}; i < ints.size(); i++) {
            sums += (ints[i] % 2 ? 0 : ints[i]);
        }
        for (int32_t i{0}; i < queries.size(); i++) {
            int posi = queries[i][1];
            ints[posi] += queries[i][0];
            if (ints[posi] % 2 == 0 && queries[i][0] % 2 == 0) {
                //ints[posi] += queries[i][0];
                sums += queries[i][0];
            } else if (ints[posi] % 2 == 0 && queries[i][0] % 2 != 0) {
                sums += ints[posi];
            } else if (queries[i][0] % 2 != 0) {
                sums -= (ints[posi] - queries[i][0]);
            }
            willreturn.push_back(sums);

        }
        return willreturn;
    }

    vector<int> sumEvenAfterQueries2(vector<int> &ints, vector<vector<int>> &queries) {
        vector<int> willreturn;
        if (queries.size() == 0) {
            return willreturn;
        }
        int sums = 0;
        int index = queries[0][1];
        int val = queries[0][0];
        ints[index] += val;
        for (int32_t i{0}; i < ints.size(); i++) {
            sums += (ints[i] % 2 == 0 ? ints[i] : 0);
        }
        willreturn.push_back(sums);
        for (int32_t i{1}; i < queries.size(); i++) {
            //cout << i << endl;
            index = queries[i][1];
            val = queries[i][0];
            if (ints[index] % 2 == 0) {
                sums -= ints[index];
            }
            ints[index] += val;
            if (ints[index] % 2 == 0) {
                sums += ints[index];
            }
            willreturn.push_back(sums);
        }
        return willreturn;
    }

    void test() {
        vector<int> vec1 = {1, 2, 3, 4};
        vector<vector<int>> vec2 = {
                {1,  0},
                {-3, 1},
                {-4, 0},
                {2,  3}
        };
        vector<int> out1 = sumEvenAfterQueries2(vec1, vec2);
        for (auto i : out1) {
            cout << i << endl;
        }
    }
};
/*
Runtime: 152 ms,
Memory Usage: 29 MB,
93.07%,93.75%.
*/
#endif
