/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-03-31 18:40:21
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
#include "leetcode_26_.hpp"

namespace Solution26 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution26 sol26;

TEST_CASE("1 [test 26]", "[test 26]") {
    vector<int32_t> vec{1, 2};
    const vector<int32_t> result{1, 2};
    THEN("then1 [test 26]") {
        sol26.removeDuplicates(vec);
    }THEN("then2 [test26]") {
        sol26.removeDuplicates2(vec);
    }
    CHECK_THAT(vec, Equals(result));
}

TEST_CASE("2 [test 26]", "[test 26]") {
    vector<int32_t> vec{1, 1, 2};
    const vector<int32_t> result{1, 2};
    THEN("then3 [test 26]") {
        sol26.removeDuplicates(vec);
    }THEN("then4 [test26]") {
        sol26.removeDuplicates2(vec);
    }
    CHECK_THAT(vec, Equals(result));
}

TEST_CASE("3 [test 26]", "[test 26]") {
    vector<int32_t> vec{0, 0, 1, 1, 1, 2, 2, 3, 3, 4};
    const vector<int32_t> result{0, 1, 2, 3, 4};
    THEN("then5 [test 26]") {
        sol26.removeDuplicates(vec);
    }
    THEN("then6 [test26]") {
        sol26.removeDuplicates2(vec);
    }
    CHECK_THAT(vec, Equals(result));
}
}
