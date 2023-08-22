/**
 * O(n), O(n)... n becomes the set size as well in worst case that's why
 * 
 * Given a string s, find the length of the longest substring without repeating characters.
 * 
 * link : https://leetcode.com/problems/longest-substring-without-repeating-characters/
 */

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        /*
        quite wierd of a sliding window.
        we keep track of new elements encountered using a set

        left pointer is actually a reference for the length of substring

        right pointer is the one traversing...
        it keeps inserting new elements and if

        if it encounters old element from the whole of the substring (recall they are present in the set),
        they will be popped using the reference of left pointer until that old element is fully new in the set/substring.

        thus the window (substring) slides and maxLength is recorded in the process.

        this method works fine but I really don't know how.
        */
        
        int maxLength = 0;
        int l = 0, r;
        unordered_set<char> charSet;

        for (r = l; r < s.length(); r++) {      //right actually starts from the start (left) this time
            
            //when we find an old element
            while (charSet.find(s[r]) != charSet.end()) {
                charSet.erase(s[l]);    //erase it using the reference of left pointer
                l++;                    //increment the left pointer
            }

            //otherwise insert it 
            charSet.insert(s[r]);

            //keep updating current maxLength every iteration
            maxLength = max(maxLength, r - l + 1);
        }

        return maxLength;
    }
};