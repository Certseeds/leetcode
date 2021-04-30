/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-03-26 10:00:53
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
#include "leetcode_21_.hpp"

namespace Solution21 {
using namespace LISTNODE;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution21 sol21;

TEST_CASE("1 [test 21]", "[test 21]") {
    ListNodeLink vec1{1,2,4};
    ListNodeLink vec2{1,3,4};
    ListNode *node1 = sol21.mergeTwoLists2(vec1[0], vec2[0]);
    int32_t lastV = std::numeric_limits<int32_t>::min();
    while (node1 != nullptr) {
        CHECK(node1->val >= lastV);
        lastV = node1->val;
        node1 = node1->next;
    }
}

TEST_CASE("2 [test 21]", "[test 21]") {
    ListNodeLink vec1{1, 1, 1, 4, 4, 5};
    ListNodeLink vec2{0, 1, 1, 1, 8, 9, 9};
    ListNode *node1 = sol21.mergeTwoLists2(vec1[0], vec2[0]);
    int32_t lastV = std::numeric_limits<int32_t>::min();
    while (node1 != nullptr) {
        CHECK(node1->val >= lastV);
        lastV = node1->val;
        node1 = node1->next;
    }
}
}