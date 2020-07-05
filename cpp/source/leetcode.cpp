//#include "leetcode_pragma.h"
//#pragma GCC optimize(2)
#include <fstream>
#include <iostream>
#include "assert.h"
#include "leetcode_helper.hpp"

#define leetcode_NUM 44

#include "leetcode_macro.h"
#include TO_STRING(leetcode_include)
#include "leetcode_timer.hpp"

using std::ios;
using std::cin;
using std::cout;
using std::endl;
leetcode_timer timer{};

void function_head();

static int faster_streams = []() {
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();

int main() {
    std::cout << __DATE__ << " " << __TIME__ << endl;
    std::cout << leetcode_NUM << " begin" << std::endl;
    function_head();
    std::cout << leetcode_NUM << " end" << std::endl;
    for (int i = 0; i < INT32_MAX / 2; i++) {
        i++;
    }
    return 0;
}

void function_head() {
    Solution_head Solution_object;
    Solution_object.test();
}
