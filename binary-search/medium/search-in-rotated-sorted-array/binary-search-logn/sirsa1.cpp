/**
 * O(logn) --> binary search using two pointer without recursion
 * 
 * Given the array nums after the possible rotation and an integer target, return the index of target if it is in nums, or -1 if it is not in nums.
 * 
 * link: https://leetcode.com/problems/search-in-rotated-sorted-array/
 */

/**
 * @brief some IMP things to discuss that we didn't notice in the last binary search problem to find the minimum in rotated sorted array:
 * 
 * whenever we alot the mid in any sorted or unsorted array, we get a sublist either on its left or its right that is sorted.
 * this is very very true.
 * that's why in this case when we divide the two parts with mid, we initially check if the target is present in the sorted portion first.
 * if we dont find in the sorted one first, then we go the other part from there anyways.
 * 
 * - the mid element will always find the target. true for all binary search algorithms.
 * 
 * technicalities:
 *  - we find for the sorted sublist using the formula, if mid element is greater than or equal to left element.
 *  - this means that if true, left side will be sorted, if not right side will be sorted.
 *  - the first check case in any sorted portion will be to check if it belongs there or not, if not push the left/right to the other half.
 *  - to check if it belongs there or not, we check if target is in its range or not. i.e. (lower than left and greater than right) -> fails this
 */

class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l = 0, r = nums.size() - 1;

        while (l <= r) {
            int mid = l + (r - l) / 2;

            //target will be found by mid.
            if (nums[mid] == target) return mid;

            //we check whichever portion is sorted first, after the mid is distributed.
            //because we do get a sorted sublist either its left or right confirm everytime.

            //left sorted portion
            if (nums[l] <= nums[mid]) {
                if (target < nums[l] || target > nums[mid]) {
                    l = mid + 1;
                }
                else {
                    r = mid - 1;
                }
            }
            //right sorted portion
            else {
                if (target < nums[mid] || target > nums[r]) {
                    r = mid - 1;
                }
                else {
                    l = mid + 1;
                }
            }
        }
        return -1;
    }
}; 