/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-03-30 11:19:50
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
#include "leetcode_23_.hpp"


namespace Solution23 {
using namespace LISTNODE;

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution23 sol23;

TEST_CASE("4 [test 23]", "[test 23]") {
    ListNodeLink vec1{1, 4, 5};
    ListNodeLink vec2{1, 3, 4};
    ListNodeLink vec3{2, 6};
    vector<ListNode *> vec4{};
    GIVEN("init data 1 [test 23]") {
        WHEN("data init results [test 23]") {
            ListNode *temp{nullptr};
            THEN("mergeKList4 [test 23]") {
                THEN("3-1-4 [test 23]") {
                    vec4 = {vec1[0], vec2[0], vec3[0]};
                }THEN("3-2-4 [test 23]") {
                }THEN("3-3-4 [test 23]") {
                    vec4 = {nullptr};
                }
                temp = sol23.mergeKLists4(vec4);
            }THEN("mergeKList3 [test 23]") {
                THEN("3-1-3 [test 23]") {
                    vec4 = {vec1[0], vec2[0], vec3[0]};
                }THEN("3-2-3 [test 23]") {
                }THEN("3-3-3 [test 23]") {
                    vec4 = {nullptr};
                }
                temp = sol23.mergeKLists3(vec4);
            }THEN("mergeKList2 [test 23]") {
                THEN("3-1-2 [test 23]") {
                    vec4 = {vec1[0], vec2[0], vec3[0]};
                }THEN("3-2-2 [test 23]") {
                }THEN("3-3-2 [test 23]") {
                    vec4 = {nullptr};
                }
                temp = sol23.mergeKLists2(vec4);
            }THEN("mergeKList1 [test 23]") {
                THEN("3-1-1 [test 23]") {
                    vec4 = {vec1[0], vec2[0], vec3[0]};
                }THEN("3-2-1 [test 23]") {
                }THEN("3-3-1 [test 23]") {
                    vec4 = {nullptr};
                }
                temp = sol23.mergeKLists(vec4);
            }
            int32_t before_num = std::numeric_limits<int32_t>::min();
            while (temp != nullptr) {
                CHECK(before_num <= temp->val);
                before_num = temp->val;
                temp = temp->next;
            }
        }
    }
}
}
