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
#include "leetcode_12_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution12 sol12;

TEST_CASE("test case 1", "[test 12]") {
    CHECK(sol12.intToRoman(3) == "III");
    CHECK(sol12.intToRoman_2(3) == "III");
}

TEST_CASE("test case 2", "[test 12]") {
    CHECK(sol12.intToRoman(4) == "IV");
    CHECK(sol12.intToRoman_2(4) == "IV");
}

TEST_CASE("test case 3", "[test 12]") {
    CHECK(sol12.intToRoman(9) == "IX");
    CHECK(sol12.intToRoman_2(9) == "IX");
}

TEST_CASE("test case 4", "[test 12]") {
    CHECK(sol12.intToRoman(58) == "LVIII");
    CHECK(sol12.intToRoman_2(58) == "LVIII");
}

TEST_CASE("test case 5", "[test 12]") {
    CHECK(sol12.intToRoman(1994) == "MCMXCIV");
    CHECK(sol12.intToRoman_2(1994) == "MCMXCIV");
}

TEST_CASE("test case 6", "[test 12]") {
    CHECK(sol12.intToRoman(114514) ==
          "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXIV");
    CHECK(sol12.intToRoman_2(114514) ==
          "MMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMMDXIV");
}
