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
 * @Date: 2020-05-29 22:24:03
 * @LastEditors : nanoseeds
 */
package array_string;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.Collections;
import java.util.HashMap;
import java.util.HashSet;
import java.util.List;
import java.util.Map;
// TODO
public class leetcode15 {
    public static List<List<Integer>> threeSum(int[] nums) {
        List<List<Integer>> will_return = new ArrayList<List<Integer>>();
        if (nums.length <= 2) {
            return will_return;
        }
        Arrays.sort(nums);
        if (nums[0] > 0 || nums[nums.length - 1] < 0) {
            return will_return;
        }
        HashSet<Integer> hashSet = new HashSet<Integer>();
        for (int i : nums) {
            hashSet.add(i);
        }
        HashMap<Integer, Integer> hashmap = new HashMap<Integer, Integer>();
        HashSet<Long> hashSet1 = new HashSet<>();
        for (int i = 0; i < nums.length; i++) {
            for (int j = i + 1; j < nums.length; j++) {
                if (hashSet.contains(-nums[i] - nums[j])) {
                    hashSet1.add((long) (((long) (nums[i]) << 32) + nums[j]));
                }
            }
        }
        for (Long i : hashSet1) {
            int num1 = (int) (i >> 32);
            int num2 = (int) (i - (num1 << 32));
            will_return.add(new ArrayList<>() {{
                add(num1);
                add(num2);
                add(-num1 - num2);
            }});
        }
        return will_return;
    }


}
