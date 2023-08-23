/**
 * O(n), O(n)   --> unoptimized one takes 26.n time because of searching in 26 alphabet map in worst case, but not in this algo.
 * 
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
 * 
 * link: https://leetcode.com/problems/longest-repeating-character-replacement/
 */

/**
 * @brief we perform the same substring implementation using two pointer, which is also a sliding window.
 * we keep track of validity this time using a map this time, instead of a set like last time (during longest substring without repeating character).
 * As we need to keep track of their frequency as well.
 * 
 * IMP : 
 * - A very special technique or optimization decreases the algorithm complexity (as in time and space) very nicely. 
 * - Using the maxf implementation. (more of that in technicalities).
 * 
 * technicalities:
 * - right pointer goes on till the end.
 * - left pointer starts to change only when some normal condition goes wrong. (following a very repeating template in sliding window problems).
 * 
 * - MAXF variable keeps track of the maximum frequency of obviously the the most frequent character but it also compares it to the current new character's frequency that was introduced in that iteration.
 * - thus keeping track if there's a change in the new frequent character. (while that iteration only)
 * - this is due to the fact that the new (or most recent) character introduced will be the only one changing or impacting the maximum repeating character.
 * - becuase of this optimization, we dont need to search the entire map for the most frequent character in the current substring every iteration. 
 *      -which will take O(n) time in c++ making it O(n^2) at times.
 * 
 * - The validity check formula is :
 *      - (length of substring - maxf <= k) --> the difference will give the no. of less frequent characters that substring can be kept if we have enough k.
 * 
 * 
 */

class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int l = 0, r;
        int maxf = 0;

        unordered_map<char, int> substring;     //maintaines the substring between left and right pointers. doesn't matter if valid right now or not, that will be checked with the formula later on.

        for (r = 0; r < s.size(); r++) {
            //increase or make new addition for theat character in the map (substring)
            substring[s[r]]++;

            //maxf only changes if a more frequent character is introduced. (care: every character introduced in that iteration will be the only change in the map/substring)
            //or the frequency of that character might be the new maxf!! (note: this is performed every character so its not scanning the entire map every iteration for that)
            maxf = max(maxf, substring[s[r]]);       

            //the validity check, if we find it to be true, then the rule is broken and we decrease the map entry for the left pointer character, essentially decreasing the substring size while adding the new element
            while((r - l + 1) - maxf > k) {
                substring[s[l]]--;
                l++;
            }

            //maxLength checks for new substring size if bigger.
            maxLength = max(maxLength, r - l + 1);
        }
        
        return maxLength;
    }
};