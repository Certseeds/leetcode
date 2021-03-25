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
#include "leetcode_9_.hpp"

Solution9 sol9;

TEST_CASE("test case 1 [test 9]", "[test 9]") {
    CHECK(sol9.isPalindrome(121));
}

TEST_CASE("test case 2 [test 9]", "[test 9]") {
    CHECK_FALSE(sol9.isPalindrome(-121));
}

TEST_CASE("test case 3 [test 9]", "[test 9]") {
    CHECK_FALSE(sol9.isPalindrome(120));
}

TEST_CASE("test case 4 [test 9]", "[test 9]") {
    CHECK_FALSE(sol9.isPalindrome(10));
}