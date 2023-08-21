/**
 * O(n), O(n) because of only iterating the array multiple times and declaring prefix and suffix arrays.
 * 
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * link: https://leetcode.com/problems/product-of-array-except-self/
 */

/**
 * - declaring prefix array to store product of left side elements of current number.
 * - declaring suffix array to store product of right side elements of current number.
 * 
 * technicalities : 
 * - we iterate left to right for prefix array. Also the prefix for first element will be default 1.
 * - we iterate right to left for suffix array and same, the suffix for last element will be default 1.
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        //declaring 3 vectors for result, prefix array and suffix array of size n (vector allows assigning later only when size if predifined)
        vector<int> result(n);
        vector<int> prefix(n);
        vector<int> suffix(n);

        //prefix array will store product of all the numbers before nums[i] as prefix[i]
        prefix[0] = 1;
        for (int i = 1; i < n; i++) {
            prefix[i] = nums[i - 1] * prefix[i - 1];
        }

        //suffix will store the product of all the numbers after nums[i] as suffix[i]
        suffix[n - 1] = 1;
        for (int i = n - 2; i >= 0; i--) {
            suffix[i] = nums[i + 1] * suffix [i + 1];
        }

        //finalizing the result[i] as product of prefix and postfix
        for (int i = 0; i < n; i++) {
            result[i] = prefix[i] * suffix[i];
        }

        return result;
    }
};