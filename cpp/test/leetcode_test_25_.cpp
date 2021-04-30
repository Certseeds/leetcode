/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-03-31 10:48:56
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
#include "leetcode_25_.hpp"
#include <functional>

namespace Solution25 {
using namespace LISTNODE;
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution25 sol25;

static ListNode *reverseKGroup_test(ListNode *root, int k) {
    return sol25.reverseKGroup(root, k);
}

static ListNode *reverseKGroup2_test(ListNode *root, int k) {
    return sol25.reverseKGroup2(root, k);
}

static ListNode *reverseKGroup3_test(ListNode *root, int k) {
    return sol25.reverseKGroup3(root, k);
}

void transfer(vector<int> &vec, int k) {
    if (k == 1) {
        return;
    }
    auto iter = vec.begin();
    auto iter2 = vec.begin() + k;
    for (size_t i = 0; i < vec.size() / k - 1; i++) {
        //cout << i << endl;
        std::reverse(iter, iter2);
        iter += k;
        iter2 += k;
    }
    std::reverse(iter, iter2);
}

void _test(int x, int y, const std::function<ListNode *(ListNode *, int)> &func) {
    vector<int> nums1(x, -1);
    for (int32_t i{0}; i < x; i++) {
        nums1[i] = i + 1;
    }
    vector<ListNode *> vec1 = ListNode::numToList(nums1);
    const ListNodeLink vec1_{vec1};
    transfer(nums1, y);
    ListNode *node1 = func(vec1[0], y);
    int begin = 0;
    while (node1 != nullptr) {
        CHECK(node1->val == nums1[begin]);
        //cout << node1->val << " " << nums1[begin] << " ";
        node1 = node1->next;
        begin++;
    }
}

TEST_CASE("10-1 [test 25]", "[test 25]") {
    _test(10, 1, reverseKGroup_test);
    _test(10, 1, reverseKGroup2_test);
    _test(10, 1, reverseKGroup3_test);
}

TEST_CASE("5-2 [test 25]", "[test 25]") {
    _test(5, 2, reverseKGroup_test);
    _test(5, 2, reverseKGroup2_test);
    _test(5, 2, reverseKGroup3_test);
}

TEST_CASE("6-2 [test 25]", "[test 25]") {
    _test(6, 2, reverseKGroup_test);
    _test(6, 2, reverseKGroup2_test);
    _test(6, 2, reverseKGroup3_test);
}

TEST_CASE("6-3 [test 25]", "[test 25]") {
    _test(6, 3, reverseKGroup_test);
    _test(6, 3, reverseKGroup2_test);
    _test(6, 3, reverseKGroup3_test);
}

TEST_CASE("7-3 [test 25]", "[test 25]") {
    _test(7, 3, reverseKGroup_test);
    _test(7, 3, reverseKGroup2_test);
    _test(7, 3, reverseKGroup3_test);
}

TEST_CASE("3-3 [test 25]", "[test 25]") {
    _test(3, 3, reverseKGroup_test);
    _test(3, 3, reverseKGroup2_test);
    _test(3, 3, reverseKGroup3_test);
}

TEST_CASE("9-3 [test 25]", "[test 25]") {
    _test(9, 3, reverseKGroup_test);
    _test(9, 3, reverseKGroup2_test);
    _test(9, 3, reverseKGroup3_test);
}
}
