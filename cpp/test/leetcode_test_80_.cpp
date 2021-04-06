/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-06 09:32:27
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
#include "leetcode_80_.hpp"

namespace Solution80 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution80 sol80;

TEST_CASE("1 [test 80]", "[test 80]") {
    vector<int32_t> vec1{};
    vector<int32_t> result{};
    THEN("1-1 [test 80]") {
        vec1 = {0, 0, 1, 1, 1, 1, 2, 3, 3};
        result = {0, 0, 1, 1, 2, 3, 3};
    }THEN("1-2 [test 80]") {
        vec1 = {1, 1, 1, 2, 2, 3};
        result = {1, 1, 2, 2, 3};
    }
    const auto size = sol80.removeDuplicates(vec1);
    vec1.resize(size);
    CHECK_THAT(vec1, Equals(result));
}
}
