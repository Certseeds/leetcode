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
#include "leetcode_1010_.hpp"

Solution1010 sol1010;

TEST_CASE("2", "[test 2]") {
    const vector<int32_t> vec1 = {30, 20, 150, 100, 40};
    CHECK(sol1010.numPairsDivisibleBy60(vec1) == 3);
}

TEST_CASE("3", "[test 2]") {
    const vector<int32_t> vec2 = {60, 60, 60};
    CHECK(sol1010.numPairsDivisibleBy60(vec2) == 3);
}

TEST_CASE("4", "[test 2]") {
    const vector<int32_t> vec3 = {54, 8, 17, 437, 54, 498, 455, 239, 183, 347, 59, 199, 52, 488, 147, 82};
    CHECK(sol1010.numPairsDivisibleBy60(vec3) == 2);
}

TEST_CASE("5", "[test 2]") {
    const vector<int32_t> vec4 = {418, 204, 77, 278, 239, 457, 284, 263, 372, 279, 476, 416, 360, 18};
    CHECK(sol1010.numPairsDivisibleBy60(vec4) == 1);
}
