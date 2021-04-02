/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-03 00:17:41
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
#include "leetcode_372_.hpp"

namespace Solution372 {
Solution372 sol372;

// 快速幂
TEST_CASE("1 [test 372]", "[test 372]") {
    CHECK(8 == sol372.superPow(2, {3}));
    CHECK(1024 == sol372.superPow(2, {1, 0}));
    CHECK(1 == sol372.superPow(1, {4, 3, 3, 8, 5, 2}));
    CHECK(1198 == sol372.superPow(std::numeric_limits<int32_t>::max(), {2, 0, 0}));
    CHECK(true);
    CHECK_FALSE(false);
}
}
