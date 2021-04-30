/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-03-30 16:55:38
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
#include "leetcode_24_.hpp"

namespace Solution24 {
using namespace LISTNODE;

Solution24 sol24;

TEST_CASE("1 [test 24]", "[test 24]") {
    CHECK(sol24.swapPairs(nullptr) == nullptr);
}

TEST_CASE("2 [test 24]", "[test 24]") {
    ListNodeLink vec1{1, 2, 3, 4};
    const auto *const results = sol24.swapPairs(vec1[0]);
    CHECK(results->val == 2);
    CHECK(results->next->val == 1);
    CHECK(results->next->next->val == 4);
    CHECK(results->next->next->next->val == 3);
    CHECK(results->next->next->next->next == nullptr);
}

TEST_CASE("3 [test 24]", "[test 24]") {
    ListNodeLink vec1{1, 1, 4, 5, 1, 4};
    const auto *const results = sol24.swapPairs(vec1[0]);
    CHECK(results->val == 1);
    CHECK(results->next->val == 1);
    CHECK(results->next->next->val == 5);
    CHECK(results->next->next->next->val == 4);
    CHECK(results->next->next->next->next->val == 4);
    CHECK(results->next->next->next->next->next->val == 1);
    CHECK(results->next->next->next->next->next->next == nullptr);
}
}
