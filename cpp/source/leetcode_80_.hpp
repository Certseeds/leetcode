#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_80_H
#define LEETCODE_CPP_SOURCE_LEETCODE_80_H

#include <vector>
#include <array>
#include <string>
#include <algorithm>

namespace Solution80 {
using namespace std;

class Solution80 {
public:
    int32_t removeDuplicates(vector<int32_t> &nums) {
        size_t s{nums.size()};
        if (s <= 2) {
            return s;
        }
        int32_t number{nums[0]};
        size_t number_c{1}, insert_count{0}, count{1};
        while (count < s) {
            if (number == nums[count]) {
                number_c++;
                if (number_c == 2) {
                    while (count < s && number == nums[count]) {
                        count++;
                    }
                }
            } else {
                while (number_c > 0) {
                    nums[insert_count] = number;
                    insert_count++;
                    number_c--;
                }
                number = nums[count];
                number_c = 1;
                count++;
            }
        }
        while (number_c > 0) {
            nums[insert_count] = number;
            insert_count++;
            number_c--;
        }
        return insert_count;
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_80_H