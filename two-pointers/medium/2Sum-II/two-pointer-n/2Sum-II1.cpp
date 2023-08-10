/**
 * O(n), O(1)
 * 
 * Given a 1-indexed array of integers numbers that is already sorted in non-decreasing order, find two numbers such that they add up to a specific target number.
 * 
 * link : https://leetcode.com/problems/two-sum-ii-input-array-is-sorted/
 */


/**
 * @brief this algorithm works as the array is sorted
 * we make the left and right pointers and increment left (as its lower) if the sum is lower than the target and decrement right (as its greater) if the sum is greater than the target. 
 */

class Solution {
public:
    vector<int> twoSum(vector<int>& numbers, int target) {
        int l = 0, r = numbers.size() - 1;

        while (l < r) {
            int currentSum = numbers[l] + numbers[r];
            if (currentSum > target) {
                r--;
            }
            else if (currentSum < target) {
                l++;
            }
            else {
                return {l + 1, r + 1};
            } 
        }
        return {};
    }
};