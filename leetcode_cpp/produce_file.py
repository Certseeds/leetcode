import os
import sys
number = sys.argv[1]
number = str(number)
model = 
"""#pragma once
#ifndef _LEETCODE_{}_H_
#define _LEETCODE_{}_H_
#include <vector>
#include <array>
#include <string>
#include <algorithm>
using namespace std;
class Solution{} {{
public:
    void test() {{
    }}
}};

#endif
"""
writefile = open("leetcode_{}.h".format(number),mode='a+')
writefile.write(model.format(number,number ,number))
print("leetcode_{}.h write success".format(number))