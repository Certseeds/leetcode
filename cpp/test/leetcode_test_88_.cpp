/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-05 00:48:41
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
#include "leetcode_88_.hpp"

namespace Solution88 {
using Catch::Matchers::Equals;
Solution88 sol88;

TEST_CASE("4 [test 88]", "[test 88]") {
    vector<int> vec1;
    vector<int> vec2;
    vector<int> result;
    GIVEN("given [test 88]") {
        THEN("test case 1 [test 88]") {
            vec1 = {4, 5, 6, 0, 0, 0};
            vec2 = {1, 2, 3};
            result = {1, 2, 3, 4, 5, 6};
        }THEN("test case 2 [test 88]") {
            vec1 = {1, 2, 3, 0, 0, 0};
            vec2 = {2, 5, 6};
            result = {1, 2, 2, 3, 5, 6};
        }THEN("test case 3 [test 88]") {
            vec1 = {2, 0};
            vec2 = {1};
            result = {1, 2};
        }THEN("test case 4 [test 88]") {
            vec1 = {0};
            vec2 = {1};
            result = {1};
        }
        sol88.merge(vec1, vec1.size() - vec2.size(), vec2, vec2.size());
        CHECK_THAT(vec1, Equals(result));
    }
}
}
