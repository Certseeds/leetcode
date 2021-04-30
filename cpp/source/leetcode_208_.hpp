/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-14 12:36:15
 * @LastEditors: nanoseeds
 */
/*  leetcode
    Copyright (C) 2020-2021 nanoseeds

    leetcode is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    leetcode is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_208_H
#define LEETCODE_CPP_SOURCE_LEETCODE_208_H

#include <algorithm>
#include <array>
#include <string>
#include <unordered_set>

namespace Solution208 {
using std::array;
using std::string;
using std::unordered_set;
static size_t alloc_delete_count {0};

class Solution208 {
    class Trie {
    private:
        unordered_set<string> uset{};
    public:
        /** Initialize your data structure here. */
        Trie() = default;

        /** Inserts a word into the trie. */
        void insert(const string &word) {
            uset.insert(word);
        }

        /** Returns if the word is in the trie. */
        bool search(const string &word) {
            return uset.find(word) != std::end(uset);
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(const string &prefix) {
            return
                    std::any_of(std::cbegin(uset), std::cend(uset), [& prefix](const auto &item) {
                        return prefix.size() <= item.size() && memcmp(item.c_str(), prefix.c_str(), prefix.size()) == 0;
                    });
        }
    };

public:
    Trie tire{};
private:

    class Trie2 {
    private:
        static constexpr const size_t array_size{26};
        class Node {
        public:
            uint8_t self;
            uint8_t isfinish;
            std::array<Node *, array_size> sons{nullptr};

            explicit Node(uint8_t self_, uint8_t finish) : self(self_), isfinish(finish) {
                alloc_delete_count++;
            }

            ~Node() {
                alloc_delete_count--;
                for (size_t i{0}; i < array_size; i++) {
                    delete sons[i];
                    sons[i]= nullptr;
                }
            }
        };

        std::array<Node *, array_size> sons{nullptr};
    public:
        Trie2() = default;
        ~Trie2(){
            for (size_t i{0}; i < array_size; i++) {
                delete sons[i];
                sons[i]= nullptr;
            }
            assert(alloc_delete_count == 0);
        }
        /** Inserts a word into the trie. */
        void insert(const string &word) {
            std::array<Node *, 26> *array = &sons;
            for (size_t i{0}; i < word.size() - 1; i++) {
                const auto &ch = word[i] - 'a';
                if ((*array)[ch] == nullptr) {
                    (*array)[ch] = new Node(ch, false);
                }
                array = &(*array)[ch]->sons;
            }
            {
                const auto &ch = word.back() - 'a';
                if ((*array)[ch] == nullptr) {
                    (*array)[ch] = new Node(ch, false);
                }
                (*array)[ch]->isfinish = true;
            }
        }

        /** Returns if the word is in the trie. */
        bool search(const string &word) {
            const std::array<Node *, 26> *array = &sons;
            uint8_t isfinish{false};
            for (auto ch: word) {
                ch -= 'a';
                if ((*array)[ch] == nullptr) {
                    return false;
                }
                isfinish = (*array)[ch]->isfinish;
                array = &(*array)[ch]->sons;
            }
            return isfinish;
        }

        /** Returns if there is any word in the trie that starts with the given prefix. */
        bool startsWith(const string &prefix) {
            const std::array<Node *, 26> *array = &sons;
            for (auto ch: prefix) {
                ch -= 'a';
                if ((*array)[ch] == nullptr) {
                    return false;
                }
                array = &(*array)[ch]->sons;
            }
            return true;
        }
    };

public:
    Trie2 tire2{};
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_208_H