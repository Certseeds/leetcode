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
    template<typename X, typename Y,typename Z>
    class hash < tuple <X,Y,Z >> {
    public:
        size_t operator()(const tuple <X, Y, Z >& p) const {
            return (
            std::hash<X>()(std::get<0>(p)) ^
            std::hash<Y>()(std::get<1>(p)) ^ 
            std::hash<Z>()(std::get<2>(p)) );
        }
    }; 
    class int32_vector_hasher {
    public:
        std::size_t operator()(std::vector<int32_t> const& vec) const {
            std::size_t ret = 0;
            for (auto& i : vec) {
                ret ^= std::hash<int32_t>()(i);
            }
            return ret;
        }
    };
}
#endif
