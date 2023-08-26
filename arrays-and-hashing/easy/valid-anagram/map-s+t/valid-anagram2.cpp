/*
O(S + T) where s is length of first string and t is of second 

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

link : https://leetcode.com/problems/valid-anagram/
*/

/**
 * @brief so basically using a map to keep track of their elements is fine enough we just use more space to tackle the sorting complexity.
 * this works for dedicated algorithms to search for validity of anagram tho but there's an even better way next solution.
 * also sorting is fine and not a bad solution at all as we will find out in the medium valid anagram problem.
 * 
 * just keep track of frequency of elements and compare them later on.
 */

class Solution {
public:
    bool isAnagram(string s, string t) {

        //  3 to 12ms, 7.8mb         Using Maps          O(S+T), O(S+T)
        if (s.size() != t.size()) return false;

        // keeping track of individual letter count in both strings
        unordered_map <char, int> Smap;
        unordered_map <char, int> Tmap;

        for (int i = 0; i < s.size(); i++) {
            Smap[s[i]]++;
            Tmap[t[i]]++;
        }

        //this check could have been wrong if one string was a superset of the other (an edge case) which we cover with the size of them both not being equal above.
        for (int i = 0; i < Smap.size(); i++) {
            if (Smap[i] != Tmap[i]) return false;
        }
        return true;
    }
};