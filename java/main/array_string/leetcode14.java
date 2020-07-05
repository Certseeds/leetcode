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
 * @Date: 2020-05-29 17:33:15
 * @LastEditors : nanoseeds
 */
package array_string;

public class leetcode14 {
    public static String longestCommonPrefix(String[] strs) {
        if (strs.length == 0) {
            return "";
        }
        int min_length = Integer.MAX_VALUE / 2;
        int max_v = 0;
        for (String s : strs) {
            min_length = Math.min(min_length, s.length());
        }
        byte[] pub_str = strs[0].substring(0, min_length).getBytes();
        for (int i = 0; i < min_length; i++) {
            for (String s : strs) {
                if (s.charAt(i) != pub_str[i]) {
                    return strs[0].substring(0, max_v);
                }
            }
            max_v++;
        }
        return strs[0].substring(0, max_v);
    }
}
