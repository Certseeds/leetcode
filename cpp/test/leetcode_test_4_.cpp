/*  leetcode
    Copyright (C) 2020  nanoseeds

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
/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-07 22:27:29
 * @LastEditors  : nanoseeds
 */
#include "catch_main.hpp"
#include "leetcode_4_.hpp"

namespace Solution4 {

Solution4 sol4;

TEST_CASE("1 [test 4]", "[test 4]") {
    const vector<int32_t> num1{1, 3};
    const vector<int32_t> num2{2};
    CHECK(sol4.findMedianSortedArrays(num1, num2) == 2);
}

TEST_CASE("2 [test 4]", "[test 4]") {
    const vector<int32_t> num1{1, 3};
    const vector<int32_t> num2{2, 4};
    CHECK(sol4.findMedianSortedArrays(num1, num2) == 2.5f);
}

TEST_CASE("3 [test 4]", "[test 4]") {
    const vector<int32_t> num1{0, 0};
    const vector<int32_t> num2{0, 0};
    CHECK(sol4.findMedianSortedArrays(num1, num2) == 0);
}

TEST_CASE("4 [test 4]", "[test 4]") {
    const vector<int32_t> num1{1};
    const vector<int32_t> num2{};
    CHECK(sol4.findMedianSortedArrays(num1, num2) == 1);
}

TEST_CASE("5 [test 4]", "[test 4]") {
    const vector<int32_t> num1{2};
    const vector<int32_t> num2{};
    CHECK(sol4.findMedianSortedArrays(num1, num2) == 2);
}
}