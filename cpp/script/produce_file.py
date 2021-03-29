#!/usr/bin/env python3
# coding=utf-8
import sys
import time

"""
@Github: https://github.com/Certseeds/leetcode
@Organization: SUSTech
@Author: nanoseeds
@LastEditors: nanoseeds
@LastEditTime: 2020-07-20 23:47:50
"""
""" leetcode_cpp
    Copyright (C) 2020-2021  nanoseeds

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
"""

year: str = time.strftime("%Y", time.localtime())
create_time: str = time.strftime("%Y-%m-%d %H:%M:%S", time.localtime())
path: str = "./../source/leetcode_{}_.hpp"
test_path: str = "./../test/leetcode_test_{}_.cpp"
code_template: str
code_test_template: str
file_header: str


def read_file(file_name: str) -> str:
    will_return: str
    with open(file_name, mode='r', encoding="UTF-8") as template:
        will_return = template.read()
    return will_return


def write_to_file(order: int) -> None:
    with open(path.format(order), mode='a+') as file:
        file.write(file_header.format(create_time, year))
        file.write(code_template.format(order))
    with open(test_path.format(order), mode='a+') as file:
        file.write(file_header.format(create_time, year))
        file.write(code_test_template.format(order))
    print(f"{path.format(order)} write success")


def main(begin_num: int, end_num: int) -> None:
    for i in range(begin_num, end_num):
        write_to_file(i)
    print("main finish\n")


# range in [begin,end)
if __name__ == '__main__':
    code_template = read_file("./cpp_template.txt")
    code_test_template = read_file("./cpp_test_template.txt")
    file_header = read_file("file_header.txt")
    begin: int = int(sys.argv[1])
    end: int = int(sys.argv[2])
    main(begin, end)
