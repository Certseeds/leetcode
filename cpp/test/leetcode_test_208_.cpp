/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-14 12:36:15
 * @LastEditors: nanoseeds
 */
/*  leetcode
    Copyright (C) 2020-2021 nanoseeds

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
#include "leetcode_208_.hpp"

namespace Solution208 {
Solution208 sol208;

TEST_CASE("1 [test 208]", "[test 208]") {
    sol208.tire.insert("apple");
    CHECK(sol208.tire.search("apple"));
    CHECK_FALSE(sol208.tire.search("app"));
    CHECK(sol208.tire.startsWith("app"));
    sol208.tire.insert("app");
    CHECK(sol208.tire.search("app"));
}

TEST_CASE("2 [test 208]", "[test 208]") {
    sol208.tire.insert("hello");
    CHECK_FALSE(sol208.tire.search("hell"));
    CHECK_FALSE(sol208.tire.search("helloa"));
    CHECK(sol208.tire.search("hello"));
    CHECK(sol208.tire.startsWith("hell"));
    CHECK_FALSE(sol208.tire.startsWith("helloa"));
    CHECK(sol208.tire.startsWith("hello"));
}

TEST_CASE("1-2 [test 208]", "[test 208]") {
    sol208.tire2.insert("apple");
    CHECK(sol208.tire2.search("apple"));
    CHECK_FALSE(sol208.tire2.search("app"));
    CHECK(sol208.tire2.startsWith("app"));
    sol208.tire2.insert("app");
    CHECK(sol208.tire2.search("app"));
}

TEST_CASE("2-2 [test 208]", "[test 208]") {
    sol208.tire2.insert("hello");
    CHECK_FALSE(sol208.tire2.search("hell"));
    CHECK_FALSE(sol208.tire2.search("helloa"));
    CHECK(sol208.tire2.search("hello"));
    CHECK(sol208.tire2.startsWith("hell"));
    CHECK_FALSE(sol208.tire2.startsWith("helloa"));
    CHECK(sol208.tire2.startsWith("hello"));
}
}
