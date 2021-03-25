/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-23 23:26:46
 * @LastEditors: nanoseeds
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
#include "leetcode_19_.hpp"

Solution19 sol19;

TEST_CASE("test case 1 [test 19]", "[test 19]") {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<ListNode *> vec1 = ListNode::numToList(nums);
    ListNode *temp = sol19.removeNthFromEnd(vec1[0], 2);
    CHECK(temp->val == 1);
    CHECK(temp->next->val == 2);
    CHECK(temp->next->next->val == 3);
    CHECK(temp->next->next->next->val == 5);
    CHECK(temp->next->next->next->next == nullptr);
    for (auto &i : vec1) {
        delete i;
    }
}

TEST_CASE("test case 2 [test 19]", "[test 19]") {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<ListNode *> vec1 = ListNode::numToList(nums);
    ListNode *temp = sol19.removeNthFromEnd(vec1[0], 0);
    CHECK(temp->val == 1);
    CHECK(temp->next->val == 2);
    CHECK(temp->next->next->val == 3);
    CHECK(temp->next->next->next->val == 4);
    CHECK(temp->next->next->next->next == nullptr);
    for (auto &i : vec1) {
        delete i;
    }
}

TEST_CASE("test case 3 [test 19]", "[test 19]") {
    vector<int> nums = {1, 2, 3, 4, 5};
    vector<ListNode *> vec1 = ListNode::numToList(nums);
    ListNode *temp = sol19.removeNthFromEnd(vec1[0], 5);
    CHECK(temp->val == 2);
    CHECK(temp->next->val == 3);
    CHECK(temp->next->next->val == 4);
    CHECK(temp->next->next->next->val == 5);
    CHECK(temp->next->next->next->next == nullptr);
    for (auto &i : vec1) {
        delete i;
    }
}