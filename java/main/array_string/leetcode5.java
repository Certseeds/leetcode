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
 * @Date: 2020-05-29 16:20:29
 * @LastEditors : nanoseeds
 */
package array_string;

import java.util.ArrayList;
import java.util.Arrays;

public class leetcode5 {
    public static String longestPalindrome2(String s) {
        if (s.isEmpty()) {
            return "";
        }
        byte[] by = s.getBytes();
        ArrayList<Integer> begin = new ArrayList<>();
        ArrayList<Integer> end = new ArrayList<>();
        for (int i = 0; i < s.length() - 1; i++) {
            if (by[i] == by[i + 1]) {
                begin.add(i);
                end.add(i + 1);
            }
        }
        for (int i = 0; i < s.length() - 2; i++) {
            if (by[i] == by[i + 2]) {
                begin.add(i);
                end.add(i + 2);
            }
        }
        while (true) {
            ArrayList<Integer> newbegin = new ArrayList<>();
            ArrayList<Integer> newend = new ArrayList<>();
            for (int i = 0; i < begin.size(); i++) {
                int a = begin.get(i);
                int b = end.get(i);
                if (a - 1 < 0 || b + 1 >= by.length) {
                    continue;
                }
                if (by[a - 1] == by[b + 1]) {
                    newbegin.add(a - 1);
                    newend.add(b + 1);
                }
            }
            if (newbegin.isEmpty()) {
                break;
            }
            begin = newbegin;
            end = newend;
        }
        System.out.println(Arrays.toString(begin.toArray()));
        System.out.println(Arrays.toString(end.toArray()));
        if (begin.isEmpty()) {
            return s.substring(0, 1);
        }
        int max_v = -1;
        for (int i = 0; i < begin.size(); i++) {
            max_v = Math.max(max_v, end.get(i) - begin.get(i));
        }
        for (int i = 0; i < begin.size(); i++) {
            if (end.get(i) - begin.get(i) == max_v) {
                return s.substring(begin.get(i), end.get(i) + 1);
            }
        }
        return s.substring(begin.get(0), end.get(0) + 1);
    }

    public static String longestPalindrome(String s) {
        if (s.isEmpty()) {
            return "";
        }
        byte[] by = s.getBytes();
        int[] range = {0, 0};
        for (int i = 0; i < by.length - 1; i++) {
            int[] odd = get_range(by, i, i + 1);
            int[] even = get_range(by, i, i + 2);
            if (odd[1] - odd[0] > range[1] - range[0]) {
                range = odd;
            }
            if (even[1] - even[0] > range[1] - range[0]) {
                range = even;
            }
        }
        return s.substring(range[0], range[1] + 1);
    }

    public static int[] get_range(byte[] by, int begin, int end) {
        if (begin < 0 || end >= by.length) {
            return new int[]{0, 0};
        } else if (by[begin] != by[end]) {
            return new int[]{begin, begin};
        }
        while (begin >= 0 && end < by.length && by[begin] == by[end]) {
            begin--;
            end++;
        }
        return new int[]{++begin, --end};
    }
}
