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
 * @Date: 2020-05-29 22:24:23
 * @LastEditors : nanoseeds
 */
package array_string;

import org.junit.jupiter.api.Test;


import org.junit.jupiter.api.Test;

import java.util.Collections;
import java.util.List;

import static array_string.leetcode15.*;
import static org.junit.jupiter.api.Assertions.assertArrayEquals;
import static org.junit.jupiter.api.Assertions.assertEquals;

public class leetcode15Test {
    @Test
    public void test15() {
        testArray(new int[]{-1, 0, 1, 2, -1, -4});
        testArray(new int[]{3,0,-2,-1,1,2});
    }

    public void testArray(int[] nums) {
        List<List<Integer>> temp = threeSum(nums);
        for (List<Integer> li : temp) {
            for (Integer I_in : li) {
                System.out.printf("%d%s", I_in, " ");
            }
            System.out.println();
        }
    }
}
