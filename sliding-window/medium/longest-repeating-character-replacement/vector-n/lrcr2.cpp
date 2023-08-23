/**
 * O(n), O(n)   --> unoptimized one takes 26.n time because of searching in 26 alphabet map in worst case, but not in this algo.
 * 
 * You are given a string s and an integer k. You can choose any character of the string and change it to any other uppercase English character. You can perform this operation at most k times.
 * 
 * link: https://leetcode.com/problems/longest-repeating-character-replacement/
 */

/**
 * @brief same thing as lrcr1.cpp just this time instead of keeping track of frequency of characters using a map we do it using a vector which essentially acts as a hash table.
 * 
 */
class Solution {
public:
    int characterReplacement(string s, int k) {
        int maxLength = 0;
        int l = 0, r;
        int maxf = 0;

        vector<int> substring(26);

        for (r = 0; r < s.size(); r++) {
            substring[s[r] - 'A']++;
            maxf = max(maxf, substring[s[r] - 'A']);

            while((r - l + 1) - maxf > k) {
                substring[s[l] - 'A']--;
                l++;
            }

            maxLength = max(maxLength, r - l + 1);
        }
        
        return maxLength;
    }
};