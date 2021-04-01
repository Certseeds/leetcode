/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-01 09:44:06
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
#include "leetcode_28_.hpp"

namespace Solution28 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution28 sol28;

TEST_CASE("1 [test 28]", "[test 28]") {
    CHECK(sol28.strStr_kmp("hello", "ll") == 2);
    CHECK(sol28.strStr_kmp("aaaaa", "bba") == -1);
    CHECK(sol28.strStr_kmp("aaaaa", "") == 0);
    CHECK(sol28.strStr_kmp("a", "a") == 0);
    CHECK(sol28.strStr_kmp("mississippi", "issi") == 1);
    CHECK(sol28.strStr_kmp("mississippi", "issip") == 4);
}
}
