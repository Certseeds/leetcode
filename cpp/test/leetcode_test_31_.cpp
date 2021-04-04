/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-04 23:04:53
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
#include "leetcode_31_.hpp"

namespace Solution31 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution31 sol31;

TEST_CASE("basic test [test 31]", "[test 31]") {
    vector<int> vec1 {1, 2, 3};
    vector<int> _vec1 {1, 3, 2};
    sol31.nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("test reverse [test 31]", "[test 31]") {
    vector<int> vec1 {3, 2, 1};
    vector<int> _vec1 {1, 2, 3};
    sol31.nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("basic test 2 [test 31]", "[test 31]") {
    vector<int> vec1 {1, 1, 5};
    vector<int> _vec1 {1, 5, 1};
    sol31.nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("complext test 1 [test 31]", "[test 31]") {
    vector<int> vec1 {1, 2, 1, 5, 4, 3, 3, 2, 1};
    vector<int> _vec1 {1, 2, 2, 1, 1, 3, 3, 4, 5};
    sol31.nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("test same elemtes [test 31]", "[test 31]") {
    vector<int> vec1 {1, 1};
    vector<int> _vec1 {1, 1};
    sol31.nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}

TEST_CASE("test just one element [test 31]", "[test 31]") {
    vector<int> vec1 = {1};
    vector<int> _vec1 = {1};
    sol31.nextPermutation(vec1);
    CHECK_THAT(vec1, Equals(_vec1));
}
}
