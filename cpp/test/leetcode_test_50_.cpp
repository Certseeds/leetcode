/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-02 23:51:45
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
#include "leetcode_50_.hpp"

namespace Solution50 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution50 sol50;
// 快速幂
// double误差
TEST_CASE("1 [test 50]", "[test 50]") {
    CHECK(Approx(0.0f).epsilon(1e-3) == sol50.myPow(2.00000, -2147483648));
    CHECK(Approx(1024.0f).epsilon(1e-3) == sol50.myPow(2.00000, 10));
    CHECK(Approx(0.25f).epsilon(1e-3) == sol50.myPow(2.00000, -2));
    CHECK(Approx(9.261f).epsilon(1e-3) == sol50.myPow(2.1, 3));
}
}
