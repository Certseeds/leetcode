/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-03-27 10:32:10
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
#include "leetcode_22_.hpp"

namespace Solution22 {
using Catch::Matchers::UnorderedEquals;

Solution22 sol22;
static const vector<string> gene5{
        "((()))",
        "(()())",
        "(())()",
        "()(())",
        "()()()"
};

TEST_CASE("1 [test 22]", "[test 22]") {
    CHECK(sol22.generateParenthesis(1).size() == 1);
    CHECK(sol22.generateParenthesis(2).size() == 2);
    CHECK(sol22.generateParenthesis(3).size() == 5);
    CHECK(sol22.generateParenthesis(4).size() == 14);
    CHECK_THAT(sol22.generateParenthesis(3), UnorderedEquals(gene5));
}

TEST_CASE("2 [test 22]", "[test 22]") {
    for (int32_t i = 1; i < 5; ++i) {
        CHECK_THAT(sol22.generateParenthesis(i), UnorderedEquals(sol22.generateParenthesis2(i)));
        //std::cout << i << std::endl;
    }
}
}
