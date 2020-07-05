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
 * @Date: 2020-05-29 10:26:58
 * @LastEditors : nanoseeds
 */
package array_string;

import org.junit.jupiter.api.Test;

import java.util.Arrays;

import static array_string.leetcode1.twoSum;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;


public class leetcode1Test {

    @Test
    public void test_leetcode1() {
        int[] temp = twoSum(new int[]{2, 7, 11, 15}, 9);
        assert temp != null;
        Arrays.sort(temp);
        assertArrayEquals(temp, new int[]{0, 1});
    }
}
