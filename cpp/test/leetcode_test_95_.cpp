/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-21 20:33:53
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
#include "leetcode_95_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution95 sol95;

TEST_CASE("test case 1 [test 95]", "[test 95]") {
    auto three = sol95.generateTrees(0);
    CHECK_THAT(three, Equals<TreeNode *>({}));
}

TEST_CASE("test case 2 [test 95]", "[test 95]") {
    const vector<vector<int32_t>> result{
            {1, No, 2,  No, 3,  No, No},
            {1, No, 3,  2,  No, No, No},
            {2, 1,  3,  No, No, No, No},
            {3, 1,  No, No, 2,  No, No},
            {3, 2,  No, 1,  No, No, No},
    };
    auto three = sol95.generateTrees(3);
    CHECK(three.size() == 5);
    for (int i = 0; i < 5; ++i) {
        CHECK(TreeNode::judge_equal(three[i], result[i]));
    }
}
