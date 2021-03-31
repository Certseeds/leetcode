/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-03-31 19:37:54
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
#include "leetcode_27_.hpp"

namespace Solution27 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution27 sol27;

TEST_CASE("1 [test 27]", "[test 27]") {
    vector<int> vec1 = {0, 1, 2, 2, 3, 0, 4, 2};
    THEN("1-1 [test 27]") {
        CHECK(sol27.removeElement(vec1, 2) == 5);
    }THEN("1-2 [test 27]") {
        CHECK(sol27.removeElement2(vec1, 2) == 5);
    }
}

TEST_CASE("2 [test 27]", "[test 27]") {
    vector<int> vec1 = {3, 2, 2, 3};
    THEN("2-1 [test 27]") {
        CHECK(sol27.removeElement(vec1, 2) == 2);
    }THEN("2-2 [test 27]") {
        CHECK(sol27.removeElement2(vec1, 2) == 2);
    }

}

TEST_CASE("3 [test 27]", "[test 27]") {
    vector<int> vec1 = {1};
    THEN("3-1 [test 27]") {
        CHECK(sol27.removeElement(vec1, 1) == 0);
    }THEN("3-2 [test 27]") {
        CHECK(sol27.removeElement2(vec1, 1) == 0);
    }
}

TEST_CASE("4 [test 27]", "[test 27]") {
    vector<int> vec1 = {};
    THEN("4-1 [test 27]") {
        CHECK(sol27.removeElement(vec1, 0) == 0);
    }THEN("4-2 [test 27]") {
        CHECK(sol27.removeElement(vec1, 0) == 0);
    }
}

TEST_CASE("5 [test 27]", "[test 27]") {
    vector<int> vec1 = {3, 3};
    THEN("5-1 [test 27]") {
        CHECK(sol27.removeElement(vec1, 3) == 0);
    }THEN("5-2 [test 27]") {
        CHECK(sol27.removeElement(vec1, 3) == 0);
    }
}
}
