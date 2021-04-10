/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-10 10:38:20
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
#include "leetcode_263_.hpp"

namespace Solution263 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution263 sol263;

TEST_CASE("1 [test 263]", "[test 263]") {
    CHECK(sol263.isUgly(1));
    CHECK(sol263.isUgly(6));
    CHECK(sol263.isUgly(8));
    CHECK_FALSE(sol263.isUgly(14));
    CHECK_FALSE(sol263.isUgly(233));
    CHECK_FALSE(sol263.isUgly(114514));
    CHECK_FALSE(sol263.isUgly(1919810));
    CHECK_FALSE(sol263.isUgly(std::numeric_limits<int32_t>::max()));
    CHECK_FALSE(sol263.isUgly(std::numeric_limits<int32_t>::min()));
}
}
