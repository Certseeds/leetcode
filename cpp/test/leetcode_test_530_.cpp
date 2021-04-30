/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-13 09:42:57
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
#include "leetcode_530_.hpp"

namespace Solution530 {
using namespace TREENODE;
Solution530 sol530;

TEST_CASE("1 [test 530]", "[test 530]") {
    vector<int32_t> test_data{4, 2, 6, 1, 3};
    const auto vec = TreeNode::numToTree(test_data);
    THEN("1-rec [test 530]") {
        CHECK(sol530.getMinimumDifference(vec[0]) == 1);
    }THEN("1-iter [test 530]") {
        CHECK(sol530.getMinimumDifference2(vec[0]) == 1);
    }
    std::unique_ptr<TreeNode> vec_{vec[0]};
}

TEST_CASE("2 [test 530]", "[test 530]") {
    vector<int32_t> test_data{1, 0, 48, No, No, 12, 49};
    const auto vec = TreeNode::numToTree(test_data);
    THEN("2-rec [test 530]") {
        CHECK(sol530.getMinimumDifference(vec[0]) == 1);
    }THEN("2-iter [test 530]") {
        CHECK(sol530.getMinimumDifference2(vec[0]) == 1);
    }
    std::unique_ptr<TreeNode> vec_{vec[0]};
}
}
