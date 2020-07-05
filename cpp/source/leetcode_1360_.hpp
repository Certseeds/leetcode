/*
 * @Github: https://github.com/Certseeds
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-02-23 10:31:29
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-02-23 12:30:31
 */
#ifndef _LEETCODE_1360_H_
#define _LEETCODE_1360_H_

#include <vector>
#include <string>
#include <algorithm>

using std::max;
using std::min;
using std::stoi;
using std::cout;
using std::endl;
using std::swap;
using std::vector;
using std::string;

/*
Write a program to count the number of days between two dates.

The two dates are given as strings, 
their format is YYYY-MM-DD as shown in the examples.

Example 1:
Input: date1 = "2019-06-29", date2 = "2019-06-30"
Output: 1

Example 2:
Input: date1 = "2020-01-15", date2 = "2019-12-31"
Output: 15

Constraints:
The given dates are valid dates between the years 1971 and 2100.
10:30-11:08
*/
class Solution1360 {
public:
    vector<int> month_365 = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};
    vector<int> month_366 = {31, 29, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int daysBetweenDates(string date1, string date2) {
        int year_1 = stoi(date1.substr(0, 4));
        int month_1 = stoi(date1.substr(5, 7));
        int day_1 = stoi(date1.substr(8, 10));

        int year_2 = stoi(date2.substr(0, 4));
        int month_2 = stoi(date2.substr(5, 7));
        int day_2 = stoi(date2.substr(8, 10));
        if (year_1 > year_2) {
            swap(year_1, year_2);
            swap(month_1, month_2);
            swap(day_1, day_2);
        } else if (year_2 == year_1 && month_1 > month_2) {
            swap(month_1, month_2);
            swap(day_1, day_2);
        } else if (year_2 == year_1 && month_1 == month_2 && day_1 > day_2) {
            swap(day_1, day_2);
        }
        int will_return = 0;
        if (year_1 == year_2) {
            if (month_1 == month_2) {
                return day_2 - day_1;
            }
            if (judge_year_days(year_1) == 365) {
                for (int i = month_1 + 1; i < month_2; i++) {
                    will_return += month_365[i];
                }
                will_return += day_2;
                will_return += month_365[month_1] - day_1;

            } else {
                for (int i = month_1 + 1; i < month_2; i++) {
                    will_return += month_366[i];
                }
                will_return += day_2;
                will_return += month_366[month_1] - day_1;
            }

        }
        for (int i = year_1 + 1; i < year_2; i++) {
            //cout << "year " << i << endl;
            will_return += judge_year_days(i);
        }
        vector<int> temp1 = month_366;
        if (judge_year_days(year_1) == 365) {
            temp1 = month_365;
        }
        will_return += temp1[month_1 - 1] - day_1;
        for (int i = month_1; i < 12; i++) {
            will_return += temp1[i];
        }
        temp1 = month_366;

        if (judge_year_days(year_2) == 365) {
            temp1 = month_365;
        }
        for (int i = 0; i < month_2 - 1; i++) {
            will_return += temp1[i];
        }
        will_return += day_2;
        return will_return;
    }

    int judge_year_days(int year) {
        if ((0 == year % 4 && 0 != year % 100) ||
            (0 == year % 400)) {
            return 366;
        }
        return 365;
    }

    void test() {
        cout << "same year and month test" << endl;
        assert(1 == daysBetweenDates("2019-06-29", "2019-06-30"));
        cout << "1 year pass test" << endl;
        assert(15 == daysBetweenDates("2020-01-15", "2019-12-31"));
        cout << "long time test" << endl;
        assert(14331 == daysBetweenDates("1971-06-29", "2010-09-23"));
        cout << "end at leap year test" << endl;
        assert(25923 == daysBetweenDates("2009-08-18", "2080-08-08"));
    }
};
/*
Runtime: 0 ms,
Memory Usage: 8.5 MB,
100%,100%.
*/
#endif
