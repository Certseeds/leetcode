/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-31 23:49:58
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
#include "leetcode_0803_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution0803 sol0803;

TEST_CASE("test case 1 [test 803]", "[test 803]") {
    vector<int> vec{0, 2, 3, 4, 5};
    CHECK(sol0803.findMagicIndex(vec) == 0);
}

TEST_CASE("test case 2 [test 803]", "[test 803]") {
    vector<int> vec{1, 1, 1};
    CHECK(sol0803.findMagicIndex(vec) == 1);
}

TEST_CASE("test case 3 [test 803]", "[test 803]") {
    vector<int> vec{0, 0, 2};
    CHECK(sol0803.findMagicIndex(vec) == 0);
}

