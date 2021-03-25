/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-08-01 00:00:12
 * @LastEditors: nanoseeds
 */
/*  leetcode
    Copyright (C) 2020 nanoseeds

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
#include "leetcode_14_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution14 sol14;

TEST_CASE("test case 1 [test 14]", "[test 14]") {
    const vector<string> strs = {
            "flower", "flow", "flight"
    };
    CHECK(sol14.longestCommonPrefix(strs) == "fl");
}

TEST_CASE("test case 2 [test 14]", "[test 14]") {
    const vector<string> strs = {
            "dog", "racecar", "car"
    };
    CHECK(sol14.longestCommonPrefix(strs) == "");

}

TEST_CASE("test case 3 [test 14]", "[test 14]") {
    const vector<string> strs = {
    };
    CHECK(sol14.longestCommonPrefix(strs) == "");
}