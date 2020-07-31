/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-31 23:15:18
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
#include "leetcode_1025_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution1025 sol1025;

TEST_CASE("test case 1", "[test 1025]") {
    CHECK(sol1025.divorGame1(2));
    CHECK(sol1025.divorGame1_2(2));
}

TEST_CASE("test case 2", "[test 1025]") {
    CHECK_FALSE(sol1025.divorGame1(3));
    CHECK_FALSE(sol1025.divorGame1_2(3));
}

TEST_CASE("test case multiply", "[test 1025]") {
    for (int i = 4; i < 114; ++i) {
        CHECK(sol1025.divorGame1_2(i) == (i % 2 == 0));
    }
}