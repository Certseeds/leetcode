/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-14 21:52:31
 * @LastEditors  : nanoseeds
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
#include "leetcode_120_.hpp"
namespace Solution120 {

Solution120 sol120;

TEST_CASE("test case 1 [test 120]", "[test 120]") {
    vector<vector<int32_t>> vec = {{2},
                                   {3, 4},
                                   {6, 5, 7},
                                   {4, 1, 8, 3}};
    CHECK(sol120.minimumTotal(vec) == 11);
}

TEST_CASE("test case 2 [test 120]", "[test 120]") {
    for (int32_t i{0}; i < 10; ++i) {
        //std::cout << sol120.multiply("12345", '0' + i) << std::endl;
    }
    sol120.multiply_0("123", "456");
    std::cout << sol120.add_str("123", "459") << end8_t;
    std::cout << string(10, '0') << std::endl;
    //for (int j = 0; j < 10; ++j) {
    //string temp;
    //std::cout << temp.append('0', j) << end8_t;
    //}
}}