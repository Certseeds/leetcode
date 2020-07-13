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
#include "leetcode_7_.hpp"

Solution7 sol7;

TEST_CASE("1", "[test 7]") {
    CHECK(sol7.reverse(123) == 321);
    CHECK(sol7.reverse2(123) == 321);
}

TEST_CASE("2", "[test 7]") {
    CHECK(sol7.reverse(-123) == -321);
    CHECK(sol7.reverse2(-123) == -321);
}

TEST_CASE("3", "[test 7]") {
    CHECK(sol7.reverse(120) == 21);
    CHECK(sol7.reverse2(120) == 21);
}

TEST_CASE("4", "[test 7]") {
    CHECK(sol7.reverse(0) == 0);
    CHECK(sol7.reverse2(0) == 0);
}

TEST_CASE("5", "[test 7]") {
    CHECK(sol7.reverse(-2147483648) == 0);
    CHECK(sol7.reverse2(-2147483648) == 0);
}

TEST_CASE("6", "[test 7]") {
    CHECK(sol7.reverse(1463847412) == 2147483641);
    CHECK(sol7.reverse2(1463847412) == 2147483641);
}
