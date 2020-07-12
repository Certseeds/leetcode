/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-12 21:56:13
 * @LastEditors  : nanoseeds
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
#include "leetcode_174_.hpp"

Solution174 sol174;

TEST_CASE("test 1", "[test 174]") {
    vector<vector<int32_t>> vec = {{-2, -3,  3},
                                   {-5, -10, 1},
                                   {10, 30,  -5}};
    CHECK(sol174.calculateMinimumHP(vec) == 7);
}

TEST_CASE("test 2", "[test 174]") {
    vector<vector<int32_t>> vec = {{0, -3}};
    CHECK(sol174.calculateMinimumHP(vec) == 4);
}

TEST_CASE("test 3", "[test 174]") {
    vector<vector<int32_t>> vec = {{0}};
    CHECK(sol174.calculateMinimumHP(vec) == 1);
}