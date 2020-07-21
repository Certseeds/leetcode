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
/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-07 22:27:29
 * @LastEditors  : nanoseeds
 */
#include "catch_main.hpp"
#include "leetcode_1_.hpp"

Solution1 sol1;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;

TEST_CASE("basic tests", "[test 1]") {
    vector<int32_t> vec{2, 7, 11, 15};
    auto result = sol1.twoSum(vec, 9);
    SECTION("size is always 2") {
        CHECK(result.size() == 2);
    }SECTION("test cases") {
        CHECK_THAT(result, UnorderedEquals<int>({0, 1}));
        CHECK_THAT(result, Contains<int>({0, 1}));
    }
}

TEST_CASE("basic tests 2", "[test 1]") {
    vector<int32_t> vec{3, 2, 4};
    auto result = sol1.twoSum(vec, 6);
    SECTION("size is always 2") {
        CHECK(result.size() == 2);
    }SECTION("test cases") {
        CHECK_THAT(result, UnorderedEquals<int32_t>({1, 2}));
        CHECK_THAT(result, Contains<int32_t>({}));
    }
}
