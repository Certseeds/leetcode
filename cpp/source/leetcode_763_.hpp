#pragma once
#ifndef _LEETCODE_763_H_
#define _LEETCODE_763_H_

#include <string>
#include <vector>
#include <unordered_map>
#include <algorithm>

using namespace std;

/*
A string S of lowercase letters is given.
We want to partition this string into as many parts as possible
so that each letter appears in at most one part,
and return a list of integers representing the size of these parts.
*/
class Solution763 {
public:
    vector<int> partitionLabels(string S) {
        vector<int> left(26, INT32_MAX);
        vector<int> right(26, INT32_MIN);
        unordered_map<int, vector<int>> umaps;
        vector<int> willreturn;
        int count = 0;
        for (int32_t i{0}; i < S.size(); i++) {
            left[S[i] - 'a'] = min(left[S[i] - 'a'], i);
            right[S[i] - 'a'] = max(right[S[i] - 'a'], i);
        }
        for (int32_t i{0}; i < 26; i++) {
            if (left[i] != INT32_MAX || right[i] != INT32_MIN) {
                umaps.insert(make_pair(i, vector<int>{left[i], right[i]}));
                //cout << char(i+'a')<< " "<<left[i] << " " << right[i] << endl;
            }
        }
        auto iter = umaps.begin();
        while (iter != umaps.end()) {
            for (auto iter_in = umaps.begin(); iter_in != umaps.end(); iter_in++) {
                //cout << "??" << endl;
                if (iter->second[0] < iter_in->second[0] &&
                    iter_in->second[0] < iter->second[1] &&
                    iter->second[1] < iter_in->second[1]) {
                    iter_in->second[0] = iter->second[0];
                    iter->second[1] = iter_in->second[1];
                } else if (iter->second[0] < iter_in->second[0] &&
                           iter->second[1] > iter_in->second[1]) {
                    iter_in->second[0] = iter->second[0];
                    iter_in->second[1] = iter->second[1];
                }
            }
            iter++;
        }
        while (count < S.size()) {
            //cout << count << " " << S[count] <<" " << S.size();
            int temp = umaps[S[count] - 'a'][1] - umaps[S[count] - 'a'][0];
            willreturn.push_back(temp + 1);
            count += (temp + 1);
        }
        return willreturn;
    }

    vector<int> partitionLabels2(string S) {
        array<int, 26> vals = {0};
        vector<int> willreturn;
        for (int32_t i{0}; i < S.size(); i++) {
            vals[S[i] - 'a'] = i;
        }
        int left = 0;
        int right = 0;
        for (int32_t i{0}; i < S.size(); i++) {
            right = max(right, vals[S[i] - 'a']);
            // this and the next judge means, if the left's range final in here.
            if (right == i) {
                willreturn.push_back(right - left + 1);
                left += willreturn[willreturn.size() - 1];
            }
        }
        return willreturn;
    }

    void test() {
        string str1 = "ababcbacadefegdehijhklij";
        vector<int> vec1 = partitionLabels(str1);
        cout << "vec1 begin " << endl;
        for (int32_t i{0}; i < vec1.size(); i++) {
            cout << vec1[i] << endl;
        }
        cout << "vec1 finish " << endl;
        string str2 = "eccbbbbdec";
        vector<int> vec2 = partitionLabels2(str2);
        cout << "vec2 begin " << endl;
        for (int32_t i{0}; i < vec2.size(); i++) {
            cout << vec1[i] << endl;
        }
        cout << "vec2 finish " << endl;

    }
};
/*
my own way:
Runtime: 8ms,
Memory Usage: 9.1MB,
46%,50&.
other way:
Runtime: 4 ms,
Memory Usage: 8.6 MB,
92.88%,96.77%.
However, they both are O(n),which n is the S.size()
difference is the constant.
*/
#endif
