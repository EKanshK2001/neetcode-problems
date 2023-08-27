/**
 * O(n), O(n) set creation and iteration.
 * 
 * Given an unsorted array of integers nums, return the length of the longest consecutive elements sequence.
 * 
 * link: https://leetcode.com/problems/longest-consecutive-sequence/
 */

/**
 * @brief this code is essentially the same as the previous we just checked if finding an element in a set faster:
 * the inbuilt function count which returns 0/1 or the inbulit function find which returns the iterator of end() if not found and iterator of the element if found.
 * 
 * results : find function consistently performed better idk how. (105ms vs 127ms)
 * but they both are fast O(1) in theory. 
 * 
 * ik its not much of a difference but i know which one i'll be using more now.
 * and its not like find made count func obsolete its just that i was more used to it and that it proved to be little faster as well so ggs.
 */

class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        unordered_set<int>s(nums.begin(), nums.end());
        int longest = 0;
        
        for(auto &n: s){
            //if this is the start of the sequence
            if(!s.count(n - 1)){
                int length = 1; 
                while(s.count(n + length))
                    ++length;
                longest = max(longest, length);
            } 

        }
        return longest;
    }
};