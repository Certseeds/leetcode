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
/**
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-07 22:27:29
 * @LastEditors  : nanoseeds
 */
#include "catch_main.hpp"
#include "leetcode_6_.hpp"

Solution6 sol6;

TEST_CASE("test basic", "[test 6]") {
    CHECK(sol6.convert("PAYPALISHIRING", 3) == "PAHNAPLSIIGYIR");
    CHECK(sol6.convert("PAYPALISHIRING", 4) == "PINALSIGYAHRPI");
    CHECK(sol6.convert("A", 1) == "A");
    CHECK(sol6.convert("AB", 2) == "AB");
    CHECK(sol6.convert("ABC", 3) == "ABC");
    CHECK(sol6.convert("ABCD", 4) == "ABCD");
    CHECK(sol6.convert("ABCDE", 4) == "ABCED");
    CHECK_FALSE(false);
}
