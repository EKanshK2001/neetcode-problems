/**
 * O(logn) - binary search
 * 
 * Given the sorted rotated array nums of unique elements, return the minimum element of this array.
 * 
 * link : https://leetcode.com/problems/find-minimum-in-rotated-sorted-array/
 * 
 */

/**
 * Here the important things to note are that the array is rotated, that means that we will always find a sorted sublist eventually (either eventually or after some iterations of binary search)
 * So if we find that the right most element (in that iteration) is lower than the left, that means that we found an anomally. This anomally arises due to the fact that its rotated.
 * 
 * Also, when we find a mid element to be greater than left most element, it means that sublist is sorted and we take the left most element to check if it is the minimum.
 * then increment left = mid + 1, to check right sublist for the anomaly is still not cleared.
 * 
 * If not, then find an even bigger anomaly. This should mean two things : 
 * At its left it might contain even lower elements.
 * At its right it should be a sorted sublist. (this has to be a confirm case becuase its a rotated sorted array and if originally if right was lower than left then we have found a mid even lower than right)
 * all this becuase its rotated sorted, if this don't make sense then please refer to neetcode video solution, it might make you remember it or just do it on paper.
 */
class Solution {
public:
    int findMin(vector<int>& nums) {
        //setting res to an arbitrary value from nums initially
        int res = nums[0];
        int l = 0, r = nums.size() - 1;     //setting left and right pointers at each end

        while (l <= r) {                    //basic binary search condition

            //this case covers when we reach a fully sorted sublist (or original list as sorted)
            if (nums[l] < nums[r]) {

                //this means that a sorted list will have its lowest element in the left
                res = min(res, nums[l]);
                break;
            }

            //binary search
            int mid = l + (r - l) / 2;
            //here we have to put a least value (if any from mid or left)
            //also when we find a right sorted sublist similar to the else case below but we put the lower value in the res here
            res = min(res, nums[mid]);

            //this case covers when we find a left half as sorted sublist (this does not mean we found the lowest element)
            //because we still had that anomaly of finding right pointer element lower than left
            //that means that lowest element is still in the right
            if (nums[mid] >= nums[l]) { 
                l = mid + 1;
            }

            //this case covers when we find the mid element to be lower than left !!
            //very imp that finding a mid lower than left after finding right was lower already,
            //means that mid is lower than right as well because mind that they are rotated sorted sublists
            //that's why searching the right of mid is no-no because it contains elements greater than mid
            //so we search if there's even lower element than mid in its left, again because they are 
            //rotated sorted
            else {
                r = mid - 1;
            }
        }
        return res;
    }
};