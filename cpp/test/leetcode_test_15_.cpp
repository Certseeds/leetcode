/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-03-29 19:27:49
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
#include "leetcode_15_.hpp"

namespace Solution15 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution15 sol15;

TEST_CASE("1 [test 15]", "[test 15]") {
    vector<int32_t> nums = {-4, -1, -1, 0, 1, 2};
    auto out1 = sol15.threeSum(nums);
    const vector<vector<int32_t>> results{{-1, 0,  1},
                                          {-1, -1, 2}};
    CHECK_THAT(sol15.threeSum(nums), UnorderedEquals(results));
}

TEST_CASE("2 [test 15]", "[test 15]") {
    vector<int32_t> nums = {};
    auto out1 = sol15.threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(sol15.threeSum(nums), UnorderedEquals(results));
}

TEST_CASE("3 [test 15]", "[test 15]") {
    vector<int32_t> nums = {0};
    auto out1 = sol15.threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(sol15.threeSum(nums), UnorderedEquals(results));
}

TEST_CASE("8 [test 15]", "[test 15]") {
    vector<int32_t> nums = {0, 0, 0};
    auto out1 = sol15.threeSum(nums);
    const vector<vector<int32_t>> results{{0, 0, 0}};
    CHECK_THAT(sol15.threeSum(nums), UnorderedEquals(results));
}

TEST_CASE("4 [test 15]", "[test 15]") {
    vector<int32_t> nums = {-1, 0, 1, 2, -1, -4};
    auto out1 = sol15.threeSum(nums);
    const vector<vector<int32_t>> results{{-1, 0,  1},
                                          {-1, -1, 2}};
    CHECK_THAT(sol15.threeSum2(nums), UnorderedEquals(results));
}

TEST_CASE("5 [test 15]", "[test 15]") {
    vector<int32_t> nums = {};
    auto out1 = sol15.threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(sol15.threeSum2(nums), UnorderedEquals(results));
}

TEST_CASE("6 [test 15]", "[test 15]") {
    vector<int32_t> nums = {0};
    auto out1 = sol15.threeSum(nums);
    const vector<vector<int32_t>> results{};
    CHECK_THAT(sol15.threeSum2(nums), UnorderedEquals(results));
}

TEST_CASE("7 [test 15]", "[test 15]") {
    vector<int32_t> nums = {0, 0, 0};
    auto out1 = sol15.threeSum(nums);
    const vector<vector<int32_t>> results{{0, 0, 0}};
    CHECK_THAT(sol15.threeSum2(nums), UnorderedEquals(results));
}
}
