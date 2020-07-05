#pragma once
#ifndef _LEETCODE_1353_H_
#define _LEETCODE_1353_H_

#include <vector>
#include <algorithm>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::unordered_set;

/*
Given an array of events where events[i] = [startDayi,
endDayi]. Every event i starts at startDayi and ends at endDayi.

You can attend an event i at any day d where startTimei <= d <= endTimei.
Notice that you can only attend one event at any time d.

Return the maximum number of events you can attend.

Example 1:
Input: events = [[1,2],[2,3],[3,4]]
Output: 3
Explanation: You can attend all the three events.
One way to attend them all is as shown.
Attend the first event on day 1.
Attend the second event on day 2.
Attend the third event on day 3.

Example 2:
Input: events= [[1,2],[2,3],[3,4],[1,2]]
Output: 4

Example 3:
Input: events = [[1,4],[4,4],[2,2],[3,4],[1,1]]
Output: 4

Example 4:
Input: events = [[1,100000]]
Output: 1

Example 5:
Input: events = [[1,1],[1,2],[1,3],[1,4],[1,5],[1,6],[1,7]]
Output: 7

Constraints:
1 <= events.length <= 10^5
events[i].length == 2
1 <= events[i][0] <= events[i][1] <= 10^5
*/
class Solution1353 {
public:
    //O(N^2)
    int maxEvents(vector<vector<int>> &events) {
        if (events.size() == 0 || events[0].size() == 0) {
            return 0;
        }
        std::sort(events.begin(), events.end());
        auto cmp = [](vector<int> vec1, vector<int> vec2) { return vec1[1] < vec2[1]; };
        std::sort(events.begin(), events.end(), cmp);
        int end = 0;
        int count = 0;
        unordered_set<int> uset;
        for (int i = 0; i < events.size(); i++) {
            //cout << i << " ";
            for (int j = events[i][0]; j <= events[i][1]; j++) {
                if (uset.count(j) == 0) {
                    uset.insert(j);
                    break;
                }
            }
        }//cout << endl;
        return uset.size();
    }

    void test() {
        vector<vector<int>> vec1 = {{1, 1},
                                    {2, 2},
                                    {1, 4},
                                    {3, 4},
                                    {4, 4}};
        vector<vector<int>> vec2 = {{1, 1},
                                    {1, 2},
                                    {2, 2}};
        vector<vector<int>> vec3 = {{1, 2},
                                    {1, 2},
                                    {3, 3},
                                    {1, 5},
                                    {1, 5}};
        vector<vector<int>> vec4 = {{2, 2},
                                    {2, 2},
                                    {2, 2},
                                    {2, 2},
                                    {1, 10}};
        vector<vector<int>> vec5 = {{1, 2},
                                    {2, 3},
                                    {3, 4}};
        vector<vector<int>> vec6 = {{1, 2},
                                    {1, 2},
                                    {2, 3},
                                    {3, 4}};
        vector<vector<int>> vec7 = {{1, 10000}};
        vector<vector<int>> vec8 = {{1, 1},
                                    {1, 2},
                                    {1, 3},
                                    {1, 4},
                                    {1, 5},
                                    {1, 6},
                                    {1, 7}};
        vector<vector<int>> vec9 = {{2, 3},
                                    {2, 3},
                                    {1, 5},
                                    {1, 5},
                                    {1, 5}};
        cout << "normal test" << endl;
        assert(4 == maxEvents(vec1));
        cout << "small range test" << endl;
        assert(2 == maxEvents(vec2));
        cout << "single element more than one test" << endl;
        assert(5 == maxEvents(vec3));
        cout << "4 same elements test" << endl;
        assert(2 == maxEvents(vec4));
        cout << "normal test" << endl;
        assert(3 == maxEvents(vec5));
        cout << "normal test" << endl;
        assert(4 == maxEvents(vec6));
        cout << "single element test" << endl;
        assert(1 == maxEvents(vec7));
        cout << "O(n^2) test" << endl;
        assert(7 == maxEvents(vec8));
        cout << "normal test" << endl;
        assert(5 == maxEvents(vec9));
    }
};
/*
TLE now.
*/
#endif
