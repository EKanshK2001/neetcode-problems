/*
O(n) where s is length of first string and t is of second 

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

link : https://leetcode.com/problems/valid-anagram/
*/

/**
 * @brief this algorithm makes use of (kind of) hash functions. But really just an array.
 * and the fact that anagrams contain the same elements in the same frequency.
 * 
 * we make a zero array of size 26 for all the alphabets, then just increment and decrement the value (0) for a character index.
 * if they are really anagrams, then they should have the same characters the same no. of times.
 * this means that incrementing and decrementing them the same no. of times, will result in them being the same or 0, in this case.
 * 
 * so we check for any non-zero element in the array later, and if found, its not an anagram or else it is.
 */

class Solution {
public:
    bool isAnagram(string s, string t) {

        //4ms, 7.3mb            Using Hash Table              O(n), O(1)
        if (s.size() != t.size()) return false;

        int arr[26] = {0};

        //maintain a hash map for S with increment and T with decrement 
        for (int i = 0; i < s.length(); i++) {
            arr[s[i] - 'a']++;
            arr[t[i] - 'a']--;
        }

        //check for non 0s if any
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) return false;
        }

        return true;
    }
};