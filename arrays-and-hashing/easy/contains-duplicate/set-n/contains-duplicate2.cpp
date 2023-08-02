/*
O(n) n is the no. of words in array, O(n)

Given an integer array nums, return true if any value appears at least twice in the array,
and return false if every element is distinct.

link :  https://leetcode.com/problems/contains-duplicate/

*/

class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {

        /*solution 3 neetcode not as good, just better version of my map code   158ms, 69.4mb */
        
        //hashmap O(n), space O(n)
        unordered_set<int> s;
        
        //if u find an earlier entry of that word, return true, else keep insert i.e. false
        for (int i = 0; i < nums.size(); i++) {
            if (s.find(nums[i]) != s.end()) {
                return true;
            }
            s.insert(nums[i]);
        }
        
        return false;
    }
};