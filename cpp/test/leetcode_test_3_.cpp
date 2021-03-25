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
#include "leetcode_3_.hpp"

Solution3 sol3;

TEST_CASE("1 [test 3]", "[test 3]") {
    string str = "abcabcbb";
    CHECK(sol3.lengthOfLongestSubstring(str) == 3);
    CHECK(sol3.lengthOfLongestSubstring2(str) == 3);
}

TEST_CASE("2 [test 3]", "[test 3]") {
    string str = "bbbbb";
    CHECK(sol3.lengthOfLongestSubstring(str) == 1);
    CHECK(sol3.lengthOfLongestSubstring2(str) == 1);

}

TEST_CASE("3 [test 3]", "[test 3]") {
    string str = "pwwkew";
    CHECK(sol3.lengthOfLongestSubstring(str) == 3);
    CHECK(sol3.lengthOfLongestSubstring2(str) == 3);
}

TEST_CASE("4 [test 3]", "[test 3]") {
    string str = "abba";
    cout << sol3.lengthOfLongestSubstring(str) << endl;
    CHECK(sol3.lengthOfLongestSubstring(str) == 2);
    CHECK(sol3.lengthOfLongestSubstring2(str) == 2);
}

TEST_CASE("5 [test 3]", "[test 3]") {
    string str = " ";
    CHECK(sol3.lengthOfLongestSubstring(str) == 1);
    CHECK(sol3.lengthOfLongestSubstring2(str) == 1);
}

TEST_CASE("6 [test 3]", "[test 3]") {
    string str = "   ";
    CHECK(sol3.lengthOfLongestSubstring(str) == 1);
    CHECK(sol3.lengthOfLongestSubstring2(str) == 1);
}
