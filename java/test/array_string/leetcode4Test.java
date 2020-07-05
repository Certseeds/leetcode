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
 * @Date: 2020-05-29 11:22:33
 * @LastEditors : nanoseeds
 */
package array_string;

import org.junit.jupiter.api.Test;

import static array_string.leetcode4.findMedianSortedArrays;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class leetcode4Test {
    @Test
    public void test2() {
        assertEquals(findMedianSortedArrays(new int[]{1, 3, 4, 9}, new int[]{1, 2, 3, 4, 5, 6, 7, 8, 9}),
                4.0f, 1.0f / 10000f);
        assertEquals(findMedianSortedArrays(new int[]{0, 0}, new int[]{0, 0}),
                0.0f, 1.0f / 10000f);
        assertEquals(findMedianSortedArrays(new int[]{1}, new int[]{2, 3, 4, 5, 6}),
                3.5f, 1.0f / 10000f);
    }
}
