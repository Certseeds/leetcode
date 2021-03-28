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
#include "leetcode_8_.hpp"

namespace Solution8 {

Solution8 sol8;

TEST_CASE("1 [test 8]", "[test 8]") {
    CHECK(sol8.myAtoi("42") == 42);
    CHECK(sol8.myAtoi("65537") == 65537);
    CHECK(sol8.myAtoi("114514") == 114514);
    CHECK(sol8.myAtoi("1919810") == 1919810);
}

TEST_CASE("2 [test 8]", "[test 8]") {
    CHECK(sol8.myAtoi("+42") == 42);
    CHECK(sol8.myAtoi("+65537") == 65537);
    CHECK(sol8.myAtoi("+114514") == 114514);
    CHECK(sol8.myAtoi("+1919810") == 1919810);
}

TEST_CASE("3 [test 8]", "[test 8]") {
    CHECK(sol8.myAtoi("-42") == -42);
    CHECK(sol8.myAtoi("-65537") == -65537);
    CHECK(sol8.myAtoi("-114514") == -114514);
    CHECK(sol8.myAtoi("-1919810") == -1919810);
}

TEST_CASE("4 [test 8]", "[test 8]") {
    CHECK(sol8.myAtoi("  -42") == -42);
    CHECK(sol8.myAtoi("  -65537") == -65537);
    CHECK(sol8.myAtoi("    -114514") == -114514);
    CHECK(sol8.myAtoi("     -1919810") == -1919810);
}

TEST_CASE("5 [test 8]", "[test 8]") {
    CHECK(sol8.myAtoi("114514 with meaningless words") == 114514);
    CHECK(sol8.myAtoi("meaningless words with -65537") == 0);
    CHECK(sol8.myAtoi("2147483647") == std::numeric_limits<int32_t>::max());
    CHECK(sol8.myAtoi("-2147483648") == std::numeric_limits<int32_t>::min());
}
}
