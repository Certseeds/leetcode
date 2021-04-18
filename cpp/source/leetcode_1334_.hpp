#pragma once
#ifndef _LEETCODE_1334_H_
#define _LEETCODE_1334_H_

#include <vector>
#include <algorithm>
#include <numeric>
#include <queue>
#include <unordered_set>

using namespace std;

/*

There are n cities numbered from 0 to n-1.
Given the array edges where edges[i] = [fromi, toi, weighti]
represents a bidirectional and weighted edge between cities fromi and toi,
and given the integer distanceThreshold.

Return the city with the smallest number of cities that are reachable through some path
and whose distance is at most distanceThreshold, If there are multiple such cities,
return the city with the greatest number.

Notice that the distance of a path connecting cities i and j is equal to
the sum of the edges' weights along that path.
min path of map.
O(ElogV).
input:
vector<vector<std::pair<int,int>>> maps,first is number,second is length.
begin node  n.
output:
a vector<int> vec, vec[i] means the min path's length from n to i.
*/
class Solution1334 {
public:
    int findTheCity(int n, vector<vector<int>> &edges, int distanceThreshold) {
        vector<vector<std::pair<int, int>>> maps(n);
        auto cmp = [&distanceThreshold](int i) { return (i <= distanceThreshold); };
        for (int32_t i{0}; i < edges.size(); i++) {
            if (edges[i][2] <= distanceThreshold) {
                maps[edges[i][0]].push_back(std::make_pair(edges[i][1], edges[i][2]));
                maps[edges[i][1]].push_back(std::make_pair(edges[i][0], edges[i][2]));
            }
        }
        int count = INT16_MAX;
        int willreturn = -1;
        vector<int> dis(n);
        for (int32_t i{0}; i < n; i++) {
            dis = minimum_path(maps, i);
            int temp = std::count_if(dis.begin(), dis.end(), cmp) - 1;
            if (count >= temp) {
                count = temp;
                willreturn = i;
            }
            //for (auto i : dis) {
            //    cout << i << " ";
            //}cout << endl;
        }
        return willreturn;
    }

    vector<int> minimum_path(
            const vector<vector<std::pair<int, int>>> &map, const int &n) {
        auto cmp = [](const std::pair<int, int> &p1, const std::pair<int, int> &p2) { return p1.second < p2.second; };
        priority_queue<std::pair<int, int>, vector<std::pair<int, int>>, decltype(cmp)> nodes(cmp);
        vector<int> d(map.size(), INT32_MAX);
        d[n] = 0;
        nodes.push(make_pair(n, 0));
        while (!nodes.empty()) {
            auto root = nodes.top();
            nodes.pop();
            for (int32_t i{0}; i < map[root.first].size(); i++) {
                int root_v = root.first;
                if (d[map[root_v][i].first] > d[root_v] + map[root_v][i].second) {
                    d[map[root_v][i].first] = d[root_v] + map[root_v][i].second;
                    nodes.push(make_pair(map[root_v][i].first, d[map[root_v][i].first]));
                }
            }
        }
        return d;
    }

    void test() {
        vector<vector<int>> vec1 = {
                {0, 1, 3},
                {1, 2, 1},
                {1, 3, 4},
                {2, 3, 1}};
        cout << findTheCity(4, vec1, 4) << endl;
        vector<vector<int>> vec2 = {
                {0, 1, 2},
                {0, 4, 8},
                {1, 2, 3},
                {1, 4, 2},
                {2, 3, 1},
                {3, 4, 1}};
        cout << findTheCity(5, vec2, 2) << endl;
        vector<vector<int>> vec3 = {
                {0, 2, 3996},
                {0, 3, 7495},
                {0, 4, 5966},
                {0, 5, 3399},
                {0, 6, 6},
                {0, 7, 2904},
                {1, 2, 1079},
                {1, 4, 2262},
                {1, 5, 6327},
                {1, 6, 2458},
                {1, 7, 7782},
                {2, 6, 1390},
                {3, 4, 7284},
                {3, 7, 2336},
                {4, 5, 5055},
                {4, 6, 2857},
                {4, 7, 7558},
                {5, 7, 2870},
                {6, 7, 2202},};
        cout << findTheCity(8, vec3, 7937) << endl;
    }
};
/*
Runtime: 356 ms,
Memory Usage: 13.3 MB,
66.67%,100%.
*/
#endif
