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
 * @Date: 2020-06-11 20:30:23
 * @LastEditors : nanoseeds
 */
package array_string;

import java.util.ArrayDeque;
import java.util.Deque;

public class leetcode_71 {
    public static String simplifyPath(String path) {
        Deque<String> deque = new ArrayDeque<>();
        path = path.replaceAll("(/+)", "/");
        String[] results = path.split("/");
        if (results.length == 0) {
            return "/";
        }
        for (int i = 1;i<results.length;i++) {
            if (results[i].equals(".")) {
                continue;
            } else if (results[i].equals("..")) {
                if (deque.isEmpty()) {
                } else {
                    deque.removeLast();
                }
            } else {
                deque.add(results[i]);
            }
        }
        StringBuilder stringBuilder = new StringBuilder();
        while (!deque.isEmpty()) {
            stringBuilder.append("/" + deque.getFirst());
            deque.removeFirst();
        }
        if (stringBuilder.toString().equals("")){
            return "/";
        }
        return stringBuilder.toString();
    }
}
