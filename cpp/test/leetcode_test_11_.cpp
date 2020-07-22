/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-22 20:56:48
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
#include "leetcode_11_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution11 sol11;

TEST_CASE("test case 1", "[test 11]") {
    const vector<int32_t> vec = {1, 8, 6, 2, 5, 4, 8, 3, 7};
    CHECK(sol11.maxArea(vec) == 49);
    CHECK(sol11.maxArea_n2(vec) == 49);
}

TEST_CASE("test case 2", "[test 11]") {
    const vector<int32_t> vec = {1, 1, 4, 5, 1, 4, 1, 9, 1, 9, 8, 1, 0};
    CHECK(sol11.maxArea(vec) == 35);
    CHECK(sol11.maxArea_n2(vec) == 35);
}

TEST_CASE("test case 3", "[test 11]") {
    const vector<int32_t> vec = {959, 231, 691, 608, 805, 486, 630, 971, 712, 984, 856, 529, 979, 540, 301, 381, 285,
                                 908, 78, 301, 818, 599, 996, 438, 163, 758, 301, 878, 22, 526, 771, 941, 59, 206, 636,
                                 421, 45, 736, 676, 518, 645, 128, 291, 747, 458, 209, 987, 902, 632, 221, 955, 275,
                                 889, 864, 827, 562, 554, 304, 610, 216, 41, 776, 700, 601, 457, 256, 825, 110, 429,
                                 399, 488, 358, 346, 674, 557, 884, 665, 36, 810, 689, 520, 760, 455, 573, 881, 865,
                                 568, 225, 588, 283, 689, 792, 677, 312, 229, 665, 585, 417, 666};
    CHECK(sol11.maxArea(vec) == 74004);
    CHECK(sol11.maxArea_n2(vec) == 74004);
}
