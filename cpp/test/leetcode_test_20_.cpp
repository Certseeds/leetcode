/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-23 23:26:46
 * @LastEditors: nanoseeds
 */
/*  leetcode
    Copyright (C) 2020-2021  nanoseeds

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
#include "leetcode_20_.hpp"

Solution20 sol20;

TEST_CASE("test case 1", "[test 20]") {
    CHECK(sol20.isValid("()"));
    CHECK(sol20.isValid("()[]{}"));
    CHECK(sol20.isValid("(()[]{})[()[]{}]{()[]{}}"));
    CHECK(sol20.isValid("(((()[]{})[()[]{}]{()[]{}})[]{})[()[]{}]{()[]{}}"));
}

TEST_CASE("test case 0", "[test 20]") {
    CHECK_FALSE(sol20.isValid("(]"));
    CHECK_FALSE(sol20.isValid("(}"));
    CHECK_FALSE(sol20.isValid("[}"));
    CHECK_FALSE(sol20.isValid("[)"));
    CHECK_FALSE(sol20.isValid("{)"));
    CHECK_FALSE(sol20.isValid("{]"));
    CHECK_FALSE(sol20.isValid("(((()[]{})[()[]{}]{()[]{}})[]{))[()[]{}]{()[]{}}"));
}
