/*
O(slogs + tlogt) where s is length of first string and t is of second 

Given two strings s and t, return true if t is an anagram of s, and false otherwise.

link : https://leetcode.com/problems/valid-anagram/
*/

/**
 * @brief basically if both of them are equal after sorting both strings, then yes else no.
 * 
 */
class Solution {
public:
    bool isAnagram(string s, string t) {

    //  22ms,7.3mb         Using Sorting    O(slogs + tlogt), O(1)
        
        if (s.length() != t.length()) {     //basic check - if not of same length, return false.
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
    }
};