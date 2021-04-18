/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2021-04-18 22:26:36
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
#include "leetcode_33_.hpp"

namespace Solution33 {
using Catch::Matchers::Equals;
using Catch::Matchers::UnorderedEquals;
using Catch::Matchers::Contains;
Solution33 sol33;

TEST_CASE("1 [test 33]", "[test 33]") {
    vector<int> vec1{4, 5, 6, 7, 8, 0, 1, 2};
    vector<int> vec2{4, 5, 6, 7, 8, 9, 0, 1, 2};
    vector<int> vec3{4, 5, 6, 7, 8, 9, 10, 0, 1, 2};
    vector<int> vec4{4, 5, 6, 7, 8, 9, 10, 11, 0, 1, 2};
    vector<int> vec5{4, 5, 6, 7, 8, 9, 10, 11, 12, 0, 1, 2};
    vector<int> vec6{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 0, 1, 2};
    vector<int> vec7{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 0, 1, 2};
    vector<int> vec8{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 0, 1, 2};
    vector<int> vec9{4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15, 16, 0, 1, 2};
    //cout << binary_search_pos(vec1, 8, 0, 4) << endl;
    vector<int> vec10{
            49, 64, 66, 67, 68, 69, 71, 74, 76, 78, 83, 86, 91, 93, 94, 96, 97, 106, 113, 11,
            6, 118, 119, 120, 121, 122, 123, 125, 126, 129, 131, 132, 141, 142, 144, 146, 14,
            7, 156, 157, 167, 170, 171, 172, 178, 183, 185, 188, 191, 192, 196, 209, 210, 211,
            213, 221, 226, 228, 230, 233, 235, 236, 237, 242, 243, 246, 247, 250, 251, 252,
            256, 261, 266, 267, 272, 275, 286, 289, 291, 296, 299,
            0, 7, 8, 9, 14, 16, 21, 35, 37, 41, 44, 45, 47, 48};
    CHECK(sol33.search(vec1, 8) == 4);
    CHECK(sol33.search(vec2, 9) == 5);
    CHECK(sol33.search(vec3, 3) == -1);
    CHECK(sol33.search(vec4, 2) == 10);
    CHECK(sol33.search(vec5, 7) == 3);
    CHECK(sol33.search(vec6, 24) == -1);
    CHECK(sol33.search(vec7, 13) == 9);
    CHECK(sol33.search(vec8, 1) == 13);
    CHECK(sol33.search(vec9, 0) == 13);
    CHECK(sol33.search(vec10, 35) == 88);
    CHECK(binary_search_pos(vec1, 0, 0, 5) == -1);
    CHECK(binary_search_pos(vec2, 4, 0, 5) == 0);
    CHECK(binary_search_pos(vec3, 5, 0, 5) == 1);
    CHECK(binary_search_pos(vec4, 6, 0, 5) == 2);
    CHECK(binary_search_pos(vec5, 7, 0, 5) == 3);
    CHECK(binary_search_pos(vec6, 8, 0, 5) == 4);
}
}
