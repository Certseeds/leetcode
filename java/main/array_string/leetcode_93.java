/*  leetcode/java
    Copyright (C) 2020 nanoseeds

    leetcode_java is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    leetcode_java is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
/**
 * @Github: https://github.com/Certseeds/leetcode/java
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-06-11 21:31:43
 * @LastEditors : nanoseeds
 */
package array_string;

import java.util.ArrayList;
import java.util.List;

public class leetcode_93 {
    public static List<String> restoreIpAddresses(String s) {
        List<String> will_return = new ArrayList<>();
        char[] array = s.toCharArray();
        for (char ch : array) {
            ch -= '0';
        }
        if (s.length() < 4 || s.length() > 12) {
            return will_return;
        }

        return null;
    }

    public int transfer(char[] s, int begin, int end) {
        if (end - begin > 1 && s[begin] == 0) {
            return -1;
        }
        int will_return = 0;
        switch (end - begin) {
            case 1: {
                will_return = s[begin];
                break;
            }
            case 2: {
                will_return = 10 * s[begin] + s[begin + 1];
                break;

            }
            case 3: {
                will_return = 100 * s[begin] + 10 * s[begin + 1] + s[begin + 2];
                break;
            }
        }
        if (will_return > 255) {
            return -1;
        }
        return will_return;
    }

}
