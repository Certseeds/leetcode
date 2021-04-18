#pragma once
#ifndef _LEETCODE_821_H
#define _LEETCODE_821_H

#include <string>
#include <vector>

using namespace std;


class Solution821 {
public:
    vector<int> shortestToChar(string S, char C) {
        vector<bool> vec(S.size());
        vector<int> vec2;
        vector<int> vec3(S.size());
        for (int32_t i{0}; i < S.size(); i++) {
            vec[i] = (S[i] == C);
            vec3[i] = 0;
            if (vec[i])
                vec2.push_back(i);
        }
        for (int32_t i{0}; i < vec2.size(); i++) {
            int temp = vec2[i] - 1;
            int count = 1;
            while (temp >= 0 && !vec[temp]) {
                vec3[temp] = (vec3[temp] ? (count > vec3[temp] ? vec3[temp] : count) : count);
                count++;
                temp--;
            }
            temp = vec2[i] + 1;
            count = 1;
            while (temp < S.size() && !vec[temp]) {
                vec3[temp] = (vec3[temp] ? (count > vec3[temp] ? vec3[temp] : count) : count);
                count++;
                temp++;
            }
        }
        return vec3;
    }
};

#endif
