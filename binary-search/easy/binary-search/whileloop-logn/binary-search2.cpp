/*
O(logn) of binary search where n is the size of input array

Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

link : https://leetcode.com/problems/binary-search/

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        
        //should not cross the right pointer as it means the target is not present
        while (right >= left) {

            //TO PREVENT INTERGER OVERFLOW!! (it wont let the sum cross the max int size)
            int mid = left + (right - left) / 2;

            //when it finds the target
            if (nums[mid] == target) {
                return mid;
            }

            //when the num is present in the right half
            else if (nums[mid] < target) {
                left = mid + 1;
            }

            //when the num is present in the left half
            else {
                right = mid - 1;
            }
        }

        // when element not found in either half      or (left > right)
        else return -1;
    }
};