/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-01 22:48:59
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
#include "leetcode_30_.hpp"

namespace Solution30 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution30 sol30;

TEST_CASE("1 [test 30]", "[test 30]") {
    CHECK_THAT(sol30.findSubstring("barfoothefoobarman", {"foo", "bar"}),
               UnorderedEquals(vector<int32_t>{0, 9}));
    CHECK_THAT(sol30.findSubstring("wordgoodgoodgoodbestword", {"word", "good", "best", "word"}),
               UnorderedEquals(vector<int32_t>{}));
    CHECK_THAT(sol30.findSubstring("wordgoodgoodgoodbestword", {"word", "good", "best", "good"}),
               UnorderedEquals(vector<int32_t>{8}));
}
}
