#pragma once
#ifndef _LEETCODE_HASH_H_
#define _LEETCODE_HASH_H_
namespace std {
    template<typename T, typename U>
    class hash<pair<T, U>> {
    public:
        size_t operator()(const pair<T, U>& p) const {
            return std::hash<T>()(p.first) ^ std::hash<U>()(p.second);
        }
    };
}
#endif
