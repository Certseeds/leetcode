/*
 * @Github: https://github.com/Certseeds/leetcode
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-05 21:27:49
 * @LastEditors: nanoseeds
 * @LastEditTime: 2020-07-05 21:32:52
 */
#include "catch_main.hpp"
#include "leetcode_44_.hpp"

Solution44 sol44;

TEST_CASE("double empty [test 44]", "[test 44]") {
    CHECK(sol44.isMatch("", "*"));
}

TEST_CASE("test 1 [test 44]", "[test 44]") {
    CHECK_FALSE(sol44.isMatch("aa", "a"));
}


TEST_CASE("test 2 [test 44]", "[test 44]") {
    CHECK(sol44.isMatch("aa", "*"));
}

TEST_CASE("? [test 44]", "[test 44]") {
    CHECK_FALSE(sol44.isMatch("cb", "*a"));
}


TEST_CASE("* can match '' or any string [test 44]", "[test 44]") {
    CHECK(sol44.isMatch("adceb", "a*b"));
}

TEST_CASE("both * and ? [test 44]", "[test 44]") {
    CHECK_FALSE(sol44.isMatch("acdcb", "a*c?b"));
}
