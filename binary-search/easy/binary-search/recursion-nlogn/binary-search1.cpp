/*
O(logn) of binary search where n is the size of input array

Given an array of integers nums which is sorted in ascending order, and an integer target,
write a function to search target in nums. If target exists, then return its index. Otherwise, return -1.

link : https://leetcode.com/problems/binary-search/

*/


class Solution {
public:
    int search(vector<int>& nums, int target) {
        return BinarySearch(0, nums.size() - 1, nums, target);
    }

private: 
    int BinarySearch (int left, int right, vector<int>&nums, int target) {

        //should not cross the right pointer as it means the target is not present
        if (right >= left) {

            //TO PREVENT INTERGER OVERFLOW!! (it wont let the sum cross the max int size)
            int mid = left + (right - left) / 2;

            //when it finds the target
            if (nums[mid] == target) {
                return mid;
            }

            //when the num is present in the right half
            else if (nums[mid] < target) {
                return BinarySearch(mid + 1, right, nums, target);
            }

            //when the num is present in the left half
            else return BinarySearch(left, mid - 1, nums, target);
        }

        // when element not found in either half      or (left > right)
        else return -1;
    }
};