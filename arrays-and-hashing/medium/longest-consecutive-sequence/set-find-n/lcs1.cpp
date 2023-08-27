/**
 * O(n), O(n) set creation and iteration.
 * 
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * 
 * link: https://leetcode.com/problems/longest-consecutive-sequence/
 */

/**
 * @brief Here we need to find the longest sequence length in an array of integers, so we just need to check it once and not store it anywhere.
 * 
 * we convert the array to a set to make every operation faster O(1).
 * after this we iterate over every element and check if it is a start of a new sequence.
 * once we know a number is the start, we start finding the sequential numbers after it and increment the length as well.
 * and during this iteration as well we compare the previous longest if the new length we longer.
 * 
 * we just convert it into a set to:
 *  - remove duplicates as they dont matter (for a sequence anyways)
 *  - make the operations of anything but specially searching for a number O(1)
 *  - also for iterating, we can use the set as this actually reduced the runtime very significantly like 4times.
 * 
 * technicalities:
 *  - we check for a start of sequence number by finding the n-1 number in the set.
 *  - we check for further elements by finding the n + length number in the set. where length is being incremented after every find.
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        int longest = 0;
        unordered_set<int> numSet(nums.begin(), nums.end());

        for (auto &num : numSet) {      //we need to iterate in set as it removes duplicates or just is better for iterating. (saved time 4x from 485ms to 105ms!!)

            //check if a num is the start of a sequence
            if (numSet.find(num - 1) == numSet.end()) {

                int length = 0;

                //if it has more numbers after it
                while (numSet.find(num + length) != numSet.end()) {     //mind that we find num + length and not num + 1 (as this will find only the one element after it, an endless loop!)
                    length++;
                    longest = max(length, longest);
                }  
            }
        }
        return longest;
    }
};