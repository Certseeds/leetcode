#pragma once
#ifndef LEETCODE_CPP_SOURCE_LEETCODE_263_H
#define LEETCODE_CPP_SOURCE_LEETCODE_263_H
/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-10 10:38:20
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


namespace Solution263 {

class Solution263 {
public:
    bool isUgly(const int32_t n) {
        if (n <= 0) {
            return false;
        }
        return isUgly2(n);
    }

    bool isUgly2(const int32_t n) {
        if (n <= 6) {
            return true;
        } else if (n % 2 == 0) {
            return isUgly2(n >> 1);
        } else if (n % 3 == 0) {
            return isUgly2(n / 3);
        } else if (n % 5 == 0) {
            return isUgly2(n / 5);
        }
        return false;
    }
};
}
#endif //LEETCODE_CPP_SOURCE_LEETCODE_263_H