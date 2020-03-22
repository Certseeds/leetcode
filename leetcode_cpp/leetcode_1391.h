/*
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-03-22 22:25:41
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-03-23 00:32:39
 */
#ifndef _LEETCODE_1391_H_
#define _LEETCODE_1391_H_
#include <queue>
#include <vector>
#include <numeric>
#include <algorithm>
using std::cout;
using std::endl;
using std::queue;
using std::vector;
/*
Given a m x n grid. Each cell of the grid represents a street. The street of grid[i][j] can be:
1 which means a street connecting the left cell and the right cell.
2 which means a street connecting the upper cell and the lower cell.
3 which means a street connecting the left cell and the lower cell.
4 which means a street connecting the right cell and the lower cell.
5 which means a street connecting the left cell and the upper cell.
6 which means a street connecting the right cell and the upper cell.
You will initially start at the street of the upper-left cell (0,0).
A valid path in the grid is a path which starts from the upper left cell (0,0) 
and ends at the bottom-right cell (m - 1, n - 1). The path should only follow the streets.

Notice that you are not allowed to change any street.
Return true if there is a valid path in the grid or false otherwise.

Example 1:
Input: grid = [[2,4,3],[6,5,2]]
Output: true
Explanation: As shown you can start at cell (0, 0) and visit all the cells of the grid to reach (m - 1, n - 1).

Example 2:
Input: grid = [[1,2,1],[1,2,1]]
Output: false
Explanation: As shown you the street at cell (0, 0) is not connected with any street of any other cell and you will get stuck at cell (0, 0)

Example 3:
Input: grid = [[1,1,2]]
Output: false
Explanation: You will get stuck at cell (0, 1) and you cannot reach cell (0, 2).

Example 4:
Input: grid = [[1,1,1,1,1,1,3]]
Output: true

Example 5:
Input: grid = [[2],[2],[2],[2],[2],[2],[6]]
Output: true

Constraints:
m == grid.length
n == grid[i].length
1 <= m, n <= 300
1 <= grid[i][j] <= 6
30min->78min
queue,complex logic and action.
*/
class Solution1391 {
public:
    const vector<vector<int32_t>> values_array = {
        {2,5,6},
        {2,3,4},
        {1,3,5},
        {1,4,6}
    };
    bool hasValidPath(vector<vector<int>>& grid) {
        if (grid.size() == 0 || grid[0].size() == 0) {
            return true;
        }
        vector<vector<uint8_t>> visited(grid.size(),vector<uint8_t>(grid[0].size(),0));
        queue<std::pair<int32_t, int32_t>> que;
        que.push(std::make_pair(0, 0));
        visited[0][0] = 1;
        while (!que.empty()) {
            auto point = que.front(); que.pop();
            if (grid.size() - 1 == point.first && grid[0].size() - 1 == point.second) {
                return true;
            }
            vector<std::pair<int32_t, int32_t>> nexts = get_next_point(grid, visited, point);
            for (auto i : nexts) {
                que.push(i);
            }
        }
        return false;
    }
    vector<std::pair<int32_t, int32_t>> get_next_point(
        const vector<vector<int>>& grid,
        vector<vector<uint8_t>>& visited,
        const std::pair<int32_t,int32_t>& point) {
        int32_t x = point.first;
        int32_t y = point.second;
        vector<std::pair<int32_t, int32_t>> will_return;
        if ((x - 1 >= 0 && visited[x - 1][y] == 0) &&
            (std::find(values_array[0].begin(), values_array[0].end(), grid[x][y]) != values_array[0].end() &&
                std::find(values_array[1].begin(), values_array[1].end(), grid[x - 1][y]) != values_array[1].end())) {
            will_return.push_back(std::make_pair(x - 1, y));
            visited[x - 1][y] = 1;
        }
        if (x + 1 < grid.size() && visited[x + 1][y] == 0 &&
            (std::find(values_array[1].begin(), values_array[1].end(), grid[x][y]) != values_array[1].end() &&
                std::find(values_array[0].begin(), values_array[0].end(), grid[x + 1][y]) != values_array[0].end())) {
            will_return.push_back(std::make_pair(x + 1, y));
            visited[x + 1][y] = 1;
        }
        if (y - 1 >= 0 && visited[x][y - 1] == 0 && 
            std::find(values_array[2].begin(), values_array[2].end(), grid[x][y]) != values_array[2].end() &&
                std::find(values_array[3].begin(), values_array[3].end(), grid[x][y-1]) != values_array[3].end()) {
                will_return.push_back(std::make_pair(x, y-1));
                visited[x][y-1] = 1;
        }
        if (y + 1 < grid[0].size() && 0 == visited[x][y + 1] && 
            std::find(values_array[3].begin(), values_array[3].end(), grid[x][y]) != values_array[3].end() &&
                std::find(values_array[2].begin(), values_array[2].end(), grid[x][y + 1]) != values_array[2].end()) {
                will_return.push_back(std::make_pair(x, y + 1));
                visited[x][y + 1] = 1;
        }
        return will_return;
    }
    void test() {
        vector<vector<int32_t>> input1 = { {1,2,1},{1,2,1} };
        vector<vector<int32_t>> input2 = { {1,1,2} };
        vector<vector<int32_t>> input3 = { {1,1,1,1,1,1,3} };
        vector<vector<int32_t>> input4 = { {2},{2},{2},{2},{2},{2},{6} };
        assert(false == hasValidPath(input1));
        assert(false == hasValidPath(input2));
        assert(true == hasValidPath(input3));
        assert(true == hasValidPath(input4));
    }
};
/*
Runtime: 360 ms,
Memory Usage: 63.3 MB,
36.36%,100%.
*/
#endif