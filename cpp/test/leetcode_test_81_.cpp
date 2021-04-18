/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-18 22:59:48
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
#include "catch_main.hpp"
#include "leetcode_81_.hpp"

namespace Solution81 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution81 sol81;

TEST_CASE("1 [test 81]", "[test 81]") {
    CHECK_FALSE(sol81.search({1}, 0));
    CHECK(sol81.search({2, 5, 6, 0, 0, 1, 2}, 0));
}

TEST_CASE("2 [test 81]", "[test 81]") {
    CHECK(sol81.search({1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 2, 1, 1, 1, 1, 1}, 2));
}

TEST_CASE("3 [test 81]", "[test 81]") {
    CHECK(sol81.search({1, 0, 1, 1, 1}, 0));
    CHECK_FALSE(sol81.search({1, 0, 1, 1, 1}, 2));
}

TEST_CASE("4 [test 81]", "[test 81]") {
    CHECK_FALSE(sol81.search({2, 5, 6, 0, 0, 1, 2}, 3));
}

TEST_CASE("5 [test 81]", "[test 81]") {
    CHECK_FALSE(sol81.search({1, 1}, 0));
}

TEST_CASE("6 [test 81]", "[test 81]") {
    CHECK_FALSE(sol81.search({1, 1, 1, 3}, 2));
}
}
