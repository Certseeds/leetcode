/*  leetcode_cpp 
    Copyright (C) 2020  nanoseeds

    leetcode_cpp is free software: you can redistribute it and/or modify
    it under the terms of the GNU Affero General Public License as
    published by the Free Software Foundation, either version 3 of the
    License, or (at your option) any later version.

    leetcode_cpp is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU Affero General Public License for more details.

    You should have received a copy of the GNU Affero General Public License
    along with this program.  If not, see <https://www.gnu.org/licenses/>.
    */
/**
 * @Github: https://github.com/Certseeds/leetcode_cpp
 * @Organization: SUSTech
 * @Author: nanoseeds
 * @Date: 2020-06-29 21:59:13 
 * @LastEditors  : nanoseeds
 */
#include <vector>
#include <iostream>

using std::vector;

void quick_sort(vector<int> &nums);

int get_rand(int left, int right);

void rec_quicksort(vector<int> &nums, int left, int right);

int partition(vector<int> &nums, int left, int right, int pivotIndex);

int main() {
    vector<int> nums1{3, 2, 1, 5, 6, 4};
    vector<int> nums2{3, 2, 3, 1, 2, 4, 5, 5, 6};
    quick_sort(nums1);
    quick_sort(nums2);
    for (const auto &item : nums1) {
        std::cout << item << "\n";
    }
    std::cout << "\n";

    for (const auto &item : nums2) {
        std::cout << item << " ";
    }
    std::cout << "\n";
}

void quick_sort(vector<int> &nums) {
    srand(time(0));
    int left = 0;
    int right = nums.size() - 1;
    rec_quicksort(nums, 0, nums.size() - 1);
}

void rec_quicksort(vector<int> &nums, int left, int right) {
    if (left >= right) {
        return;
    }
    int rand_posi = get_rand(left, right);
    int final_posi = partition(nums, left, right, rand_posi);
    rec_quicksort(nums, left, final_posi - 1);
    rec_quicksort(nums, final_posi + 1, right);
}

int get_rand(int left, int right) {
    return rand() % (right - left + 1) + left;
}

int partition(vector<int> &nums, int left, int right, int pivotIndex) {
    int pivotValue = nums[pivotIndex];
    std::swap(nums[pivotIndex], nums[right]); // 把pivot移到結尾
    int storeIndex = left;
    for (int i = left; i < right; i++) {
        if (nums[i] <= pivotValue) {
            std::swap(nums[storeIndex], nums[i]);
            storeIndex++;
        }
    }
    std::swap(nums[right], nums[storeIndex]);
    return storeIndex;
}