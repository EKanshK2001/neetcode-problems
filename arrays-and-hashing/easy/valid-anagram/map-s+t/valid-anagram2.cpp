/*
O(S + T) where s is length of first string and t is of second 

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

link : https://leetcode.com/problems/valid-anagram/
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

        for (int i = 0; i < Smap.size(); i++) {
            if (Smap[i] != Tmap[i]) return false;
        }
        return true;
    }
};