/**
 * O(n), O(n)   --> unoptimized one takes O(26.n) time because of searching in 26 alphabet map in worst case, but not in this algo.
 * 
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. 
 * You can perform this operation at most k times.
 * 
 * link: https://leetcode.com/problems/longest-repeating-character-replacement/
 */

/**
 * @brief we perform the same substring implementation using two pointer, which is also a sliding window.
 * we keep track of validity this time using a map, instead of a set like last time (during longest substring without repeating character).
 * As we need to keep track of their frequency as well.
 * 
 * IMP: 
 * - A very special technique or optimization decreases the algorithm complexity (as in time) very nicely. 
 * - Using the maxf implementation. (more of that in technicalities).
 * - note that maxf from a previous substring might be bigger than the max freq of a current substring.
 *      - this does not hinder the longest length at that we recorded, however a new maxf will. so even if we leave an old maxf we will still be having the longest length at the end. (works fine idk how)
 * 
 * technicalities:
 * - right pointer goes on till the end.
 * - left pointer starts to change only when some normal condition (here the substring validity) goes wrong. (following a very repeating template in sliding window problems).
 * 
 * - MAXF variable keeps track of the maximum frequency of the the most frequent character BUT IT DOES SO BY: *comparing it to the current new character's frequency that was introduced in that iteration*. 
 * - as its the only one changing in the map at the time.
 * - if the new frequency passes the old max frequency (maxf) then we update it. before going for the validity check.
 * - becuase of this optimization, we dont need to search the entire map for the most frequent character in the current substring every iteration. 
 *      -which will take O(26) (26 alphabets) time in c++ making it O(26.n).
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
            //increase or make new addition for this character in the map (substring)
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