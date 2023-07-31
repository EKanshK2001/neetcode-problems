/*
O(n) even for being fairly efficient

A phrase is a palindrome if, after converting all uppercase letters into lowercase letters and removing all non-alphanumeric characters, 
it reads the same forward and backward. Alphanumeric characters include letters and numbers.

link: https://leetcode.com/problems/valid-palindrome/

*/


class Solution {
public:
    bool isPalindrome(string s) {

        int size = s.length();
        //start left pointer at left index and right at right most
        int l = 0, r = size - 1;

        //to keep left pointer at left of right
        while (l < r) {

            //increments left pointer simultaneously if not alphanum
            while (l < r && !iswalnum(s[l]))  {     
                ++l;
            }

            //increments right pointer simultaneously if not alphanum
            while (r > l && !iswalnum(s[r])) {      
                --r;
            }

            //to return immediately if unmatched characters found
            if (tolower(s[l]) != tolower(s[r])) {
                return false;
            }

            //incrementing regularly as a while loop
            l++; r--;
        }

        return true;
    }
};