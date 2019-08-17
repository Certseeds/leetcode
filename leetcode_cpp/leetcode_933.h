#pragma once
#ifndef _LEETCODE_933_H
#define _LEETCODE_933_H
#include <queue>
using namespace std;
class RecentCounter {
public:
	queue<int> que;
	RecentCounter() {

	}
	int ping(const int & t) {
		que.push(t);
		while (que.front() < t - 3000) {
			que.pop();
		}
		return que.size();
	}
};

#endif
