#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_30_H
#define LEETCODE_CPP_SOURCE_LEETCODE_30_H

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

namespace Solution30 {

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_set;

class Solution30 {
public:
    vector<int32_t> findSubstring(const string &s, const vector<string> &words) {
        vector<int32_t> will_return{};
        if (s.empty() || words.empty() || s.size() < words[0].size() * words.size()) {
            return will_return;
        }
        vector<vector<int32_t>> temp{};
        for (auto &word : words) {
            if (strStr_kmp(s, word) == -1) {
                return will_return;
            }
        }
        //cout << 1 << endl;
        for (size_t i = 0; i < words.size(); i++) {
            vector<int32_t> pos(s.size(), -1);
            for (size_t j = 0; j <= s.size() - words[0].size();) {
                int loca = strStr_kmp(s.substr(j), words[i]);
                //cout << loca << endl;
                if (-1 == loca) {
                    break;
                } else {
                    pos[j + loca] = i;
                    j++;
                    //cout << pos[j+loca] << endl;
                }
            }
            temp.push_back(pos);
        }
        //cout << 2 << endl;

        vector<vector<int32_t>> locas(s.size(), vector<int32_t>{});
        for (auto i : temp) {
            for (size_t j = 0; j <= s.size() - words[0].size(); j++) {
                if (-1 != i[j]) {
                    locas[j].push_back(i[j]);
                }
            }
        }
        //cout << 3 << endl;
        for (size_t i = 0; i <= s.size() - words[0].size() * words.size(); i++) {
            unordered_set<int32_t> uset;
            if (!locas[i].empty()) {
                for (size_t j = 0; j < words.size(); j++) {
                    if (locas[i + j * words[0].size()].empty()) {
                        break;
                    } else {
                        size_t temp2 = uset.size();
                        for (auto k : locas[i + j * words[0].size()]) {
                            if (uset.count(k) == 0) {
                                uset.insert(k);
                                break;
                            }
                        }
                        if (uset.size() == temp2) {
                            uset.clear();
                            break;
                        }
                    }
                }
            }
            if (uset.size() == words.size()) {
                will_return.push_back(i);
            }
            //cout << i << endl;
        }
        return will_return;
    }

    int strStr_kmp(const string &h, const string &n) {
        if (h.size() < n.size()) {
            return -1;
        }
        if (n.empty()) {
            return 0;
        }
        int x = 0;
        int y = 0;
        int hsize = h.size();
        int nsize = n.size();
        vector<int32_t> next = get_next(n);
        while ((x < hsize) && (y < nsize)) {
            if (y == -1 || h[x] == n[y]) {
                x++;
                y++;
            } else {
                y = next[y];
            }
        }
        if (y == nsize) {
            return x - y;
        }
        return -1;
    }

    vector<int32_t> get_next(const string &h) {
        vector<int32_t> will_return(h.size(), -1);
        int64_t x = -1;
        size_t y = 0;
        while (y < h.size() - 1) {
            if (x == -1 || h[x] == h[y]) {
                x++;
                y++;
                will_return[y] = x;
            } else {
                x = will_return[x];
            }
        }
        return will_return;
    }

    void test() {
        string str1 = "barfoothefoobarman";
        string str2 = "wordgoodgoodgoodbestword";
        vector<string> vec1{"foo", "bar"};
        vector<string> vec2{"word", "good", "best", "word"};
        vector<string> vec3{"word", "good", "best", "good"};
        findSubstring(str1, vec1);
        findSubstring(str2, vec2);
        findSubstring(str2, vec3);
    }
};
}

#endif //LEETCODE_CPP_SOURCE_LEETCODE_30_H