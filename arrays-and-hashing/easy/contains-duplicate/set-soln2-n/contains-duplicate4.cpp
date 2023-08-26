/*
O(n) n is the no. of words in array, O(n)

Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

link :  https://leetcode.com/problems/contains-duplicate/

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        /*solution 4, just better version of my map code   127ms, 74mb  very good*/
        
        //hashset O(n), space O(n)
        
        //makes use of the fact that set don't store duplicate values.
        return (set(nums.begin(), nums.end()).size() < nums.size());    //returns true if set size is lower than the original array size and false otherwise.
    }
};