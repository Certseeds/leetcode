/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-20 23:47:54
 * @LastEditors  : nanoseeds
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
#include "leetcode_167_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution167 sol167;

TEST_CASE("test case 1", "[test 167]") {
    const vector<int32_t> vec{2, 7, 11, 15};
    CHECK_THAT(sol167.twoSum(vec, 9), Equals<int32_t>({1, 2}));
    CHECK_THAT(sol167.twoSum2(vec, 9), Equals<int32_t>({1, 2}));
}

TEST_CASE("test case 2", "[test 167]") {
    const vector<int32_t> vec{3, 2, 4};
    CHECK_THAT(sol167.twoSum(vec, 6), Equals<int32_t>({1, 2}));
    CHECK_THAT(sol167.twoSum2(vec, 6), Equals<int32_t>({1, 2}));
}
