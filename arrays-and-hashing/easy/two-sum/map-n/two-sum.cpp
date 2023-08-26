/**
 * O(n), O(n)
 * 
 * Given an array of integers nums and an integer target, return indices of the two numbers such that they add up to target.
 * 
 * link: https://leetcode.com/problems/two-sum/
 */

/**
 * @brief we cannot use two pointer solution here because: 
 *  - they are not sorted
 *  - we need to return the index so we cannot really return changed indices after sorting.
 * 
 * anyways the map solutions work fine, storing the index of a number encountered in the map against them.
 * whenever we encounter a new number, we check if its complement is already in the map,
 * if it is then we found the pair, if not by the end of array then outside the loop we return an empty array.
 * 
 */
class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        // unordered_map<int, int> m;

        // for (int i = 0; i < nums.size(); i++) {
        //     m[nums[i]] = i;
        // }

        // for (int i=0; i<nums.size(); i++) {
        //     int complement = target - nums[i];
        //     if (m.find(complement) != m.end() && m[complement] != i) {
        //         return {i, m[complement]};
        //     }
        // }
        // return {};

    //optimised solution 8ms, 10.7mb        O(n), O(n)
        unordered_map <int,int> m;

        for (int i = 0; i < nums.size(); i++) {
            int complement = target - nums[i];

            //if we find it as a complement, return it (and its index) in array format else keep adding the number with its index in the map
            if (m.find(complement) != m.end() && m[complement] != i) {
                return {i, m[complement]};
            }
            else {
                m[nums[i]] = i;
            }
        }

        return {};  
    }
};