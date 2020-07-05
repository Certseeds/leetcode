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
 * @Date: 2020-07-05 16:38:16 
 * @LastEditors  : nanoseeds
 */
#ifndef LEETCODE_SOURCE_LEETCODE_TIMER_HPP
#define LEETCODE_SOURCE_LEETCODE_TIMER_HPP

#include <iostream>
#include <chrono>

std::chrono::milliseconds get_ms() {
    return std::chrono::duration_cast<std::chrono::milliseconds>(
            std::chrono::system_clock::now().time_since_epoch());
}

class leetcode_timer {
private:
    std::chrono::milliseconds ms;
public:
    explicit leetcode_timer() {
        ms = get_ms();
    }

    leetcode_timer(const leetcode_timer &timer) = delete;

    leetcode_timer(leetcode_timer &&timer) = delete;

    leetcode_timer &operator=(const leetcode_timer &timer) = delete;

    leetcode_timer &operator=(leetcode_timer &&mat) = delete;

    ~leetcode_timer() {
        std::cout << "cost " << get_ms().count() - ms.count() << " ms\n";
    }

};

#endif //LEETCODE_SOURCE_LEETCODE_TIMER_HPP
