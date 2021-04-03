/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-03 18:24:22
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
#include "leetcode_56_.hpp"

namespace Solution56 {
using Catch::Matchers::Equals;
Solution56 sol56;

TEST_CASE("1 {test 56}", "{test 56}") {
    const vector<vector<int32_t>> result{{{1, 6}, {8, 10}, {15, 18}}};
    CHECK_THAT(sol56.merge({{{1, 3}, {2, 6}, {8, 10}, {15, 18}}}), Equals(result));
}

TEST_CASE("2 {test 56}", "{test 56}") {
    const vector<vector<int32_t>> result{{{1, 5}}};
    CHECK_THAT(sol56.merge({{{1, 4}, {4, 5}}}), Equals(result));
}
}
