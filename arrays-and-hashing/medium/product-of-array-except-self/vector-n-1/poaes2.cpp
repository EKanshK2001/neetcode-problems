/**
 * O(n), O(n) because of only iterating the array multiple times and declaring prefix and suffix arrays.
 * 
 * Given an integer array nums, return an array answer such that answer[i] is equal to the product of all the elements of nums except nums[i].
 * 
 * link: https://leetcode.com/problems/product-of-array-except-self/
 */

/**
 * - we declare the prefix and suffix variables (as 1) and operate their storage (or product) in the result vector itself. (saves space).
 * 
 * technicalities :
 * - store the prefixes first.
 * - multiply the suffix with the already present prefixes before storing them.
 * - update both of them simulataneously after.
 */

class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();

        vector<int> result(n);

        //maintain variables
        int prefix = 1;
        int suffix = 1;

        //prefix will have to be stored left to right while readying the prefix to be multiplied in the next iteration to the no. of the original array.
        for (int i = 0; i < n; i++) {
            result[i] = prefix;
            prefix *= nums[i];      //mind that its being multiplied to the same index no. from the array when its a prefix. (cuz its to be used in the next iteration).
        }

        //suffix on the otherhand is now multiplied instead of stored. and readied again for its next iteration by being multiplied with the no. of the original array.
        for (int i = n - 1; i >= 0; i--) {
            result[i] *= suffix;
            suffix *= nums[i];      //mind that its being multiplied to the same index no. from the array when its a suffix. (cuz its to be used in the next iteration).
        }

        return result;
    }
};