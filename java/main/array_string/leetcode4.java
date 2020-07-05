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
 * @Date: 2020-05-29 11:22:23
 * @LastEditors : nanoseeds
 */
package array_string;

public class leetcode4 {
    public static double findMedianSortedArrays(int[] nums1, int[] nums2) {
        int left = (nums1.length + nums2.length + 1) / 2;
        int right = (nums1.length + nums2.length + 2) / 2;
        return (get_nums(nums1, 0, nums2, 0, left) * 1.0f +
                get_nums(nums1, 0, nums2, 0, right) * 1.0f) / 2;
    }

    public static int get_nums(int[] nums1, int begin1, int[] nums2, int begin2, int k) {
        // 每一次迭代会删去某个数组中的k/2个元素
        // 关键就在于将A,B联动起来,每次削减1/2.
        if (begin1 >= nums1.length) {
            return nums2[begin2 + k - 1];
        } else if (begin2 >= nums2.length) {
            return nums1[begin1 + k - 1];
        } else if (k == 1) {
            return Math.min(nums1[begin1], nums2[begin2]);
        }
        int half = k / 2;
        int newIndex1 = Math.min(begin1 + half, nums1.length) - 1;
        int newIndex2 = Math.min(begin2 + half, nums2.length) - 1;
        if (nums1[newIndex1] <= nums2[newIndex2]) {
            k -= (newIndex1 - begin1 + 1);
            begin1 = newIndex1 + 1;
        } else {
            k -= (newIndex2 - begin2 + 1);
            begin2 = newIndex2 + 1;
        }
        return get_nums(nums1, begin1, nums2, begin2, k);
    }

}
