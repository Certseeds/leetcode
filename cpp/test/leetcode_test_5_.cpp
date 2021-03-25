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
#include "leetcode_5_.hpp"

Solution5 sol5;

TEST_CASE("1 [test 5]", "[test 5]") {
    CHECK(sol5.longestPalindrome("babad").size() == 3);
}

TEST_CASE("2 [test 5]", "[test 5]") {
    CHECK(sol5.longestPalindrome("cbbc").size() == 4);
}

TEST_CASE("2_  [test 5]", "[test 5]") {
    CHECK(sol5.longestPalindrome("cbbd").size() == 2);
}

TEST_CASE("3 [test 5]", "[test 5]") {
    CHECK(sol5.longestPalindrome("cb").size() == 2);
}

TEST_CASE("4 [test 5]", "[test 5]") {
    CHECK(sol5.longestPalindrome("c").size() == 1);
}

TEST_CASE("5 [test 5]", "[test 5]") {
    CHECK(sol5.longestPalindrome("").size() == 0);
}