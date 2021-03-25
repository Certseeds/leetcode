/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-21 21:00:02
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
#include "leetcode_13_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution13 sol13;

TEST_CASE("test case 1 [test 13]", "[test 13]") {
    CHECK(sol13.romanToInt("III") == 3);
}

TEST_CASE("test case 2 [test 13]", "[test 13]") {
    CHECK(sol13.romanToInt("IV") == 4);
}

TEST_CASE("test case 3 [test 13]", "[test 13]") {
    CHECK(sol13.romanToInt("IX") == 9);
}

TEST_CASE("test case 4 [test 13]", "[test 13]") {
    CHECK(sol13.romanToInt("LVIII") == 58);
}

TEST_CASE("test case 5 [test 13]", "[test 13]") {
    CHECK(sol13.romanToInt("MCMXCIV") == 1994);
}

TEST_CASE("test case 6 [test 13]", "[test 13]") {
    CHECK(sol13.romanToInt(
            "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXIV") ==
          114514);
}


