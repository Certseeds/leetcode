#pragma once
#ifndef LEETCODE_SOURCE_LEETCODE_27_H
#define LEETCODE_SOURCE_LEETCODE_27_H

#include <vector>
#include <algorithm>
#include <array>


/*
Given an array nums and a value val,
remove all instances of that value in-place and return the new length.

Do not allocate extra space for another array,
you must do this by modifying the input array in-place with O(1) extra memory.

The order of elements can be changed.
It doesn't matter what you leave beyond the new length.
standard vector delete should use that
standard vector find.
*/
namespace Solution27 {
using namespace std;

class Solution27 {
public:
    //It's more easy to understand.
    int removeElement(vector<int32_t> &vec, int32_t val) {
        vec.erase(std::remove(vec.begin(), vec.end(), val), vec.end());
        return vec.size();
    }

    int removeElement2(vector<int32_t> &vec, int32_t val) {
        size_t begin{0};
        size_t count{vec.size() - 1};
        while (begin < count) {
            if (vec[begin] == val) {
                swap(vec[begin], vec[count]);
                count--;
            } else {
                begin++;
            }
        }
        return std::distance(vec.begin(), std::find(vec.begin(), vec.end(), val));
    }
};
}
/*
Runtime: 0 ms,
Memory Usage: 8.7 MB,
100%,61.76%.
*/
#endif //LEETCODE_SOURCE_LEETCODE_27_H
