#!/usr/bin/env python3
# coding=utf-8
'''
@Github: https://github.com/Certseeds/leetcode
@Organization: SUSTech
@Author: nanoseeds
@LastEditors: nanoseeds
@LastEditTime: 2020-07-05 12:04:06
'''
""" leetcode_cpp
    Copyright (C) 2020  nanoseeds

    CS305_Network is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    CS305_Network is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
"""

import sys
import time

code_template: str
year: str = time.strftime("%Y", time.localtime())
create_time: str = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
path: str = "./../source/leetcode_{}_.hpp"


def read_template() -> str:
    will_return: str
    with open("./cpp_template.hpp") as template:
        will_return = template.read()
    return will_return


def write_to_file(order: int) -> None:
    with open(path.format(order), mode='a+') as file:
        file.write(code_template.format(
            year, create_time, order, order, order, order))
    print("{} write success".format(path.format(order)))


def main(begin_num: int, end_num: int) -> None:
    for i in range(begin_num, end_num):
        write_to_file(i)
    print("main finish\n")


# range in [begin,end)
if __name__ == '__main__':
    code_template = read_template()
    begin: int = int(sys.argv[1])
    end: int = int(sys.argv[2])
    main(begin, end)
