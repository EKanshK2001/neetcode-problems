/*
O(slogs + tlogt) where s is length of first string and t is of second 

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

link : https://leetcode.com/problems/valid-anagram/
*/


class Solution {
public:
    bool isAnagram(string s, string t) {

    //  22ms,7.3mb         Using Sorting    O(slogs + tlogt), O(1)
        
        if (s.length() != t.length()) {
            return false;
        }
        else {
            sort(s.begin(), s.end());
            sort(t.begin(), t.end());
            
            //if sorted s != sorted t, then return
            if(s!=t) {
                return false;
            }
            else return true;
        }

};