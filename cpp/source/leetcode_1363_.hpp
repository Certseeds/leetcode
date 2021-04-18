#ifndef _LEETCODE_1363_H_
#define _LEETCODE_1363_H_

#include <queue>
#include <string>
#include <vector>
#include <algorithm>
#include <numeric>

using std::max;
using std::min;
using std::cout;
using std::endl;
using std::swap;
using std::queue;
using std::vector;
using std::string;

class Solution1363 {
public:
    string largestMultipleOfThree(vector<int> &d) {
        vector<int> add(d.size(), 1);
        int sum = std::accumulate(d.begin(), d.end(), 0);
        std::sort(d.begin(), d.end(), std::less<int>());
        while (sum % 3 != 0) {
            for (int32_t i{0}; i < add.size(); i++) {
                if (add[i] == 1 && d[i] > 0) {
                    sum -= d[i];
                    add[i] = 0;
                    break;
                }
            }
        }
        vector<int> nums;
        for (int32_t i{0}; i < add.size(); i++) {
            if (1 == add[i]) {
                nums.push_back(d[i]);
            }
        }
        if (0 == sum && !nums.empty()) {
            if (nums.size() == d.size()) {
                return "0";
            }
            return "";
        }
        std::sort(nums.begin(), nums.end(), std::greater<int>());
        string will_return = "";
        for (auto i: nums) {
            will_return += ('0' + i);
        }
        return will_return;
    }

    void test() {
        vector<int> vec1 = {8, 7, 6, 1, 0};
        vector<int> vec2 = {0, 0, 0, 0, 0, 0};
        vector<int> vec3 = {0, 0, 0, 0, 0, 1};
        cout << largestMultipleOfThree(vec1) << endl;
        cout << largestMultipleOfThree(vec2) << endl;
        cout << largestMultipleOfThree(vec3) << endl;
    }
};
/*
Runtime: 20 ms,
Memory Usage: 9.4 MB,
85.71%,100%.
*/
#endif
