#pragma once
#ifndef _LEETCODE_1185_H
#define _LEETCODE_1185_H
#include <array>
#include <vector>
#include <algorithm>
using namespace std;


class Solution1185 {
public:
	string dayOfTheWeek(int day, int month, int year) {
		array<string,7> days = {  "Monday", "Tuesday", "Wednesday",
			"Thursday", "Friday", "Saturday","Sunday", };
		if (month < 3) {
			month += 12;
			year -= 1;
		}
		return days[(day + 2*month + 3*(month+1)/5 + year + year/4- year/100 +year/400) %7];

	}
	void test() {
		cout << dayOfTheWeek(31, 8, 2019) << endl;
	}
};

#endif
