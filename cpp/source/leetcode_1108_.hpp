#pragma once
#ifndef _LEETCODE_1108_H_
#define _LEETCODE_1108_H_

#include <string>
#include <fstream>
#include <iostream>

using namespace std;

string defangIPaddr(string address);

class Solution1108 {
public:
    string defangIPaddr(string address) {
        short *location = new short[3];
        string *numbers = new string[4];
        short i = 0;
        for (int loc = 0; loc < address.length(); loc++) {
            if (address[loc] == '.') {
                location[i] = loc;
                i++;
            }
        }
        int begin = 0;
        int end = location[0];
        {
            numbers[0] = address.substr(0, location[0]);
            numbers[1] = address.substr(location[0] + 1, location[1] - location[0] - 1);
            numbers[2] = address.substr(location[1] + 1, location[2] - location[1] - 1);
            numbers[3] = address.substr(location[2] + 1);

        }
        string temp = "[.]";
        string willreturned = "";

        for (int i = 0; i < 3; i++) {
            willreturned = willreturned + numbers[i] + temp;
        }
        willreturned += numbers[3];
        delete[]location;
        delete[]numbers;
        return willreturned;
    }
};

#endif leetcode_1108_H_
