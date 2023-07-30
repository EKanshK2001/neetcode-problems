/*
O(n) n is the no. of words in array, O(n)

Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

link :  https://leetcode.com/problems/contains-duplicate/

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        
                    /* solution 1 using map 166ms runtime and 71mb space quite bad!  */

        //hashmap O(n), space O(n)
        unordered_map <int, int> m;      
        
        for (int i = 0; i < nums.size(); i++) {
            m[nums[i]]++;
        }

        //check if any entry registered more than once
        for (auto i: m) {
            if (i.second > 1) {
                return true;
            }
        }

        return false;
    }
};