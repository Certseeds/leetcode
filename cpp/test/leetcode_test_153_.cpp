/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-22 20:41:21
 * @LastEditors: nanoseeds
 */
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
#include "catch_main.hpp"
#include "leetcode_153_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution153 sol153;

TEST_CASE("test case 1 [test 153]", "[test 153]") {
    const vector<int32_t> input = {1, 2, 5};
    CHECK(sol153.findMin(input) == 1);
}

TEST_CASE("test case 2 [test 153]", "[test 153]") {
    const vector<int32_t> input = {2, 114, 514, 0, 1};
    CHECK(sol153.findMin(input) == 0);
}

TEST_CASE("test case 3 [test 153]", "[test 153]") {
    const vector<int32_t> input = {3, 4, 5, 1, 2};
    CHECK(sol153.findMin(input) == 1);
}

TEST_CASE("test case 4 [test 153]", "[test 153]") {
    const vector<int32_t> input = {4, 5, 6, 7, 0, 1, 2};
    CHECK(sol153.findMin(input) == 0);
}