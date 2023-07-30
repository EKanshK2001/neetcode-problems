/*
O(n) where s is length of first string and t is of second 

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

link : https://leetcode.com/problems/valid-anagram/
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

        //check for still 0s
        for (int i = 0; i < 26; i++) {
            if (arr[i] != 0) return false;
        }

        return true;
    }
};