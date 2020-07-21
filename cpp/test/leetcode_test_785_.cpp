/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-20 23:59:37
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
#include "leetcode_785_.hpp"

using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution785 sol785;

TEST_CASE("test case 1", "[test 785]") {
    const vector<vector<int32_t>> vec{{1, 3},
                                      {0, 2},
                                      {1, 3},
                                      {0, 2}};
    CHECK(sol785.isBipartite(vec));
}

TEST_CASE("test case 2", "[test 785]") {
    const vector<vector<int32_t>> vec{{1, 2, 3},
                                      {0, 2},
                                      {0, 1, 3},
                                      {0, 2}};
    CHECK(sol785.isBipartite(vec) == 0);
}

TEST_CASE("test case 3", "[test 785]") {
    const vector<vector<int32_t>> vec{{},
                                      {2, 4, 6},
                                      {1, 4, 8, 9},
                                      {7, 8},
                                      {1, 2, 8, 9},
                                      {6, 9},
                                      {1, 5, 7, 8, 9},
                                      {3, 6, 9},
                                      {2, 3, 4, 6, 9},
                                      {2, 4, 5, 6, 7, 8}};
    CHECK(sol785.isBipartite(vec) == 0);
}

TEST_CASE("test case 4", "[test 785]") {

    const vector<vector<int32_t>> vec{{4},
                                      {},
                                      {4},
                                      {4},
                                      {0, 2, 3}};
    CHECK(sol785.isBipartite(vec));
}

TEST_CASE("test case 5", "[test 785]") {
    const vector<vector<int32_t>> vec{{2,  4},
                                      {2,  3,  4},
                                      {0,  1},
                                      {1},
                                      {0,  1},
                                      {7},
                                      {9},
                                      {5},
                                      {},
                                      {6},
                                      {12, 14},
                                      {},
                                      {10},
                                      {},
                                      {10},
                                      {19},
                                      {18},
                                      {},
                                      {16},
                                      {15},
                                      {23},
                                      {23},
                                      {},
                                      {20, 21},
                                      {},
                                      {},
                                      {27},
                                      {26},
                                      {},
                                      {},
                                      {34},
                                      {33, 34},
                                      {},
                                      {31},
                                      {30, 31},
                                      {38, 39},
                                      {37, 38, 39},
                                      {36},
                                      {35, 36},
                                      {35, 36},
                                      {43},
                                      {},
                                      {},
                                      {40},
                                      {},
                                      {49},
                                      {47, 48, 49},
                                      {46, 48, 49},
                                      {46, 47, 49},
                                      {45, 46, 47, 48}};
    CHECK(sol785.isBipartite(vec) == 0);
}