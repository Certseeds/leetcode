/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-04 23:16:48
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
#include "leetcode_32_.hpp"

namespace Solution32 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution32 sol32;

TEST_CASE("1 [test 32]", "[test 32]") {
    CHECK(0 == sol32.longestValidParentheses(""));
    CHECK(2 == sol32.longestValidParentheses("(()"));
    CHECK(2 == sol32.longestValidParentheses("())"));
    CHECK(4 == sol32.longestValidParentheses(")()())"));
    CHECK(6 == sol32.longestValidParentheses("()(())"));
    CHECK(2 == sol32.longestValidParentheses("()(()"));
    CHECK(6 == sol32.longestValidParentheses("(()())"));
}
}
