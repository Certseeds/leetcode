/*  leetcode_cpp 
    Copyright (C) 2020  nanoseeds

    leetcode_cpp is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    leetcode_cpp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
/**
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-07-05 21:56:16 
 * @LastEditors  : nanoseeds
 */
#ifndef LEETCODE_PUBLIC_HPP
#define LEETCODE_PUBLIC_HPP

#include <string>
#include <cassert>
#include <fstream>
#include <iostream>
#include "leetcode_helper.hpp"
#include "leetcode_timer.hpp"

using std::ios;
using std::cin;
using std::cout;
static constexpr const char end8_t = '\n';
leetcode_timer timer{};

static int faster_streams = []() {
    srand(time(0));
    std::ios::sync_with_stdio(false);
    std::istream::sync_with_stdio(false);
    std::ostream::sync_with_stdio(false);
    std::cin.tie(nullptr);
    std::cout.tie(nullptr);
    return 0;
}();
#endif //LEETCODE_PUBLIC_HPP
