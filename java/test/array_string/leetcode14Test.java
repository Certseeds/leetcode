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
 * @Date: 2020-05-29 17:37:14
 * @LastEditors : nanoseeds
 */
package array_string;


import org.junit.jupiter.api.Test;

import static array_string.leetcode14.longestCommonPrefix;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class leetcode14Test {
    @Test
    public void test14() {
        String[] str1 = {"a"};
        assertEquals(longestCommonPrefix(str1), "a");
        assertEquals(longestCommonPrefix(new String[]{"aa", "a"}), "a");
    }
}
