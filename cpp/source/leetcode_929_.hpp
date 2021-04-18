#pragma once
#ifndef _LEETCODE_929_H
#define _LEETCODE_929_H

#include <vector>
#include <string>
#include <unordered_map>

using namespace std;


class Solution929 {
public:
    int numUniqueEmails(vector<string> &emails) {
        vector<int> point;
        vector<int> plus;
        unordered_map<string, int> pairs;
        for (int32_t i{0}; i < emails.size(); i++) {
            transfer(emails[i], point, plus);
            cout << emails[i] << endl;
            if (pairs.count(emails[i]) == 0) {
                pairs.insert(make_pair(emails[i], i));
            }
        }
        return pairs.size();
    }

    void transfer(string &str, vector<int> &po, vector<int> &pl) {
        int at = str.find('@');
        for (int32_t i{0}; i < at; i++) {
            if (str[i] == 46) {
                po.push_back(i);
            } else if (str[i] == 43) {
                pl.push_back(i);
                break;
            }
        }
        if (pl.size()) {
            str.erase(pl.front(), at - pl.front());
        }
        at = po.size();
        for (int32_t i{0}; i < at; i++) {
            str.erase(po.back(), 1);
            po.pop_back();
        }
        po.clear();
        pl.clear();
    }
};

#endif
