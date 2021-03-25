/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-13 21:44:20
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
#include "leetcode_350_.hpp"

Solution350 sol350;
using Catch::Matchers::UnorderedEquals;

TEST_CASE("1 [test 350]", "[test 350]") {
    vector<int32_t> vec1{1, 2, 2, 1};
    vector<int32_t> vec2{2, 2};
    CHECK_THAT(sol350.intersect(vec1, vec2), UnorderedEquals<int>({2, 2}));
}

TEST_CASE("2 [test 350]", "[test 350]") {
    vector<int32_t> vec1{4, 9, 5};
    vector<int32_t> vec2{9, 4, 9, 8, 4};
    CHECK_THAT(sol350.intersect(vec1, vec2), UnorderedEquals<int>({4, 9}));
}

TEST_CASE("3 [test 350]", "[test 350]") {
    vector<int32_t> vec1{1, 2};
    vector<int32_t> vec2{1, 1};
    CHECK_THAT(sol350.intersect(vec1, vec2), UnorderedEquals<int>({1}));
}
