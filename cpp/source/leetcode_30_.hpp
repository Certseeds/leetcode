#pragma once
#ifndef _LEETCODE_30_H_
#define _LEETCODE_30_H_

#include <vector>
#include <string>
#include <algorithm>
#include <unordered_set>

using std::cout;
using std::endl;
using std::vector;
using std::string;
using std::unordered_set;

class Solution30 {
public:
    vector<int> findSubstring(string s, vector<string> &words) {
        if (s.size() == 0 || words.size() == 0 || s.size() < words[0].size() * words.size()) {
            return vector<int>{};
        }
        vector<int> will_return;
        vector<vector<int>> temp;
        for (int i = 0; i < words.size(); i++) {
            if (strStr_kmp(s, words[i]) == -1) {
                return will_return;
            }
        }
        //cout << 1 << endl;
        for (int i = 0; i < words.size(); i++) {
            vector<int> pos(s.size(), -1);
            for (int j = 0; j <= s.size() - words[0].size();) {
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

        vector<vector<int>> locas(s.size(), vector<int>{});
        for (auto i : temp) {
            for (int j = 0; j <= s.size() - words[0].size(); j++) {
                if (-1 != i[j]) {
                    locas[j].push_back(i[j]);
                }
            }
        }
        //cout << 3 << endl;
        for (int i = 0; i <= s.size() - words[0].size() * words.size(); i++) {
            unordered_set<int> uset;
            if (locas[i].size() != 0) {
                for (int j = 0; j < words.size(); j++) {
                    if (locas[i + j * words[0].size()].size() == 0) {
                        break;
                    } else {
                        int temp = uset.size();
                        for (auto k : locas[i + j * words[0].size()]) {
                            if (uset.count(k) == 0) {
                                uset.insert(k);
                                break;
                            }
                        }
                        if (uset.size() == temp) {
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
        if (n == "") {
            return 0;
        }
        int x = 0;
        int y = 0;
        int hsize = h.size();
        int nsize = n.size();
        vector<int> next = get_next(n);
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

    vector<int> get_next(const string &h) {
        vector<int> will_return(h.size(), -1);
        int x = -1;
        int y = 0;
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
        vector<string> vec1 = {"foo", "bar"};
        vector<string> vec2 = {"word", "good", "best", "word"};
        vector<string> vec3 = {"word", "good", "best", "good"};
        findSubstring(str1, vec1);
        findSubstring(str2, vec2);
        findSubstring(str2, vec3);
    }
};

#endif
