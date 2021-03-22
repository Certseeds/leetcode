#ifndef _LEETCODE_6_H
#define _LEETCODE_6_H

#include <vector>
#include <array>
#include <string>
#include <algorithm>

using namespace std;

class Solution6 {
public:
    string convert(string s, int numRows) {
        int32_t s_size = s.size();
        if (s_size <= numRows || numRows == 1) {
            return s;
        }
        vector<uint8_t> vec(s_size);
        int32_t batch = numRows * 2 - 2;
        int32_t block_number = s_size / batch;
        int32_t batch_size = batch * block_number;
        int32_t left_num = s_size - batch_size;
        int32_t count = 0uLL;
        for (int32_t i = 0; i < s_size; i += batch, count++) {
            vec[count] = s[i];
        }
        for (int32_t i = 1; i < numRows - 1; i++) {
            for (int32_t j = 0; j < batch_size; j += batch, count += 2) {
                vec[count] = s[j + i];
                vec[count + 1] = s[j + batch - i];
            }
            if (left_num > i) {
                vec[count] = s[batch_size + i];
                count++;
                if (left_num > batch - i) {
                    vec[count] = s[batch_size + batch - i];
                    count++;
                }
            }
        }
        for (int32_t i = 0; i < batch_size; i += batch, count++) {
            vec[count] = s[i + (numRows - 1)];
        }
        if (left_num >= numRows) {
            vec[count] = s[batch_size + numRows - 1];
        }
        return string(vec.cbegin(), vec.cend());
    }
};

#endif
