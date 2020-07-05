#pragma once
#ifndef _LEETCODE_401_H_
#define _LEETCODE_401_H_
/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-15 09:46:48
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-15 10:51:41
*/
#include <vector>
#include <string>
#include <algorithm>

using std::min;
using std::cout;
using std::endl;
using std::sort;
using std::vector;
using std::string;

/*
A binary watch has 4 LEDs on the top which represent the hours (0-11), 
and the 6 LEDs on the bottom represent the minutes (0-59).

Each LED represents a zero or one, 
with the least significant bit on the right.

For example, 
"0011" "011001"
the above binary watch reads "3:25".

Given a non-negative integer n which represents 
the number of LEDs that are currently on, 
return all possible times the watch could represent.

Example:
Input: n = 1
Return: 
["1:00", "2:00", "4:00", "8:00", "0:01",
"0:02","0:04", "0:08", "0:16", "0:32"]

Note:
The order of output does not matter.
The hour must not contain a leading zero, 
for example "01:00" is not valid, it should be "1:00".
The minute must be consist of two digits and may contain a leading zero,
for example "10:2" is not valid, it should be "10:02".
*/
class Solution401 {
public:
    vector<string> readBinaryWatch(const int num) {
        vector<string> will_return;
        for (int k = 0; k <= min(4, num); k++) {
            vector<string> hours = hours_complex(k);
            vector<string> minutes = minutes_complex(num - k);
            for (auto i : hours) {
                for (auto j : minutes) {
                    will_return.push_back(i + ":" + j);
                }
            }
        }
        sort(will_return.begin(), will_return.end());
        return will_return;
    }

    vector<string> hours_complex(const int x) {
        vector<int> nums;
        switch (x) {
            case 0: {
                nums.push_back(0);
                break;
            }
            case 1: {
                for (int i = 0; i < 4; i++) {
                    nums.push_back((1 << i));
                }
                break;
            }
            case 2: {
                nums.push_back(3);
                nums.push_back(5);
                nums.push_back(6);
                nums.push_back(9);
                nums.push_back(10);
                break;
            }
            case 3: {
                nums.push_back(7);
                nums.push_back(11);
                break;
            }
        }
        vector<string> will_return;
        for (int i = 0; i < nums.size(); i++) {
            will_return.push_back(hour_toStirng(nums[i]));
        }
        return will_return;
    }

    string hour_toStirng(const int x) {
        string will_return;
        if (x < 10) {
            will_return.push_back(x + '0');
        } else {
            will_return.push_back((x / 10) + '0');
            will_return.push_back((x % 10) + '0');
        }
        return will_return;
    }

    vector<string> minutes_complex(const int x) {
        vector<int> nums;
        switch (x) {
            case 0: {
                nums.push_back(0);
                break;
            }
            case 1: {
                for (int i = 0; i < 6; i++) {
                    nums.push_back((1 << i));
                }
                break;
            }
            case 2: {
                for (int i = 0; i < 6; i++) {
                    for (int j = i + 1; j < 6; j++) {
                        nums.push_back((1 << i) + (1 << j));
                    }
                }
                break;
            }
            case 3: {
                for (int i = 0; i < 6; i++) {
                    for (int j = i + 1; j < 6; j++) {
                        for (int k = j + 1; k < 6; k++) {
                            nums.push_back((1 << i) + (1 << j) + (1 << k));
                        }
                    }
                }
                break;
            }
            case 4: {
                for (int i = 0; i < 6; i++) {
                    for (int j = i + 1; j < 6; j++) {
                        if (63 - (1 << i) - (1 << j) < 60) {
                            nums.push_back(63 - (1 << i) - (1 << j));
                        }
                    }
                }
                break;
            }
            case 5: {
                for (int i = 0; i < 6; i++) {
                    if (63 - (1 << i) < 60) {
                        nums.push_back(63 - (1 << i));
                    }
                }
                break;
            }
        }
        vector<string> will_return;
        for (auto i : nums) {
            will_return.push_back(minutes_toString(i));
        }
        return will_return;
    }

    string minutes_toString(const int x) {
        string will_return;
        if (x < 10) {
            will_return.push_back('0');
            will_return.push_back(x + '0');
        } else {
            will_return.push_back((x / 10) + '0');
            will_return.push_back((x % 10) + '0');
        }
        return will_return;
    }

    void test() {
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.8 MB,
100%,85.71%.
*/
#endif
