/*
O(nlogn) sorting , O(1)

Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

link :  https://leetcode.com/problems/contains-duplicate/

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
    
    /*solution 2 using sorting     pretty good    134ms, 57mb */
    //sorting O(nlogn), space O(1)

    sort(nums.begin(), nums.end());         
    for(int i = 0; i < nums.size() - 1; i++) {
        if (nums[i] == nums[i+1]) {
            return true;
        }
    }
    return false;
    }
};