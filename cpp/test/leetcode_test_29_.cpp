/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-01 20:25:35
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
#include "leetcode_29_.hpp"

namespace Solution29 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution29 sol29;

TEST_CASE("1 [test 29]", "[test 29]") {
    CHECK(sol29.divide(std::numeric_limits<int32_t>::min(), -1) == std::numeric_limits<int32_t>::max());
    CHECK(sol29.divide(std::numeric_limits<int32_t>::min(), 1) == std::numeric_limits<int32_t>::min());
    CHECK(sol29.divide(std::numeric_limits<int32_t>::min(), 2) == -1073741824);
    CHECK(sol29.divide(std::numeric_limits<int32_t>::min(), -2) == 1073741824);
    CHECK(sol29.divide(10, 3) == 3);
    CHECK(sol29.divide(7, -3) == -2);
    CHECK(sol29.divide(std::numeric_limits<int32_t>::min(), std::numeric_limits<int32_t>::min()) == 1);
    CHECK(sol29.divide(-1010369383, -2147483648) == 0);
}
}
