#pragma once
#ifndef _LEETCODE_509_H
#define _LEETCODE_509_H
#include <array>
using namespace std;
class Solution509 {
public:
	int fib(int N) {
		array <int, 31> x = { 0,1,1,2,3,5,8,13,21,34,55,89,144,233,377,610,987,1597,2584,4181,6765
		,10946,17711,28657,46368,75025,121393,196418,317811,514229,832040};
		return x[N];
	}
};

#endif
